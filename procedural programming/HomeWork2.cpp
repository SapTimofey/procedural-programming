#include <iostream>    //Для case2
#include <locale>      //Для вывода русским
#include <windows.h>   //Для ввода русским
#include <cmath>       //Для вычисления уравнений
#include <string>      //Для перевода string -> int/float
#include "Chek.h"      //Модуль провкрки
#include "ExitToMenu.h"//Модуль выхода

using namespace std;

// Д/з 2

//Задание 1 "Конус"
void cone()
{
    system("cls");
    float R = 0, h = 0, r = 0;
    double l;
    const double PI = 3.141592653589793;

    cout << "Задание 'Конус'\n";
    R = chek(1, "Введите значение для нижнего радиуса R: ", false);

    r = chek(1, "Введите значение для верхнего радиуса r: ", false);

    h = chek(1, "Введите значение для высоты h: ", false);

    l = sqrt(pow(h, 2) + pow((R - r), 2)); //Расчёт длины образующей

    cout << "Объём V = " << 1. / 3 * PI * h * (pow(R, 2) + R * r + pow(r, 2)) << endl << "Площадь S = " << PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    
    ExitToMenu();
}

//Задание 2 "Разветвление"
void branching()
{
    system("cls");
    float x = 0, a = 0;

    cout << "Задание 'Разветвление' (Дробные числа писать через запятую.)\n";
    
    cout << "Введите значения для переменных x, a: ";
    cin >> x >> a;
        

    if (abs(x) < 1 && x != 0) cout << "w = " << a * log(abs(x)) << endl;
    else
    {
        if ((a - pow(x, 2)) >= 0) cout << "w = " << sqrt(a - pow(x, 2)) << endl;
        else cout << "Корень из отрицательного числа невозможен.\n";
    }

    ExitToMenu();
}

//Задание 3 "Функция"
void function()
{
    system("cls");
    float x = 0, y = 0, b = 0;

    cout << "Задание 'Функция'\n" << "Введите значения для переменных x, y, b: ";

    cin >> x >> y >> b;

    if (b - y > 0 && b - x >= 0) cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    else if (b - y <= 0) cout << "b-y должна быть больше 0.\n";
    else cout << "b-x должна быть больше, либо равна 0.\n";

    ExitToMenu();
}

//Задание 4 "Порядок"
void sequence()
{
    system("cls");
    int N, g;

    cout << "Задание 'Порядок'\n";
    N = chek(0, "Введите число N: ", false);

    cout << "Последовательность из 10 чисел: " << N - 1;
    for (N, g = 0; g <= 8; N++, g++) cout << ", " << N;

    ExitToMenu();
}

//Задание 5 "Табуляция"
void tabulation()
{
    system("cls");
    float x;

    cout << "Задание 'Табуляция'\n";
    for (x = -4; x <= 4; x += 0.5)
    {
        if (x != 1.0) cout << "При x равном: " << x << " \t" << " Значение выражения равно: " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        else cout << "При x равном: " << x << " \t" << " Значение выражения неопределено.\n";
    }

    ExitToMenu();
}

//Главная часть дз 2
int case2()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string cons_out = "Задание 1 'Конус'\nЗадание 2 'Разветвление'\nЗадание 3 'Функция'\nЗадание 4 'Порядок'\nЗадание 5 'Табуляция'\n0 вернуться к выбору д/з.\nВведите номер задания: ";
    bool chek_hw2 = true;
    system("cls");
    while (chek_hw2)
    {
        switch ((int)chek(3, cons_out, true))
        {
        default:
            system("cls");
            cout << "Нет такого задания.\n";
            break;
        case 1:
            cone();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 2:
            branching();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 3:
            function();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 4:
            sequence();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 5:
            tabulation();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 0:
            system("cls");
            cout << "Вы вернулись назад.\n";
            chek_hw2 = false;
        }
    }
    chek_hw2 = true;
}