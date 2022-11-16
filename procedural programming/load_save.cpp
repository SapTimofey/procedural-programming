#include <iostream>    //Для cin/cout
#include <fstream>     //Для файла
#include <windows.h>   //Для ввода/вывода русским
#include <string>      //Для перевода string -> int/float
#include <stdlib.h>    //Для exit
#include "Settings.h"  //Модуль настроек
#include "Chek.h"      //Модуль проверки
#include <conio.h>     //Для считывания клавиш
#include <list>        

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

list <string> error_load;

// 1 - частичная загрузка сохранения
// 2 - ошибка загрузки сохранения
// 3 - успешная загрузка
// 4 - не удалось открыть файл сохранения

int load_save()
{
    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;
    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string* KeyUC = &KeyUpChar;
    string* KeyDC = &KeyDownChar;
    string* KeyExC = &KeyExitChar;
    string* KeyEnC = &KeyEnterChar;

    string set;
    int i = 0;
    int chek = 0;
    bool flag = true;
    bool KeyEnF = true, KeyExF = true, KeyUF = true, KeyDF = true;
    ifstream fin("Save.txt");

    if (!fin.is_open()) return 4;
    else
    {
        for (i; i < 20; i++)
        {
            fin >> set;
            switch (i)
            {
            case 0:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("TextColor");
                        break;
                    }
                if (flag) *ColorText = stoi(set);
                else flag = true;
                break;
            }
            case 2:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("TextBackgroundColor");
                        break;
                    }
                if (flag) *ColorBackground = stoi(set);
                else flag = true;
                break;
            }
            case 4:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyExit");
                        KeyExF = false;
                        break;
                    }
                if (flag) *KeyEx = stoi(set);
                else flag = true;
                break;
            }
            case 6:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyEnter");
                        KeyEnF = false;
                        break;
                    }
                if (flag) *KeyEn = stoi(set);
                else flag = true;
                break;
            }
            case 8:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyUp");
                        KeyUF = false;
                        break;
                    }
                if (flag) *KeyU = stoi(set);
                else flag = true;
                break;
            }
            case 10:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyDown");
                        KeyDF = false;
                        break;
                    }
                if (flag) *KeyD = stoi(set);
                else flag = true;
                break;
            }
            case 12:
            {
                if (set.length() != 1 && set != "Enter"
                    && set != "Backspace"
                    && set != "Space"
                    && set != "ESC"
                    && set != "Up"
                    && set != "Down"
                    && set != "Left"
                    && set != "Right")
                {
                    chek += 1;
                    flag = false;
                    error_load.push_back("KeyExitChar");
                    KeyExF = false;
                }
                if (flag) *KeyExC = set;
                else flag = true;
                break;
            }
            case 14:
            {
                if (set.length() != 1 && set != "Enter"
                    && set != "Backspace"
                    && set != "Space"
                    && set != "ESC"
                    && set != "Up"
                    && set != "Down"
                    && set != "Left"
                    && set != "Right")
                {
                    chek += 1;
                    flag = false;
                    error_load.push_back("KeyEnterChar");
                    KeyEnF = false;
                }
                if (flag) *KeyEnC = set;
                else flag = true;
                break;
            }
            case 16:
            {
                if (set.length() != 1 && set != "Enter"
                    && set != "Backspace"
                    && set != "Space"
                    && set != "ESC"
                    && set != "Up"
                    && set != "Down"
                    && set != "Left"
                    && set != "Right")
                {
                    chek += 1;
                    flag = false;
                    error_load.push_back("KeyUpChar");
                    KeyUF = false;
                }
                if (flag) *KeyUC = set;
                else flag = true;
                break;
            }
            case 18:
            {
                if (set.length() != 1 && set != "Enter"
                    && set != "Backspace"
                    && set != "Space"
                    && set != "ESC"
                    && set != "Up"
                    && set != "Down"
                    && set != "Left"
                    && set != "Right")
                {
                    chek += 1;
                    flag = false;
                    error_load.push_back("KeyDownChar");
                    KeyDF = false;
                }
                if (flag) *KeyDC = set;
                else flag = true;
                break;
            }
            }
        }
    }

    if (!KeyExF)
    {
        *KeyEx = 27;
        *KeyExC = "ESC";
    }
    if (!KeyEnF)
    {
        *KeyEn = 13;
        *KeyEnC = "Enter";
    }
    if (!KeyUF)
    {
        *KeyU = 301;
        *KeyUC = "Up";
    }
    if (!KeyDF)
    {
        *KeyD = 13;
        *KeyDC = "Down";
    }

    fin.close();
    if (chek == 10) return 2;
    else if (chek < 10 && chek > 0) return 1;
    else return 3;
}