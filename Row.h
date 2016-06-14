#ifndef Row_h
#define Row_h
#define ROWLENGTH 23
#include "Pixel.h"
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include <LinkedList.h>

class Row
{
	public:
		Row(int rowOffset, bool reverse, Adafruit_NeoPixel& pixels);
		int handlePixel();
	private:
		Adafruit_NeoPixel _pixels;
		int _incrementor;
		int _rowOffset;
		long _onColor;
		long _offColor;
		long _brightColor;
		bool _reverse;
    void turnPixelOn(int pixelNum);
    void setIncrementor();
    void createPixel();
    void createPixelCondition(int size, int position);
    void removePixel(int pixelPos, int index, int size);
    void hideLastPixel();
    LinkedList<Pixel*>* _pixelList;

};


#endif
