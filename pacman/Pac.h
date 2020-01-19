#ifndef Pac_h
#define Pac_h

class Pac
{
public:
	int X_Pac,Y_Pac;
	int life;
	void Draw(); 
	enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
	eDirection dir;
	Pac();
	~Pac();
};

#endif