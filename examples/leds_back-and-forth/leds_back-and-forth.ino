#include <pio8255.h>

PIO8255 mcont;

void setup() {
  mcont.init();
}

void loop(){ 
  //Walk the leds forward
  for (byte mask = B10000000; mask>0; mask >>= 1) {
    mcont.set_port('B', mask);
    delay(100);
  }
  //And walk back
  for (byte mask = B00000001; mask>0; mask <<= 1) {
    mcont.set_port('B', mask);
    delay(100);
  }
}

// PIO8255(int d0,int d1,int d2,int d3,int d4,int d5,int d6,int d7,int cs,int rd,int wr,int res,int a0,int a1)
/*
	     ┌──────┐ ┌──────┐
	PA3  │  1   └─┘   40 │  PA4
	PA2  │  2         39 │  PA5
	PA1  │  3         38 │  PA6
	PA0  │  4         37 │  PA7
	 RD  │  5         36 │  WR
	 CS  │  6         35 │  Reset
	GND  │  7         34 │  D0
	 A1  │  8         33 │  D1
	 A0  │  9         32 │  D2
	PC7  │ 10         31 │  D3
	PC6  │ 11         30 │  D4
	PC5  │ 12         29 │  D5
	PC4  │ 13         28 │  D6
	PC0  │ 14         27 │  D7
	PC1  │ 15         26 │  Vcc
	PC2  │ 16         25 │  PB7
	PC3  │ 17         24 │  PB6
	PB0  │ 18         23 │  PB5
	PB1  │ 19         22 │  PB4
	PB2  │ 20         21 │  PB3
	     └───────────────┘
*/
