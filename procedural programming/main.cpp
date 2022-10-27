#include <iostream>    //Для main
#include <windows.h>   //Для ввода/вывода русским
#include <string>      //Для перевода string -> int/float
#include <stdlib.h>    //Для exit
#include "HomeWork1.h" //Модуль Д/з 1
#include "HomeWork2.h" //Модуль Д/з 2
#include "HomeWork3.h" //Модуль Д/з 3
#include "HomeWork4.h" //Модуль Д/з 4
#include "HomeWork5.h" //Модуль Д/з 4
#include "Chek.h"      //Модуль проверки

using namespace std;

//Главная часть
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string cons_out = "Д/з 1\nД/з 2\nД/з 3\nД/з 4\nД/з 5\n0 Завершить работу.\nВведите номер д/з: ";
    while (true)
    {
        switch ((int)chek(3, cons_out, true))
        {
        default:
            system("cls");
            cout << "Нет такого д/з.\n";
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
        case 5:
            case5(); //Д/з 5
            break;
        case 0:
            cout << "Вы завершили работу.\n";
            exit(EXIT_SUCCESS);
        }
    }
    
}
