#include "pio8255.h"
#include <Arduino.h>

PIO8255::PIO8255(int d0,int d1,int d2,int d3,int d4,int d5,int d6,int d7,int cs,int rd,int wr,int res,int a0,int a1)
{
  _d0 = d0;
  _d1 = d1;
  _d2 = d2;
  _d3 = d3;
  _d4 = d4;
  _d5 = d5;
  _d6 = d6;
  _d7 = d7;
  _cs = cs;
  _rd = rd;
  _wr = wr;
  _res = res;
  _a0 = a0;
  _a1 = a1;
  out_data[0] = _d0;
  out_data[1] = _d1;
  out_data[2] = _d2;
  out_data[3] = _d3;
  out_data[4] = _d4;
  out_data[5] = _d5;
  out_data[6] = _d6;
  out_data[7] = _d7;
  porta, portb, portc = B0000000;
  
  pinMode(_a0, OUTPUT);   
  pinMode(_a1, OUTPUT);     
  pinMode(_res, OUTPUT);    
  pinMode(_d0, OUTPUT);     
  pinMode(_d1, OUTPUT);     
  pinMode(_d2, OUTPUT);     
  pinMode(_d3, OUTPUT);     
  pinMode(_d4, OUTPUT);     
  pinMode(_d5, OUTPUT);     
  pinMode(_d6, OUTPUT);     
  pinMode(_d7, OUTPUT);     
  pinMode(_cs, OUTPUT);     
  pinMode(_rd, OUTPUT);
  pinMode(_wr, OUTPUT);
}


void PIO8255::init(){
 //Start 8255 init sequence
  digitalWrite(_res, HIGH);
  digitalWrite(_res, LOW);
  digitalWrite(_wr, HIGH);

  digitalWrite(_d0, LOW);
  digitalWrite(_d1, LOW);
  digitalWrite(_d2, LOW);
  digitalWrite(_d3, LOW);
  digitalWrite(_d4, LOW);
  digitalWrite(_d5, LOW);
  digitalWrite(_d6, LOW);
  digitalWrite(_d7, HIGH);

  digitalWrite(_a0, HIGH);
  digitalWrite(_a1, HIGH);
  digitalWrite(_wr, LOW);
  digitalWrite(_wr, HIGH);
  digitalWrite(_rd, HIGH);
}

void PIO8255::set_port(char port, byte data){
   // With the char A / B / C set according ports on 8255
   // Track change to support bit switching with porta, portb, portc.
  if('A'==port){
    digitalWrite(_a0, LOW);
    digitalWrite(_a1, LOW);
    porta=data;
   }else if('B'==port){
    digitalWrite(_a0, HIGH);
    digitalWrite(_a1, LOW);
     portb=data;
   }else if('C'==port){
    digitalWrite(_a0, LOW);
    digitalWrite(_a1, HIGH);
     portc=data;
   }
   digitalWrite(_cs, LOW);
   digitalWrite(_wr, LOW);
   int i=0;
   for (byte mask = B00000001; mask>0; mask <<= 1) { 
     if (data & mask){
     digitalWrite(out_data[i],HIGH);
    }else{
     digitalWrite(out_data[i],LOW);
    }
    i++;
   }
   digitalWrite(_wr, HIGH);
   digitalWrite(_cs, HIGH);
   digitalWrite(_a0, LOW);
   digitalWrite(_a1, LOW);
}

//port = 8255 A / B / C, pin -> 0(lsb) to 7(msb) ,highlow=true|false
//6,212 KHz setPort 6,059 KHz setPin (Writing 1 and 0 means x2)
void PIO8255::set_pin(char port,int pin, boolean highlow){
  byte data;
  if('A'==port){
     data=(highlow)?porta | B00000001<<pin : porta & B11111110<<pin;
   }else if('B'==port){
     data=(highlow)?portb | B00000001<<pin : portb & B11111110<<pin;
   }else if('C'==port){
     data=(highlow)?portc | B00000001<<pin : portc & B11111110<<pin;
   }
  
  set_port(port,data);
}
