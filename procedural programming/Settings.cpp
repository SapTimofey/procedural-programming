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

int get_key();

enum ascii_codes
{
    /*ascii_Home = 71,
    ascii_End = 79,*/
    ascii_Right = 77,
    ascii_Left = 75,
    ascii_Up = 72,
    ascii_Down = 80,
    /*ascii_F1 = 59,*/
    //ascii_F2, // дальше +1
    //ascii_F3,
    //ascii_F4,
    //ascii_F5,
    //ascii_F6,
    //ascii_F7,
    //ascii_F8,
    //ascii_F9,
    //ascii_F10,
    //ascii_F11
};

enum class keyboard : unsigned short
{
    /*enter = 13,
    escape = 27,
    space = 32,
    bspace = 8,
    tab = 9,
    del = 83,*/
    left = 300, // для спец символов сами придумываем значения > 255 (для char)
    up = 301,
    right = 302,
    down = 303,
    /*cup,
    home,
    end,
    f1,
    f2,
    f3,
    f4,
    f5,
    f6,
    f7,
    f8,
    f9,
    f10,
    f11*/
};

int TextColor = 15;
int TextBackgroundColor = 0;
int KeyExit = 27;
int KeyEnter = 13;
int KeyUp = 301;
int KeyDown = 303;

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

    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string* KeyUC = &KeyUpChar;
    string* KeyDC = &KeyDownChar;
    string* KeyExC = &KeyExitChar;
    string* KeyEnC = &KeyEnterChar;

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
        cout << "Используйте:\n- " << *KeyUC << ", " << *KeyDC << " - для передвижения\n- " << *KeyEnC << " - для выбора\n- " << *KeyExC << " - для выхода\n";
        if (type == 1) cout << "--------Выбор цвета текста-------- - " << endl;
        else cout << "------Выбор цвета фона текста------ - " << endl;
        
        for (int i = 0; i < 16; i++)
        {
            if (i == num)
            {
                setColor(TextBackgroundColor, TextColor);
                if (i == *ColorText && type == 1 || i == *ColorBackground && type == 2) cout << cons_out[i] << " - выбран.";
                else if (key == *KeyEn)
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

        key = get_key();
        if (key == *KeyD && num < 16 - 1) num++;
        if (key == *KeyU && num > 0) num--;
        if (key == *KeyEx)
        {
            system_cls();
            return;
        }
    } while (flag);

    if (type == 1) *ColorText = num;
    if (type == 2) *ColorBackground = num;

    ofstream fout("Color_setting.txt");

    fout << *ColorText << "  \tTextColor" <<
        endl << *ColorBackground << "   \tTextBackgroundColor" <<
        endl << *KeyEx << "  \tKeyExit" <<
        endl << *KeyEn << "  \tKeyEnter" <<
        endl << *KeyU << "  \tKeyUp" <<
        endl << *KeyD << "  \tKeyDown" <<
        endl << *KeyExC << "  \tKeyExitChar" <<
        endl << *KeyEnC << "\tKeyEnterChar" <<
        endl << *KeyUC << "  \tKeyUpChar" <<
        endl << *KeyDC << "\tKeyDownChar";

    fout.close();
}

int get_key()
{
    auto key = _getch(); // считываем
    if (_kbhit())        // проверяем есть ли в очереди еще символы
    {                    // если есть - значит нажата спец.клавиша
        key = _getch();  // считываем следующий символ
        // хардкодим
        switch (key)
        {
        case ascii_Left: return static_cast<int>(keyboard::left);
        case ascii_Up: return static_cast<int>(keyboard::up);
        case ascii_Right: return static_cast<int>(keyboard::right);
        case ascii_Down: return static_cast<int>(keyboard::down);
            // далее по аналогии
            // ...
        }
    }
    return key;
}

