#ifndef GHOST_H
#define GHOST_H

#include"Draw.h"
class Ghost
{
public:
    Ghost();
    virtual ~Ghost();
    void DrawPlayer(short color, char name, short x, short y);
    void ClearPlayer(short x, short y);
    void DrawScore(int &score);
    Draw draw;
private:

};

#endif // GHOST_H
