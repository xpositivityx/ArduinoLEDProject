#ifndef Row_h
#define Row_h

#include "Arduino.h"

class Row
{
	public:
		Row();
		void checkTime();
		void setNewDelay();
	private:
		unsigned long _currentTime;
		unsigned long _prevTime;
		int _delay
		bool _pixelPositions[23];
}


#endif