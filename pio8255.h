#ifndef PIO8255_H
#define PIO8255_H

#include <Arduino.h>

class PIO8255
{
  public:
    PIO8255(int d0 = 2,int d1 = 3,int d2 = 4,int d3 = 5,int d4 = 6,int d5 = 7,int d6 = 8,int d7 = 9,int cs = 10,int rd = 16,int wr = 14,int res = A2,int a0 = A0,int a1 = A1);
    void init();
    void set_port(char port, byte data);
    void set_pin(char port, int pin, boolean highlow);

  private:
    int _d0,_d1,_d2,_d3,_d4,_d5,_d6,_d7,_cs,_rd,_wr,_res,_a0,_a1;
    int out_data[8];
    byte porta,portb,portc;
};




#endif
