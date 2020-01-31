#include "pch.h"
#include "Ghost.h"
#include <iostream>
#include <cmath>

Ghost::Ghost()
{
    m_start = false;
    m_freedom = false;
    m_frightened = false;
}


Ghost::~Ghost()
{
}

void Ghost::setX(short x) { m_x = x; }
short Ghost::getX() const { return m_x; }

void Ghost::setY(short y) { m_y = y; }
short Ghost::getY() const { return m_y; }

void Ghost::setMode(short mode) { m_mode = mode; }
short Ghost::getMode() const { return m_mode; }

void Ghost::setFreedom(bool freedom) { m_freedom = freedom; }
void Ghost::setStart(bool start) { m_start = start; }

short Ghost::getOldX() const { return m_oldX; }
short Ghost::getOldY() const { return m_oldY; }

short Ghost::getXRandom()
{
    return rand() % 49;
}

short Ghost::getYRandom()
{
    return rand() % 22;
}

void Ghost::DrawPlayer(short x, short y)
{
    if(!m_frightened) draw.DrawPlayer(color, name, x, y);
    else draw.DrawPlayer(1, name, x, y);
    
}

void Ghost::ClearPlayer(short x, short y)
{
    draw.Clear(x, y);
}

void Ghost::DrawLife(short life)
{
    draw.setDrawLife();
    std::cout << life << std::endl;
}

void Ghost::DrawScore(int &score)
{
    draw.SetDrawScore();
    std::cout << score << std::endl;
}

void Ghost::ClearAndDrawScore(short item_map, short x, short y)
{
    draw.SetClearAndDrawScore(item_map, x, y);
}

inline void Ghost::writeOldState(int oldX, int oldY)
{
    m_oldX = oldX;
    m_oldY = oldY;
}

void Ghost::MoveRight()
{
    if (map.getMap(m_x + 1, m_y) != 1)
    {
        writeOldState(m_x, m_y);
        m_x++;
        Ghost::DrawPlayer(m_x, m_y);
    }
    if (map.getMap(m_x - 1, m_y) != 1) Ghost::ClearAndDrawScore(map.getMap(m_x - 1, m_y), m_x - 1, m_y);
    Sleep(150);
}

void Ghost::MoveLeft()
{
    if (map.getMap(m_x - 1, m_y) != 1)
    {
        writeOldState(m_x, m_y);
        m_x--;
        Ghost::DrawPlayer(m_x, m_y);
        
    }
    if (map.getMap(m_x + 1, m_y) != 1) Ghost::ClearAndDrawScore(map.getMap(m_x + 1, m_y), m_x + 1, m_y);
    Sleep(150);
}

void Ghost::MoveUp()
{
    if (map.getMap(m_x, m_y - 1) != 1)
    {
        writeOldState(m_x, m_y);
        m_y--;
        Ghost::DrawPlayer(m_x, m_y);
        
    }
    if (map.getMap(m_x, m_y + 1) != 1) Ghost::ClearAndDrawScore(map.getMap(m_x, m_y + 1), m_x, m_y + 1);
    Sleep(150);
}

void Ghost::MoveDown()
{
    if (map.getMap(m_x, m_y + 1) != 1)
    {
        writeOldState(m_x, m_y);
        m_y++;
        Ghost::DrawPlayer(m_x, m_y);
        
    }
    if (map.getMap(m_x, m_y - 1) != 1) Ghost::ClearAndDrawScore(map.getMap(m_x, m_y - 1), m_x, m_y - 1);
    Sleep(150);
}



