#ifndef TIMER_H
#define TIMER_H
class Timer
{
public:
    Timer();
    ~Timer();
    void startTimer();
    void timerReset();
    int getTime() const;

private:
    int m_hour, m_min, m_sec;
    
};

#endif