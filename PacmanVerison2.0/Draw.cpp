#include "Draw.h"
#include <iostream>
#include "Windows.h"

Draw::Draw()
{
}


Draw::~Draw()
{
}

void Draw::DrawMap(short height, short width, short map[][49])
{
    system("cls");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            switch (map[i][j])
            {
            case 0:
                std::cout << (char)(250);
                break;
            case 1:
                std::cout << (char)(176);
                break;
            case 2:
                std::cout << " ";
                break;
            case 3:
                std::cout << (char)(250);
                break;

            default:
                break;
            }
        }
        std::cout << std::endl;
    }
}

void Draw::DrawPlayer(short color, char name, short x, short y)
{
    cursor.SetCursor(x, y);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | color));
    std::cout << name;
}

void Draw::Clear(short x, short y)
{
    cursor.SetCursor(x, y);
    std::cout << " ";
}

void Draw::SetDrawScore()
{
    cursor.SetCursor(8, 23);

}
