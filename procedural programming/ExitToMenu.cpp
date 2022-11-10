#include <iostream> //Для ExitToMenu
#include <locale>   //Для вывода русским
#include <conio.h>  //Для считывания клавишь

using namespace std;

void ExitToMenu()
{
	char ch;
	cout << "Чтобы вернутся, нажмите любой символ.";
	ch = _getch();
}