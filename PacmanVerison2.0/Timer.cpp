#include "pch.h"
#include "Timer.h"
#include <chrono>
#include <thread>
#include <iostream>
Timer::Timer()
{
    m_hour = m_min = m_sec = 0;
}

int Timer::m_hour;
int Timer::m_min;
int Timer::m_sec;

Timer::~Timer()
{
}

int Timer::getTime() const
{    
    return m_hour * 3600 + m_min * 60 + m_sec;
}

void Timer::timerReset()
{
    m_hour = m_min = m_sec = 0;
}

void Timer::startTimer()
{
    using namespace std;
    using namespace std::chrono;
    m_sec++;
    if (m_sec == 60) {
        m_sec = 0;
        m_min++;
    }
    if (m_min == 60) {
        m_min = 0;
        m_hour++;
    }
    
    this_thread::sleep_for(0.999s);
    
}

/*void Timer::DrawTime()
{
    draw.setDrawTime();
    std::cout << "Time: " << Timer::getTime();
}*/
