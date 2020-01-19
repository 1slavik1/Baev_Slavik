#include "pch.h"
#include "Inki.h"
#include "Windows.h"
#include "iostream"

Inki::Inki()
{
}


Inki::~Inki()
{
}

void Inki::draw(int color)
{
    using namespace std;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | color));
    cout << "I";
}

void Inki::logic(int xPac, int yPac)
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