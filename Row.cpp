#include "Arduino.h"
#include "Row.h"
#include <Adafruit_NeoPixel.h>

Row::Row(int rowOffset, bool reverse, Adafruit_NeoPixel pixels)
{
	_pixelPosition = false;
	_rowOffset = rowOffset;
	setIncrementor(reverse);
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
	_delay = random(0, 2000);
	_prevTime = millis();
}

void Row::movePixels()
{
	updatePixelPosition();
	turnPixelOn(_pixelPosition);
}

void Row::turnPixelOn(int pixelNum)
{
	if(_incrementor == -1){
		pixelNum = (_rowOffset + ROWLENGTH) + (_rowOffset - pixelNum);
	}
  _pixels.setPixelColor(pixelNum - _incrementor, _pixels.Color(0,0,0));//hide the last one
  _pixels.setPixelColor(pixelNum, _pixels.Color(75,75,75));//show the current one
}

void Row::updatePixelPosition()
{
	if(_pixelPosition == false){
		_pixelPosition = _rowOffset;
	}else if(_pixelPosition >= _rowOffset || _pixelPosition <= (_rowOffset - ROWLENGTH)){
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

int Row::handlePixel()
{

	if(checkTime() != true){
		return 0;
	}

	movePixels();
  return 1;
}
