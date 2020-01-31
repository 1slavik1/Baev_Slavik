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
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    void changeScore(int s);
    void setScore();
    int getScore() const;

    void setLife(short life);
    short getLife() const;
    void changeLife();

private:
    //Map map;

    int score = 0;
    short m_life;
};

#endif // PAC_H
