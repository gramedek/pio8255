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
