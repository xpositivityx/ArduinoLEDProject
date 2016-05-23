#include "Arduino.h"
#include "Row.h"
#include <Adafruit_NeoPixel.h>

Row::Row(int rowOffset, bool reverse, Adafruit_NeoPixel& pixels)
{
	_pixelPosition = rowOffset;
	_rowOffset = rowOffset;
	_reverse = reverse;
  _pixels = pixels;
  setNewDelay();
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
	_delay = random(0, 1500);
	_prevTime = millis();
}

void Row::movePixels()
{
	updatePixelPosition();
	turnPixelOn(_pixelPosition);
}

void Row::turnPixelOn(int pixelNum)
{
	if(_reverse){
		pixelNum = (_rowOffset) + (_rowOffset - pixelNum);
	}
  // make this call reusable
  if(_pixelPosition == _rowOffset){
   _pixels.setPixelColor(_rowOffset - ROWLENGTH, _pixels.Color(0,0,0));//hide the last one
  }
  // fix the incrementor so it wont be static.
  _pixels.setPixelColor(pixelNum - -1, _pixels.Color(0,0,0));//hide the last one
  _pixels.setPixelColor(pixelNum, _pixels.Color(75,75,75));//show the current one
}

void Row::updatePixelPosition()
{
	if(_pixelPosition >= (_rowOffset + ROWLENGTH) || _pixelPosition <= (_rowOffset - ROWLENGTH)){
		_pixelPosition = _rowOffset;
	}else{
		_pixelPosition++;
	}
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
	if(checkTime() == true){
		movePixels();
	}
 return _pixelPosition;
}
