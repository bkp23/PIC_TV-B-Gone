#define NA_CODES  // Tell WORLDcodes.c that we want North American codes

// Needed for compatibility with WORLDcodes.c:
#define uint8_t  unsigned char
#define uint16_t unsigned int
#define PROGMEM

// Lets us calculate the size of the NA/EU databases
#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)));

// Makes the codes more readable. the PWM is actually
// programmed in terms of 'periods' not 'freqs' - that
// is, the inverse!
#define freq_to_timerval(x) (( (4e6+x/2)/x )-1) // auto-rounds
//#define freq_to_timerval(x) ((4e6/x)-1)

// The structure of compressed code entries
// Packing this struct costs only 5.567ms, but
// saves 95 instructions of memory.
// (The compiler still wastes 1/3 of each memory location.)
struct __attribute__ ((packed)) IrCode { // now packed!
  unsigned char timer_val;
  unsigned char numpairs;
  unsigned char bitcompression;
  unsigned int const *times; // ontimes and offtimes
  unsigned char codes[]; // time indicies are stored here
};

unsigned char readBits(const unsigned char codes[], unsigned char index, unsigned char numbits);
void xmitCodeElement(unsigned int ontime, unsigned int offtime, unsigned int period);
void flashslowLEDx(unsigned char num_blinks);
void quickflashLEDx(unsigned char x);
void tvbgone_sleep();
inline void delay_ten_us(unsigned int tenUs);
void quickflashLED();
void startPWM(unsigned int period);
void stopPWM();
