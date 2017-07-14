#include "main.h"

//Codes captured from Generation 3 TV-B-Gone by Limor Fried & Mitch Altman
// table of POWER codes

// Unable to include more than 47 NA codes due to 1408-byte
// limit of the PIC24F04KA200.
// A larger device would be able to use the complete WORLDcodes.c.


const uint16_t code_na000Times[] PROGMEM = {
        60, 60,
        60, 2700,
        120, 60,
        240, 60,
};
const struct IrCode code_na000Code PROGMEM = {
        freq_to_timerval(38400),
        26,             // # of pairs
        2,              // # of bits per index
        code_na000Times,
        {
                0xE2,
                0x20,
                0x80,
                0x78,
                0x88,
                0x20,
                0x10,
        }
};

const uint16_t code_na001Times[] PROGMEM = {
	50, 100,
	50, 200,
	50, 800,
	400, 400,
};
const struct IrCode code_na001Code PROGMEM = {
	freq_to_timerval(57143),
	52,		// # of pairs
	2,		// # of bits per index
	code_na001Times,  
	{
		0xD5,
		0x41,
		0x11,
		0x00,
		0x14,
		0x44,
		0x6D,
		0x54,
		0x11,
		0x10,
		0x01,
		0x44,
		0x45,
	}
};
const uint16_t code_na002Times[] PROGMEM = {
	42, 46,
	42, 133,
	42, 7519,
	347, 176,
	347, 177,
};
const struct IrCode code_na002Code PROGMEM = {
	freq_to_timerval(37037),
	100,		// # of pairs
	3,		// # of bits per index
	code_na002Times,  
	{
		0x60,
		0x80,
		0x00,
		0x00,
		0x00,
		0x08,
		0x00,
		0x00,
		0x00,
		0x20,
		0x00,
		0x00,
		0x04,
		0x12,
		0x48,
		0x04,
		0x12,
		0x48,
		0x2A,
		0x02,
		0x00,
		0x00,
		0x00,
		0x00,
		0x20,
		0x00,
		0x00,
		0x00,
		0x80,
		0x00,
		0x00,
		0x10,
		0x49,
		0x20,
		0x10,
		0x49,
		0x20,
		0x80,
	}
};
const uint16_t code_na003Times[] PROGMEM = {
	26, 185,
	27, 80,
	27, 185,
	27, 4549,
};
const struct IrCode code_na003Code PROGMEM = {
	freq_to_timerval(38610),
	64,		// # of pairs
	2,		// # of bits per index
	code_na003Times,  
	{
		0x15,
		0x5A,
		0x65,
		0x67,
		0x95,
		0x65,
		0x9A,
		0x9B,
		0x95,
		0x5A,
		0x65,
		0x67,
		0x95,
		0x65,
		0x9A,
		0x99,
	}
};
const uint16_t code_na004Times[] PROGMEM = {
	55, 57,
	55, 170,
	55, 3949,
	55, 9623,
	56, 0,
	898, 453,
	900, 226,
};
const struct IrCode code_na004Code PROGMEM = {
	freq_to_timerval(38610),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,  
	{
		0xA0,
		0x00,
		0x01,
		0x04,
		0x92,
		0x48,
		0x20,
		0x80,
		0x40,
		0x04,
		0x12,
		0x09,
		0x2B,
		0x3D,
		0x00,
	}
};
const uint16_t code_na005Times[] PROGMEM = {
	88, 90,
	88, 91,
	88, 181,
	88, 8976,
	177, 91,
};
const struct IrCode code_na005Code PROGMEM = {
	freq_to_timerval(35714),
	24,		// # of pairs
	3,		// # of bits per index
	code_na005Times,  
	{
		0x10,
		0x92,
		0x49,
		0x46,
		0x33,
		0x09,
		0x24,
		0x94,
		0x60,
	}
};
const uint16_t code_na006Times[] PROGMEM = {
	50, 62,
	50, 172,
	50, 4541,
	448, 466,
	450, 465,
};
const struct IrCode code_na006Code PROGMEM = {
	freq_to_timerval(38462),
	68,		// # of pairs
	3,		// # of bits per index
	code_na006Times,  
	{
		0x64,
		0x90,
		0x00,
		0x04,
		0x90,
		0x00,
		0x00,
		0x80,
		0x00,
		0x04,
		0x12,
		0x49,
		0x2A,
		0x12,
		0x40,
		0x00,
		0x12,
		0x40,
		0x00,
		0x02,
		0x00,
		0x00,
		0x10,
		0x49,
		0x24,
		0x90,
	}
};
const uint16_t code_na007Times[] PROGMEM = {
	49, 49,
	49, 50,
	49, 410,
	49, 510,
	49, 12107,
};
const struct IrCode code_na007Code PROGMEM = {
	freq_to_timerval(39216),
	34,		// # of pairs
	3,		// # of bits per index
	code_na007Times,  
	{
		0x09,
		0x94,
		0x53,
		0x29,
		0x94,
		0xD9,
		0x85,
		0x32,
		0x8A,
		0x65,
		0x32,
		0x9B,
		0x20,
	}
};
const uint16_t code_na008Times[] PROGMEM = {
	56, 58,
	56, 170,
	56, 4011,
	898, 450,
	900, 449,
};
const struct IrCode code_na008Code PROGMEM = {
	freq_to_timerval(38462),
	68,		// # of pairs
	3,		// # of bits per index
	code_na008Times,  
	{
		0x64,
		0x00,
		0x49,
		0x00,
		0x92,
		0x00,
		0x20,
		0x82,
		0x01,
		0x04,
		0x10,
		0x48,
		0x2A,
		0x10,
		0x01,
		0x24,
		0x02,
		0x48,
		0x00,
		0x82,
		0x08,
		0x04,
		0x10,
		0x41,
		0x20,
		0x90,
	}
};
const uint16_t code_na009Times[] PROGMEM = {
	53, 56,
	53, 171,
	53, 3950,
	53, 9599,
	898, 451,
	900, 226,
};
const struct IrCode code_na009Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,  
	{
		0x84,
		0x90,
		0x00,
		0x20,
		0x80,
		0x08,
		0x00,
		0x00,
		0x09,
		0x24,
		0x92,
		0x40,
		0x0A,
		0xBA,
		0x40,
	}
};
const uint16_t code_na010Times[] PROGMEM = {
	51, 55,
	51, 158,
	51, 2286,
	841, 419,
};
const struct IrCode code_na010Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	2,		// # of bits per index
	code_na010Times,  
	{
		0xD4,
		0x00,
		0x15,
		0x10,
		0x25,
		0x00,
		0x05,
		0x44,
		0x09,
		0x40,
		0x01,
		0x51,
		0x01,
	}
};
const uint16_t code_na011Times[] PROGMEM = {
	55, 55,
	55, 172,
	55, 4039,
	55, 9348,
	56, 0,
	884, 442,
	885, 225,
};
const struct IrCode code_na011Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na011Times,  
	{
		0xA0,
		0x00,
		0x41,
		0x04,
		0x92,
		0x08,
		0x24,
		0x90,
		0x40,
		0x00,
		0x02,
		0x09,
		0x2B,
		0x3D,
		0x00,
	}
};
const uint16_t code_na012Times[] PROGMEM = {
	81, 87,
	81, 254,
	81, 3280,
	331, 336,
	331, 337,
};
const struct IrCode code_na012Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	3,		// # of bits per index
	code_na012Times,  
	{
		0x64,
		0x12,
		0x08,
		0x24,
		0x00,
		0x08,
		0x20,
		0x10,
		0x09,
		0x2A,
		0x10,
		0x48,
		0x20,
		0x90,
		0x00,
		0x20,
		0x80,
		0x40,
		0x24,
		0x90,
	}
};
const uint16_t code_na013Times[] PROGMEM = {
	53, 55,
	53, 167,
	53, 2304,
	53, 9369,
	893, 448,
	895, 447,
};
const struct IrCode code_na013Code PROGMEM = {
	freq_to_timerval(38462),
	48,		// # of pairs
	3,		// # of bits per index
	code_na013Times,  
	{
		0x80,
		0x12,
		0x40,
		0x04,
		0x00,
		0x09,
		0x00,
		0x12,
		0x41,
		0x24,
		0x82,
		0x01,
		0x00,
		0x10,
		0x48,
		0x24,
		0xAA,
		0xE8,
	}
};

