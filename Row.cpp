#include "Arduino.h"
#include "Row.h"
#include "Pixel.h"
#include <Adafruit_NeoPixel.h>

Row::Row(int rowOffset, bool reverse, Adafruit_NeoPixel& pixels)
{
	_rowOffset = rowOffset;
	_reverse = reverse;
  _pixels = pixels;
  Pixel *pixel = new Pixel(_rowOffset);
  _pixelList = new LinkedList<Pixel*>;
  _pixelList->add(pixel);
  _onColor = _pixels.Color(25,25,25);
  _offColor = _pixels.Color(0,0,0);
  _brightColor = _pixels.Color(50,50,50);
  setIncrementor();
}

void Row::turnPixelOn(int pixelNum)
{
	if(_reverse){
		pixelNum = (_rowOffset) + (_rowOffset - pixelNum) - 1;
	}

  if(pixelNum == _rowOffset - 1 && _reverse){
   _pixels.setPixelColor(_rowOffset - ROWLENGTH, _offColor);
   Serial.print(pixelNum);//hide the last one
  }

  if(pixelNum == _rowOffset)
  {
    _pixels.setPixelColor(_rowOffset + ROWLENGTH - 1, _offColor);
  }
  // fix the incrementor so it wont be static.
  _pixels.setPixelColor(pixelNum - _incrementor, _offColor);//hide the last one
  _pixels.setPixelColor(pixelNum, _onColor);//show the current one
  _pixels.show();
}

void Row::setIncrementor()
{
  if(_reverse){
    _incrementor = -1;
  }else{
    _incrementor = 1;
  }
}

void Row::createPixel()
{

  Pixel *newPixel = new Pixel(_rowOffset);
  _pixelList->add(newPixel);
}

// make void for final version. Int just for debugging.
int Row::handlePixel()
{
 int size = _pixelList->size();
 for(int i = 0; i < size - 1; i++){
  if(_pixelList->get(i)->checkTime()){
    turnPixelOn(_pixelList->get(i)->position);
  }
 }
 return 1;
}
