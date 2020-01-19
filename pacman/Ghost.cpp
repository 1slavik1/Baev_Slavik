#include "pch.h"
#include "Ghost.h"
#include <cmath>
#include "Map.h"
#include <ctime>

Map map;

Ghost::Ghost()
{
	m_start = false;
	m_freedom = false;	
    srand(time(0));
}


Ghost::~Ghost()
{
}

void Ghost::setMode(short mode) { m_mode = mode; }
short Ghost::getMode() const { return m_mode; }

void Ghost::setX(int x) { m_x = x; }
short Ghost::getX() const { return m_x; }

void Ghost::setY(int y) { m_y = y; }
short Ghost::getY() const { return m_y; }

short Ghost::getOldX() const { return  m_oldX; }
short Ghost::getOldY() const { return  m_oldY; }

void Ghost::setFreedom(bool freedom) { m_freedom = freedom; }
void Ghost::setStart(bool start) { m_start = start; }

void Ghost::setDrawMap(bool draw) { m_drawMap = draw; }
bool Ghost::getDrawMap() const { return m_drawMap; }


void Ghost::chase(int xPac, int yPac)
{
	if (m_y >= 10 && m_y <= 14 && m_x >= 21 && m_x <= 31)
	{
		writeOldState(m_x, m_y);
        m_y--;
        m_start = false;
	}
	else m_freedom = true;

	if (m_freedom)
	{

		//start ghost on left
		if (!m_start)
		{
			writeOldState(m_x, m_y);
            m_x--;
			m_start = true;
		}

		else if ((m_x == 48 && m_y == 10) || (m_x == 0 && m_y == 10))
		{
            Ghost::funcTunel();
		}

		else if (map.map_Ghost[m_y + 1][m_x] == 1 && map.map_Ghost[m_y - 1][m_x] == 1 && map.map_Ghost[m_y][m_x + 1] == 0 && map.map_Ghost[m_y][m_x - 1] == 0)
		{
            Ghost::upDownClose();
		}

		else if (map.map_Ghost[m_y + 1][m_x] == 0 && map.map_Ghost[m_y - 1][m_x] == 0 && map.map_Ghost[m_y][m_x + 1] == 1 && map.map_Ghost[m_y][m_x - 1] == 1)
		{
            Ghost::leftRightClose();
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 0 && map.map_Ghost[m_y][m_x + 1] == 0 && map.map_Ghost[m_y][m_x - 1] == 0 && map.map_Ghost[m_y + 1][m_x] == 1)
		{
            Ghost::downClose(xPac, yPac);
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 1 && map.map_Ghost[m_y][m_x + 1] == 0 && map.map_Ghost[m_y][m_x - 1] == 0 && map.map_Ghost[m_y + 1][m_x] == 0)
		{
            Ghost::upClose(xPac, yPac);
		}
		
		else if (map.map_Ghost[m_y - 1][m_x] == 0 && map.map_Ghost[m_y][m_x + 1] == 1 && map.map_Ghost[m_y][m_x - 1] == 0 && map.map_Ghost[m_y + 1][m_x] == 0)
		{
            Ghost::rightClose(xPac, yPac);
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 0 && map.map_Ghost[m_y][m_x + 1] == 0 && map.map_Ghost[m_y][m_x - 1] == 1 && map.map_Ghost[m_y + 1][m_x] == 0)
		{
            Ghost::leftClose(xPac, yPac);			
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 0 && map.map_Ghost[m_y][m_x + 1] == 0 && map.map_Ghost[m_y][m_x - 1] == 0 && map.map_Ghost[m_y + 1][m_x] == 0)
		{
            Ghost::allClose(xPac, yPac);
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 0 && map.map_Ghost[m_y][m_x + 1] == 0 && map.map_Ghost[m_y][m_x - 1] == 1 && map.map_Ghost[m_y + 1][m_x] == 1)
		{
            Ghost::leftDownClose();
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 1 && map.map_Ghost[m_y][m_x + 1] == 0 && map.map_Ghost[m_y][m_x - 1] == 1 && map.map_Ghost[m_y + 1][m_x] == 0)
		{
            Ghost::leftUpClose();
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 1 && map.map_Ghost[m_y][m_x + 1] == 1 && map.map_Ghost[m_y][m_x - 1] == 0 && map.map_Ghost[m_y + 1][m_x] == 0)
		{
            Ghost::rightUpClose();
		}

		else if (map.map_Ghost[m_y - 1][m_x] == 0 && map.map_Ghost[m_y][m_x + 1] == 1 && map.map_Ghost[m_y][m_x - 1] == 0 && map.map_Ghost[m_y + 1][m_x] == 1)
		{
            Ghost::rightDownClose();		
		}
	}
}

