#include <iostream>    //Для cin/cout
#include <locale>      //Для вывода русским
#include <windows.h>   //Для ввода русским
#include <cmath>       //Для вычисления уравнений
#include <fstream>     //Для работы с файлом
#include <map>         //Для map
#include <algorithm>   //Для сортировки
#include <ctime>       //Для генерации рандомных чисел
#include <string>      //Для перевода string -> int/float, int -> string
#include "Chek.h"      //Модуль проверки
#include "HomeWork3.h" //Модуль Д/з 3
#include "HomeWork4.h" //Модуль Д/з 4
#include "ExitToMenu.h"//Модуль выхода
#include <conio.h>     //Для считывания клавиш
#include "Settings.h"  //Модуль настроек

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

//Задание 1 "Алгоритм Евклида"
void euclid()
{
    system_cls();
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;

    cout << "Задание 'Алгоритм Евклида'\n";
    
    num1 = chek(1, "Введите 1 число: ", false);
    num2 = chek(1, "Введите 2 число: ", false);
    
    num5 = num3 = num1;
    num6 = num4 = num2;

    cout << endl << "Метод вычитания:" << endl << endl << num5 << " " << num6 << endl;

    while (num5 != num6)
    {
        if (num5 > num6) num5 -= num6;
        else num6 -= num5;
        cout << num5 << " " << num6 << endl;
    }

    cout << "НОД (" << num1 << ", " << num2 << ") = " << num5 << endl << endl;


    cout << "Метод деления:" << endl << endl << num3 << " " << num4 << endl;

    while (num4 > 0 && num3 > 0)
    {
        if (num3 > num4) num3 %= num4;
        else num4 %= num3;
        cout << num3 << " " << num4 << endl;
    }

    cout << "НОД (" << num1 << ", " << num2 << ") = ";
    if (num3 != 0) cout << num3 << endl << endl;
    else cout << num4 << endl << endl;
    
    ExitToMenu();
}

//Задание 2 "Решето Эратосфена"
void eratosthenes()
{
    system_cls();
    int n = 0;
    bool flag = false;

    cout << "Задание 'Решето Эратосфена'\n";
    
    while (n < 2)
    {
        n = (int)chek(5, "Введите число, до которого нужно найти простые числа: ", false);
        if (n < 2) cout << "Число должно быть не меньше 2.\n";
    }

    int* natural_num = new int[n + 1];
    if (n == 2) cout << 2 << "\n";
    else
    {
        for (int i = 0; i <= n; i++)
        {
            natural_num[i] = i;
        }

        for (int i = 2; i * i <= n; i++) if (natural_num[i]) for (int j = i * i; j <= n; j += i) natural_num[j] = 0;
        for (int i = 2; i < n; i++) if (natural_num[i]) cout << natural_num[i] << endl;

        cout << endl;
    }

    ExitToMenu();
}

//Задание 3 "Обработка текстовых файлов"
void file_read_1()
{
    system_cls();
    file();
    string str, f_read, output;
    map <char, int> arr {{'q', 0}, {'w', 0}, {'r', 0}, {'t', 0}, {'p', 0}, {'s', 0}, {'d', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'z', 0}, {'x', 0}, {'c', 0}, {'v', 0}, {'b', 0}, {'n', 0}, {'m', 0}, {'Q', 0}, {'W', 0}, {'R', 0}, {'T', 0}, {'P', 0}, {'S', 0}, {'D', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'J', 0}, {'K', 0}, {'L', 0}, {'Z', 0}, {'X', 0}, {'C', 0}, {'V', 0}, {'B', 0}, {'N', 0}, {'M', 0} };
    int len = 0, max = 0;

    cout << "Задание 3.1 'Обработка текстовых файлов'\n" << "Введите строку для записи в файл (для завершения строки введите '.'): ";

    getline(cin, str, '.');
    str.erase(0, 1);
    len = str.length();

    string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    //Запись строки в файл
    ofstream fout("test_HW.txt");
    fout << str;
    fout.close();

    //Чтение строки из файла
    ifstream fin("test_HW.txt");
    fin >> f_read;
    fin.close();
    
    for (int i = 0; i < len; i++)
    {
        try
        {
            arr.at(f_read[i]) += 1;
        }
        catch (out_of_range)
        {
            continue;
        }
    }
    
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        if (i->second > max)
        {
            max = i->second;
            output = i->first;
        }
        else if (i->second == max)
        {
            output = output + ", " + i->first;
        }
    }

    cout << "Часто встречаемые символы: " << output << " = " << max << endl;

    ExitToMenu();
}

