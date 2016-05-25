#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
//Row class and related Constants
#include "Row.h"
//pin output
#define PIN            6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      115
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//setup rows
Row* row1 = new Row(ROWLENGTH, true, pixels);
Row* row2 = new Row(ROWLENGTH, false, pixels);
Row* row3 = new Row(ROWLENGTH * 3, true, pixels);
Row* row4 = new Row(ROWLENGTH * 3, false, pixels);
Row* row5 = new Row(ROWLENGTH * 5, true, pixels);

//int delayval = 100; // delay for half a second when testing on for loop.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  Serial.begin(9600);
  // End of trinket special code
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  
  //for(int i=0;i<ROWLENGTH;i++){
    
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    // changePixelOn((ROWLENGTH * 1) + (i * -1), true);
    // changePixelOn((ROWLENGTH * 1) + i, false);
    // changePixelOn((ROWLENGTH * 3) + (i * -1), true);
    // changePixelOn((ROWLENGTH * 3) + i, false);
    // changePixelOn((ROWLENGTH * 5) + (i * -1), true);
    //pixels.show(); // This sends the updated pixel color to the hardware.

    //delay(delayval); // Delay for a period of time (in milliseconds).

  //}
  row1->handlePixel();
  row2->handlePixel();
  row3->handlePixel();
  row4->handlePixel();
  row5->handlePixel();
  pixels.show();
}

