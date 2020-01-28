#ifndef PAC_H
#define PAC_H
#include "Ghost.h"
#include "Map.h"
class Pac : public Ghost
{
public:
    static const short YELLOW = 6;
    static const short XSTARTPAC = 3;
    static const short YSTARTPAC = 10;
    static const char NAME = 'P';

    Pac();
    ~Pac();
    short x, y;
    short life;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    int getScore() const;

private:
    Map map;

    int m_score = 0;

};

#endif // PAC_H