//Задание 4 "Обработка текстовых файлов"
void find_str(string str, string str_find)
{
    int len = 0, len_find = 0;
    string str_begin, str_end;

    len_find = str_find.length();
    str_begin = str_end = str;
    len = str.length();

    str_end.erase(0, str.find(str_find) + len_find);
    str_begin.erase(str.find(str_find), len - str.find(str_find));

    cout << str_begin;
    setColor(LightGreen, Black);
    cout << str_find;
    setColor(LightGray, Black);
    if (str_end.find(str_find) == -1) cout << str_end << " ";
    else find_str(str_end, str_find);
}
void file_read_2()
{
    system_cls();
    string str;
    string str_find;

    cout << "Задание 'Обработка текстовых файлов'\n" << "Введите строку (для завершения строки введите '#'): ";
    getline(cin, str, '#');

    cout << "\nВведите строку, которую нужно найти (для завершения строки введите '#'): ";
    getline(cin, str_find, '#');
    cout << "\n";
    
    str.erase(0, 1);
    str_find.erase(0, 1);


    if (str.find(str_find) == -1 || str.length() == 0 || str_find.length() == 0) cout << "Такой строки нет.";
    else find_str(str, str_find);
    cout << endl;

        ////Запись строки в файл
        //fout.open("test_HW.txt");
        //fout << str << endl;
        //fout.close();

        ////Чтение строки из файла
        //ifstream fin("test_HW.txt");
        //fin >> f_read;
        //fin.close();
        //cout << f_read << endl;

    ExitToMenu();
}

//Задание 5 "Ряды"
string interpreter(int num)
{
    string numS = to_string(num);
    int i = numS.length() - 1, j = 0;
    int res_10 = 0;
    string res;
    int a = 0;
    if (num == 0) return "0";
    else
    {
        for (j, i; j < numS.length(); i--, j++)
        {
            char x = numS[j];
            a = x - 48;
            res_10 += a * pow(3, i);
        }
        while (res_10 > 0)
        {
            res = to_string(res_10 % 6) + res;
            res_10 /= 6;
        }
        return res;
    }
}
void rows_1()
{
    system_cls();
    int a = 0, n = 0;
    
    string input_num;
    int cnt = 0;
    bool flag = true;

    cout << "Задание 'Ряды'\n";

    n = (int)chek(5, "Введите количество чисел в массиве: ", false);
    
    int* num_3 = new int[n + 1] {};
    string* num_6 = new string[n] {};

    while (cnt < n)
    {
        cin >> input_num;
        for (int j = 0; j < input_num.length(); j++)
        {
            if (isdigit(input_num[j]))
            {
                char x = input_num[j];
                a = x - 48;
            }
            else
            {
                char x = input_num[j];
                a = x;
                if (a < 97) a -= 55;
                else a -= 87;
            }
            if (a >= 3)
            {
                cout << "Число не соответствует 3 системе счисления." << endl << "Осталось ввести " << n - cnt;
                if ((n - cnt) % 10 == 0 || (n - cnt) % 10 == 5 || (n - cnt) % 10 == 6 || (n - cnt) % 10 == 7 || (n - cnt) % 10 == 8 || (n - cnt) % 10 == 9 || (n - cnt >=10 && n - cnt <= 19)) cout << " чисел: ";
                else if ((n - cnt) % 10 == 2 || (n - cnt) % 10 == 3 || (n - cnt) % 10 == 4) cout << " числа: ";
                else cout << " число: ";
                flag = false;
                break;
            }
        }
        if (flag)
        {
            num_3[cnt] = stoi(input_num);
            cnt++;
        }
        flag = true;
    }

    cout << "Массив из чисел в 3 СС: [";
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1) cout << num_3[i] << ", ";
        else cout << num_3[i];
    }
    cout << "]" << endl;


    for (int i = 0; i < n; i++)
    {
        num_6[i] = interpreter(num_3[i]);
    }

    cout << "Массив из чисел в 6 СС: [";
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1) cout << num_6[i] << ", ";
        else cout << num_6[i];
    }
    cout << "]" << endl;

    ExitToMenu();
}

