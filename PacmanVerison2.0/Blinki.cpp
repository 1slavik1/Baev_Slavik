#include "pch.h"
#include "Blinki.h"
#include <Windows.h>
Blinki::Blinki()
{
    Ghost::color = RED;
    Ghost::name = NAME;
    Ghost:m_frightened = false;
}

Blinki::~Blinki()
{

}

void Blinki::Logic(int xPac, int yPac)
{
   
    switch (getMode())
    {
    case Ghost::SCATTER:
        Ghost::chase(X, Y); // SCATTER
        break;
    case Ghost::CHASE:
        Ghost::chase(xPac, yPac);
        break;
    case Ghost::FRIGHTENED:
        chase(Ghost::getXRandom(), Ghost::getYRandom()); // FRIGHTENED
        break;
    default:
        break;
    }
}

