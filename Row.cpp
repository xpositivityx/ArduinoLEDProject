#include "Arduino.h"
#include "Row.h"

Row::Row()
{
	_pixelPositions[23] = {false}
}

bool Row::checkTime()
{
	_currentTime = millis();
	if(_currentTime >= (_prevTime + _delay)){
		setNewDelay();
		return true
	}
	return false
}

void Row::setNewDelay()
{
	_delay = random(0, 2000);
}