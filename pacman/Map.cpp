#include "pch.h"
#include "Map.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include "Pac.h"
#include "Blinki.h"
#include "Pinki.h"
#include "Inki.h"
#include "Klayd.h"
#include <string>



Pac pac;
Blinki blinki;
Pinki pinki;
Inki inki;
Klayd klayd;

Map::Map()
{
	m_error = false;
	m_save = false;
    m_frightened = false;
    m_countFrightened = 0;
    m_countDraw = 0;
    m_countLevel = 1;
    m_levelUp = false;
    m_ready = false;
	memcpy(map, map2, sizeof(map));
	blinki.setDrawMap(false);
	pinki.setDrawMap(false);
    inki.setDrawMap(false);
    klayd.setDrawMap(false);
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   
}


Map::~Map()
{
}



void Map::draw()
{
    using namespace std;

    m_countDraw++;
    if (m_frightened) m_countFrightened++;
	system("cls");
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{

			if (map[i][j] == 1)
			{
                Map::funcWall(i,j);
			}
			else if (map[i][j] == 0)
			{
                Map::funcEat(i, j);				
			}
			else if (map[i][j] == 3)
			{
                Map::funcBonus(i, j);
			}
			else
			{			
                Map::funcOther(i, j);
			}
		}
		cout << endl;
	}

    if (m_ready)
    {
        do
        {
            cout << "You have completed level " << m_countLevel - 1 << endl;
            cout << "Click \"SPACE\" when ready" << endl;
            m_ready = false;
        } while (!(_getch() == 32));
     
    }

	blinki.setDrawMap(false);
	pinki.setDrawMap(false);
    inki.setDrawMap(false);
    klayd.setDrawMap(false);

	if (m_countDraw > 10000)
	{
        m_countDraw = 0;
	}

    if (m_countFrightened >= 100)
    {
        m_countFrightened = 0;
        m_frightened = false;
    }

    if (m_score % 240 == 0)
    {
        m_levelUp = true;
        m_ready = true;
        m_countLevel++;
        m_countDraw = 0;
        Map::setup();
    }
	
	cout << endl;
	//cout << countDraw << "count = " << countDraw << endl;
	cout << "Life: " << pac.life << endl;
	cout << "Score: " << m_score << endl;
    cout << "Level - " << m_countLevel << endl;
	//cout << "X_Blinki: " << blinki.getX() << ", " << "Y_Blinki " << blinki.getY() << endl;
	//cout << "X = " << blinki.getOldX() << ", " << "Y = " << blinki.getOldY() << endl;
	//cout << "X_Pac: " << pac.X_Pac << ", " << "Y_Pac " << pac.Y_Pac << endl;
    //cout << "Frightened = " << frightened << " " << count_frightened << endl;
    
}


void Map::setup()
{
    m_gameOver = false;
	pac.dir = pac.STOP;
	pac.X_Pac = XSTARTPAC;
	pac.Y_Pac = YSTARTPAC;
	blinki.setX(XSTARTBLINKI);
	blinki.setY(YSTARTBLINKI);
	pinki.setX(XSTARTPINKI);
	pinki.setY(YSTARTPINKI);
    inki.setX(XSTARTINKI);
    inki.setY(YSTARTINKI);
    klayd.setX(XSTARTBKLAYD);
    klayd.setY(YSTARTBKLAYD);
    m_oldState = 0;
    mapUpdate();

    if (!m_levelUp)
    {
        pac.life = 3;
        m_score = 0;
    }
    
	
}

void Map::saveSetup()
{
    using namespace std;

    m_gameOver = false;
	ifstream in("save.txt");
	if (in.is_open())
	{
		in >> pac.life;
		in >> m_score;
        in >> m_countLevel;

		in >> pac.X_Pac >> pac.Y_Pac;
		int x, y;

		in >> x >> y;
		blinki.setX(x);
		blinki.setY(y);
		in >> x >> y;
		blinki.writeOldState(x, y);

		in >> x >> y;
		pinki.setX(x);
		pinki.setY(y);
		in >> x >> y;
		pinki.writeOldState(x, y);

        in >> x >> y;
        inki.setX(x);
        inki.setY(y);
        in >> x >> y;
        inki.writeOldState(x, y);

        in >> x >> y;
        klayd.setX(x);
        klayd.setY(y);
        in >> x >> y;
        klayd.writeOldState(x, y);

		char ch[1];
		for (int i = 0; i < height; i++) 
		{
			for (int j = 0; j < width; j++)
			{
				in >> ch[0];
				map[i][j] = atoi(ch);
			}

		}

	}
	
	
	pac.dir = pac.STOP;
    m_oldState = 0;
	
	
}


