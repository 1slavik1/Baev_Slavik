#ifndef GAME_H
#define GAME_H
#include "Map.h"
#include "Menu.h"
#include "Pac.h"
#include "Blinki.h"
#include "Timer.h"
class Game
{
public:
    Game();
    ~Game();
    void StartProg();


private:
    static const short STARTNEWGAME = 1;
    static const short CONTINUE = 2;
    static const short STATISTICS = 3;

    static const short EXIT = 4;
    static const short BACK = 27;
    static const short PAUSE = 27;

    static const short UP_ENG = 119;
    static const short UP_RU = 230;
    static const short UP_ARROW = 72;

    static const short DOWN_ENG = 115;
    static const short DOWN_RU = 235;
    static const short DOWN_ARROW = 80;

    static const short LEFT_ENG = 97;
    static const short LEFT_RU = 228;
    static const short LEFT_ARROW = 75;

    static const short RIGHT_ENG = 100;
    static const short RIGHT_RU = 162;
    static const short RIGHT_ARROW = 77;


    Map map;
    Menu menu;
    Pac pac;
    Blinki blinki;
    Timer timer;

    bool m_gameOver;
    bool m_error;
    bool m_save;
    bool m_stop;
    void StartNewGame();
    void GameDraw();
    void GameSetup();
    void GameInput();
    void GamePause();
    void GameLogic();
    void LogicBlinki();
    void StartTimer();
    void Volna();
};

#endif // GAME_H
