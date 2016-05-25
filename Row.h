#ifndef Row_h
#define Row_h
#define ROWLENGTH 23
#include "Pixel.h"
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Row
{
	public:
		Row(int rowOffset, bool reverse, Adafruit_NeoPixel& pixels);
		int handlePixel();
	private:
		Pixel* _firstPixel;
		Adafruit_NeoPixel _pixels;
		int _incrementor;
		int _rowOffset;
		bool _reverse;
    void turnPixelOn(int pixelNum);
    void setIncrementor();
    void createPixel();

};


#endif
