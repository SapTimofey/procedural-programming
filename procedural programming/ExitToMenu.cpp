#include <iostream>    //Для cin/cout
#include <locale>      //Для вывода русским
#include <conio.h>     //Для считывания клавиш
#include "Settings.h"  //Модуль настроек
#include "HomeWork4.h" //Модуль Д/з 4

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;

void ExitToMenu()
{
	setColor(TextColor, TextBackgroundColor);
	cout << "Чтобы вернутся, нажмите любую клавишу.";
	_getch();
}