#include "pch.h"
#include "Pinki.h"
#include "Windows.h"
#include "iostream"

Pinki::Pinki()
{
}


Pinki::~Pinki()
{
}

void Pinki::draw(int color)
{
    using namespace std;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | color));
	cout << "P";
}

void Pinki::logic(int xPac, int yPac)
{
    switch (getMode())
    {
    case Ghost::SCATTER:
        chase(X, Y); // SCATTER
        break;
    case Ghost::CHASE:
        chase(xPac, yPac);
        break;
    case Ghost::FRIGHTENED:
        chase(Ghost::getXRandom(), Ghost::getYRandom()); // FRIGHTENED
        break;
    default:
        break;
    }
 }