void Map::input()
{
    using namespace std;

	if (_kbhit()) {
		switch (_getch())
		{
		case LEFT_ENG:
        case LEFT_RU:
        case LEFT_ARROW:
			pac.dir = pac.LEFT;
			break;
		case RIGHT_ENG:
        case RIGHT_RU:
        case RIGHT_ARROW:
			pac.dir = pac.RIGHT;
			break;
		case UP_ENG:
        case UP_RU:
        case UP_ARROW:
			pac.dir = pac.UP;
			break;
		case DOWN_ENG:
        case DOWN_RU:
        case DOWN_ARROW:
			pac.dir = pac.DOWN;
			break;
		case PAUSE:			
            Map::funcPause();			
			break;
		default:
			break;
		}
	}
}


void Map::logic()
{
	switch (pac.dir)
	{
	case pac.LEFT:
		pac.X_Pac--;
		pac.dir = pac.STOP;
        m_oldState = 1;
		break;
	case pac.RIGHT:
		pac.X_Pac++;
		pac.dir = pac.STOP;
        m_oldState = 2;
		break;
	case pac.UP:
		//oldY = pac.Y_Pac;
		pac.Y_Pac--;
		pac.dir = pac.STOP;
        m_oldState = 3;
		break;
	case pac.DOWN:
		//oldY = pac.Y_Pac;
		pac.Y_Pac++;
		pac.dir = pac.STOP;
        m_oldState = 4;
		break;

	}

	
	if (pac.X_Pac == blinki.getX() && pac.Y_Pac == blinki.getY())
	{
        if (!m_frightened) pac.life--;
        //if (frightened) score+=100;
        m_countDraw = 0;
		blinki.writeOldState(blinki.getX(),blinki.getY());
		
		blinki.setFreedom(false);
		blinki.setStart(false);
		
		blinki.setX(XSTARTBLINKI);
		blinki.setY(YSTARTBLINKI);		
	}
	else if (pac.X_Pac == pinki.getX() && pac.Y_Pac == pinki.getY())
	{
        if (!m_frightened) pac.life--;
       // if (frightened) score += 100;
        m_countDraw = 0;
		pinki.writeOldState(pinki.getX(), pinki.getY());

		pinki.setFreedom(false);
		pinki.setStart(false);

		pinki.setX(XSTARTPINKI);
		pinki.setY(YSTARTPINKI);
	}
    else if (pac.X_Pac == inki.getX() && pac.Y_Pac == inki.getY())
    {
        if (!m_frightened) pac.life--;
        //if (frightened) score += 100;
        m_countDraw = 0;
        inki.writeOldState(inki.getX(), inki.getY());

        inki.setFreedom(false);
        inki.setStart(false);

        inki.setX(XSTARTINKI);
        inki.setY(YSTARTINKI);
    }
    else if (pac.X_Pac == klayd.getX() && pac.Y_Pac == klayd.getY())
    {
        if (!m_frightened) pac.life--;
       // if (frightened) score += 100;
        m_countDraw = 0;
        klayd.writeOldState(klayd.getX(), klayd.getY());

        klayd.setFreedom(false);
        klayd.setStart(false);

        klayd.setX(XSTARTBKLAYD);
        klayd.setY(YSTARTBKLAYD);
    }

    if (pac.life <= 0)
    {
        using namespace std;
        m_gameOver = true;
        m_levelUp = false;
        m_countLevel = 0;
        string name;
        system("cls");
        cout << "You got = "<< m_score <<" points" << "\nInput your name: ";
        cin.get();
        getline(cin, name);
        ofstream out("stat.txt", ios::app);
        out << name << ": " << m_score << endl;
        //out << name << endl;
        out.close();
    }
	
	
	if (pac.X_Pac == width-1) pac.X_Pac = 1;
	else if (pac.X_Pac == 0) pac.X_Pac = width-2;

	
}

