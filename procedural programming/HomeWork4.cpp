#include <iostream>    //Для case2
#include <locale>      //Для вывода русским
#include <windows.h>   //Для ввода русским
#include <cmath>       //Для вычисления уравнений
#include <fstream>     //Для работы с файлом
#include <string>      //Для перевода string -> int/float, int -> string
#include "Chek.h"      //Модуль провкрки
#include <ctime>       //Для генерации рандомных чисел
#include <algorithm>   //Для сортировки
#include "HomeWork3.h" //Модуль Д/з 3

using namespace std;

//Задание "Файл"
void file_4()
{
    file();
    system("cls");
    ofstream fout;
    int sum = 0, int_file, num = 0;
    string j = "no";

    cout << "Задание 'Файл'\n";


    //Генерация и запись в файл случайных чисел
    srand(time(0));
    cout << "Числа в файле: ";
    fout.open("test_HW3.txt");
    for (int i = 0; i < 10; i++)
    {
        num = rand() % 1000;
        fout << num << " ";
        cout << num << " ";
    }
    fout.close();

    //Чтение строки из файла
    ifstream fin("test_HW3.txt");
    for (int i = 0; i < 10; i++)
    {
        fin >> int_file;
        sum += int_file;
    }
    fin.close();

    cout << endl << "Сумма 10 чисел равна: " << sum << endl;

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> j;
    } while (j == "no");
}