/* Duplicate timing table, same as na004 !
const uint16_t code_na014Times[] PROGMEM = {
	55, 57,
	55, 170,
	55, 3949,
	55, 9623,
	56, 0,
	898, 453,
	900, 226,
};
*/
const struct IrCode code_na014Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,  
	{
		0xA0,
		0x00,
		0x09,
		0x04,
		0x92,
		0x40,
		0x24,
		0x80,
		0x00,
		0x00,
		0x12,
		0x49,
		0x2B,
		0x3D,
		0x00,
	}
};

/* Duplicate timing table, same as na004 !
const uint16_t code_na015Times[] PROGMEM = {
	55, 57,
	55, 170,
	55, 3949,
	55, 9623,
	56, 0,
	898, 453,
	900, 226,
};
*/
const struct IrCode code_na015Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,  
	{
		0xA0,
		0x80,
		0x01,
		0x04,
		0x12,
		0x48,
		0x24,
		0x00,
		0x00,
		0x00,
		0x92,
		0x49,
		0x2B,
		0x3D,
		0x00,
	}
};
const uint16_t code_na016Times[] PROGMEM = {
	28, 90,
	28, 211,
	28, 2507,
};
const struct IrCode code_na016Code PROGMEM = {
	freq_to_timerval(34483),
	34,		// # of pairs
	2,		// # of bits per index
	code_na016Times,  
	{
		0x54,
		0x04,
		0x10,
		0x00,
		0x95,
		0x01,
		0x04,
		0x00,
		0x10,
	}
};
const uint16_t code_na017Times[] PROGMEM = {
	56, 57,
	56, 175,
	56, 4150,
	56, 9499,
	898, 227,
	898, 449,
};
const struct IrCode code_na017Code PROGMEM = {
	freq_to_timerval(40000),
	38,		// # of pairs
	3,		// # of bits per index
	code_na017Times,  
	{
		0xA0,
		0x02,
		0x48,
		0x04,
		0x90,
		0x01,
		0x20,
		0x80,
		0x40,
		0x04,
		0x12,
		0x09,
		0x2A,
		0x38,
		0x00,
	}
};
const uint16_t code_na018Times[] PROGMEM = {
	51, 55,
	51, 161,
	51, 2566,
	849, 429,
	849, 430,
};
const struct IrCode code_na018Code PROGMEM = {
	freq_to_timerval(38462),
	136,		// # of pairs
	3,		// # of bits per index
	code_na018Times,  
	{
		0x60,
		0x82,
		0x08,
		0x24,
		0x10,
		0x41,
		0x00,
		0x12,
		0x40,
		0x04,
		0x80,
		0x09,
		0x2A,
		0x02,
		0x08,
		0x20,
		0x90,
		0x41,
		0x04,
		0x00,
		0x49,
		0x00,
		0x12,
		0x00,
		0x24,
		0xA8,
		0x08,
		0x20,
		0x82,
		0x41,
		0x04,
		0x10,
		0x01,
		0x24,
		0x00,
		0x48,
		0x00,
		0x92,
		0xA0,
		0x20,
		0x82,
		0x09,
		0x04,
		0x10,
		0x40,
		0x04,
		0x90,
		0x01,
		0x20,
		0x02,
		0x48,
	}
};
const uint16_t code_na019Times[] PROGMEM = {
	40, 42,
	40, 124,
	40, 4601,
	325, 163,
	326, 163,
};
const struct IrCode code_na019Code PROGMEM = {
	freq_to_timerval(38462),
	100,		// # of pairs
	3,		// # of bits per index
	code_na019Times,  
	{
		0x60,
		0x10,
		0x40,
		0x04,
		0x80,
		0x09,
		0x00,
		0x00,
		0x00,
		0x00,
		0x10,
		0x00,
		0x20,
		0x10,
		0x00,
		0x20,
		0x80,
		0x00,
		0x0A,
		0x00,
		0x41,
		0x00,
		0x12,
		0x00,
		0x24,
		0x00,
		0x00,
		0x00,
		0x00,
		0x40,
		0x00,
		0x80,
		0x40,
		0x00,
		0x82,
		0x00,
		0x00,
		0x00,
	}
};
const uint16_t code_na020Times[] PROGMEM = {
	60, 55,
	60, 163,
	60, 4099,
	60, 9698,
	61, 0,
	898, 461,
	900, 230,
};
const struct IrCode code_na020Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na020Times,  
	{
		0xA0,
		0x10,
		0x00,
		0x04,
		0x82,
		0x49,
		0x20,
		0x02,
		0x00,
		0x04,
		0x90,
		0x49,
		0x2B,
		0x3D,
		0x00,
	}
};
const uint16_t code_na021Times[] PROGMEM = {
	48, 52,
	48, 160,
	48, 400,
	48, 2335,
	799, 400,
};
const struct IrCode code_na021Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na021Times,  
	{
		0x80,
		0x10,
		0x40,
		0x08,
		0x82,
		0x08,
		0x01,
		0xC0,
		0x08,
		0x20,
		0x04,
		0x41,
		0x04,
		0x00,
		0x00,
	}
};
const uint16_t code_na022Times[] PROGMEM = {
	53, 60,
	53, 175,
	53, 4463,
	53, 9453,
	892, 450,
	895, 225,
};
const struct IrCode code_na022Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na022Times,  
	{
		0x80,
		0x02,
		0x40,
		0x00,
		0x02,
		0x40,
		0x00,
		0x00,
		0x01,
		0x24,
		0x92,
		0x48,
		0x0A,
		0xBA,
		0x00,
	}
};
const uint16_t code_na023Times[] PROGMEM = {
	48, 52,
	48, 409,
	48, 504,
	48, 10461,
};
const struct IrCode code_na023Code PROGMEM = {
	freq_to_timerval(40000),
	44,		// # of pairs
	2,		// # of bits per index
	code_na023Times,  
	{
		0xA1,
		0x18,
		0x61,
		0xA1,
		0x18,
		0x7A,
		0x11,
		0x86,
		0x1A,
		0x11,
		0x86,
	}
};
const uint16_t code_na024Times[] PROGMEM = {
	58, 60,
	58, 2569,
	118, 60,
	237, 60,
	238, 60,
};
const struct IrCode code_na024Code PROGMEM = {
	freq_to_timerval(38462),
	26,		// # of pairs
	3,		// # of bits per index
	code_na024Times,  
	{
		0x69,
		0x24,
		0x10,
		0x40,
		0x03,
		0x12,
		0x48,
		0x20,
		0x80,
		0x00,
	}
};
const uint16_t code_na025Times[] PROGMEM = {
	84, 90,
	84, 264,
	84, 3470,
	346, 350,
	347, 350,
};
const struct IrCode code_na025Code PROGMEM = {
	freq_to_timerval(38462),
	52,		// # of pairs
	3,		// # of bits per index
	code_na025Times,  
	{
		0x64,
		0x92,
		0x49,
		0x00,
		0x00,
		0x00,
		0x00,
		0x02,
		0x49,
		0x2A,
		0x12,
		0x49,
		0x24,
		0x00,
		0x00,
		0x00,
		0x00,
		0x09,
		0x24,
		0x90,
	}
};
const uint16_t code_na026Times[] PROGMEM = {
	49, 49,
	49, 50,
	49, 410,
	49, 510,
	49, 12582,
};
const struct IrCode code_na026Code PROGMEM = {
	freq_to_timerval(39216),
	34,		// # of pairs
	3,		// # of bits per index
	code_na026Times,  
	{
		0x09,
		0x94,
		0x53,
		0x65,
		0x32,
		0x99,
		0x85,
		0x32,
		0x8A,
		0x6C,
		0xA6,
		0x53,
		0x20,
	}
};

