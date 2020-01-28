#include "Menu.h"
#include <iostream>
#include <windows.h>
Menu::Menu()
{
}


Menu::~Menu()
{
}


short Menu::ChoiceMenuItemStart(bool error)
{
    using namespace std;
    system("cls");
    int var;
    char ch[1];
    if (error)
    {
        cout << "There isn't menu item, select from 1 to 4" << endl << endl;
    }

    cout << "Select the menu item" << endl;
    cout << "1 - Start a new game" << endl;
    cout << "2 - Continue" << endl;
    cout << "3 - Statistics" << endl;
    cout << "4 - Exit" << endl << endl;
    cout << ">>> ";
    cin >> ch[0];
    var = atoi(ch);
    return var;
}

short Menu::ChoiceMenuItemPause(bool error, bool save)
{
    using namespace std;
    system("cls");
    //setlocale(LC_ALL, "Rus");
    int var;
    char ch[1];
    if (error)
    {
        cout << "There isn't menu item, select from 1 to 3" << endl << endl;
    }
    else if (save)
    {
        cout << "The game saved" << endl << endl;
    }
    cout << "PAUSE" << endl;
    cout << "1 - Continue" << endl;
    cout << "2 - Save the game" << endl;
    cout << "3 - Exit" << endl << endl;
    cout << ">>> ";
    cin >> ch[0];
    var = atoi(ch);
    return var;
}
