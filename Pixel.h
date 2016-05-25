#ifndef Pixel_h
#define Pixel_h

class Pixel{
	public:
    Pixel(int);
    bool checkTime();
    int position;
	private:	
    void setNewDelay();
    void updatePixelPosition();
    unsigned long _currentTime;
    unsigned long _prevTime;
    int _delay;
    int _rowOffset;
};


#endif