/* Duplicate timing table, same as na001 !
const uint16_t code_na027Times[] PROGMEM = {
	50, 100,
	50, 200,
	50, 800,
	400, 400,
};
*/
const struct IrCode code_na027Code PROGMEM = {
	freq_to_timerval(57143),
	52,		// # of pairs
	2,		// # of bits per index
	code_na001Times,  
	{
		0xC5,
		0x41,
		0x11,
		0x10,
		0x14,
		0x44,
		0x6C,
		0x54,
		0x11,
		0x11,
		0x01,
		0x44,
		0x44,
	}
};
const uint16_t code_na028Times[] PROGMEM = {
	118, 121,
	118, 271,
	118, 4750,
	258, 271,
};
const struct IrCode code_na028Code PROGMEM = {
	freq_to_timerval(38610),
	36,		// # of pairs
	2,		// # of bits per index
	code_na028Times,  
	{
		0xC4,
		0x45,
		0x14,
		0x04,
		0x6C,
		0x44,
		0x51,
		0x40,
		0x44,
	}
};
const uint16_t code_na029Times[] PROGMEM = {
	88, 90,
	88, 91,
	88, 181,
	177, 91,
	177, 8976,
};
const struct IrCode code_na029Code PROGMEM = {
	freq_to_timerval(35842),
	22,		// # of pairs
	3,		// # of bits per index
	code_na029Times,  
	{
		0x0C,
		0x92,
		0x53,
		0x46,
		0x16,
		0x49,
		0x29,
		0xA2,
		0xC0,
	}
};

