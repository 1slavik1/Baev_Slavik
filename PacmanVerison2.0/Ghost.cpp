#include "Ghost.h"
#include <iostream>

Ghost::Ghost()
{
}


Ghost::~Ghost()
{
}

void Ghost::DrawPlayer(short color, char name, short x, short y)
{
    draw.DrawPlayer(color, name, x, y);
}

void Ghost::ClearPlayer(short x, short y)
{
    draw.Clear(x, y);
}

void Ghost::DrawScore(int &score)
{
    draw.SetDrawScore();
    std::cout << score << std::endl;
}
