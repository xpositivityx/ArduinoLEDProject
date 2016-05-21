#ifndef Row_h
#define Row_h
#define ROWLENGTH 23
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Row
{
	public:
		Row(int rowOffset, bool reverse, Adafruit_NeoPixel pixels);
		int handlePixel();
    bool checkTime();
    void setNewDelay();
    void movePixels();
    void turnPixelOn(int pixelNum);
    void setIncrementor(bool reverse);
    void updatePixelPosition();
	private:
		unsigned long _currentTime;
		unsigned long _prevTime;
		int _delay;
		int _pixelPosition;
		Adafruit_NeoPixel _pixels;
		bool _reverse;
		int _incrementor;
		int _rowOffset;

};


#endif