/* Duplicate timing table, same as na009 !
const uint16_t code_na030Times[] PROGMEM = {
	53, 56,
	53, 171,
	53, 3950,
	53, 9599,
	898, 451,
	900, 226,
};
*/
const struct IrCode code_na030Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,  
	{
		0x80,
		0x00,
		0x41,
		0x04,
		0x12,
		0x08,
		0x20,
		0x00,
		0x00,
		0x04,
		0x92,
		0x49,
		0x2A,
		0xBA,
		0x00,
	}
};
const uint16_t code_na031Times[] PROGMEM = {
	88, 89,
	88, 90,
	88, 179,
	88, 8977,
	177, 90,
};
const struct IrCode code_na031Code PROGMEM = {
	freq_to_timerval(35842),
	24,		// # of pairs
	3,		// # of bits per index
	code_na031Times,  
	{
		0x06,
		0x12,
		0x49,
		0x46,
		0x32,
		0x61,
		0x24,
		0x94,
		0x60,
	}
};

/* Duplicate timing table, same as na009 !
const uint16_t code_na032Times[] PROGMEM = {
	53, 56,
	53, 171,
	53, 3950,
	53, 9599,
	898, 451,
	900, 226,
};
*/
const struct IrCode code_na032Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na009Times,  
	{
		0x80,
		0x00,
		0x41,
		0x04,
		0x12,
		0x08,
		0x20,
		0x80,
		0x00,
		0x04,
		0x12,
		0x49,
		0x2A,
		0xBA,
		0x00,
	}
};
const uint16_t code_na033Times[] PROGMEM = {
	40, 43,
	40, 122,
	40, 5297,
	334, 156,
	336, 155,
};
const struct IrCode code_na033Code PROGMEM = {
	freq_to_timerval(38462),
	100,		// # of pairs
	3,		// # of bits per index
	code_na033Times,  
	{
		0x60,
		0x10,
		0x40,
		0x04,
		0x80,
		0x09,
		0x00,
		0x00,
		0x00,
		0x00,
		0x10,
		0x00,
		0x20,
		0x82,
		0x00,
		0x20,
		0x00,
		0x00,
		0x0A,
		0x00,
		0x41,
		0x00,
		0x12,
		0x00,
		0x24,
		0x00,
		0x00,
		0x00,
		0x00,
		0x40,
		0x00,
		0x82,
		0x08,
		0x00,
		0x80,
		0x00,
		0x00,
		0x00,
	}
};

