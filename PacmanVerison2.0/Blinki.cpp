#include "pch.h"
#include "Blinki.h"
#include <Windows.h>
Blinki::Blinki()
{
    //ctor
    //freedom = false;
}

Blinki::~Blinki()
{
    //dtor
}

void Blinki::Logic(int xPac, int yPac)
{
    Ghost::Logic(xPac, yPac, RED, NAME);
}

