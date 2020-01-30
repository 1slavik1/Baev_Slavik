#include "pch.h"
#include "Blinki.h"
#include <Windows.h>
Blinki::Blinki()
{
    Ghost::color = RED;
    Ghost::name = NAME;
}

Blinki::~Blinki()
{

}

void Blinki::Logic(int xPac, int yPac)
{
    //Ghost::Logic(xPac, yPac);

    switch (getMode())
    {
    case Ghost::SCATTER:
        Ghost::chase(X, Y); // SCATTER
        break;
    case Ghost::CHASE:
        Ghost::chase(xPac, yPac);
        break;
    case Ghost::FRIGHTENED:
        //chase(Ghost::getXRandom(), Ghost::getYRandom()); // FRIGHTENED
        break;
    default:
        break;
    }
}

