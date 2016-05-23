#ifndef Row_h
#define Row_h
#define ROWLENGTH 23
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Row
{
	public:
		Row(int rowOffset, bool reverse, Adafruit_NeoPixel& pixels);
		int handlePixel();
	private:
		unsigned long _currentTime;
		unsigned long _prevTime;
    unsigned long _secondPrevTime;
		int _delay;
    int _secondDelay;
		int _pixelPosition;
    int _secondPixelPosition;
		Adafruit_NeoPixel _pixels;
		bool _reverse;
		int _incrementor;
		int _rowOffset;
		bool checkTime();
    void setNewDelay();
    void movePixels();
    void turnPixelOn(int pixelNum);
    void setIncrementor();
    void updatePixelPosition();

};


#endif
