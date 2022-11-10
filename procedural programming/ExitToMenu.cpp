#include <iostream> //Для cin/cout
#include <locale>   //Для вывода русским
#include <conio.h>  //Для считывания клавиш

using namespace std;

void ExitToMenu()
{
	char ch;
	cout << "Чтобы вернутся, нажмите любой символ.";
	ch = _getch();
}