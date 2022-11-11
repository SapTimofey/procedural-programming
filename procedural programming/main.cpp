#include <iostream>    //Для cin/cout
#include <fstream>     //Для файла
#include <windows.h>   //Для ввода/вывода русским
#include <string>      //Для перевода string -> int/float
#include <stdlib.h>    //Для exit
#include "HomeWork1.h" //Модуль Д/з 1
#include "HomeWork2.h" //Модуль Д/з 2
#include "HomeWork3.h" //Модуль Д/з 3
#include "HomeWork4.h" //Модуль Д/з 4
#include "HomeWork5.h" //Модуль Д/з 4
#include "Settings.h"  //Модуль настроек
#include "Chek.h"      //Модуль проверки
#include <conio.h>     //Для считывания клавиш

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;

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
    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;
    string set;

    ifstream fin("Color_setting.txt");
    fin >> set;
    if (stoi(set) != *ColorText) *ColorText = stoi(set);
    if (set.length() == 2) fin.seekg(14);
    else fin.seekg(13);
    fin >> set;
    if (stoi(set) != *ColorBackground) *ColorBackground = stoi(set);
    fin.close();

    const int volume = 6;
    string cons_out[volume] = {"Д/з 1", "Д/з 2", "Д/з 3", "Д/з 4", "Д/з 5", "Настройки"};

    while (true)
    {
        int num = 0;
        do
        {
            system_cls();
            cout << "Используйте:\n- стрелки вверх, вниз - для передвижения\n- enter - для выбора\n- escape - для выхода\n----------Выбор Д/з------------" << endl;
            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    cout << cons_out[i];
                    setColor(TextColor, TextBackgroundColor);
                    cout << endl;
                }
                else cout << cons_out[i] << endl;
            }

            key = static_cast<int>(_getch());

            if (key == 80 && num < volume - 1) num++;
            if (key == 72 && num > 0) num--;
            if (key == 27)
            {
                cout << "Вы завершили работу.\n";
                exit(EXIT_SUCCESS);
            }
        } while (key != 13);
        switch (num + 1)
        {
        case 1:
            menu_HW1(); // Д/з 1
            break;
        case 2:
            menu_HW2(); // Д/з 2
            break;
        case 3:
            menu_HW3(); // Д/з 3
            break;
        case 4:
            menu_HW4(); // Д/з 4
            break;
        case 5:
            menu_HW5(); // Д/з 5
            break;
        case 6:
            Settings();
            break;
        }
    }
}
