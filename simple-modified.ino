// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
//Row class
#include "Row.h"
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      115
// Number of pixesl in each row
#define ROWLENGTH      23 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pixelColorOn = pixels.Color(75,75,75);

int pixelColorOff = pixels.Color(0,0,0);

int delayval = 100; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  Row *row1 = new Row();
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<ROWLENGTH;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    changePixelOn((ROWLENGTH * 1) + (i * -1), true);
    changePixelOn((ROWLENGTH * 1) + i, false);
    changePixelOn((ROWLENGTH * 3) + (i * -1), true);
    changePixelOn((ROWLENGTH * 3) + i, false);
    changePixelOn((ROWLENGTH * 5) + (i * -1), true);

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}
//takes boolean reverse 
int changePixelOn(int pixelNum, bool reverse) {
  int incrementor = 1;
  if(reverse == true){
    incrementor = -1;
  }
  pixels.setPixelColor(pixelNum - incrementor, pixelColorOff);//hide the last one
  pixels.setPixelColor(pixelNum, pixelColorOn);//show the current one
  return 1;
}


