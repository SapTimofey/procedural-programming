#include <iostream> //Для case2
#include <locale>   //Для вывода русским
#include <windows.h>//Для ввода русским
#include <cmath>    //Для вычисления уравнений
#include <fstream>  //Для работы с файлом
#include <string>   //Для перевода string -> int/float, int -> string
#include "Chek.h"   //Модуль провкрки
#include <ctime>    //Для генерации рандомных чисел
#include <algorithm>//Для сортировки

using namespace std;

//Создание файла
void file()
{
    ofstream fout("test_HW3.txt");
    fout.close();
}

// Д/з 3

//Задание "Заём"
void loan()
{
    system("cls");
    string i = "no";
    float S = 0, n = 0, p = 0, r = 0, m = 0;

    cout << "Задание 'Заём'\n";

    cout << "Введите S, n, p: ";
    cin >> S >> n >> p;
    r = p / 100; //Доли
    if (S >= 0 && n > 0 && p != 0)
    {
        m = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));//Расчёт месячной выплаты

        cout << "Ваша месячная выплата составляет " << m << " рублей.\n";
    }
    else if (p == 0)
    {
        m = S / (12 * n);

        cout << "Ваша месячная выплата составляет " << m << " рублей.\n";
    }
    else cout << "S, n должны быть больше 0.\n";

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Ссуда"
void loan2()
{
    
    system("cls");
    string i = "no";
    float S = 0, n = 0, m = 0, p = 0, m_chek = 0, r = 0.1;

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
    else if (S == 0) cout << "Вы не брали кредит. =)\n";
    else cout << "S должна быть неотрицательной, n, m - больше 0.\n";

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Копирование файла"
void copying_file()
{
    file();
    system("cls");
    char f_read[100];
    string i = "no", str;
    ofstream fout;
    int len = 0;
    
    cout << "Задание 'Копирование файла'\n" << "Введите строку для записи в файл: ";
    
    cin >> str;
    //Запись 1 строки в файл
    fout.open("test_HW3.txt");
    fout << str << endl;
    fout.close();
    
    //Чтение 1 строки из файла
    ifstream fin("test_HW3.txt");
    fin >> f_read;
    fin.close();
    len = str.length();
    cout << "Первая строка: " << f_read << endl;

    //Запись 2 строки в файл
    cout << "Введите 2 строку для записи в файл: ";
    cin >> str;
    fout.open("test_HW3.txt", ios::app);
    fout << str;
    fout.close();

    //Чтение 2 строки из файла
    ifstream fin2("test_HW3.txt");
    fin2.seekg(len);
    fin2 >> f_read;
    fin2.close();
    cout << "Вторая строка: " << f_read << endl;

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Фильтр"
void filter()
{
    file();
    system("cls");
    ofstream fout;
    string str_output, str_file, j = "no", str;
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

    //Модуль выхода в меню
    do
    {
        cout << endl << "Чтобы вернутся, введите любой символ.";
        cin >> j;
    } while (j == "no");
}

//Задание "Сортировка букв"
void sorting_letters()
{
    file();
    system("cls");

    ofstream fout;
    int const SIZE = 30;
    int arr[SIZE]{}, num_ENG = 65, num_eng = 97, num_RUS = -64, num_rus = -32, flag_ENG = 0, flag_RUS = 0, a = 0;
    string str_output, h = "no", str, str_file;

    cout << "Задание 'Сортировка букв'\n" << "Введите строку: ";

    cin >> str;

    //Запись строки в файл
    fout.open("test_HW3.txt");
    fout << str;
    fout.close();

    //Чтение строки из файла
    ifstream fin("test_HW3.txt");
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

    //Модуль выхода в меню
    do
    {
        cout << endl << "Чтобы вернутся, введите любой символ.";
        cin >> h;
    } while (h == "no");
}

//Главная часть дз 3
int case3()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string hw3;
    bool chek_hw3 = true;
    system("cls");
    while (chek_hw3)
    {
        cout << "Задание 1 'Заём'\n" << "Задание 2 'Ссуда'\n" << "Задание 3 'Копирование файла'\n" << "Задание 4 'Фильтр'\n" << "Задание 5 'Сортировка букв'\n" << "0 вернуться к выбору д/з.\n" << "Введите номер задания: ";
        cin >> hw3;
        if (chek(hw3, true))
        {
            switch (stoi(hw3))
            {
            default:
                system("cls");
                cout << stoi(hw3) << " - нет такого задания.\n";
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
    }
    chek_hw3 = true;
}
