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
void Pac::changeScore(int s) { score += s; }

void Pac::setLife(short life) { m_life = life; }
short Pac::getLife() const { return m_life; }

void Pac::changeLife() { m_life--; }
void Pac::setScore() { score = 0; }

void Pac::MoveRight()
{
    if (map.getMap(x + 1, y) == 0)
    {
        score++;
        Ghost::DrawScore(score);
        map.setMap(x + 1, y);
    }
    else if (map.getMap(x + 1, y) == 3)
    {
        m_frightened = true;
        score += 10;
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
    else if (map.getMap(x - 1, y) == 3)
    {
        m_frightened = true;
        score+=10;
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
    else if (map.getMap(x, y - 1) == 3)
    {
        m_frightened = true;
        score += 10;
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
    else if (map.getMap(x, y + 1) == 3)
    {
        m_frightened = true;
        score += 10;
        Ghost::DrawScore(score);
        map.setMap(x, y + 1);
    }
    if (map.getMap(x, y + 1) == 1) dir = STOP;
    else y++;
    Ghost::DrawPlayer(x, y);
    if (map.getMap(x, y - 1) != 1) Ghost::ClearPlayer(x, y - 1);
    Sleep(150);
}