void Key(int type)
{
    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string* KeyUC = &KeyUpChar;
    string* KeyDC = &KeyDownChar;
    string* KeyExC = &KeyExitChar;
    string* KeyEnC = &KeyEnterChar;

    string key;

    if (type == 0)
    {
        if (*KeyEn == 13) *KeyEnC = "Enter";
        else if (*KeyEn == 8) *KeyEnC = "Backspace";
        else if (*KeyEn == 32) *KeyEnC = "Space";
        else if (*KeyEn == 27) *KeyEnC = "ESC";
        else if (*KeyEn == 301) *KeyEnC = "Up";
        else if (*KeyEn == 303) *KeyEnC = "Down";
        else if (*KeyEn == 300) *KeyEnC = "Left";
        else if (*KeyEn == 302) *KeyEnC = "Right";
        else *KeyEnC = (char)*KeyEn;
    }
    if (type == 1)
    {
        if (*KeyEn == 13) *KeyExC = "Enter";
        else if (*KeyEx == 8) *KeyExC = "Backspace";
        else if (*KeyEx == 32) *KeyExC = "Space";
        else if (*KeyEx == 27) *KeyExC = "ESC";
        else if (*KeyEx == 301) *KeyExC = "Up";
        else if (*KeyEx == 303) *KeyExC = "Down";
        else if (*KeyEx == 300) *KeyExC = "Left";
        else if (*KeyEx == 302) *KeyExC = "Right";
        else *KeyExC = (char)*KeyEx;
    }if (type == 2)
    {
        if (*KeyEn == 13) *KeyEnC = "Enter";
        else if (*KeyU == 8) *KeyUC = "Backspace";
        else if (*KeyU == 32) *KeyUC = "Space";
        else if (*KeyU == 27) *KeyUC = "ESC";
        else if (*KeyU == 301) *KeyUC = "Up";
        else if (*KeyU == 303) *KeyUC = "Down";
        else if (*KeyU == 300) *KeyUC = "Left";
        else if (*KeyU == 302) *KeyUC = "Right";
        else *KeyUC = (char)*KeyU;
    }if (type == 3)
    {
        if (*KeyD == 13) *KeyDC = "Enter";
        else if (*KeyD == 8) *KeyDC = "Backspace";
        else if (*KeyD == 32) *KeyDC = "Space";
        else if (*KeyD == 27) *KeyDC = "ESC";
        else if (*KeyD == 301) *KeyDC = "Up";
        else if (*KeyD == 303) *KeyDC = "Down";
        else if (*KeyD == 300) *KeyDC = "Left";
        else if (*KeyD == 302) *KeyDC = "Right";
        else *KeyDC = (char)*KeyD;
    }
}

