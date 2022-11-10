#include <iostream>    //Для cin/cout
#include <windows.h>   //Для ввода/вывода русским
#include <string>      //Для перевода string -> int/float
#include <stdlib.h>    //Для exit
#include "HomeWork1.h" //Модуль Д/з 1
#include "HomeWork2.h" //Модуль Д/з 2
#include "HomeWork3.h" //Модуль Д/з 3
#include "HomeWork4.h" //Модуль Д/з 4
#include "HomeWork5.h" //Модуль Д/з 4
#include "Chek.h"      //Модуль проверки
#include <conio.h>     //Для считывания клавиш

using namespace std;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

//Главная часть
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int key = 0;

    string cons_out[5] = {"Д/з 1", "Д/з 2", "Д/з 3", "Д/з 4", "Д/з 5"};

    while (true)
    {
        int num = 0;
        do
        {
            cout << "Используйте:\nстрелки вверх, вниз - для передвижения\nenter - для выбора\nescape - для выхода\n----------Выбор Д/з------------" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (i == num)
                {
                    setColor(Black, LightGray);
                    cout << cons_out[i];
                    setColor(LightGray, Black);
                    cout << endl;
                }
                else cout << cons_out[i] << endl;
            }

            key = static_cast<int>(_getch());
            if (key == 80 && num < 4) num++;
            if (key == 72 && num > 0) num--;
            if (key == 27)
            {
                cout << "Вы завершили работу.\n";
                exit(EXIT_SUCCESS);
            }
            system("cls");

        } while (key != 13);
        switch (num + 1)
        {
        case 1:
            menu_HW1(); //Д/з 1
            break;
        case 2:
            menu_HW2(); //Д/з 2
            break;
        case 3:
            menu_HW3(); //Д/з 3
            break;
        case 4:
            menu_HW4(); //Д/з 4
            break;
        case 5:
            menu_HW5(); //Д/з 5
            break;
        }
    }
}
