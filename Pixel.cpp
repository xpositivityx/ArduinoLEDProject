#include "Arduino.h"
#include "Pixel.h"
#include "Row.h"

Pixel::Pixel(int rowOffset){
	_rowOffset = rowOffset;
	setNewDelay();
}

bool Pixel::checkTime()
{
	_currentTime = millis();
	if(_currentTime >= (_prevTime + _delay)){
		setNewDelay();
		updatePixelPosition();
		return true;
	}
	return false;
}

void Pixel::setNewDelay()
{
	_delay = random(0, 1500);
	_prevTime = millis();
}

void Pixel::updatePixelPosition()
{
	if(position >= (_rowOffset + ROWLENGTH) || position <= (_rowOffset - ROWLENGTH)){
		position = _rowOffset;
	}else{
		position++;
	}
	Serial.print(position);
}

	


