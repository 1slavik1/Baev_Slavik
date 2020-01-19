#ifndef Ghost_h
#define Ghost_h
class Ghost
{

public:
	Ghost();
	virtual ~Ghost();
	
    void setMode(short mode);
    short getMode() const;

    void setX(int x);
    short getX() const;

    void setY(int y);
    short getY() const;

    short getOldX() const;
    short getOldY() const;

    void setFreedom(bool freedom);
    void setStart(bool start);
	
    void setDrawMap(bool draw);
    bool getDrawMap() const;

    inline void writeOldState(int oldX, int oldY);

    virtual short getXRandom();
    virtual short getYRandom();
	
	virtual void draw(int color) = 0;
	virtual void logic(int xPac, int yPac) = 0;

	virtual void chase(int xPac, int yPac);
   

    void funcTunel();
    void upClose(int xPac, int yPac);
    void downClose(int xPac, int yPac);
    void rightClose(int xPac, int yPac);
    void leftClose(int xPac, int yPac);
    void allClose(int xPac, int yPac);
    void upDownClose();
    void leftRightClose();
    void leftDownClose();
    void leftUpClose();
    void rightUpClose();
    void rightDownClose();

private:
    
	short m_mode;
	bool m_start;
	bool m_freedom;
	bool m_drawMap;
	int m_x, m_y;
	int m_oldX, m_oldY;

protected:
    static const short SCATTER = 1;
    static const short CHASE = 2;
    static const short FRIGHTENED = 3;
    
};

#endif

