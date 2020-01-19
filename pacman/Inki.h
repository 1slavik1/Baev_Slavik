#ifndef Inki_h
#define Inki_h

#include "Ghost.h"
class Inki : public Ghost
{
public:
    Inki();
    ~Inki();
    void draw(int color) override;
    void logic(int xPac, int yPac) override;
private:
    const short X = 48;
    const short Y = 21;
};
#endif