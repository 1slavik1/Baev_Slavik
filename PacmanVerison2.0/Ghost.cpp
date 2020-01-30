#include "pch.h"
#include "Ghost.h"
#include <iostream>

Ghost::Ghost()
{
    m_start = false;
    m_freedom = false;
}


Ghost::~Ghost()
{
}

void Ghost::setX(short x) { m_x = x; }
short Ghost::getX() const { return m_x; }

void Ghost::setY(short y) { m_y = y; }
short Ghost::getY() const { return m_y; }



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

void Ghost::ClearAndDrawScore(short item_map, short x, short y)
{
    draw.SetClearAndDrawScore(item_map, x, y);
}

inline void Ghost::writeOldState(int oldX, int oldY)
{
    m_oldX = oldX;
    m_oldY = oldY;
}

void Ghost::MoveRight(short color, char name)
{
    if (map.getMap(m_x + 1, m_y) != 1)
    {
        writeOldState(m_x, m_y);
        m_x++;
        Ghost::DrawPlayer(color, name, m_x, m_y);
        Sleep(150);
    }
    //if (map.getMap(m_x - 1, m_y, 2) != 1) Ghost::ClearPlayer(m_x - 1, m_y);
    if (map.getMap(m_x - 1, m_y) != 1) Ghost::ClearAndDrawScore(map.getMap(m_x - 1, m_y), m_x - 1, m_y);
}

void Ghost::MoveLeft(short color, char name)
{
    if (map.getMap(m_x - 1, m_y) != 1)
    {
        writeOldState(m_x, m_y);
        m_x--;
        Ghost::DrawPlayer(color, name, m_x, m_y);
        Sleep(150);
    }
    //if (map.getMap(m_x + 1, m_y, 2) != 1) Ghost::ClearPlayer(m_x + 1, m_y);
    if (map.getMap(m_x + 1, m_y) != 1) Ghost::ClearAndDrawScore(map.getMap(m_x + 1, m_y), m_x + 1, m_y);
}

void Ghost::MoveUp(short color, char name)
{
    if (map.getMap(m_x, m_y - 1) != 1)
    {
        writeOldState(m_x, m_y);
        m_y--;
        Ghost::DrawPlayer(color, name, m_x, m_y);
        Sleep(150);
    }
    if (map.getMap(m_x, m_y + 1) != 1) Ghost::ClearPlayer(m_x, m_y + 1);
}

void Ghost::MoveDown(short color, char name)
{
    if (map.getMap(m_x, m_y + 1) != 1)
    {
        writeOldState(m_x, m_y);
        m_y++;
        Ghost::DrawPlayer(color, name, m_x, m_y);
        Sleep(150);
    }
    if (map.getMap(m_x, m_y - 1) != 1) Ghost::ClearPlayer(m_x, m_y - 1);
}



void Ghost::Logic(int xPac, int yPac, short color, char name)
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
            Ghost::DrawPlayer(color, name, m_x, m_y);            
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
            Ghost::MoveLeft(color, name);
            m_start = true;
        }
        else if (map.getMap(m_x, m_y + 1) == 1 && map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1)
        {
            Ghost::upDownClose(color, name);
        }
        else if (map.getMap(m_x, m_y + 1) != 1 && map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) == 1)
        {
            Ghost::leftRightClose(color, name);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) == 1)
        {
            Ghost::downClose(xPac, yPac, color, name);
        }

        else if (map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::upClose(xPac, yPac, color, name);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::rightClose(xPac, yPac, color, name);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) == 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::leftClose(xPac, yPac, color, name);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::allClose(xPac, yPac, color, name);
        }

        else if (map.getMap(m_x, m_y - 1) != 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) == 1 && map.getMap(m_x, m_y + 1) == 1)
        {
            Ghost::leftDownClose(color, name);
        }

        else if (map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) != 1 && map.getMap(m_x - 1, m_y) == 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::leftUpClose(color, name);
        }

        else if (map.getMap(m_x, m_y - 1) == 1 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) != 1)
        {
            Ghost::rightUpClose(color, name);
        }

        else if (map.getMap(m_x, m_y - 1) == 0 && map.getMap(m_x + 1, m_y) == 1 && map.getMap(m_x - 1, m_y) != 1 && map.getMap(m_x, m_y + 1) == 1)
        {
            Ghost::rightDownClose(color, name);
        }

    }
}

void Ghost::upDownClose(short color, char name)
{
    //Came on the LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveLeft(color, name);
    }
    //Came on the RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveLeft(color, name);
    }
}

void Ghost::leftRightClose(short color, char name)
{
    //Came on the UP
    if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
       
    }
}

void Ghost::downClose(short xPac, short yPac, short color, char name)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        
    }
}

void Ghost::upClose(short xPac, short yPac, short color, char name)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
       
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        
    }
}

void Ghost::rightClose(short xPac, short yPac, short color, char name)
{
    //Came on the DOWN
    if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        
    }
}

void Ghost::leftClose(short xPac, short yPac, short color, char name)
{
    //Came on the DOWN
    if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        
    }
    //Came on the RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
       
    }
}

void Ghost::allClose(short xPac, short yPac, short color, char name)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
      
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        
    }
}

void Ghost::leftDownClose(short color, char name)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        
    }
}

void Ghost::leftUpClose(short color, char name)
{
    //Came on the RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        Ghost::MoveDown(color, name);
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        Ghost::MoveRight(color, name);
    }
}

void Ghost::rightUpClose(short color, char name)
{
    //Came on the LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        
    }
}

void Ghost::rightDownClose(short color, char name)
{
    //Came on the LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        
    }
    //Came on the UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        
    }
}