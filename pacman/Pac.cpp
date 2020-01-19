#include "pch.h"
#include "Pac.h"
#include "iostream"
#include "Windows.h"

using namespace std;

Pac::Pac()
{
}


Pac::~Pac()
{
}

void Pac::Draw(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 6));
	cout << "P";
}
