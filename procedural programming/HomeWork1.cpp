#include <iostream>    //Для case1
#include <locale>      //Для вывода русским
#include <cmath>       //Для вычисления уравнений
#include <windows.h>   //Для ввода русским
#include <string>      //Для перевода string -> int/float
#include "Chek.h"      //Модуль проверки
#include "ExitToMenu.h"//Модуль выхода

using namespace std;

// Д/з 1

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
int case1()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string cons_out = "Задание 1 'Имя'\nЗадание 2 'Арифметика'\nЗадание 3 'Уравнение'\nЗадание 4 'Ещё уравнение'\nЗадание 5 'Лампа со шторой'\n0 вернуться к выбору д/з.\nВведите номер задания: ";
    bool chek_hw1 = true;
    system("cls");
    while (chek_hw1)
    {
        switch ((int)chek(3, cons_out, true))
        {
        default:
            system("cls");
            cout << "Нет такого задания.\n";
            break;
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
        case 0:
            system("cls");
            cout << "Вы вернулись назад.\n";
            chek_hw1 = false;
        }
    }
    chek_hw1 = true;
}
