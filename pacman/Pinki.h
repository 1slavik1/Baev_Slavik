#ifndef Pinki_h
#define Pinki_h

#include "Ghost.h"
class Pinki : public Ghost
{
public:
	Pinki();
	~Pinki();
	void draw(int color) override;
	void logic(int xPac, int yPac) override;
private:
    const short X = 0;
    const short Y = 0;
};
#endif