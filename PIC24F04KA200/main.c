/*
 * Based on TV-B-Gone Firmware version 1.2
 * for use with PIC24F04KA200 and custom hardware
 * Original code (c) Mitch Altman + Limor Fried 2009
 * Original code last edits, August 16 2009
 * Distributed under Creative Commons 2.5 -- Attrib & Share Alike
 * Last edit: June 2010
 */

// GOALS:
// 1) Create a TV-B-Gone for the PIC.
// 2) Allow PIC version to use AVR version of WORLDcodes.c
// #2 almost accomplished. The specific PIC I chose has only 1408 bytes of program
// flash, so I had to trim down the codes. But a larger PIC could, in fact, use the
// full WORLDcodes.c and work just fine.

#include "main.h"
#include "P24Fxxxx.h"


/* PIC24F04KA200 hookup is very simple:
 *     pin 1   MCLR_Low: pulled high through 10k resistor
 *     pin 4   One pin of 8 MHz reonator
 *     pin 5   Other pin of 8 MHz resonator
 *     pin 10  OC1 - IR emmitter(s)
 *     pin 13  Vss: ground
 *     pin 14  Vdd: 3.0V - 5.0V 
 */

// _FOSCSEL(FNOSC_FRC); // use internal FRC (~8 MHz)
_FOSCSEL(FNOSC_PRI);                            // Use external 8 MHz resonator
_FOSC(POSCFREQ_MS & OSCIOFNC_OFF & POSCMOD_HS); // External resonator in HS (high-speed) mode
_FWDT(FWDTEN_OFF); // disable watchdog timer


extern const struct IrCode *NApowerCodes[] PROGMEM;
extern const uint8_t num_NAcodes;
extern void __delay32(unsigned int);



/* This function is the 'workhorse' of transmitting IR codes.
   Given the on and off times, it turns on the PWM output on and off
   to generate one 'pair' from a long code. Each code has ~50 pairs! */
void xmitCodeElement(unsigned int ontime, unsigned int offtime, unsigned int period)
{
  if(period != 0)
  {
    // 99% of codes are PWM codes, they are pulses of a carrier frequecy
    // Usually the carrier is around 38KHz, and we generate that with PWM
    // timer 0
    startPWM(period);
  } 
  else
  {
    // However some codes dont use PWM in which case we just turn the IR
    // LED on for the period of time.
    
    // Could enable LED manually, but I'm worried about burning it out
  }

  // Now we wait, allowing the PWM hardware to pulse out the carrier 
  // frequency for the specified 'on' time
  delay_ten_us(ontime);
  
  stopPWM();  // Now we have to turn it off so disable the PWM output
  _LATB14 = 0; // Turn off LED (if on from non-PWM use)
  
  delay_ten_us(offtime); // Now we wait for the specified 'off' time
}


// Returns <numbits> bits from the bit array codes[] as indexed by index
unsigned char readBits(const unsigned char codes[], unsigned char index, unsigned char numbits)
{
  unsigned char bitdex = index*numbits; // useful for calculations
  unsigned char x=0, tmp;
  int a;

  for(a=0; a<numbits; a++)
  {                         // Do the bit dance!
    tmp = codes[bitdex/8];   // grab the byte with our target bit
    tmp <<= (bitdex%8);      // shift our target bit clear to the left
    tmp >>= 7;               // now shift it all the way back to the right
    tmp <<= numbits - a - 1; // now shift it into its proper bit position
    x |= tmp;                // and give it to x
    bitdex++; // prepare to grab the next bit
  }
  return x;
}


int main(void) {
  int i, k; // used for iterating power codes, pairs
  unsigned char timeIndex;
  const struct IrCode *code;
  
  // Initialize pins here !@#!!
  AD1PCFGbits.PCFG4 = 1; // Disable ANA4 (OSCI)
  AD1PCFGbits.PCFG4 = 1; // Disable ANA5 (OSCO)
  _TRISB14 = 0; // Set RB14 (pin 10) to output



  delay_ten_us(5000);            // Let everything settle for a bit

  // Consider blinking LED indicator here
  
  // Starting execution loop
  delay_ten_us(25000);
  
  do 	//Execute the code at least once.  If Loop is on, execute forever.
  {
    for(i=0 ; i < num_NAcodes; i++) // iterate through North American power codes
    {
      code = NApowerCodes[i];  // point to next POWER code, from the NA database      

      // Transmit all codeElements for this POWER code.
      // (A codeElement is an onTime and an offTime.)
      // Transmitting onTime means pulsing the IR emitters at the carrier 
      // frequency for the length of time specified in onTime.
      // Transmitting offTime means no output from the IR emitters for the 
      // length of time specified in offTime.

      // For EACH pair in this code....
      for (k=0; k < code->numpairs; k++)
      {
        // Read the next 'n' bits as indicated by the compression variable
        // then multiply by 2 because there are 2 timing numbers per pair.
        timeIndex = readBits(code->codes, k, code->bitcompression)*2;

        // transmit this codeElement (ontime and offtime)
        xmitCodeElement(code->times[timeIndex], code->times[timeIndex+1], code->timer_val);  
      } // for(each pair)
      
      // delay 250 milliseconds before transmitting next POWER code
      delay_ten_us(25000);
      
      // visible indication that a code has been output.
      quickflashLED(); 
    }
  } while (0); // do not loop

  quickflashLEDx(4);

  _TRISB14 = 0; // Set RB14 (pin 10) to input, just in case it's driving LED still

  while(1);
}



/****************************** LED AND DELAY FUNCTIONS ********/


// This function delays the specified number of 10 microseconds
void inline delay_ten_us(unsigned int tenUs)
{
  __delay32(tenUs*40); // Fcy = 4MHz. That's 4 cycles/us, or 40/10us.
}


// This function quickly pulses the visible LED
void quickflashLED()
{
  //turn on visible LED by pulling pin to ground
  // delay_ten_us(3000);   // 30 millisec delay
  //turn off visible LED at PB0 by pulling pin to high
}

// This function just flashes the visible LED a couple times, used to
// tell the user what region is selected
void quickflashLEDx(unsigned char x )
{
  //quickflashLED();
  while(--x)
  {
	  //delay_ten_us(15000);     // 150 millisec delay between flahes
    //quickflashLED();
  }
}

void startPWM(unsigned int period)
{
  OC1CONbits.OCM = 0; // Disable PWM
  PR2 = period; // 0x68 = 38,095 Hz
  TMR2 = 0;    // reset timer count, to keep values aligned
  OC1R = period/2; // 50% duty cycle
  OC1RS = period/2; // same value as O1CR
  OC1CONbits.OCM = 0b110; // Initialize PWM mode; fault_pin/OFCA disabled
  T2CONbits.TON	= 1; // Start Timer2
}


void stopPWM()
{
  T2CONbits.TON = 0;// Stop Timer2
  OC1CONbits.OCM = 0; // Disable PWM
}
