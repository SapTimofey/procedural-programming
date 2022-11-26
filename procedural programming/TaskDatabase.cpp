#include "TaskDatabase.h"

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;


void miniCalc()
{
    system_cls();
    keyboard KEY;

    int num1 = 0;
    int num2 = 0;
    int key = 0;
    const int volume = 4;

    string cons_out[volume] = { "Сложение", "Вычитание", "Умножение", "Деление" };

    int num = 0;

    cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------А.М.В. 5------------" << endl;

    num1 = chek(0, "Введите первое число: ", false);
    while (num2 == 0)
    {
        num2 = chek(0, "Введите второе число: ", false);
        if (num2 == 0) cout << "Число не может равняться 0.\n";
    }


    while (true)
    {
        do
        {
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------А.М.В. 5------------" << endl << "Выбирите действие над числами: " << num1 << " и " << num2 << "\n----------------------------\n";
            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    cout << cons_out[i];
                    setColor(TextColor, TextBackgroundColor);
                    cout << endl;
                }
                else cout << cons_out[i] << endl;
            }

            key = KEY.get_key();
            if (key == KeyDown && num < volume - 1) num++;
            if (key == KeyUp && num > 0) num--;
            if (key == KeyExit)
            {
                system_cls();
                return;
            }
        } while (key != KeyEnter);
        switch (num + 1)
        {
        case 1:
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------А.М.В. 5------------" << endl;

            cout << "Сумма чисел " << num1 << " и " << num2 << " равна: " << num1 + num2 << endl;
            ExitToMenu();
            return;
        case 2:
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------А.М.В. 5------------" << endl;

            cout << "Разность чисел " << num1 << " и " << num2 << " равна: " << num1 - num2 << endl;
            ExitToMenu();
            return;
        case 3:
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------А.М.В. 5------------" << endl;

            cout << "Произведение чисел " << num1 << " и " << num2 << " равно: " << num1 * num2 << endl;
            ExitToMenu();
            return;
        case 4:
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------А.М.В. 5------------" << endl;

            cout << "Частное чисел " << num1 << " и " << num2 << " равно: " << num1 / num2 << endl;
            ExitToMenu();
            return;
        }
    }

}


//Меню базы заданий
void menu_TD()
{
    keyboard KEY;

    int key = 0;
    const int volume = 5;

    string cons_out[volume] = { "Задание 1 'А.М.В. 5'", "Задание 2 'Решето Эратосфена'", "Задание 3 'Обработка текстовых файлов'", "Задание 4 'Обработка текстовых файлов'", "Задание 5 'Ряды'" };

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Д/з 5------------" << endl;
            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    cout << cons_out[i];
                    setColor(TextColor, TextBackgroundColor);
                    cout << endl;
                }
                else cout << cons_out[i] << endl;
            }

            key = KEY.get_key();
            if (key == KeyDown && num < volume - 1) num++;
            if (key == KeyUp && num > 0) num--;
            if (key == KeyExit)
            {
                system_cls();
                return;
            }
        } while (key != KeyEnter);
        switch (num + 1)
        {
        case 1:
            miniCalc();
            break;
        case 2:
            eratosthenes();
            break;
        case 3:
            file_read_1();
            break;
        case 4:
            file_read_2();
            break;
        case 5:
            rows_1();
            break;
        }
    }
}