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
int KeyExit = 27;
int KeyEnter = 13;
int KeyUp = 78;
int KeyDown = 80;

string KeyExitChar = "ESC";
string KeyEnterChar = "Enter";
string KeyUpChar = "Up";
string KeyDownChar = "Down";

void system_cls()
{
    setColor(15, 0);
    system("cls");
    setColor(TextColor, TextBackgroundColor);
}

void Color_set(int type)
{
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
                if (i == *ColorText && type == 1 || i == *ColorBackground && type == 2) cout << cons_out[i] << " - выбран.";
                else if (key == 13)
                {
                    if (*ColorBackground == num || *ColorText == num) cout << cons_out[i] << " - Нельзя использовать одинаковые цвета для текста и фона.";
                    else
                    {
                        flag = false;
                    }
                }
                else cout << cons_out[i];
                setColor(TextColor, TextBackgroundColor);
                cout << endl;
            }
            else if (i == *ColorText && type == 1 || i == *ColorBackground && type == 2) cout << cons_out[i] << " - выбран." << endl;
            else cout << cons_out[i] << endl;
        }
        if (flag == false) break;
        key = static_cast<int>(_getch());
        
        if (key == 80 && num < 15) num++;
        if (key == 72 && num > 0) num--;
        if (key == 27)
        {
            system_cls();
            return;
        }
    } while (flag);

    if (type == 1) *ColorText = num;
    if (type == 2) *ColorBackground = num;

    ofstream fout("Color_setting.txt");
    fout << *ColorText << " TextColor" <<
    endl << *ColorBackground << " TextBackgroundColor";
    fout.close();

    system_cls();
}

//void Key(int type)
//{
//    int* KeyU = &KeyUp;
//    int* KeyD = &KeyDown;
//    int* KeyEx = &KeyExit;
//    int* KeyEn = &KeyEnter;
//
//    string* KeyUC = &KeyUpChar;
//    string* KeyDC = &KeyDownChar;
//    string* KeyExC = &KeyExitChar;
//    string* KeyEnC = &KeyEnterChar;
//
//    string key;
//
//    if (type == 0)
//    {
//        if (*KeyEn == 13) *KeyEnC = "Enter";
//        else if (*KeyEn == 8) *KeyEnC = "Backspace";
//        else if (*KeyEn == 32) *KeyEnC = "Space";
//        else if (*KeyEn == 27) *KeyEnC = "Escape";
//        else if (*KeyEn == 78) *KeyEnC = "Up";
//        else if (*KeyEn == 80) *KeyEnC = "Down";
//        else if (*KeyEn == 77) *KeyEnC = "Left";
//        else if (*KeyEn == 79) *KeyEnC = "Right";
//        else *KeyEnC = (char)*KeyEn;
//    }
//    if (type == 1)
//    {
//        if (*KeyEn == 13) *KeyExC = "Enter";
//        else if (*KeyEx == 8) *KeyExC = "Backspace";
//        else if (*KeyEx == 32) *KeyExC = "Space";
//        else if (*KeyEx == 27) *KeyExC = "Escape";
//        else if (*KeyEx == 78) *KeyExC = "Up";
//        else if (*KeyEx == 80) *KeyExC = "Down";
//        else if (*KeyEx == 77) *KeyExC = "Left";
//        else if (*KeyEx == 79) *KeyExC = "Right";
//        else *KeyExC = (char)*KeyEx;
//    }if (type == 2)
//    {
//        if (*KeyEn == 13) *KeyEnC = "Enter";
//        else if (*KeyU == 8) *KeyUC = "Backspace";
//        else if (*KeyU == 32) *KeyUC = "Space";
//        else if (*KeyU == 27) *KeyUC = "Escape";
//        else if (*KeyU == 78) *KeyUC = "Up";
//        else if (*KeyU == 80) *KeyUC = "Down";
//        else if (*KeyU == 77) *KeyUC = "Left";
//        else if (*KeyU == 79) *KeyUC = "Right";
//        else *KeyUC = (char)*KeyU;
//    }if (type == 3)
//    {
//        if (*KeyD == 13) *KeyDC = "Enter";
//        else if (*KeyD == 8) *KeyDC = "Backspace";
//        else if (*KeyD == 32) *KeyDC = "Space";
//        else if (*KeyD == 27) *KeyDC = "Escape";
//        else if (*KeyD == 78) *KeyDC = "Up";
//        else if (*KeyD == 80) *KeyDC = "Down";
//        else if (*KeyD == 77) *KeyDC = "Left";
//        else if (*KeyD == 79) *KeyDC = "Right";
//        else *KeyDC = (char)*KeyD;
//    }
//}

