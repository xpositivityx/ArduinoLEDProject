#include "Arduino.h"
#include "Row.h"
#include "Pixel.h"
#include <Adafruit_NeoPixel.h>

Row::Row(int rowOffset, bool reverse, Adafruit_NeoPixel& pixels)
{
	_rowOffset = rowOffset;
	_reverse = reverse;
  _pixels = pixels;
}

void Row::movePixels(Pixel*& pixel)
{
	pixel->updatePixelPosition();
	turnPixelOn(pixel->position);
}

void Row::turnPixelOn(int pixelNum)
{
	if(_reverse){
		pixelNum = (_rowOffset) + (_rowOffset - pixelNum);
	}
  // make this call reusable
  if(pixelNum == _rowOffset){
   _pixels.setPixelColor(_rowOffset - ROWLENGTH, _pixels.Color(0,0,0));//hide the last one
  }
  // fix the incrementor so it wont be static.
  _pixels.setPixelColor(pixelNum - -1, _pixels.Color(0,0,0));//hide the last one
  _pixels.setPixelColor(pixelNum, _pixels.Color(75,75,75));//show the current one
}

//This function is completely non functional.
void Row::setIncrementor()
{
	int _incrementor = 1;
  if(_reverse == true){
    _incrementor = -1;
  }
}
// make void for final version. Int just for debugging.
int Row::handlePixel()
{
	if(_firstPixel->checkTime() == true){
		movePixels(_firstPixel);
	}
 return _firstPixel->position;
}

void Row::createPixel()
{
	Pixel* _firstPixel = new Pixel(_rowOffset);
}