void Ghost::funcTunel()
{
    //LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(0, 10);
        m_x = 1;
    }
    //RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(48, 10);
        m_x = 47;
    }
}

void Ghost::upDownClose()
{
    //LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_x++;
    }
    //RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_x--;
    }
}

void Ghost::leftRightClose()
{
    //UP
    if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_y++;
    }
    //DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_y--;
    }
}

void Ghost::downClose(int xPac, int yPac)
{
    //RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));
        writeOldState(m_x, m_y);

        if (a < b) m_x--;
        else m_y--;
    }
    //LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_x++;
        else m_y--;
    }
    //UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_x++;
        else m_x--;
    }
}

void Ghost::upClose(int xPac, int yPac)
{
    //RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));
        writeOldState(m_x, m_y);

        if (a < b) m_x--;
        else m_y++;
    }
    //LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_x++;
        else m_y++;
    }
    //DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_x++;
        else m_x--;
    }
}

void Ghost::rightClose(int xPac, int yPac)
{
    //DOWN
    if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));
        writeOldState(m_x, m_y);

        if (a < b) m_x--;
        else m_y--;
    }
    //LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_y++;
        else m_y--;
    }
    //UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));
        double b = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_y++;
        else m_x--;
    }
}

void Ghost::leftClose(int xPac, int yPac)
{
    //DOWN
    if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));
        writeOldState(m_x, m_y);

        if (a < b) m_x++;
        else m_y--;
    }
    //RIGHT
    else if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_y++;
        else m_y--;
    }
    //UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));
        double b = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b) m_y++;
        else m_x++;
    }
}

void Ghost::allClose(int xPac, int yPac)
{
    //RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));
        double c = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b && a < c) m_x--;
        else if (b < a && b < c) m_y--;
        else if (c < b && c < a) m_y++;
        else if (a == b) m_x--;
        else if (b == c) m_y--;
        else if (c == a) m_y++;
    }
    //LEFT
    else if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));
        double c = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b && a < c) m_x++;
        else if (b < a && b < c) m_y--;
        else if (c < b && c < a) m_y++;
        else if (a == b) m_x++;
        else if (b == c) m_y--;
        else if (c == a) m_y++;
    }
    //UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));
        double c = sqrt(pow(m_x - xPac, 2) + pow(m_y + 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b && a < c) m_x++;
        else if (b < a && b < c) m_x--;
        else if (c < b && c < a) m_y++;
        else if (a == b) m_x++;
        else if (b == c) m_x--;
        else if (c == a) m_y++;
    }
    //DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        double a = sqrt(pow(m_x + 1 - xPac, 2) + pow(m_y - yPac, 2));
        double b = sqrt(pow(m_x - 1 - xPac, 2) + pow(m_y - yPac, 2));
        double c = sqrt(pow(m_x - xPac, 2) + pow(m_y - 1 - yPac, 2));

        writeOldState(m_x, m_y);

        if (a < b && a < c) m_x++;
        else if (b < a && b < c) m_x--;
        else if (c < b && c < a) m_y--;
        else if (a == b) m_x++;
        else if (b == c) m_x--;
        else if (c == a) m_y--;
    }
}

void Ghost::leftDownClose()
{
    //RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_y--;
    }
    //UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_x++;
    }
}

void Ghost::leftUpClose()
{
    //RIGHT
    if (m_x + 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_y++;
    }
    //DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_x++;
    }
}

void Ghost::rightUpClose()
{
    //LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_y++;
    }
    //DOWN
    else if (m_x == m_oldX && m_y + 1 == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_x--;
    }
}

void Ghost::rightDownClose()
{
    //LEFT
    if (m_x - 1 == m_oldX && m_y == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_y--;
    }
    //UP
    else if (m_x == m_oldX && m_y - 1 == m_oldY)
    {
        writeOldState(m_x, m_y);
        m_x--;
    }
}

short Ghost::getXRandom()
{    
    return rand() % 49;
}

short Ghost::getYRandom()
{
    return rand() % 22;
}

inline void Ghost::writeOldState(int oldX, int oldY)
{
    m_oldX = oldX;
    m_oldY = oldY;
}