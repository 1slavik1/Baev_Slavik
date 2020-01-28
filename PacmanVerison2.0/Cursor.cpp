#include "Cursor.h"
#include <windows.h>
Cursor::Cursor()
{
    //ctor
}

Cursor::~Cursor()
{
    //dtor
}

void Cursor::SetCursor(SHORT xPos, SHORT yPos)
{
    COORD curPos;
    curPos.X = xPos; curPos.Y = yPos;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curPos);
}