/* Duplicate timing table, same as na004 !
const uint16_t code_na034Times[] PROGMEM = {
	55, 57,
	55, 170,
	55, 3949,
	55, 9623,
	56, 0,
	898, 453,
	900, 226,
};
*/
const struct IrCode code_na034Code PROGMEM = {
	freq_to_timerval(38462),
	38,		// # of pairs
	3,		// # of bits per index
	code_na004Times,  
	{
		0xA0,
		0x00,
		0x41,
		0x04,
		0x92,
		0x08,
		0x24,
		0x92,
		0x48,
		0x00,
		0x00,
		0x01,
		0x2B,
		0x3D,
		0x00,
	}
};
const uint16_t code_na035Times[] PROGMEM = {
	96, 93,
	97, 93,
	97, 287,
	97, 3431,
};
const struct IrCode code_na035Code PROGMEM = {
	freq_to_timerval(41667),
	22,		// # of pairs
	2,		// # of bits per index
	code_na035Times,  
	{
		0x16,
		0x66,
		0x5D,
		0x59,
		0x99,
		0x50,
	}
};
const uint16_t code_na036Times[] PROGMEM = {
	82, 581,
	84, 250,
	84, 580,
	85, 0,
};
const struct IrCode code_na036Code PROGMEM = {
	freq_to_timerval(37037),
	11,		// # of pairs
	2,		// # of bits per index
	code_na036Times,  
	{
		0x15,
		0x9A,
		0x9C,
	}
};
const uint16_t code_na037Times[] PROGMEM = {
	39, 263,
	164, 163,
	514, 164,
};
const struct IrCode code_na037Code PROGMEM = {
	freq_to_timerval(41667),
	11,		// # of pairs
	2,		// # of bits per index
	code_na037Times,  
	{
		0x80,
		0x45,
		0x00,
	}
};

