# MPLAB IDE generated this makefile for use with GNU make.
# Project: TV-B-Gone.mcp
# Date: Wed Jul 21 08:05:43 2010

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

TV-B-Gone.hex : TV-B-Gone.cof
	$(HX) "TV-B-Gone.cof"

TV-B-Gone.cof : main.o WORLDcodes.o
	$(CC) -mcpu=24F08KA101 "main.o" "WORLDcodes.o" -o"TV-B-Gone.cof" -Wl,-L"C:\Program Files\Microchip\MPLAB C30\lib",-Tp24F08KA101.gld,--defsym=__MPLAB_BUILD=1,-Map="TV-B-Gone.map",--report-mem

main.o : ../../../../../../program\ files/microchip/mplab\ c30/support/PIC24F/h/p24F08KA101.h ../../../../../../program\ files/microchip/mplab\ c30/support/PIC24F/h/P24Fxxxx.h main.h main.c
	$(CC) -mcpu=24F08KA101 -x c -c "main.c" -o"main.o" -g -Wall -Os

WORLDcodes.o : main.h WORLDcodes.c
	$(CC) -mcpu=24F08KA101 -x c -c "WORLDcodes.c" -o"WORLDcodes.o" -g -Wall -Os

clean : 
	$(RM) "main.o" "WORLDcodes.o" "TV-B-Gone.cof" "TV-B-Gone.hex"

