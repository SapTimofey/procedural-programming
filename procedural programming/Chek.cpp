#include <iostream>    //Для cin/cout
#include <locale>      //Для вывода русским
#include <string>      //Для перевода string -> int/float
#include "HomeWork4.h" //Модуль Д/з 4
#include "Settings.h"  //Модуль настроек

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;

//Проверка на ввод
float chek(int type, string cons_out, bool main)
{
    setlocale(LC_NUMERIC, "eng");
    string num;
    float Fnum = 0;
    float s = 0, n = 0;
    bool flag = true;
    
    do
    {
        try
        {
            setColor(TextColor, TextBackgroundColor);
            cout << cons_out;
            cin >> num;
            for (int i = 0; i < num.length(); i++)
            {
                if (num[0] == '.')
                {
                    flag = false;
                    if (main) system_cls();
                    cout << num << " - число не может начинаться с точки.\n";
                    break;
                }
                else if (num[1] == '.' && num[0] == '-')
                {
                    flag = false;
                    if (main) system_cls();
                    cout << num << " - число не содержит целой части.\n";
                    break;
                }
                else if (num[i] == '.' || isdigit(num[i]) || num[i] == '-') continue;
                else
                {
                    flag = false;
                    if (main) system_cls();
                    cout << num << " - это не число.\n";
                    break;
                }
            }
            
            if (flag)
            {
                Fnum = stof(num);
                n = modf(Fnum, &s);
                switch (type)
                {
                case 1: // Для числа большего 0.
                    if (Fnum > 0) return Fnum;
                    else
                    {
                        cout << num << " - число должно быть больше 0.\n";
                        break;
                    }
                case 2: // Для угла.
                    if (Fnum > 0 && Fnum < 180) return Fnum;
                    else
                    {
                        cout << "Угол должен быть в пределах (0, 180).\n";
                        break;
                    }
                case 4: // Для системы счисления.
                    if (n == 0 && Fnum > 0) return Fnum;
                    else if (n != 0)
                    {
                        cout << num << " - СС не может быть дробной.\n";
                        break;
                    }
                    else if (Fnum < 0)
                    {
                        cout << num << " - СС не может быть отрицательной.\n";
                        break;
                    }
                    else
                    {
                        cout << num << " - СС не может равняться 0.\n";
                        break;
                    }
                case 5: // Проверка на целое положительное число.
                    if (n == 0 && Fnum > 0) return Fnum;
                    else if (n != 0)
                    {
                        cout << num << " - Число не может быть дробным.\n";
                        break;
                    }
                    else if (Fnum < 0)
                    {
                        cout << num << " - Число не может быть отрицательным.\n";
                        break;
                    }
                    else
                    {
                        cout << num << " - Число не может равняться 0.\n";
                        break;
                    }
                default:// Для остальных случаев.
                    return Fnum;
                }
            }
            flag = true;
        }
        catch (out_of_range)
        {
            if (main) system_cls();
            cout << "Слишком большое число.\n";
        }
        catch (...)
        {
            if (main) system_cls();
            cout << num << "Произошла ошибка.\n";
        }
    } while (true);
}