/* Duplicate timing table, same as na017 !
const uint16_t code_na038Times[] PROGMEM = {
	56, 57,
	56, 175,
	56, 4150,
	56, 9499,
	898, 227,
	898, 449,
};
*/
const struct IrCode code_na038Code PROGMEM = {
	freq_to_timerval(40000),
	38,		// # of pairs
	3,		// # of bits per index
	code_na017Times,  
	{
		0xA4,
		0x10,
		0x40,
		0x00,
		0x82,
		0x09,
		0x20,
		0x80,
		0x40,
		0x04,
		0x12,
		0x09,
		0x2A,
		0x38,
		0x40,
	}
};
const uint16_t code_na039Times[] PROGMEM = {
	113, 101,
	688, 2707,
};
const struct IrCode code_na039Code PROGMEM = {
	freq_to_timerval(40000),
	4,		// # of pairs
	2,		// # of bits per index
	code_na039Times,  
	{
		0x11,
	}
};
const uint16_t code_na040Times[] PROGMEM = {
	113, 101,
	113, 201,
	113, 2707,
};
const struct IrCode code_na040Code PROGMEM = {
	freq_to_timerval(40000),
	8,		// # of pairs
	2,		// # of bits per index
	code_na040Times,  
	{
		0x06,
		0x04,
	}
};
const uint16_t code_na041Times[] PROGMEM = {
	58, 62,
	58, 2746,
	117, 62,
	242, 62,
};
const struct IrCode code_na041Code PROGMEM = {
	freq_to_timerval(76923),
	26,		// # of pairs
	2,		// # of bits per index
	code_na041Times,  
	{
		0xE2,
		0x20,
		0x80,
		0x78,
		0x88,
		0x20,
		0x00,
	}
};
const uint16_t code_na042Times[] PROGMEM = {
	54, 65,
	54, 170,
	54, 4099,
	54, 8668,
	899, 226,
	899, 421,
};
const struct IrCode code_na042Code PROGMEM = {
	freq_to_timerval(40000),
	38,		// # of pairs
	3,		// # of bits per index
	code_na042Times,  
	{
		0xA4,
		0x80,
		0x00,
		0x20,
		0x82,
		0x49,
		0x00,
		0x02,
		0x00,
		0x04,
		0x90,
		0x49,
		0x2A,
		0x38,
		0x40,
	}
};
const uint16_t code_na043Times[] PROGMEM = {
	43, 120,
	43, 121,
	43, 3491,
	131, 45,
};
const struct IrCode code_na043Code PROGMEM = {
	freq_to_timerval(40000),
	24,		// # of pairs
	2,		// # of bits per index
	code_na043Times,  
	{
		0x15,
		0x75,
		0x56,
		0x55,
		0x75,
		0x54,
	}
};
const uint16_t code_na044Times[] PROGMEM = {
	51, 51,
	51, 160,
	51, 4096,
	51, 9513,
	431, 436,
	883, 219,
};
const struct IrCode code_na044Code PROGMEM = {
	freq_to_timerval(40000),
	38,		// # of pairs
	3,		// # of bits per index
	code_na044Times,  
	{
		0x84,
		0x90,
		0x00,
		0x00,
		0x02,
		0x49,
		0x20,
		0x80,
		0x00,
		0x04,
		0x12,
		0x49,
		0x2A,
		0xBA,
		0x40,
	}
};
const uint16_t code_na045Times[] PROGMEM = {
	58, 53,
	58, 167,
	58, 4494,
	58, 9679,
	455, 449,
	456, 449,
};
const struct IrCode code_na045Code PROGMEM = {
	freq_to_timerval(38462),
	40,		// # of pairs
	3,		// # of bits per index
	code_na045Times,  
	{
		0x80,
		0x90,
		0x00,
		0x00,
		0x90,
		0x00,
		0x04,
		0x92,
		0x00,
		0x00,
		0x00,
		0x49,
		0x2A,
		0x97,
		0x48,
	}
};
const uint16_t code_na046Times[] PROGMEM = {
	51, 277,
	52, 53,
	52, 105,
	52, 277,
	52, 2527,
	52, 12809,
	103, 54,
};
const struct IrCode code_na046Code PROGMEM = {
	freq_to_timerval(29412),
	23,		// # of pairs
	3,		// # of bits per index
	code_na046Times,  
	{
		0x0B,
		0x12,
		0x63,
		0x44,
		0x92,
		0x6B,
		0x44,
		0x92,
		0x50,
	}
};



