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
#include "load_save.h" //Модуль загрузки сохранения
#include <conio.h>     //Для считывания клавиш

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

extern string KeyExitChar;
extern string KeyEnterChar;
extern string KeyUpChar;
extern string KeyDownChar;
int load = 0;

//Главная часть
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string* KeyUC = &KeyUpChar;
    string* KeyDC = &KeyDownChar;
    string* KeyExC = &KeyExitChar;
    string* KeyEnC = &KeyEnterChar;

    int* l = &load;
    int k = 0;
    if (*l == 0) k = load_save();

    int key = 0;

    const int volume = 6;
    string cons_out[volume] = {"Д/з 1", "Д/з 2", "Д/з 3", "Д/з 4", "Д/з 5", "Настройки"};

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();

            cout << "Используйте:\n- " << *KeyUC << ", " << *KeyDC << " - для передвижения\n- " << *KeyEnC << " - для выбора\n- " << *KeyExC << " - для выхода\n----------Выбор Д/з------------" << endl;
            
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

            if (k == 1)
            {
                *l = 5;
                k = 8;
                cout << "------------------------------" << endl;
                cout << "Частичная загрузка сохранения.\n";
                cout << "------------------------------" << endl;
            }
            else if (k == 2)
            {
                *l = 5;
                k = 8;
                cout << "---------------------------" << endl;
                cout << "Ошибка загрузки сохранения.\n";
                cout << "---------------------------" << endl;
            }
            else if (k == 3)
            {
                *l = 5;
                k = 8;
                cout << "-----------------------------" << endl;
                cout << "Успешная загрузка сохранения.\n";
                cout << "-----------------------------" << endl;
            }
            else if (k == 4)
            {
                *l = 5;
                k = 8;
                cout << "-----------------------------------" << endl;
                cout << "Не удалось открыть файл сохранения.\n";
                cout << "-----------------------------------" << endl;
            }

            key = get_key();
            if (key == *KeyD && num < volume - 1) num++;
            if (key == *KeyU && num > 0) num--;
            if (key == *KeyEx)
            {
                cout << "Вы завершили работу.\n";
                exit(EXIT_SUCCESS);
            }
        } while (key != *KeyEn);
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
