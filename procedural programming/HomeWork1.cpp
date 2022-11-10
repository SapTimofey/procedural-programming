#include <iostream>    //Для case1
#include <locale>      //Для вывода русским
#include <cmath>       //Для вычисления уравнений
#include <windows.h>   //Для ввода русским
#include <string>      //Для перевода string -> int/float
#include "Chek.h"      //Модуль проверки
#include "ExitToMenu.h"//Модуль выхода
#include <conio.h>     //Для считывания клавишь
#include "HomeWork4.h" //Модуль Д/з 4

using namespace std;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

//Задание 1 "Имя"
void Name()
{
    system("cls");
    cout << "Задание 'имя'\n" << "Тимофей\n";
    
    ExitToMenu();
}

//Задание 2 "Арифметика"
void arithmetic()
{
    system("cls");
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
    system("cls");
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
    system("cls");
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
    system("cls");
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

//Главная часть дз 1
void case1()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    
    int key = 0;
    bool flag = false;

    string cons_out[5] = {"Задание 1 'Имя'", "Задание 2 'Арифметика'", "Задание 3 'Уравнение'", "Задание 4 'Ещё уравнение'","Задание 5 'Лампа со шторой'" };
    bool chek_hw1 = true;


    system("cls");
    
    /*for (int i = 0; i < 6; i++) cout << cons_out[i] << endl;*/

    while (chek_hw1)
    {
        int num = 0;
        do
        {
            cout << "Используйте:\nстрелки вверх, вниз - для передвижения\nenter - для выбора\nescape - для выхода\n------------------------" << endl;
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
                chek_hw1 = false;
                system("cls");
                cout << "Вы вернулись назад.\n";
                break;
            }
            system("cls");

        } while (key != 13);
        if (chek_hw1)
        {
            switch (num + 1)
            {
                /*default:
                    system("cls");
                    cout << "Нет такого задания.\n";
                    break;*/
            case 1:
                Name();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 2:
                arithmetic();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 3:
                equation();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 4:
                another_equation();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 5:
                lamp();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
                /*case 0:
                    system("cls");
                    cout << "Вы вернулись назад.\n";
                    chek_hw1 = false;*/
            }
        }
    }
    chek_hw1 = true;
}
