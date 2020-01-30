#include "pch.h"
#include "Pac.h"
#include <Windows.h>
#include <iostream>
Pac::Pac()
{
    Ghost::color = YELLOW;
    Ghost::name = NAME;
}


Pac::~Pac()
{
}

int Pac::getScore() const { return score; }

void Pac::MoveRight()
{
    if (map.getMap(x + 1, y) == 0)
    {
        score++;
        Ghost::DrawScore(score);
        map.setMap(x + 1, y);
    }
    if (map.getMap(x + 1, y) == 1) dir = STOP;
    else x++;
    Ghost::DrawPlayer(x, y);
    if (map.getMap(x - 1, y) != 1) Ghost::ClearPlayer(x - 1, y);
    Sleep(150);
}

void Pac::MoveLeft()
{
    if (map.getMap(x - 1, y) == 0)
    {
        score++;
        Ghost::DrawScore(score);
        map.setMap(x - 1, y);
    }
    if (map.getMap(x - 1, y) == 1) dir = STOP;
    else x--;
    Ghost::DrawPlayer(x, y);
    if (map.getMap(x + 1, y) != 1) Ghost::ClearPlayer(x + 1, y);
    Sleep(150);
}

void Pac::MoveUp()
{
    if (map.getMap(x, y - 1) == 0)
    {
        score++;
        Ghost::DrawScore(score);
        map.setMap(x, y - 1);
    }
    if (map.getMap(x, y - 1) == 1) dir = STOP;
    else y--;
    Ghost::DrawPlayer(x, y);
    if (map.getMap(x, y + 1) != 1) Ghost::ClearPlayer(x, y + 1);
    Sleep(150);
}

void Pac::MoveDown()
{
    if (map.getMap(x, y + 1) == 0)
    {
        score++;
        Ghost::DrawScore(score);
        map.setMap(x, y + 1);
    }
    if (map.getMap(x, y + 1) == 1) dir = STOP;
    else y++;
    Ghost::DrawPlayer(x, y);
    if (map.getMap(x, y - 1) != 1) Ghost::ClearPlayer(x, y - 1);
    Sleep(150);
}
