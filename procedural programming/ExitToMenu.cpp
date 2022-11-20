#include <iostream> //Для ExitToMenu
#include <locale>   //Для вывода русским
#include <conio.h>  //Для считывания клавишь

using namespace std;

void ExitToMenu()
{
	int ch;
	cout << "Чтобы вернутся, введите любой символ.";
	cin >> ch;
}