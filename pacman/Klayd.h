#ifndef Klayd_h
#define klayd_h

#include "Ghost.h"
class Klayd : public Ghost
{
public:
    Klayd();
    ~Klayd();
    void draw(int color) override;
    void logic(int xPac, int yPac) override;
private:
    const short X = 0;
    const short Y = 21;
};
#endif