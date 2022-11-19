#include "keyboard.h"

int keyboard::get_key()
{
    int key = _getch();
    if (_kbhit())        // проверяем есть ли в очереди еще символы
    {                    // если есть - значит нажата спец.клавиша
        key = _getch();  // считываем следующий символ
        switch (key)
        {
        case 75: return 300;
        case 72: return 301;
        case 77: return 302;
        case 80: return 303;
        }
    }
    return key;
}

std::string keyboard::Key_translation(int key)
{
    switch (key)
    {
    case 13: return "Enter";
    case 8: return "Backspace";
    case 32: return "Space";
    case 27: return "ESC";
    case 300: return "Left";
    case 301: return "Up";
    case 302: return "Right";
    case 303: return "Down";
    default: return std::to_string((char)key);
    }
}
