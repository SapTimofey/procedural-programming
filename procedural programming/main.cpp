#include "main.h"

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

extern std::list <std::string> error_load;

int load = 0;

//Главная часть
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    keyboard KEY;

    int* l = &load;
    int k = 0;
    if (load == 0) k = load_save();

    int key = 0;

    const int volume = 7;
    std::string cons_out[volume] = {"Д/з 1", "Д/з 2", "Д/з 3", "Д/з 4", "Д/з 5", "База заданий", "Настройки"};

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();

            std::cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Выбор Д/з------------\n";

            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    std::cout << cons_out[i];
                    setColor(TextColor, TextBackgroundColor);
                    std::cout << "\n";
                }
                else std::cout << cons_out[i] << "\n";
            }

            if (k == 2)
            {
                *l = 5;
                k = 8;
                std::cout << "-------------------------------------------\n";
                std::cout << "Ошибка при загрузке:\n";
                copy(error_load.begin(), error_load.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
                std::cout << "Будут использоваться значения по умолчанию.\n";
                std::cout << "-------------------------------------------\n";
            }
            else if (k == 1)
            {
                *l = 5;
                k = 8;
                std::cout << "-----------------------------\n";
                std::cout << "Успешная загрузка сохранения.\n";
                std::cout << "-----------------------------\n";
            }
            else if (k == 3)
            {
                *l = 5;
                k = 8;
                std::cout << "-------------------------------------------\n";
                std::cout << "Не удалось открыть файл сохранения.\n";
                std::cout << "Будут использоваться значения по умолчанию.\n";
                std::cout << "-------------------------------------------\n";
            }

            key = KEY.get_key();
            if (key == KeyDown && num < volume - 1) num++;
            if (key == KeyUp && num > 0) num--;
            if (key == KeyExit)
            {
                std::cout << "Вы завершили работу.\n";
                exit(EXIT_SUCCESS);
            }
        } while (key != KeyEnter);
        switch (num + 1)
        {
        case 1:
            menu_HW1(); // Д/з 1
            break;
        case 2:
            menu_HW2(); // Д/з 2
            break;
        case 3:
            menu_HW3(); // Д/з 3
            break;
        case 4:
            menu_HW4(); // Д/з 4
            break;
        case 5:
            menu_HW5(); // Д/з 5
            break;
        case 6:
            menu_TD(); // База заданий
            break;
        case 7:
            Settings(); // Настройки
            break;
        }
        
    }
}
