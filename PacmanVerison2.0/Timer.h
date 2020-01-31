#ifndef TIMER_H
#define TIMER_H
//#include "Draw.h"
class Timer
{
public:
    Timer();
    ~Timer();
   void startTimer();
   void timerReset();
   int getTime() const; 
  // void DrawTime();

private:
   static int m_hour, m_min, m_sec;
   //Draw draw;
};

#endif