void Map::funcPause()
{
    using namespace std;

    do
    {
        int var = menu.choice_menu_item_pause(m_error, m_save);
        m_error = false;
        m_save = false;
        if (var == 1)
        {
            break;
        }
        else if (var == 2)
        {
            ofstream out("save.txt");
            out << pac.life << endl;
            out << m_score << endl;
            out << m_countLevel << endl;
            out << pac.X_Pac << " " << pac.Y_Pac << endl;
            out << blinki.getX() << " " << blinki.getY() << endl;
            out << blinki.getOldX() << " " << blinki.getOldY() << endl;
            out << pinki.getX() << " " << pinki.getY() << endl;
            out << pinki.getOldX() << " " << pinki.getOldY() << endl;
            out << inki.getX() << " " << inki.getY() << endl;
            out << inki.getOldX() << " " << inki.getOldY() << endl;
            out << klayd.getX() << " " << klayd.getY() << endl;
            out << klayd.getOldX() << " " << klayd.getOldY() << endl;

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    out << map[i][j];
                }
                out << endl;
            }
            out.close();
            m_save = true;
        }
        else if (var == 3)
        {
            cout << "Exit..." << endl;
            exit(0);
        }
        else
        {
            m_error = true;
        }
    } while (m_error || m_save);
}

void Map::mapUpdate()
{
	memcpy(map, map2, sizeof(map));
}

void Map::funcWall(int i, int j)
{
    using namespace std;
    SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
    cout << (char)(176);
    //проверка на столкновение со стеной
    if (i == pac.Y_Pac && j == pac.X_Pac)
    {
        switch (m_oldState)
        {
        case 1:
            pac.X_Pac++;
            break;
        case 2:
            pac.X_Pac--;
            break;
        case 3:
            pac.Y_Pac++;
            break;
        case 4:
            pac.Y_Pac--;
            break;

        }

    }

    if (i == blinki.getY() && j == blinki.getX() && m_countDraw % 2 == 0)
    {
        blinki.logic(pac.X_Pac, pac.Y_Pac);
    }

    if (i == pinki.getY() && j == pinki.getX() && m_countDraw % 2 == 0)
    {
        pinki.logic(pac.X_Pac, pac.Y_Pac);
    }

    if (i == inki.getY() && j == inki.getX() && m_countDraw % 2 == 0)
    {
        inki.logic(pac.X_Pac, pac.Y_Pac);
    }

    if (i == klayd.getY() && j == klayd.getX() && m_countDraw % 2 == 0)
    {
        klayd.logic(pac.X_Pac, pac.Y_Pac);
    }
}

void Map::funcEat(int i, int j)
{
    using namespace std;

    if (i == pac.Y_Pac && j == pac.X_Pac)
    {
        pac.Draw();
        map[i][j] = 2;
        m_score++;
    }
    else if (i == blinki.getY() && j == blinki.getX() && !blinki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) blinki.draw(LIGHTBLUE);
        else blinki.draw(RED);
        Map::volna();
        blinki.logic(pac.X_Pac, pac.Y_Pac);
        blinki.setDrawMap(true);
    }
    else if (i == pinki.getY() && j == pinki.getX() && !pinki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) pinki.draw(LIGHTBLUE);
        else pinki.draw(PINK);
        Map::volna();
        pinki.logic(pac.X_Pac, pac.Y_Pac);
        pinki.setDrawMap(true);
    }
    else if (i == inki.getY() && j == inki.getX() && !inki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) inki.draw(LIGHTBLUE);
        else inki.draw(BLUE);
        Map::volna();
        inki.logic(pac.X_Pac, pac.Y_Pac);
        inki.setDrawMap(true);
    }
    else if (i == klayd.getY() && j == klayd.getX() && !klayd.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) klayd.draw(LIGHTBLUE);
        else klayd.draw(YELLOW);
        Map::volna();
        klayd.logic(pac.X_Pac, pac.Y_Pac);
        klayd.setDrawMap(true);
    }
    else {
       /* if ((i == 10 && j == 0) || (i == 10 && j == 48))
        {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 0));
            cout << (char)(250);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 1));
            cout << (char)(250);
        }*/
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 1));
        cout << (char)(250);
        
    }
}