void Ghost::chase(int xPac, int yPac)
{
    if (m_y >= 10 && m_y <= 14 && m_x >= 21 && m_x <= 31)
    {
        if (map.getMap(m_x, m_y - 1) == 1)
        {
            
            m_y--;
            Sleep(150);
        }
        else if (map.getMap(m_x, m_y - 1) != 1)
        {
            m_y--;
            Ghost::DrawPlayer(m_x, m_y);            
            Sleep(150);
        }
        if (map.getMap(m_x, m_y + 1) != 1) Ghost::ClearPlayer(m_x, m_y + 1);
        
        m_start = false;
    }
    else m_freedom = true;

    if (m_freedom)
    {
        //start ghost on left
        if (!m_start)
        {
            Ghost::MoveLeft();
            m_start = true;
        }
        else if ((m_x == 48 && m_y == 10) || (m_x == 0 && m_y == 10))
        {
            Ghost::tunel();
        }
        else if (map.getMap(m_x, m_y + 1) == 1 && map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1)
        {
            Ghost::upDownClose();
        }
        else if (map.getMap(m_x, m_y + 1) != 1 && map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) == 1)
        {
            Ghost::leftRightClose();
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) == 1)
        {
            Ghost::downClose(xPac, yPac);
        }

        else if (map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::upClose(xPac, yPac);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::rightClose(xPac, yPac);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) == 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::leftClose(xPac, yPac);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::allClose(xPac, yPac);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) == 1 && map.getMap(m_x, m_y + 1) == 1)
        {
            Ghost::leftDownClose();
        }

        else if (map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) == 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::leftUpClose();
        }

        else if (map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::rightUpClose();
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) == 1)
        {
            Ghost::rightDownClose();
        }

    }
}

void Ghost::tunel()
{
    //Came on the LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(0, 10);
        m_x = 1;
        Ghost::ClearAndDrawScore(map.getMap(48, 10), 48, 10);
    }
    //Came on the RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(48, 10);
        m_x = 47;
        Ghost::ClearAndDrawScore(map.getMap(0, 10), 0, 10);
    }
}

void Ghost::upDownClose()
{
    //Came on the LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveRight();
    }
    //Came on the RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveLeft();
    }
}

void Ghost::leftRightClose()
{
    //Came on the UP
    if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        Ghost::MoveDown();
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        Ghost::MoveUp();
    }
}

void Ghost::downClose(short xPac, short yPac)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveUp();
        else MoveLeft();
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveUp();
        else MoveRight();
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));
        double b = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveRight();
        else MoveLeft();
    }
}

void Ghost::upClose(short xPac, short yPac)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));
        double b = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveDown();
        else MoveLeft();
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));
        double b = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveDown();
        else MoveRight();
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));
        double b = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveLeft();
        else MoveRight();
    }
}

void Ghost::rightClose(short xPac, short yPac)
{
    //Came on the DOWN
    if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveUp();
        else MoveLeft();
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));

        if (a < b) MoveUp();
        else MoveDown();
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));
        double b = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveDown();
        else MoveLeft();
    }
}

void Ghost::leftClose(short xPac, short yPac)
{
    //Came on the DOWN
    if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));

        if (a < b) MoveUp();
        else MoveRight();
    }
    //Came on the RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));

        if (a < b) MoveUp();
        else MoveDown();
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));
        double b = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));

        if (a < b) MoveRight();
        else MoveDown();
    }
}

void Ghost::allClose(short xPac, short yPac)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));
        double c = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if ((a < b && a < c) || (a == b)) MoveUp();
        else if ((b < a && b < c) || (b == c)) MoveDown();
        else if ((c < a && c < b) || (c == a)) MoveLeft();
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double b = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));
        double c = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));

        if ((a < b && a < c) || (a == b)) MoveUp();
        else if ((b < a && b < c) || (b == c)) MoveDown();
        else if ((c < a && c < b) || (c == a)) MoveRight();
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));
        double b = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y + 1), 2)));
        double c = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if ((a < b && a < c) || (a == b)) MoveRight();
        else if ((b < a && b < c) || (b == c)) MoveDown();
        else if ((c < a && c < b) || (c == a)) MoveLeft();
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(xPac - (m_x + 1), 2) + (pow(yPac - m_y, 2)));
        double b = sqrt(pow(xPac - m_x, 2) + (pow(yPac - (m_y - 1), 2)));
        double c = sqrt(pow(xPac - (m_x - 1), 2) + (pow(yPac - m_y, 2)));

        if ((a < b && a < c) || (a == b)) MoveRight();
        else if ((b < a && b < c) || (b == c)) MoveUp();
        else if ((c < a && c < b) || (c == a)) MoveLeft();
    }
}

void Ghost::leftDownClose()
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveUp();
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        Ghost::MoveRight();
    }
}

void Ghost::leftUpClose()
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveDown();
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        Ghost::MoveRight();
    }
}

void Ghost::rightUpClose()
{
    //Came on the LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveDown();
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        Ghost::MoveLeft();
    }
}

void Ghost::rightDownClose()
{
    //Came on the LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveUp();
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        Ghost::MoveLeft();
    }
}