////////////////////////////////////////////////////////////////


const struct IrCode *NApowerCodes[] PROGMEM = {
	&code_na000Code,
	&code_na001Code,
   	&code_na002Code,
	&code_na003Code,
	&code_na004Code,
	&code_na005Code,
	&code_na006Code,
	&code_na007Code,
	&code_na008Code,
	&code_na009Code,
	&code_na010Code,
	&code_na011Code,
	&code_na012Code,
	&code_na013Code,
	&code_na014Code,
	&code_na015Code,
	&code_na016Code,
	&code_na017Code,
	&code_na018Code,
	&code_na019Code,
	&code_na020Code,
	&code_na021Code,
	&code_na022Code,
	&code_na023Code,
	&code_na024Code,
	&code_na025Code,
	&code_na026Code,
	&code_na027Code,
	&code_na028Code,
	&code_na029Code,
	&code_na030Code,
	&code_na031Code,
	&code_na032Code,
	&code_na033Code,
	&code_na034Code,
	&code_na035Code,
	&code_na036Code,
	&code_na037Code,
	&code_na038Code,
	&code_na039Code,
	&code_na040Code,
	&code_na041Code,
	&code_na042Code,
	&code_na043Code,
	&code_na044Code,
	&code_na045Code,
	&code_na046Code,
};

const struct IrCode *EUpowerCodes[] PROGMEM = {};

const uint8_t num_NAcodes = NUM_ELEM(NApowerCodes);