//void Key_set()
//{
//    //while (true)
//    //{
//    //    int* KeyU = &KeyUp;
//    //    char ch = _getch();
//    //    ch = _getch();
//    //    *KeyU = ch;
//    //    
//    //    cout << *KeyU << endl;
//    //    /*cout << k << " " << static_cast<int>(k) << endl;*/
//    //}
//    int* KeyU = &KeyUp;
//    int* KeyD = &KeyDown;
//    int* KeyEx = &KeyExit;
//    int* KeyEn = &KeyEnter;
//
//    string* KeyUC = &KeyUpChar;
//    string* KeyDC = &KeyDownChar;
//    string* KeyExC = &KeyExitChar;
//    string* KeyEnC = &KeyEnterChar;
//
//    int key = 0;
//    const int volume = 4;
//    string cons_out[volume] = { "Ввод - ", "Выход - ", "Вверх - ", "Вниз - " };
//    int num = 0;
//    while (true)
//    {
//        
//        do
//        {
//            system_cls();
//            cout << "Используйте:\n- стрелки вверх, вниз - для передвижения\n- enter - для выбора\n- escape - для выхода\n--------Меню настроек---------" << endl;
//            for (int i = 0; i < volume; i++)
//            {
//                if (i == num)
//                {
//                    setColor(TextBackgroundColor, TextColor);
//                    if (i == 0) cout << cons_out[i] << *KeyEnC;
//                    else if (i == 1) cout << cons_out[i] << *KeyExC;
//                    else if (i == 2) cout << cons_out[i] << *KeyUC;
//                    else if (i == 3) cout << cons_out[i] << *KeyDC;
//                    setColor(TextColor, TextBackgroundColor);
//                    cout << endl;
//                }
//                else
//                {
//                    if (i == 0) cout << cons_out[i] << *KeyEnC << endl;
//                    else if (i == 1) cout << cons_out[i] << *KeyExC << endl;
//                    else if (i == 2) cout << cons_out[i] << *KeyUC << endl;
//                    else if (i == 3) cout << cons_out[i] << *KeyDC << endl;
//                }
//            }
//            key = _getch();
//            key = _getch();
//            if (key == *KeyD && num < volume - 1) num++;
//            if (key == *KeyU && num > 0) num--;
//            if (key == *KeyEx)
//            {
//                system_cls();
//                return;
//            }
//
//
//        } while (key != *KeyEn);
//
//
//        system_cls();
//        cout << "Используйте:\n- стрелки вверх, вниз - для передвижения\n- enter - для выбора\n- escape - для выхода\n--------Меню настроек---------" << endl;
//        for (int i = 0; i < volume; i++)
//        {
//            if (i == num)
//            {
//                setColor(TextBackgroundColor, TextColor);
//                /*if (i == 0) cout << cons_out[i] << *KeyEnC;
//                else if (i == 1) cout << cons_out[i] << *KeyExC;
//                else if (i == 2) cout << cons_out[i] << *KeyUC;
//                else if (i == 3) cout << cons_out[i] << *KeyDC;*/
//                cout << cons_out[i];
//                setColor(TextColor, TextBackgroundColor);
//                cout << endl;
//            }
//            else
//            {
//                if (i == 0) cout << cons_out[i] << *KeyEnC << endl;
//                else if (i == 1) cout << cons_out[i] << *KeyExC << endl;
//                else if (i == 2) cout << cons_out[i] << *KeyUC << endl;
//                else if (i == 3) cout << cons_out[i] << *KeyDC << endl;
//            }
//        }
//        key = _getch();
//        key = _getch();
//        if (num == 0) *KeyEn = key;
//        else if (num == 1) *KeyEx = key;
//        else if (num == 2) *KeyU = key;
//        else if (num == 3) *KeyD = key;
//        Key(num);
//
//
//    }
//}

void Settings()
{
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
        //case 3:
        //    Key_set();
        //    break;
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