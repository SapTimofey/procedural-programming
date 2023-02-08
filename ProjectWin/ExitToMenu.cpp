#include "ExitToMenu.h"

extern int TextColor;
extern int TextBackgroundColor;

void ExitToMenu()
{
	setColor(TextColor, TextBackgroundColor);
	std::cout << "Чтобы вернутся, нажмите любую клавишу.";
	_getch();
}
