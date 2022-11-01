#include <iostream>    //Для case3
#include <locale>      //Для вывода русским
#include <windows.h>   //Для ввода русским
#include <cmath>       //Для вычисления уравнений
#include <fstream>     //Для работы с файлом
#include <string>      //Для перевода string -> int/float, int -> string
#include "Chek.h"      //Модуль провкрки
#include <ctime>       //Для генерации рандомных чисел
#include <algorithm>   //Для сортировки
#include "ExitToMenu.h"//Для выхода

using namespace std;

//Создание файла
void file()
{
    ofstream fout("test_HW.txt");
    fout.close();
}

// Д/з 3

//Задание 1 "Заём"
void loan()
{
    system("cls");
    float S = 0, n = 0, p = 0, r = 0, m = 0, n_chek = 0, n_chek2 = 0;
    cout << "Задание 'Заём'\n";

    S = chek(1, "Введите S: ", false);
    n = chek(1, "Введите n: ", false);
    p = chek(0, "Введите p: ", false);

    n_chek = modf(n, &n_chek2);

    r = p / 100; //Доли
    if (S >= 0 && n > 0 && ((n_chek == 0 && p != -200) || (n_chek != 0 && p >= -100)))
    {
        m = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
        cout << "Ваша месячная выплата составляет " << m << " рублей.\n";
    }
    else if (p == 0)
    {
        m = S / (12 * n);
        cout << "Ваша месячная выплата составляет " << m << " рублей.\n";
    }
    else if (n == 0) cout << "Ваша выплата составляет " << S << " рублей.\n";
    else if (n_chek != 0 && p < -100) cout << "При нецелом n и p меньше -100, уравнение не решается.\n";
    else if (p == -200)
    {
        m = (-1) * S / (12 * n);
        cout << "Ваша месячная выплата составляет " << m << " рублей.\n";
    }
    else cout << "S, n должны быть больше 0.\n";

    ExitToMenu();
}

//Задание 2 "Ссуда"
void loan2()
{
    system("cls");
    float S = 0, n = 0, m = 0, p = 0;
    double r = 0.1, m_chek = 0;

    cout << "Задание 'Ссуда'\n";

    cout << "Введите S, n, m: ";
    cin >> S >> n >> m;
    if (m == S / (n * 12)) cout << "Процент, под который взят заём, равен:  " << 0 << endl;
    else if (S > 0 && n > 0 && m > 0)
    {
        m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));

        if (m > m_chek)
        {
            while (m > m_chek)
            {
                if (m - m_chek > 1)
                {
                    r += 0.1;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
                else
                {
                    r += 0.0001;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
            }
        }
        else if (m < m_chek)
        {
            while (m < m_chek)
            {
                if (m_chek - m > 1)
                {
                    r -= 0.1;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
                else
                {
                    r -= 0.0001;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
            }
        }
        cout << "Процент, под который взят заём, равен:  " << r * 100 << endl;
    }
    else if (S == 0) cout << "Вы не брали кредит.\n";
    else cout << "S должна быть неотрицательной, n, m - больше 0.\n";

    ExitToMenu();
}

//Задание 3 "Копирование файла"
void copying_file()
{
    file();
    system("cls");
    char f_read[100];
    string str;
    ofstream fout;
    int len = 0;
    
    cout << "Задание 'Копирование файла'\n" << "Введите строку для записи в файл: ";
    
    cin >> str;
    //Запись 1 строки в файл
    fout.open("test_HW.txt");
    fout << str << endl;
    fout.close();
    
    //Чтение 1 строки из файла
    ifstream fin("test_HW.txt");
    fin >> f_read;
    fin.close();
    len = str.length();
    cout << "Первая строка: " << f_read << endl;

    //Запись 2 строки в файл
    cout << "Введите 2 строку для записи в файл: ";
    cin >> str;
    fout.open("test_HW.txt", ios::app);
    fout << str;
    fout.close();

    //Чтение 2 строки из файла
    ifstream fin2("test_HW.txt");
    fin2.seekg(len);
    fin2 >> f_read;
    fin2.close();
    cout << "Вторая строка: " << f_read << endl;

    ExitToMenu();
}

//Задание 4 "Фильтр"
void filter()
{
    file();
    system("cls");
    ofstream fout;
    string str_output, str_file, str;
    bool flag = false;
    cout << "Задание 'Фильтр'\n" << "Введите строку: ";
    
    cin >> str;

    //Запись строки в файл
    fout.open("test_HW3.txt");
    fout << str;
    fout.close();
    
    //Чтение строки из файла
    ifstream fin("test_HW3.txt");
    fin >> str_file;
    fin.close();
    
    //Фильтрация строки
    for (int i = 0; i < str.length(); i++)
    {
        do
        {
            if (isdigit(str_file[i]))
            {
                flag = true;
                str_output += str_file[i];
                break;
            }
            else if (flag)
            {
                str_output += " ";
                flag = false;
                break;
            }
            else break;
            
        } while (true);
    }
    cout << "Строка после фильтрации: " << str_output;

    ExitToMenu();
}

//Задание 5 "Сортировка букв"
void sorting_letters()
{
    file();
    system("cls");

    ofstream fout;
    int const SIZE = 30;
    int arr[SIZE]{}, num_ENG = 65, num_eng = 97, num_RUS = -64, num_rus = -32, flag_ENG = 0, flag_RUS = 0, a = 0;
    string str_output, str, str_file;

    cout << "Задание 'Сортировка букв'\n" << "Введите строку: ";

    cin >> str;

    //Запись строки в файл
    fout.open("test_HW.txt");
    fout << str;
    fout.close();

    //Чтение строки из файла
    ifstream fin("test_HW.txt");
    fin >> str_file;
    fin.close();

    //Перевод символа в номер ASCII
    for (int i = 0; i < SIZE; i++)
    {
        char x = str_file[i];
        a = x;
        arr[i] = a;
        if (i >= SIZE)
            arr[i] = 1000;
    }

    //Сортировка
    while (flag_ENG < SIZE)
    {
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_ENG) str_output += (char)arr[i];
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_eng) str_output += (char)arr[i];
        num_ENG++;
        num_eng++;
        flag_ENG++;
    }
    while (flag_RUS < SIZE)
    {
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_RUS) str_output += (char)arr[i];
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_rus) str_output += (char)arr[i];
        num_RUS++;
        num_rus++;
        flag_RUS++;
    }
        
    cout << "Строка после сортировки: " << str_output;

    ExitToMenu();
}

//Главная часть дз 3
int case3()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string cons_out = "Задание 1 'Заём'\nЗадание 2 'Ссуда'\nЗадание 3 'Копирование файла'\nЗадание 4 'Фильтр'\nЗадание 5 'Сортировка букв'\n0 вернуться к выбору д/з.\nВведите номер задания: ";
    bool chek_hw3 = true;
    system("cls");
    while (chek_hw3)
    {
        switch ((int)chek(3, cons_out, true))
        {
        default:
            system("cls");
            cout << "Нет такого задания.\n";
            break;
        case 1:
            loan();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 2:
            loan2();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 3:
            copying_file();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 4:
            filter();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 5:
            sorting_letters();
            system("cls");
            cout << "Вы вернулись к выбору заданий.\n";
            break;
        case 0:
            system("cls");
            cout << "Вы вернулись назад.\n";
            chek_hw3 = false;
        }
    }
    chek_hw3 = true;
}
