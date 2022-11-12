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
#include "Chek.h"      //Модуль проверки
#include <conio.h>     //Для считывания клавиш

// Чёрный - 0
// Синий - 1
// Зелёный - 2
// Голубой - 3
// Красный - 4
// Пурпурный - 5
// Коричневый - 6
// Светло-серый - 7
// Тёмно-серый - 8
// Светло-синий - 9
// Светло-зелёный - 10
// Светло-голубой - 11
// Светло-красный - 12
// Светло-пурпурный - 13
// Жёлтый - 14
// Белый - 15

using namespace std;

int TextColor = 15;
int TextBackgroundColor = 0;

void system_cls()
{
    setColor(15, 0);
    system("cls");
    setColor(TextColor, TextBackgroundColor);
}

void Color_set(int type)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;

    bool flag = true;
    int key = 0;

    string cons_out[16] = { 
         "Чёрный",
         "Синий",
         "Зелёный",
         "Голубой",
         "Красный",
         "Пурпурный",
         "Коричневый",
         "Светло-серый",
         "Тёмно-серый",
         "Светло-синий",
         "Светло-зелёный",
         "Светло-голубой",
         "Светло-красный",
         "Светло-пурпурный",
         "Жёлтый",
         "Белый" };

    int num = 0;
    do
    {
        system_cls();
        if (type == 1) cout << "Используйте:\n- стрелки вверх, вниз - для передвижения\n- enter - для выбора\n- escape - для выхода\n--------Выбор цвета текста---------" << endl;
        else cout << "Используйте:\n- стрелки вверх, вниз - для передвижения\n- enter - для выбора\n- escape - для выхода\n------Выбор цвета фона текста-------" << endl;
        
        for (int i = 0; i < 16; i++)
        {
            if (i == num)
            {
                setColor(TextBackgroundColor, TextColor);
                if (key == 13)
                {
                    if (type == 1 && *ColorBackground == num || type == 2 && *ColorText == num) cout << cons_out[i] << " - Нельзя использовать одинаковые цвета для текста и фона.";
                    else
                    {
                        flag = false;
                    }
                }
                else cout << cons_out[i];
                setColor(TextColor, TextBackgroundColor);
                cout << endl;
            }
            else cout << cons_out[i] << endl;
        }
        if (flag == false) break;
        key = static_cast<int>(_getch());
        
        if (key == 80 && num < 15) num++;
        if (key == 72 && num > 0) num--;
    } while (flag);

    if (type == 1) *ColorText = num;
    if (type == 2) *ColorBackground = num;

    ofstream fout("Color_setting.txt");
    fout << *ColorText << " TextColor" <<
    endl << *ColorBackground << " TextBackgroundColor";
    fout.close();

    system_cls();
}

void Settings()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int key = 0;
    const int volume = 3;
    string cons_out[volume] = {"Цвет текста", "Цвет фона текста", "Сброс настроек"};

    while (true)
    {
        int num = 0;
        do
        {
            system_cls();
            cout << "Используйте:\n- стрелки вверх, вниз - для передвижения\n- enter - для выбора\n- escape - для выхода\n--------Меню настроек---------" << endl;
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
                system_cls();
                cout << "Вы вернулись назад.\n";
                return;
            }
            

        } while (key != 13);
        switch (num + 1)
        {
        case 1:
            Color_set(1);
            break;
        case 2:
            Color_set(2);
            break;
        case 3:
            int* ColorText = &TextColor;
            int* ColorBackground = &TextBackgroundColor;
            *ColorText = 15;
            *ColorBackground = 0;
            ofstream fout("Color_setting.txt");
            fout << 15 << " TextColor" <<
            endl << 0 << " TextBackgroundColor";
            fout.close();
        }
    }
}