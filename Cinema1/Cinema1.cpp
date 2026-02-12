
#include "Menu.h"

int main()
{
    MainMenu();
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1: Start(); break;
    case 2: Help(); break;
    case 3: return 0;
    default: return 0;
    }
}

