#ifndef PIO8255_H
#define PIO8255_H

#include <Arduino.h>

class PIO8255
{
  public:
    PIO8255(
		int d0 = 2,
		int d1 = 3,
		int d2 = 4,
		int d3 = 5,
		int d4 = 6,
		int d5 = 7,
		int d6 = 8,
		int d7 = 9,
		int cs = 10,
		int rd = 16,
		int wr = 14,
		int res = A2,
		int a0 = A0,
		int a1 = A1
		);
    void init();
    void set_port(char port, byte data);
    void set_pin(char port, int pin, boolean highlow);

  private:
    int _d0,_d1,_d2,_d3,_d4,_d5,_d6,_d7,_cs,_rd,_wr,_res,_a0,_a1;
    int out_data[8];
    byte porta,portb,portc;
};

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




#endif
