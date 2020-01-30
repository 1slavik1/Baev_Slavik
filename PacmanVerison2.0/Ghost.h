#ifndef GHOST_H
#define GHOST_H

#include "Draw.h"
#include "Map.h"
class Ghost
{
public:
    Ghost();
    virtual ~Ghost();

    Draw draw;

    void setX(short x);
    short getX() const;
    void setY(short y);
    short getY() const;
    void DrawScore(int &score);
    void ClearPlayer(short x, short y);
    inline void writeOldState(int oldX, int oldY);
    void ClearAndDrawScore(short item_map, short x, short y);
    void DrawPlayer(short color, char name, short x, short y);
    
  
    

protected:
    void Logic(int xPac, int yPac, short color, char name);
    

private:
    Map map;
    short m_x, m_y;
    int m_oldX, m_oldY;
    bool m_start, m_freedom;

  

    void MoveRight(short color, char name);
    void MoveLeft(short color, char name);
    void MoveUp(short color, char name);
    void MoveDown(short color, char name);

    void upDownClose(short color, char name);
    void leftRightClose(short color, char name);
    void downClose(short xPac, short yPac, short color, char name);
    void upClose(short xPac, short yPac, short color, char name);
    void rightClose(short xPac, short yPac, short color, char name);
    void leftClose(short xPac, short yPac, short color, char name);
    void allClose(short xPac, short yPac, short color, char name);
    void leftDownClose(short color, char name);
    void leftUpClose(short color, char name);
    void rightUpClose(short color, char name);
    void rightDownClose(short color, char name);
};

#endif // GHOST_H
