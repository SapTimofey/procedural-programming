#include <iostream> //Для case2
#include <locale>   //Для вывода русским
#include <windows.h>//Для ввода русским
#include <cmath>    //Для вычисления уравнений
#include <string>   //Для перевода string -> int/float
#include "Chek.h"   //Модуль провкрки

using namespace std;

// Д/з 2

//Задание "Конус"
void cone()
{
    system("cls");
    string R_test, h_test, r_test, i = "no";
    float R = 0, h = 0, r = 0;
    double l;
    bool R_TF, h_TF, r_TF;
    const double PI = 3.141592653589793;

    cout << "Задание 'Конус'\n";
    
    //Модуль проверки корректности ввода R
    do
    {
        cout << "Введите значение для нижнего радиуса R: ";
        cin >> R_test;
        R_TF = chek(R_test, false);
        if (R_TF)
        {
            R = stof(R_test);
            if (R <= 0)
            {
                cout << "R должна быть больше 0.\n";
                R_TF = false;
            }
        }
    } while (R_TF == false);

    //Модуль проверки корректности ввода r
    do
    {
        cout << "Введите значение для верхнего радиуса r: ";
        cin >> r_test;
        r_TF = chek(r_test, false);
        if (r_TF)
        {
            r = stof(r_test);
            if (r <= 0)
            {
                cout << "r должна быть больше 0.\n";
                r_TF = false;
            }
        }
    } while (r_TF == false);

    //Модуль проверки корректности ввода h
    do
    {
        cout << "Введите значение для высоты h: ";
        cin >> h_test;
        h_TF = chek(h_test, false);
        if (h_TF)
        {
            h = stof(h_test);
            if (h <= 0)
            {
                cout << "h должна быть больше 0.\n";
                h_TF = false;
            }
        }
    } while (h_TF == false);

    l = sqrt(pow(h, 2) + pow((R - r), 2)); //Расчёт длины образующей

    cout << "Объём V = " << 1. / 3 * PI * h * (pow(R, 2) + R * r + pow(r, 2)) << endl << "Площадь S = " << PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    
    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Разветвление"
void branching()
{
    system("cls");
    string i = "no";
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

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Функция"
void function()
{
    system("cls");
    string i = "no";
    float x = 0, y = 0, b = 0;


    cout << "Задание 'Функция'\n";

    cout << "Введите значения для переменных x, y, b: ";
    cin >> x >> y >> b;


    if (b - y > 0 && b - x >= 0) cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    else if (b - y <= 0) cout << "b-y должна быть больше 0.\n";
    else cout << "b-x должна быть больше, либо равна 0.\n";

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");

}

//Задание "Порядок"
void sequence()
{

    system("cls");
    string N_test, i = "no";
    int N, g;
    bool N_TF;

    cout << "Задание 'Порядок'\n";
    
    //Модуль проверки корректности ввода N
    do
    {
        cout << "Введите число N: ";
        cin >> N_test;
        N_TF = chek(N_test, false);
        if (N_TF) N = stoi(N_test);
    } while (N_TF == false);

    cout << "Последовательность из 10 чисел: " << N - 1;
    for (N, g = 0; g <= 8; N++, g++) cout << ", " << N;

    //Модуль выхода в меню
    do
    {
        cout << endl << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Табуляция"
void tabulation()
{
    system("cls");
    float x;
    string i = "no";

    cout << "Задание 'Табуляция'\n";
    for (x = -4; x <= 4; x += 0.5)
    {
        if (x != 1.0) cout << "При x равном: " << x << " \t" << " Значение выражения равно: " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        else cout << "При x равном: " << x << " \t" << " Значение выражения неопределено.\n";
    }
    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Главная часть дз 2
int case2()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string hw2;
    bool chek_hw2 = true;
    system("cls");
    while (chek_hw2)
    {
        cout << "Задание 1 'Конус'\n" << "Задание 2 'Разветвление'\n" << "Задание 3 'Функция'\n" << "Задание 4 'Порядок'\n" << "Задание 5 'Табуляция'\n" << "0 вернуться к выбору д/з.\n" << "Введите номер задания: ";
        cin >> hw2;
        if (chek(hw2, true))
        {
            switch (stoi(hw2))
            {
            default:
                system("cls");
                cout << stoi(hw2) << " - нет такого задания.\n";
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
    }
    chek_hw2 = true;
}