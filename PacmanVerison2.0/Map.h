#ifndef MAP_H
#define MAP_H
#include "Draw.h"
class Map
{
public:
    Map();
    ~Map();
    Draw draw;
    void DrawMap();
    short getMap(short x, short y) const;
    void setMap(short x, short y);
private:
    static const short WIDTH = 49;
    static const short HEIGHT = 22;
    short map[HEIGHT][WIDTH] = {
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,1,1,1,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,1,1},
                    {1,1,2,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1},
                    {1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1},
                    {1,1,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,1,1},
                    {1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1},
                    {1,1,2,1,1,1,1,1,1,1,2,1,1,1,2,0,2,0,2,0,2,0,2,0,2,1,1,1,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,1,1,1,1,1,1},
                    {1,1,0,2,0,2,0,2,0,2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,1,1,1,1,1,1},
                    {2,0,2,0,2,0,2,0,2,0,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,0,2,0,2,0,2},
                    {1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1},
                    {1,1,0,2,0,2,0,2,0,2,0,2,0,2,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1},
                    {1,1,2,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1},
                    {1,1,0,2,0,2,0,1,1,1,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,1,1},
                    {1,1,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,2,1,1},
                    {1,1,0,2,0,2,0,2,0,2,0,1,1,1,0,2,0,2,0,2,0,2,0,1,1,1,1,1,1,2,0,2,0,2,0,2,0,2,0,1,1,1,0,2,0,2,0,1,1},
                    {1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1},
                    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
                    {1,1,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,1,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };
    ;

    short mapForPac[HEIGHT][WIDTH];
};
#endif // MAP_H
