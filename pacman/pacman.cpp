#include "pch.h"
#include <iostream>
#include "Map.h"
#include "Menu.h"
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

static const short STARTNEWGAME = 1;
static const short CONTINUE = 2;
static const short STATISTICS = 3;
static const short EXIT = 4;
static const short BACK = 27;

void StartGame(Map &map);
void ContinueGame(Map &map);
void OutputStat();

int main()
{
    using namespace std;
	Map map;
	Menu menu;
	
	bool error = false;
	while (true)
	{
		switch (menu.choice_menu_item_start(error))
		{
			error = false;
			
		case STARTNEWGAME:
            StartGame(map);
			break;
			
		case CONTINUE:
            ContinueGame(map);			
			break;

		case STATISTICS:
            OutputStat();
			break;

		case EXIT:
			system("cls");
			cout << "Exit..." << endl;
			exit(0);

		default:
			error = true;
			break;
		}		
	}	
	return 0;	
}

void StartGame(Map &map)
{
    map.setup();
    while (!map.getGameOver())
    {
        setlocale(0, "C");
        map.draw();
        map.input();
        map.logic();
    }
}

void ContinueGame(Map &map)
{
    map.saveSetup();
    while (!map.getGameOver())
    {
        setlocale(0, "C");
        map.draw();
        map.input();
        map.logic();
    }
}

void OutputStat()
{
    using namespace std;
    system("cls");
    ifstream in("stat.txt");
    string stat;    

    if (in.is_open())
    {
        while (getline(in, stat))
        {
            cout << stat << endl;
        }
    }
    
    in.close();

    while (!(_getch()==BACK))
    {
        
    }
    
    
}