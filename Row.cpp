#include "Arduino.h"
#include "Row.h"
#include <Adafruit_NeoPixel.h>

Row::Row(int rowOffset, bool reverse, Adafruit_NeoPixel pixels)
{
	_pixelPosition = false;
	_rowOffset = rowOffset;
	setIncrementor(reverse);
  _pixels = pixels;
}

bool Row::checkTime()
{
	_currentTime = millis();
	if(_currentTime >= (_prevTime + _delay)){
		setNewDelay();
		return true;
	}
	return false;
}

void Row::setNewDelay()
{
	_delay = random(0, 2000);
}

void Row::movePixels()
{
	turnPixelOn(_rowOffset);
}

void Row::turnPixelOn(int pixelNum)
{
  _pixels.setPixelColor(pixelNum - _incrementor, _pixels.Color(0,0,0));//hide the last one
  _pixels.setPixelColor(pixelNum, _pixels.Color(75,75,75));//show the current one
}

void Row::updatePixelPostion()
{
	if(_pixelPosition == false){
		_pixelPosition = 0;
	}else if(_pixelPosition >= _rowOffset){
		_pixelPosition = false;
	}else{
		_pixelPosition++;
	}
	
}

void Row::setIncrementor(bool reverse)
{
	int _incrementor = 1;
  if(reverse == true){
    _incrementor = -1;
  }
}
