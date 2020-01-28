#ifndef CURSOR_H
#define CURSOR_H
#include <windows.h>
class Cursor
{
public:
    Cursor();
    ~Cursor();
    void SetCursor(SHORT xPos, SHORT yPos);
};

#endif // CURSOR_H
