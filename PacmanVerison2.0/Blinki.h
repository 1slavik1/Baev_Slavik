#ifndef BLINKI_H
#define BLINKI_H
#include "Ghost.h"
//#include "Map.h"

class Blinki : public Ghost
{
public:
    Blinki();
    ~Blinki();
    static const short RED = 4;
    static const short XSTARTBLINKI = 23;
    static const short YSTARTBLINKI = 12;
    static const char NAME = 'B';
    void Logic(int xPac, int yPac);
    //short x, y;


private:
    //Map map;
    //bool freedom;
    //bool m_start;
};

#endif // BLINKI_H