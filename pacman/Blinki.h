#ifndef Blinki_h
#define Blinki_h

#include "Ghost.h"
class Blinki : public Ghost
{
public:	
	Blinki();
	~Blinki();
	void draw(int color) override;
	void logic(int xPac, int yPac) override;    
private:
    const short X = 48;
    const short Y = 0;
};
#endif