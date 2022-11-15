#include <iostream>    //Для case1
#include <locale>      //Для вывода русским
#include <cmath>       //Для вычисления уравнений
#include <windows.h>   //Для ввода русским
#include <string>      //Для перевода string -> int/float
#include "Chek.h"      //Модуль проверки
#include "ExitToMenu.h"//Модуль выхода
#include <conio.h>     //Для считывания клавиш
#include "HomeWork4.h" //Модуль Д/з 4
#include "Settings.h"  //Модуль настроек

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

//Задание 1 "Имя"
void Name()
{
    system_cls();
    cout << "Задание 'имя'\n" << "Тимофей\n";
    
    ExitToMenu();
}

//Задание 2 "Арифметика"
void arithmetic()
{
    system_cls();
    float a = 0, b = 0;

    cout << "Задание 'Арифметика' (Дробные числа писать через запятую.)\n";

    cout << "Введите числа a, b: ";
    cin >> a >> b;

    cout << "a+b=" << a + b << endl << "a-b=" << a - b << endl << "a*b=" << a * b << endl;
    if (b != 0) cout << "a/b=" << a / b << endl;
    else cout << "Делить на ноль нельзя.\n";

    ExitToMenu();
}

//Задание 3 "Уравнение"
void equation()
{
    system_cls();
    float b = 0, c = 0;

    cout << "Задание 'Уравнение'\n";
    
    cout << "Введите значения для переменных b, c: ";
    cin >> b >> c;
    
    if (b == 0 && c == 0) cout << "x может принимать любое значение.\n";
    else if (b == 0) cout << "Нет решения.\n";
    else cout << "x=" << -c / b << endl;

    ExitToMenu();
}

//Задание 4 "Ещё уравнение"
void another_equation()
{
    system_cls();
    float a = 0, b = 0, c = 0;
    double D;

    cout << "Задание 'Ещё уравнение'\n";

    cout << "Введите значения для переменных a, b, c: ";
    cin >> a >> b >> c;
    
    if (a == 0 && b == 0 && c == 0) cout << "x может принимать любое значение.\n";
    else if (a == 0 && c == 0) cout << "Нет решения.\n";
    else if (a == 0) cout << "x=" << -c / b << endl;
    else
    {
        D = pow(b, 2) - 4 * a * c;//Расчёт дискриминанта

        if (D > 0) cout << "x1=" << (-b + sqrt(D)) / (2 * a) << endl << "x2=" << (-b - sqrt(D)) / (2 * a) << endl;
        else if (D == 0) cout << "x=" << -b / (2 * a);
        else cout << "Нет корней среди вещественных чисел.\n";
    }
    
    ExitToMenu();
}

//Задание 5 "Лампа со шторой"
void lamp()
{
    system_cls();
    string day, curtains, lamp, d, c, l;
    bool day1 = false, curtains1 = false, lamp1 = false, res, chek_d = false, chek_c = false, chek_l = false;
    
    cout << "Задание 'Лампа со шторой'\n";
    
    //Модуль проверки корректности ввода day
    do
    {
        cout << "На улице день? (да, нет): ";
        cin >> d;
        if (d == "да" || d == "нет")
        {
            day = d;
            chek_d = true;
        }
        else cout << "Я просил отвечать да или нет.\n";
    } while (chek_d == false);

    //Модуль проверки корректности ввода curtains
    do
    {
        cout << "Шторы раздвинуты? (да, нет): ";
        cin >> c;
        if (c == "да" || c == "нет")
        {
            curtains = c;
            chek_c = true;
        }
        else cout << "Я просил отвечать да или нет.\n";
    } while (chek_c == false);

    //Модуль проверки корректности ввода lamp
    do
    {
        cout << "Свет включён? (да, нет): ";
        cin >> l;
        if (l == "да" || l == "нет")
        {
            lamp = l;
            chek_l = true;
        }
        else cout << "Я просил отвечать да или нет.\n";
    } while (chek_l == false);

    if (day == "да") day1 = true;
    if (curtains == "да") curtains1 = true;
    if (lamp == "да") lamp1 = true;

    res = (day1 and curtains1) or lamp1;

    if (res) cout << "В комнате светло.\n";
    else cout << "В комнате темно.\n";

    ExitToMenu();
}

//Меню дз 1
void menu_HW1()
{
    
    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string* KeyUC = &KeyUpChar;
    string* KeyDC = &KeyDownChar;
    string* KeyExC = &KeyExitChar;
    string* KeyEnC = &KeyEnterChar;

    int key = 0;

    string cons_out[5] = {"Задание 1 'Имя'", "Задание 2 'Арифметика'", "Задание 3 'Уравнение'", "Задание 4 'Ещё уравнение'","Задание 5 'Лампа со шторой'" };

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();
            cout << "Используйте:\n- " << *KeyUC << ", " << *KeyDC << " - для передвижения\n- " << *KeyEnC << " - для выбора\n- " << *KeyExC << " - для выхода\n----------Д/з 1------------" << endl;
            for (int i = 0; i < 5; i++)
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
            if (key == *KeyD && num < 5 - 1) num++;
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
            Name();
            break;
        case 2:
            arithmetic();
            break;
        case 3:
            equation();
            break;
        case 4:
            another_equation();
            break;
        case 5:
            lamp();
            break;
        }
    }
}
