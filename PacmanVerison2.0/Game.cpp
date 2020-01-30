#include "pch.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <thread>
//#include <chrono>
Game::Game()
{
    m_stop = false;
}


Game::~Game()
{
}

void Game::StartProg()
{
    bool error = false;
    while (true)
    {
        switch (menu.ChoiceMenuItemStart(error))
        {
            error = false;

        case STARTNEWGAME:
            StartNewGame();
            break;

        case CONTINUE:
            //ContinueGame(map);
            break;

        case STATISTICS:
            //OutputStat();
            break;

        case EXIT:
            system("cls");
            std::cout << "Exit..." << std::endl;
            exit(0);

        default:
            error = true;
            break;
        }
    }

}

void Game::StartNewGame()
{

    GameSetup();
    std::thread th(&Game::LogicBlinki,this);
    th.detach();
    while (!m_gameOver)
    {

        GameInput();
        GameLogic();

    }
}

void Game::GameSetup()
{
    m_gameOver = false;
    m_error = false;
    m_save = false;

    map.DrawMap();
    std::cout << "\nScore = " << pac.getScore() << std::endl;

    pac.DrawPlayer(pac.YELLOW, pac.NAME, pac.XSTARTPAC, pac.YSTARTPAC);
    pac.dir = pac.STOP;
    pac.x = pac.XSTARTPAC;
    pac.y = pac.YSTARTPAC;

    blinki.DrawPlayer(blinki.RED, blinki.NAME, blinki.XSTARTBLINKI, blinki.YSTARTBLINKI);
    blinki.setX(blinki.XSTARTBLINKI);
    blinki.setY(blinki.YSTARTBLINKI);

}

void Game::GameDraw()
{

    map.DrawMap();
    std::cout << "\nScore = " << pac.getScore() << std::endl;
    pac.DrawPlayer(pac.YELLOW, pac.NAME, pac.x, pac.y);
    blinki.DrawPlayer(blinki.RED, blinki.NAME, blinki.getX(), blinki.getY());
}

void Game::GameInput()
{
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
            GamePause();
            break;
        default:
            break;
        }
    }
}

void Game::GamePause()
{
    using namespace std;
    m_stop = true;
    do
    {
        int var = menu.ChoiceMenuItemPause(m_error, m_save);
        m_error = false;
        m_save = false;
        if (var == 1)
        {
            m_stop = false;
            GameDraw();
            break;
        }
        else if (var == 2)
        {
            /*ofstream out("save.txt");
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
            out.close();*/
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


void Game::GameLogic()
{

    if (pac.dir == pac.UP) pac.MoveUp();
    else if (pac.dir == pac.DOWN) pac.MoveDown();
    else if (pac.dir == pac.LEFT) pac.MoveLeft();
    else if (pac.dir == pac.RIGHT) pac.MoveRight();



    if (pac.x == 49 - 1) pac.x = 1;
    else if (pac.x == 0) pac.x = 49 - 2;


}

void Game::LogicBlinki()
{
    while (true)
    {
        if (!m_stop) blinki.Logic(pac.x, pac.y);

    }

}