//Задание 6 "Ряды"
void rows_2()
{
    system_cls();
    int SIZEx = 0, SIZEy = 0;
    float a = 0;
    string cons_out;
    float sum1 = 0;
    cout << "Задание 'Ряды'" << endl;
    srand(time(NULL));

    SIZEy = (int)chek(5, "Введите количество столбцов в массиве: ", false);
    SIZEx = (int)chek(5, "Введите количество строк в массиве: ", false);

    float* sum = new float[SIZEx] {0};
    /*float** arr = new float*[SIZEy];
    for (int i = 0; i < SIZEx; i++)
        arr[i] = new float[SIZEx];*/
    for (int i = 0; i < SIZEx; i++)
    {
        for (int j = 0; j < SIZEy; j++)
        {
            cons_out = "Введите элемент [" + to_string(j) + "][" + to_string(i) + "]: ";
            /*a = chek(0, cons_out, false);*/
            a = rand() % 1000;
            sum1 += a;
        }
        /*sum[i] = sum1;*/
        cout << "Сумма " << i + 1 << " столбца равна: " << sum1 << endl;
        sum1 = 0;
    }

    /*for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }*/
    

    /*for (int i = 0; i < SIZEx; i++)
        cout << "Сумма " << i + 1 << " столбца равна: " << sum[i] << endl;*/


    ExitToMenu();
}

//Меню дз 5
void menu_HW5()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int key = 0;

    string cons_out[6] = { "Задание 1 'Алгоритм Евклида'", "Задание 2 'Решето Эратосфена'", "Задание 3 'Обработка текстовых файлов'", "Задание 4 'Обработка текстовых файлов'", "Задание 5 'Ряды'", "Задание 6 'Ряды'" };

    while (true)
    {
        int num = 0;
        do
        {
            system_cls();
            cout << "Используйте:\n- стрелки вверх, вниз - для передвижения\n- enter - для выбора\n- escape - для выхода\n----------Д/з 5------------" << endl;
            for (int i = 0; i < 6; i++)
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

            if (key == 80 && num < 5) num++;
            if (key == 72 && num > 0) num--;
            if (key == 27)
            {
                system_cls();
                cout << "Вы вернулись назад.\n";
                return;
            }
        } while (key != 13);
        switch (num + 1)
        {
        case 1:
            euclid();
            system_cls();
            cout << "Вы вернулись назад.\n";
            break;
        case 2:
            eratosthenes();
            system_cls();
            cout << "Вы вернулись назад.\n";
            break;
        case 3:
            file_read_1();
            system_cls();
            cout << "Вы вернулись назад.\n";
            break;
        case 4:
            file_read_2();
            system_cls();
            cout << "Вы вернулись назад.\n";
            break;
        case 5:
            rows_1();
            system_cls();
            cout << "Вы вернулись назад.\n";
            break;
        case 6:
            rows_2();
            system_cls();
            cout << "Вы вернулись назад.\n";
            break;
        }
    }
}
