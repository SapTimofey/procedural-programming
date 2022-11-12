#include <iostream>    //Для cin/cout
#include <fstream>     //Для файла
#include <windows.h>   //Для ввода/вывода русским
#include <string>      //Для перевода string -> int/float
#include <stdlib.h>    //Для exit
#include "Settings.h"  //Модуль настроек
#include "Chek.h"      //Модуль проверки
#include <conio.h>     //Для считывания клавиш

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;

// 1 - частичная загрузка сохранения
// 2 - ошибка загрузки сохранения
// 3 - успешная загрузка

int load_save()
{
    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;
    string set;
    int i = 0;
    int cnt = 0;
    int chek = 0;
    bool flag = true;
    ifstream fin("Color_setting.txt");

    for (i; cnt < 2; i ++)
    {
        fin >> set;
        if (i == 0)
        {
            cnt++;
            for (int j = 0; j < set.length(); j++)
                if (isdigit(set[j]) == 0)
                {
                    chek += 1;
                    flag = false;
                    break;
                }
            if (flag) *ColorText = stoi(set);
            else flag = true;
        }
        if (i == 2)
        {
            cnt++;
            for (int j = 0; j < set.length(); j++)
                if (isdigit(set[j]) == 0)
                {
                    chek += 1;
                    flag = false;
                    break;
                }
            if (flag) *ColorBackground = stoi(set);
            else flag = true;
        }
    }

    fin.close();
    if (chek == 2) return 2;
    else if (chek == 1) return 1;
    else return 3;
}