/*
 * TV-B-Gone for PIC24F08KA101 by B. Perry
 * Based on TV-B-Gone Firmware version 1.2:
 *   Original code (c) Mitch Altman + Limor Fried 2009
 *   Original code last edits, August 16 2009
 * Distributed under Creative Commons 2.5 -- Attrib & Share Alike
 * Last edit: 27 July 2010
 */

// GOALS:
// 1) Create a TV-B-Gone for the PIC24F series.
// 2) Allow PIC version to use AVR version of WORLDcodes.c
// SUCCESS!

#include "main.h"
#include "P24Fxxxx.h"

/* PIC24F08KA101 hookup is very simple:
 *     pin 1   MCLR_Low: pulled high through 10k resistor & button to ground
 *     pin 6   Button to ground (optional; used for manually stopping sequence)
 *     [pin 7   One pin of 8 MHz reonator]     OBSOLETE
 *     [pin 8   Other pin of 8 MHz resonator]  OBSOLETE
 *     pin 14  OC1 - IR emmitter(s) (active high, through PNP drivers)
 *     pin 18  LED indicator (active high) (optional)
 *     pin 19  Vss: ground
 *     pin 20  Vdd: 3.0V - 5.0V
 *   remaining pins unused - what a waste! :)
 *   Place a 0.1 uF, 20+V ceramic cap between pins 7 and 8
 */

_FOSCSEL(FNOSC_FRC); // use internal FRC (~8 MHz)
_FOSC(OSCIOFNC_ON);  // OSCO Pin Has Digital I/O Function (RA3)
//_FOSCSEL(FNOSC_PRI);                            // Use external 8 MHz resonator
//_FOSC(POSCFREQ_MS & OSCIOFNC_ON & POSCMOD_HS);  // External resonator in HS (high-speed) mode
_FWDT(FWDTEN_OFF); // disable watchdog timer
_FICD(ICS_PGx2); // Use PGC2/PGD2 (for XLP board)
_FPOR(BORV_V18); // Brown-Out Reset @ 1.8V
_FDS(DSWDTEN_OFF & DSBOREN_OFF & DSWDTOSC_LPRC); // disable deep sleep WDT, disable deep sleep BOR, set RTCC to SOSC

extern const struct IrCode *NApowerCodes[] PROGMEM;
extern const uint8_t num_NAcodes;
extern void __delay32(); // Takes an unsigned long as its argument, but compiler doesn't like it declared :(


/* This function is the 'workhorse' of transmitting IR codes.
   Given the on and off times, it turns on the PWM output on and off
   to generate one 'pair' from a long code. Each code has ~50 pairs! */
void xmitCodeElement(unsigned int ontime, unsigned int offtime, unsigned int period)
{
  if(period != 0)
  {
    // 99% of codes are PWM codes, they are pulses of a carrier frequecy
    // Usually the carrier is around 38KHz, and we generate that with PWM
    startPWM(period);
  }
  else
  {
    // However some codes dont use PWM in which case we just turn the IR
    // LED on for the period of time. (Usually only 30us at a time.)
    _LATA6 = 0; // Turn on LED
  }

  // Now we wait, allowing the PWM hardware to pulse out the carrier
  // frequency for the specified 'on' time
  delay_ten_us(ontime);

  stopPWM();  // Now we have to turn it off so disable the PWM output
  _LATA6 = 0; // Turn off LED

  if (offtime>3) // this should always be true, except on final pair
    delay_ten_us(offtime-3); // Now we wait for the specified 'off' time,
}                            // less the 30us we'll spend preparing the next pair



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

  // Initialize pins
  _PCFG4 = 1; // Set AN4/RA2 to digital so RB2 will work (see datasheet errata)
  _CN6PUE = 1; // enable RB2 internal pull-up resistor
  _TRISA6 = 0; // Set RA6 (pin 14) to output (for driving IR)
  _TRISB15 = 0; // Set RB15 (pin 18) to output (LED indicator)

  // Starting execution loop

  do    //Execute the code at least once.  If Loop is on, execute forever.
  {
    for(i=0 ; i < num_NAcodes && _RB2==1; i++) // iterate through North American power codes
    {
      delay_ten_us(25000);   // delay 250 milliseconds before transmitting next POWER code

      // This next line is so much easier than what's required for the AVR.
      code = NApowerCodes[i];  // point to next POWER code from the NA database

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
      _LATB15 = i & 1; // visible indication that a code has been output.
    }
  } while (0); // do not loop

  _LATB15 = 0; // turn off LED indicator

  PMD1 = 0xFFFF; // disable all peripherals
  PMD2 = 0xFFFF;
  PMD3 = 0xFFFF;
  PMD4 = 0xFFFF;

  DSCONbits.DSEN = 1; // Enter deep sleep
  Sleep();
  while(1); // this line should never be executed, but just in case...
}



/****************************** PWM AND DELAY FUNCTIONS ********/


// This function delays the specified number of 10 microseconds
inline void delay_ten_us(unsigned int tenUs)
{
  __delay32(tenUs*40); // Fcy = 4MHz. That's 4 cycles/us, or 40/10us.
}

void startPWM(unsigned int period)
{
  // OC1CONbits.OCM = 0; // Disable PWM
  PR2 = period; // For example, 0x68 = 38,095 Hz
  TMR2 = 0;    // reset timer count, to keep values aligned
  OC1R = period/2; // 50% duty cycle
  OC1RS = period/2; // same value as O1CR
  OC1CONbits.OCM = 0b110; // Initialize PWM mode; fault_pin/OFCA disabled
  T2CONbits.TON = 1; // Start Timer2
}


void stopPWM()
{
  T2CONbits.TON = 0;// Stop Timer2
  OC1CONbits.OCM = 0; // Disable PWM
}
