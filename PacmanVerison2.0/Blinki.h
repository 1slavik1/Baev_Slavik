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
    


private:
    const short X = 48;
    const short Y = 0;
   
};

#endif // BLINKI_H