void Key_set()
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

    int key = 0;
    const int volume = 4;
    string cons_out[volume] = { "Ввод - ", "Выход - ", "Вверх - ", "Вниз - " };
    int num = 0;
    while (true)
    {
        
        do
        {
            system_cls();
            cout << "Используйте:\n- " << *KeyUC << ", " << *KeyDC << " - для передвижения\n- " << *KeyEnC << " - для выбора\n- " << *KeyExC << " - для выхода\n-------Меню назначения клавишь--------" << endl;
            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    if (i == 0) cout << cons_out[i] << *KeyEnC;
                    else if (i == 1) cout << cons_out[i] << *KeyExC;
                    else if (i == 2) cout << cons_out[i] << *KeyUC;
                    else if (i == 3) cout << cons_out[i] << *KeyDC;
                    setColor(TextColor, TextBackgroundColor);
                    cout << endl;
                }
                else
                {
                    if (i == 0) cout << cons_out[i] << *KeyEnC << endl;
                    else if (i == 1) cout << cons_out[i] << *KeyExC << endl;
                    else if (i == 2) cout << cons_out[i] << *KeyUC << endl;
                    else if (i == 3) cout << cons_out[i] << *KeyDC << endl;
                }
            }
            key = get_key();
            if (key == *KeyD && num < volume - 1) num++;
            if (key == *KeyU && num > 0) num--;
            if (key == *KeyEx)
            {
                system_cls();
                return;
            }


        } while (key != *KeyEn);


        system_cls();
        cout << "Используйте:\n- " << *KeyUC << ", " << *KeyDC << " - для передвижения\n- " << *KeyEnC << " - для выбора\n- " << *KeyExC << " - для выхода\n-------Меню назначения клавишь--------" << endl;
        for (int i = 0; i < volume; i++)
        {
            if (i == num)
            {
                setColor(TextBackgroundColor, TextColor);
                cout << cons_out[i];
                setColor(TextColor, TextBackgroundColor);
                cout << endl;
            }
            else
            {
                if (i == 0) cout << cons_out[i] << *KeyEnC << endl;
                else if (i == 1) cout << cons_out[i] << *KeyExC << endl;
                else if (i == 2) cout << cons_out[i] << *KeyUC << endl;
                else if (i == 3) cout << cons_out[i] << *KeyDC << endl;
            }
        }
        key = get_key();
        if (num == 0) *KeyEn = key;
        else if (num == 1) *KeyEx = key;
        else if (num == 2) *KeyU = key;
        else if (num == 3) *KeyD = key;
        Key(num);

        ofstream fout("Color_setting.txt");

        fout << *ColorText << "  \tTextColor" <<
            endl << *ColorBackground << "   \tTextBackgroundColor" <<
            endl << *KeyEx << "  \tKeyExit" <<
            endl << *KeyEn << "  \tKeyEnter" <<
            endl << *KeyU << "  \tKeyUp" <<
            endl << *KeyD << "  \tKeyDown" <<
            endl << *KeyExC << "  \tKeyExitChar" <<
            endl << *KeyEnC << "\tKeyEnterChar" <<
            endl << *KeyUC << "  \tKeyUpChar" <<
            endl << *KeyDC << "\tKeyDownChar";

        fout.close();
    }
}

void Settings()
{
    int key = 0;
    const int volume = 4;
    string cons_out[volume] = {"Цвет текста", "Цвет фона текста", "Назначение клавиш", "Сброс настроек"};

    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string* KeyUC = &KeyUpChar;
    string* KeyDC = &KeyDownChar;
    string* KeyExC = &KeyExitChar;
    string* KeyEnC = &KeyEnterChar;

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();
            cout << "Используйте:\n- " << *KeyUC << ", " << *KeyDC << " - для передвижения\n- " << *KeyEnC << " - для выбора\n- " << *KeyExC << " - для выхода\n--------Меню настроек---------" << endl;
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
            key = get_key();
            if (key == *KeyD && num < volume - 1) num++;
            if (key == *KeyU && num > 0) num--;
            if (key == *KeyEx)
            {
                system_cls();
                return;
            }
            

        } while (key != *KeyEn);
        switch (num + 1)
        {
        case 1:
            Color_set(1);
            break;
        case 2:
            Color_set(2);
            break;
        case 3:
            Key_set();
            break;
        case 4:
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

            *ColorText = 15;
            *ColorBackground = 0;

            *KeyU = 301;
            *KeyD = 303;
            *KeyEx = 27;
            *KeyEn = 13;

            *KeyUC = "Up";
            *KeyDC = "Down";
            *KeyExC = "ESC";
            *KeyEnC = "Enter";

            int KeyExit = 27;
            int KeyEnter = 13;
            int KeyUp = 301;
            int KeyDown = 303;

            string KeyExitChar = "ESC";
            string KeyEnterChar = "Enter";
            string KeyUpChar = "Up";
            string KeyDownChar = "Down";

            ofstream fout("Color_setting.txt");

            fout << 15 << "  \tTextColor" <<
                endl << 0 << "   \tTextBackgroundColor" <<
                endl << 27 << "  \tKeyExit" <<
                endl << 13 << "  \tKeyEnter" <<
                endl << 301 << "  \tKeyUp" <<
                endl << 303 << "  \tKeyDown" <<
                endl << "ESC" << "  \tKeyExitChar" <<
                endl << "Enter" << "\tKeyEnterChar" <<
                endl << "Up" << "  \tKeyUpChar" <<
                endl << "Down" << "\tKeyDownChar";
            
            fout.close();
        }
    }
}