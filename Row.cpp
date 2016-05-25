#include "Arduino.h"
#include "Row.h"
#include "Pixel.h"
#include <Adafruit_NeoPixel.h>

Row::Row(int rowOffset, bool reverse, Adafruit_NeoPixel& pixels)
{
	_rowOffset = rowOffset;
	_reverse = reverse;
  _pixels = pixels;
  _firstPixel = new Pixel(_rowOffset);
  setIncrementor();
}

void Row::turnPixelOn(int pixelNum)
{
  Serial.print(pixelNum);
	if(_reverse){
		pixelNum = (_rowOffset) + (_rowOffset - pixelNum);
	}
  // make this call reusable
  if(pixelNum == _rowOffset){
   _pixels.setPixelColor(_rowOffset - ROWLENGTH, _pixels.Color(0,0,0));//hide the last one
  }
  // fix the incrementor so it wont be static.
  _pixels.setPixelColor(pixelNum - _incrementor, _pixels.Color(0,0,0));//hide the last one
  _pixels.setPixelColor(pixelNum, _pixels.Color(25,25,25));//show the current one
}

//This function is completely non functional.
void Row::setIncrementor()
{
  if(_reverse){
    _incrementor = -1;
  }else{
    _incrementor = 1;
  }
  Serial.print(_incrementor);
}
// make void for final version. Int just for debugging.
int Row::handlePixel()
{
	if(_firstPixel->checkTime()){
		turnPixelOn(_firstPixel->position);
	}
 return _firstPixel->position;
}
