#include <iostream>    //Для main
#include <windows.h>   //Для ввода/вывода русским
#include <string>      //Для перевода string -> int/float
#include <stdlib.h>    //Для exit
#include "HomeWork1.h" //Модуль Д/з 1
#include "HomeWork2.h" //Модуль Д/з 2
#include "HomeWork3.h" //Модуль Д/з 3
#include "HomeWork4.h" //Модуль Д/з 4
#include "Chek.h"      //Модуль проверки

using namespace std;

//Главная часть
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string d;
    while (true)
    {
        cout << "Д/з 1\n" << "Д/з 2\n" << "Д/з 3\n" << "Д/з 4\n" << "0 Завершить работу.\n" << "Введите номер д/з: ";
        cin >> d;
        if (chek(d, true))
        {
            switch (stoi(d))
            {
            default:
                system("cls");
                cout << stoi(d) << " - нет такого д/з.\n";
                break;
            case 1:
                case1(); //Д/з 1
                break;
            case 2:
                case2(); //Д/з 2
                break;
            case 3:
                case3(); //Д/з 3
                break;
            case 4:
                case4(); //Д/з 4
                break;
            case 0:
                cout << "Вы завершили работу.\n";
                exit(EXIT_SUCCESS);
            }
        }
    }
}
