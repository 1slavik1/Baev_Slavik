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
    void setMode(short mode);
    short getMode() const;
    void setFreedom(bool freedom);
    void setStart(bool start);
    void DrawScore(int &score);
    void ClearPlayer(short x, short y);    
    void ClearAndDrawScore(short item_map, short x, short y);
    void DrawPlayer(short x, short y);
    inline void writeOldState(int oldX, int oldY);
  
    

protected:

    static const short SCATTER = 1;
    static const short CHASE = 2;
    static const short FRIGHTENED = 3;

    Map map;

    short color;
    char name;

    void chase(int xPac, int yPac);
    



private:
    
    short m_mode;
    short m_x, m_y;
    int m_oldX, m_oldY;
    bool m_start, m_freedom;

  
    virtual void MoveUp();
    virtual void MoveDown();
    virtual void MoveLeft();
    virtual void MoveRight();
     

    void tunel();
    void upDownClose();
    void leftRightClose();    
    void leftUpClose();
    void rightUpClose();
    void leftDownClose();
    void rightDownClose();
    void upClose(short xPac, short yPac);
    void downClose(short xPac, short yPac);    
    void leftClose(short xPac, short yPac);
    void rightClose(short xPac, short yPac);    
    void allClose(short xPac, short yPac);
};

#endif // GHOST_H