//Задание "Знак числа"
int sign(float x)
{
    if (x > 0) return 1;
    else if (x == 0) return 0;
    else return -1;
}
void number_sign()
{
    system("cls");
    string x_test, i = "no"; //Переменные ввода
    float x = 0;             //Переменные для расчёта
    bool x_TF;               //Переменные проверки

    cout << "Задание 'Знак числа'\n";


    //Модуль проверки корректности ввода x
    do
    {
        cout << "Введите число x: ";
        cin >> x_test;
        x_TF = chek(x_test, false);
        if (x_TF) x = stof(x_test);
    } while (x_TF == false);

    if (sign(x) == 1) cout << "Число положительное.\n";
    else if (sign(x) == 0) cout << "Число равно 0.\n";
    else cout << "Число отрицательное.\n";

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Геометрические фигуры"
void geometry()
{
    system("cls");
    string geo;
    bool chek_geo = true;
    string R_test, A_test, B_test, corner_test, i = "no";
    float R = 0, A = 0, B = 0, corner = 0;
    bool R_TF, A_TF, B_TF, corner_TF;
    const double PI = 3.141592653589793;               

    //Модуль выбора фигур
    while (chek_geo)
    {
        cout << "Задание 'Геометрические фигуры'\n" << "Прямоугольник\t" <<  "1\n" << "Треугольник\t" << "2\n" << "Круг    \t" << "3\n" << "Введите номер фигуры: ";
        cin >> geo;
        if (chek(geo, true))
        {
            switch (stoi(geo))
            {
            default:
                system("cls");
                cout << stoi(geo) << " - нет такой фигуры.\n";
                break;
            case 1:
                system("cls");
                cout << "Площадь прямоугольника\n";

                //Модуль проверки корректности ввода A
                do
                {
                    cout << "Введите длину стороны A: ";
                    cin >> A_test;
                    A_TF = chek(A_test, false);
                    if (A_TF)
                    {
                        A = stof(A_test);
                        if (A <= 0)
                        {
                            cout << "A должна быть больше 0.\n";
                            A_TF = false;
                        }
                    }
                } while (A_TF == false);

                //Модуль проверки корректности ввода B
                do
                {
                    cout << "Введите длину стороны B: ";
                    cin >> B_test;
                    B_TF = chek(B_test, false);
                    if (B_TF)
                    {
                        B = stof(B_test);
                        if (B <= 0)
                        {
                            cout << "B должна быть больше 0.\n";
                            B_TF = false;
                        }
                    }
                } while (B_TF == false);

                
                cout << "Площадь прямоугольника равна: " << A * B << endl;

                //Модуль выхода в меню
                cout << "Чтобы вернуться к выбору фигур, введите 0.\n" << "Чтобы вернуться к выбору заданий, введите любой другой символ.";
                cin >> i;
                if (i == "0")
                {
                    system("cls");
                    cout << "Вы вернулись к выбору фигур.\n";
                    break;
                }
                else
                {
                    chek_geo = false;
                    break;
                }
            case 2:
                system("cls");
                cout << "Площадь треугольника\n";

                //Модуль проверки корректности ввода A
                do
                {
                    cout << "Введите длину стороны A: ";
                    cin >> A_test;
                    A_TF = chek(A_test, false);
                    if (A_TF)
                    {
                        A = stof(A_test);
                        if (A <= 0)
                        {
                            cout << "A должна быть больше 0.\n";
                            A_TF = false;
                        }
                    }
                } while (A_TF == false);

                //Модуль проверки корректности ввода B
                do
                {
                    cout << "Введите длину стороны B: ";
                    cin >> B_test;
                    B_TF = chek(B_test, false);
                    if (B_TF)
                    {
                        B = stof(B_test);
                        if (B <= 0)
                        {
                            cout << "B должна быть больше 0.\n";
                            B_TF = false;
                        }
                    }
                } while (B_TF == false);

                //Модуль проверки корректности ввода corner
                do
                {
                    cout << "Введите угол между двумя сторонами: ";
                    cin >> corner_test;
                    corner_TF = chek(corner_test, false);
                    if (corner_TF)
                    {
                        corner = stof(corner_test);
                        if (corner <= 0)
                        {
                            cout << "Угол должен быть больше 0.\n";
                            corner_TF = false;
                        }
                    }
                } while (corner_TF == false);

                cout << "Площадь треугольника равна: " << 0.5 * A * B * sin(corner * PI / 180) << endl;

                //Модуль выхода в меню
                cout << "Чтобы вернуться к выбору фигур, введите 0.\n" << "Чтобы вернуться к выбору заданий, введите любой другой символ.";
                cin >> i;
                if (i == "0")
                {
                    system("cls");
                    cout << "Вы вернулись к выбору фигур.\n";
                    break;
                }
                else
                {
                    chek_geo = false;
                    break;
                }
            case 3:
                system("cls");
                cout << "Площадь круга\n";
                
                //Модуль проверки корректности ввода R
                do
                {
                    cout << "Введите значение радиуса R: ";
                    cin >> R_test;
                    R_TF = chek(R_test, false);
                    if (R_TF) R = stof(R_test);
                    if (R <= 0)
                    {
                        cout << "R должна быть больше 0.\n";
                        R_TF = false;
                    }
                } while (R_TF == false);

                cout << "Площадь круга равна: " << 4 * PI * pow(R, 2) << endl;

                //Модуль выхода в меню
                cout << "Чтобы вернуться к выбору фигур, введите 0.\n" << "Чтобы вернуться к выбору заданий, введите любой другой символ.";
                cin >> i;
                if (i == "0")
                {
                    system("cls");
                    cout << "Вы вернулись к выбору фигур.\n";
                    break;
                }
                else
                {
                    chek_geo = false;
                    break;
                }
            }
        }
    }
    chek_geo = true;
}

//Задание "Былая слава"
void glory()
{
    system("cls");
    string i = "no";

    cout << "Задание 'Былая слава'\n";

    for (int i = 0; i < 6; i++)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << "* ";
        }
        for (int i = 0; i < 24; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int i = 0; i < 40; i++)
        {
            cout << "-";
        }
        cout << endl;
    }

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Синусоида" - не готово
void sin()
{
    system("cls");
    string i = "no";
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

    cout << "Задание 'Синусоида'\n";

    SelectObject(hDC, Pen);
    MoveToEx(hDC, 0, 85, NULL);
    LineTo(hDC, 200, 85);
    MoveToEx(hDC, 100, 0, NULL);
    LineTo(hDC, 100, 170);
    for (float x = -8.0f; x <= 8.0f; x += 0.01f)
    {
        MoveToEx(hDC,10 * x + 100, -10 * sin(x) + 85, NULL);
        LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
    }
    ReleaseDC(hWnd, hDC);
    cin.get();

    //Модуль выхода в меню
    do
    {
        cout << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Автоматный распознаватель"
void recognizer()
{
    system("cls");
    string str;
    string i = "no";
    int num1 = 0, num2 = 0, output_num = 0, c = 0;
    cout << "Задание 'Автоматный распознаватель'\n" << "Введите строку: ";
    cin >> str;
    while (str.length() > 0)
    {
        while (c < 2)
        {
            switch (str[c])
            {
            case 'I':
                if (c == 0) num1 = 1;
                else num2 = 1;
                break;
            case 'V':
                if (c == 0) num1 = 5;
                else num2 = 5;
                break;
            case 'X':
                if (c == 0) num1 = 10;
                else num2 = 10;
                break;
            case 'L':
                if (c == 0) num1 = 50;
                else num2 = 50;
                break;
            case 'C':
                if (c == 0) num1 = 100;
                else num2 = 100;
                break;
            case 'D':
                if (c == 0) num1 = 500;
                else num2 = 500;
                break;
            case 'M':
                if (c == 0) num1 = 1000;
                else num2 = 1000;
                break;
            }
            c++;
        }
        if (num1 >= num2)
        {
            output_num += num1;
            num1 = 0;
            num2 = 0;
            c = 0;
            str.erase(0, 1);
        }
        else
        {
            output_num += (num2 - num1);
            num1 = 0;
            num2 = 0;
            c = 0;
            str.erase(0, 1);
            str.erase(0, 1);
        }
    }

    cout << output_num << endl;

    //Модуль выхода в меню
    do
    {
        cout << endl << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Генератор псевдослучайных чисел"
void random_num()
{
    system("cls");
    int s = 0, s1 = 0, m = 37, b = 3, c = 64;
    string i = "no";
    cout << "Задание 'Генератор псевдослучайных чисел'\n" << "I вариант\n" << "10 сгенерированных чисел: ";



    for (int i = 0, s = 0, s1 = 0, m = 37, b = 3, c = 64; i < 10; i++)
    {
        s1 = (m * s + b) % c;
        cout << s1 << " ";
        s = s1;
    }
    cout << endl << "II вариант\n" << "10 сгенерированных чисел: ";
    for (int i = 0, s = 0, s1 = 0, m = 25173, b = 13849, c = 65537; i < 10; i++)
    {
        s1 = (m * s + b) % c;
        cout << s1 << " ";
        s = s1;
    }

    //Модуль выхода в меню
    do
    {
        cout << endl << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Задание "Системы счисления"
string interpreter(float num, int base_out)
{
    string res;
    int f = 0;
    bool flag = false;
    int num_befor_dot = 0, L = 0, num_after_dot_chek = 0;
    float num_after_dot = 0;

    if (num < 0)
    {
        num = abs(num);
        flag = true;
    }

    num_befor_dot = num;
    num_after_dot = num - num_befor_dot;
    
    cout << "Перевод целой части:" << endl << endl;
    while (num_befor_dot > 0)
    {
        f = num_befor_dot % base_out;
        cout << num_befor_dot << " / " << base_out << " = \t" << num_befor_dot / base_out;
        if (num_befor_dot / base_out >= 10000000) cout << "\t остаток: " << f << endl;
        else cout << "\t\t остаток: " << f << endl;

        switch (f)
        {
        case 10: 
            res = 'a' + res;
            num_befor_dot = num_befor_dot / base_out;
            break;
        case 11:
            res = 'b' + res;
            num_befor_dot = num_befor_dot / base_out;
            break;
        case 12:
            res = 'c' + res;
            num_befor_dot = num_befor_dot / base_out;
            break;
        case 13:
            res = 'd' + res;
            num_befor_dot = num_befor_dot / base_out;
            break;
        case 14:
            res = 'e' + res;
            num_befor_dot = num_befor_dot / base_out;
            break;
        case 15:
            res = 'f' + res;
            num_befor_dot = num_befor_dot / base_out;
            break;
        default:
            res = to_string(f) + res;
            num_befor_dot = num_befor_dot / base_out;
            break;
        }
    }
    cout << endl << "Перевод дробной части:" << endl << endl;
    if (num_after_dot > 0)
    {
        res += '.';
        L = log(pow(10, (to_string(num_after_dot).length() - 3)))/log(base_out);
        cout << "Количество знаков после запятой, L = " << L << endl << endl;

        while (L > 0)
        {
            cout << num_after_dot;
            num_after_dot_chek = num_after_dot * base_out;
            num_after_dot = num_after_dot * base_out;
            cout << " * " << base_out << " = " << num_after_dot;
            
            cout << " целая часть: " << num_after_dot_chek << endl;
            if (num_after_dot_chek > 0) num_after_dot -= num_after_dot_chek;
            res += to_string(num_after_dot_chek);
            if (num_after_dot == 0) break;
            L--;
        }
    }
    cout << endl;
    if (flag) res = '-' + res;
    return res;
}
long float interpreter_10(string num, float base_in, bool flag)
{
    long float a = 0, res10 = 0;
    int len = 0, c = -1, find_dot = 0;
    bool flag_sign = false, flag_dot = false;
    float* intermediate_num = new float[num.length()] {0};

    len = num.length();

    if (num.find('.') == -1) find_dot = 0;
    else find_dot = num.find('.');
    
    for (int i = 0, j = 0; i < num.length(); i++, j++)
    {
        if (num[i] == '-')
        {
            flag_sign = true;
            find_dot--;
            j--;
            continue;
        }
        else if (isdigit(num[i]))
        {
            char x = num[i];
            a = x - 48;
        }
        else if (num[i] == '.')
        {
            flag_dot = true;
            j--;
            continue;
        }
        else
        {
            char x = num[i];
            a = x;
            if (a < 97) a -= 55;
            else a -= 87;
        }
        if (flag_dot)
        {
            res10 += a * pow(base_in, c);
            cout << a << " * " << base_in << " ^ " << c << " = " << a * pow(base_in, c) << endl;
            intermediate_num[j] = a * pow(base_in, c);
            c--;
        }
        else
        {
            res10 += a * pow(base_in, find_dot - 1);
            cout << a << " * " << base_in << " ^ " << find_dot - 1 << " = " << a * pow(base_in, find_dot - 1) << endl;
            intermediate_num[j] = a * pow(base_in, find_dot - 1);
            find_dot--;
        }
        
        len--;
    }
    if (flag)
    {
        cout << endl << intermediate_num[0];
        for (int i = 1; i < num.length(); i++)
        {
            if (intermediate_num[i] != 0) cout << " + " << intermediate_num[i];
        }
        cout << " = " << res10 << endl;
    }
    cout << endl;
    if (flag_sign) res10 *= (-1);
    return res10;
}
void number_system()
{
    setlocale(LC_NUMERIC, "eng");
    system("cls");
    string i = "no";
    string input_num;
    int input_base_in = 0, input_base_out = 0, a = 0;
    bool flag = true;
    long float num = 0;
    
    cout << "Задание 'Системы счисления'\n" << "Введите число: ";
    cin >> input_num;

    cout << "Введите систему счисления введённого числа: ";
    cin >> input_base_in;

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
        if (a >= input_base_in)
        {
            cout << "Число не соответствует системе счисления." << endl;
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "Введите желаемую систему счисления: ";
        cin >> input_base_out;
        cout << endl;
        if (input_base_in == input_base_out) cout << "Число в " << input_base_out << " системе счисления: " << input_num << endl;
        else
        {
            if (input_base_in != 10)
            {
                if (input_base_out == 10)
                {
                    cout << "Перевод из " << input_base_in << " в 10 систему счисления:" << endl << endl;
                    num = interpreter_10(input_num, input_base_in, false);
                }
                else
                {
                    cout << "Перевод из " << input_base_in << " в 10 систему счисления:" << endl << endl;
                    num = interpreter_10(input_num, input_base_in, true);
                }
            }
            else num = stof(input_num);
            if (input_base_out == 10) cout << "Число в 10 системе счисления: " << num << endl;
            else
            {
                cout << "Перевод из 10 в " << input_base_out << " систему счисления:" << endl << endl;
                cout << "Введённое число в " << input_base_out << " системе счисления: " << interpreter(num, input_base_out) << endl;
            }
        }
    }


    //Модуль выхода в меню
    do
    {
        cout << endl << "Чтобы вернутся, введите любой символ.";
        cin >> i;
    } while (i == "no");
}

//Главная часть дз 4
int case4()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    

    string hw3;
    bool chek_hw3 = true;
    system("cls");
    while (chek_hw3)
    {
        cout << "Задание 1 'Файл'\n" << "Задание 2 'Знак числа'\n" << "Задание 3 'Геометрические фигуры'\n" << "Задание 4 'Былая слава'\n" << "Задание 5 'Синусоида'\n" << "Задание 6 'Автоматный распознаватель'\n" << "Задание 7 'Генератор псевдослучайных чисел'\n" << "Задание 8 'Системы счисления'\n" << "0 вернуться к выбору д/з.\n" << "Введите номер задания: ";
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
                file_4();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 2:
                number_sign();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 3:
                geometry();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 4:
                glory();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 5:
                sin();
                system("cls");
                /*cout << "Не готово.\n";*/
                break;
            case 6:
                recognizer();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 7:
                random_num();
                system("cls");
                cout << "Вы вернулись к выбору заданий.\n";
                break;
            case 8:
                number_system();
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