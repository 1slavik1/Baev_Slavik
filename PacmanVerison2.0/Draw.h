#ifndef DRAW_H
#define DRAW_H
#include "Cursor.h"
class Draw
{
public:
    Draw();
    ~Draw();
    void DrawMap(short height, short width, short map[][49]);
    void DrawPlayer(short color, char name, short x, short y);
    void Clear(short x, short y);
    void SetDrawScore();
private:
    Cursor cursor;
};
#endif // DRAW_H