void Map::funcBonus(int i, int j)
{
    using namespace std;

    if (i == pac.Y_Pac && j == pac.X_Pac)
    {
        pac.Draw();
        map[i][j] = 2;
        m_frightened = true;

    }
    else if (i == blinki.getY() && j == blinki.getX() && !blinki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) blinki.draw(LIGHTBLUE);
        else blinki.draw(RED);
        Map::volna();
        blinki.logic(pac.X_Pac, pac.Y_Pac);
        blinki.setDrawMap(true);
    }
    else if (i == pinki.getY() && j == pinki.getX() && !pinki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) pinki.draw(LIGHTBLUE);
        else pinki.draw(PINK);
        Map::volna();
        pinki.logic(pac.X_Pac, pac.Y_Pac);
        pinki.setDrawMap(true);
    }
    else if (i == inki.getY() && j == inki.getX() && !inki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) inki.draw(LIGHTBLUE);
        else inki.draw(BLUE);
        Map::volna();
        inki.logic(pac.X_Pac, pac.Y_Pac);
        inki.setDrawMap(true);
    }
    else if (i == klayd.getY() && j == klayd.getX() && !klayd.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) klayd.draw(LIGHTBLUE);
        else klayd.draw(YELLOW);
        Map::volna();
        klayd.logic(pac.X_Pac, pac.Y_Pac);
        klayd.setDrawMap(true);
    }
    else {
        SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 14));
        cout << (char)(250);
    }
}

void Map::funcOther(int i, int j)
{
    using namespace std;

    if (i == pac.Y_Pac && j == pac.X_Pac)
    {
        pac.Draw();
    }
    else if (i == blinki.getY() && j == blinki.getX() && !blinki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) blinki.draw(LIGHTBLUE);
        else blinki.draw(RED);
        Map::volna();
        blinki.logic(pac.X_Pac, pac.Y_Pac);
        blinki.setDrawMap(true);
    }
    else if (i == pinki.getY() && j == pinki.getX() && !pinki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) pinki.draw(LIGHTBLUE);
        else pinki.draw(PINK);
        Map::volna();
        pinki.logic(pac.X_Pac, pac.Y_Pac);
        pinki.setDrawMap(true);
    }
    else if (i == inki.getY() && j == inki.getX() && !inki.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) inki.draw(LIGHTBLUE);
        else inki.draw(BLUE);
        Map::volna();
        inki.logic(pac.X_Pac, pac.Y_Pac);
        inki.setDrawMap(true);
    }
    else if (i == klayd.getY() && j == klayd.getX() && !klayd.getDrawMap() && m_countDraw % 2 == 0)
    {
        if (m_frightened) klayd.draw(LIGHTBLUE);
        else klayd.draw(YELLOW);
        Map::volna();
        klayd.logic(pac.X_Pac, pac.Y_Pac);
        klayd.setDrawMap(true);
    }
    else cout << " ";
}

void Map::volna()
{
    if (m_countDraw <= 70)
    {
        blinki.setMode(1);
        pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);
    }
    else if (m_countDraw <= 270)
    {
        blinki.setMode(2);
        pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);
    }
    else if (m_countDraw <= 340)
    {
        blinki.setMode(1);
        pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);
    }
    else if (m_countDraw <= 540)
    {
        blinki.setMode(2);
        pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);
    }
    else if (m_countDraw <= 590)
    {
        blinki.setMode(1);
        pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);
    }
    else if (m_countDraw <= 790)
    {
        blinki.setMode(2);
        pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);
    }
    else if (m_countDraw <= 840)
    {
        blinki.setMode(1);
        pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);
    }
    else
    {
        blinki.setMode(2);
        pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);
    }

    if (m_frightened && m_countFrightened!=100)
    {
        blinki.setMode(3);
        pinki.setMode(3);
        inki.setMode(3);
        klayd.setMode(3);
    }
}

void Map::setGameOver(bool gameOver) { m_gameOver = gameOver; }
bool Map::getGameOver() const { return m_gameOver; }