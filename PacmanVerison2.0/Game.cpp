#include "pch.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <fstream>
#include <string>
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
            OutputStat();
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
    std::thread threadBlinki(&Game::LogicBlinki,this);
    threadBlinki.detach();
    std::thread threadTimer(&Game::StartTimer, this);
    threadTimer.detach();

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
    pac.setLife(3);
    pac.setScore();
    timer.timerReset();
    map.mapUpdate();
    map.DrawMap();

    std::cout << "\nScore = " << pac.getScore();
    std::cout << "\nLife - " << pac.getLife();
    
    pac.DrawPlayer(pac.XSTARTPAC, pac.YSTARTPAC);
    pac.dir = pac.STOP;
    pac.x = pac.XSTARTPAC;
    pac.y = pac.YSTARTPAC;

    
    blinki.DrawPlayer(blinki.XSTARTBLINKI, blinki.YSTARTBLINKI);
    blinki.setX(blinki.XSTARTBLINKI);
    blinki.setY(blinki.YSTARTBLINKI);

}

void Game::GameDraw()
{

    map.DrawMap();
    std::cout << "\nScore = " << pac.getScore();
    std::cout << "\nLife - " << pac.getLife();
    pac.DrawPlayer(pac.x, pac.y);
    blinki.DrawPlayer(blinki.getX(), blinki.getY());
    
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
            ofstream out("save.txt");
            out << pac.getLife() << endl;
            out << pac.getScore() << endl;
            //out << m_countLevel << endl;
            out << pac.x << " " << pac.y << endl;
            out << blinki.getX() << " " << blinki.getY() << endl;
            out << blinki.getOldX() << " " << blinki.getOldY() << endl;
            /*out << pinki.getX() << " " << pinki.getY() << endl;
            out << pinki.getOldX() << " " << pinki.getOldY() << endl;
            out << inki.getX() << " " << inki.getY() << endl;
            out << inki.getOldX() << " " << inki.getOldY() << endl;
            out << klayd.getX() << " " << klayd.getY() << endl;
            out << klayd.getOldX() << " " << klayd.getOldY() << endl;*/

            for (int i = 0; i < map.getHeight(); i++)
            {
                for (int j = 0; j < map.getWidth(); j++)
                {
                    out << map.getMap(j,i);
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


void Game::GameLogic()
{
    
    if (pac.dir == pac.UP) pac.MoveUp();
    else if (pac.dir == pac.DOWN) pac.MoveDown();
    else if (pac.dir == pac.LEFT) pac.MoveLeft();
    else if (pac.dir == pac.RIGHT) pac.MoveRight();

    if (pac.x == 49 - 1) pac.x = 1;
    else if (pac.x == 0) pac.x = 49 - 2;

    if (pac.getLife() <= 0) 
    {
        using namespace std;
        m_gameOver = true;
        string name;
        system("cls");
        cout << "You got = " << pac.getScore() << " points" << "\nInput your name: ";
        cin.get();
        getline(cin, name);
        ofstream out("stat.txt", ios::app);
        out << name << ": " << pac.getScore() << endl;
        //out << name << endl;
        out.close();
    }
    if (pac.m_frightened && m_count == 0)
    {
        timer.timerReset();
        blinki.m_frightened = true;
        m_count = 1;
    }

    if (pac.m_frightened && timer.getTime() >= 10)
    {
        m_count = 0;
        pac.m_frightened = false;
        blinki.m_frightened = false;
    }
   

}

void Game::Volna()
{
    if (pac.m_frightened && timer.getTime() < 10)
    {
        blinki.setMode(3);
    }
    else if (timer.getTime() <= 7)
    {
        blinki.setMode(1);
        /*pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);*/
    }
    else if (timer.getTime() <= 27)
    {
        blinki.setMode(2);
        /*pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);*/
    }
    else if (timer.getTime() <= 34)
    {
        blinki.setMode(1);
        /*pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);*/
    }
    else if (timer.getTime() <= 54)
    {
        blinki.setMode(2);
        /*pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);*/
    }
    else if (timer.getTime() <= 59)
    {
        blinki.setMode(1);
        /*pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);*/
    }
    else if (timer.getTime() <= 79)
    {
        blinki.setMode(2);
       /* pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);*/
    }
    else if (timer.getTime() <= 84)
    {
        blinki.setMode(1);
        /*pinki.setMode(1);
        inki.setMode(1);
        klayd.setMode(1);*/
    }
    else
    {
        blinki.setMode(2);
        /*pinki.setMode(2);
        inki.setMode(2);
        klayd.setMode(2);*/
    }

    
    /*if (m_frightened && m_countFrightened != 100)
    {
        blinki.setMode(3);
        pinki.setMode(3);
        inki.setMode(3);
        klayd.setMode(3);
    }*/
}

void Game::StartTimer()
{
    while (!m_gameOver)
    {
        if(!m_stop) timer.startTimer();
        //timer.DrawTime();
    }
 
}

void Game::LogicBlinki()
{
    while (!m_gameOver)
    {
        Game::Volna();
        if (!m_stop)
        {
            blinki.Logic(pac.x, pac.y);
            if (pac.x == blinki.getX() && pac.y == blinki.getY())
            {
                if (!blinki.m_frightened)
                {
                    pac.changeLife();
                    pac.DrawLife(pac.getLife());
                }
                if (blinki.m_frightened) pac.changeScore(100);

                blinki.writeOldState(blinki.getX(), blinki.getY());

                blinki.setFreedom(false);
                blinki.setStart(false);

                blinki.setX(blinki.XSTARTBLINKI);
                blinki.setY(blinki.YSTARTBLINKI);
            }
        }
        

    }

}

void Game::ContinueGame()
{

}

void Game::OutputStat()
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

    while (!(_getch() == BACK))
    {

    }


}
