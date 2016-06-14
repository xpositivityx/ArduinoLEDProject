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

  hideLastPixel();  
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

void Row::createPixelCondition(int size, int position)
{
  int halfWayUp = _rowOffset + (ROWLENGTH / 2) - 1;
  int halfWayDown = _rowOffset - (ROWLENGTH / 2) - 1;
  if((position == halfWayUp || position == halfWayDown) && size <= 3){
    int rand = random(100);
    if(rand > 80 && size == 1){
      createPixel();
    }
    if(rand > 90 && size == 2){
      createPixel();
    }
  }
}

void Row::removePixel(int pixelPos, int i, int size)
{
  int rowTerminationTop = _rowOffset + ROWLENGTH - 1;
  int rowTerminationBottom = _rowOffset - ROWLENGTH;
  if((pixelPos == rowTerminationTop || pixelPos == rowTerminationBottom)){
    hideLastPixel();
    Pixel *popped = _pixelList->remove(i);
    delete(popped);
  }
}

void Row::hideLastPixel()
{
  if(_reverse){
   _pixels.setPixelColor(_rowOffset - ROWLENGTH, _offColor);
   return;
  }

  _pixels.setPixelColor(_rowOffset + ROWLENGTH - 1, _offColor);
}

// make void for final version. Int just for debugging.
int Row::handlePixel()
{
 int size = _pixelList->size();

 for(int i = 0; i < size; i++){
  if(_pixelList->get(i)->checkTime()){
    int pixelPos = _pixelList->get(i)->position;
    createPixelCondition(size, pixelPos);
    turnPixelOn(pixelPos);
    removePixel(pixelPos, i, size);
  }
 }
 //remove after debugging
 return 1;
}
