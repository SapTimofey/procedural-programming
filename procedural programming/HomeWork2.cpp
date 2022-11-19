#include "HomeWork2.h"

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

//Задание 1 "Конус"
void cone()
{
    system_cls();
    float R = 0, h = 0, r = 0;
    double l;
    const double PI = 3.141592653589793;

    cout << "Задание 'Конус'\n";
    R = chek(1, "Введите значение для нижнего радиуса R: ", false);

    r = chek(1, "Введите значение для верхнего радиуса r: ", false);

    h = chek(1, "Введите значение для высоты h: ", false);

    l = sqrt(pow(h, 2) + pow((R - r), 2)); //Расчёт длины образующей

    cout << "Объём V = " << 1. / 3 * PI * h * (pow(R, 2) + R * r + pow(r, 2)) << endl << "Площадь S = " << PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    
    ExitToMenu();
}

//Задание 2 "Разветвление"
void branching()
{
    system_cls();
    float x = 0, a = 0;

    cout << "Задание 'Разветвление' (Дробные числа писать через запятую.)\n";
    
    cout << "Введите значения для переменных x, a: ";
    cin >> x >> a;
        

    if (abs(x) < 1 && x != 0) cout << "w = " << a * log(abs(x)) << endl;
    else
    {
        if ((a - pow(x, 2)) >= 0) cout << "w = " << sqrt(a - pow(x, 2)) << endl;
        else cout << "Корень из отрицательного числа невозможен.\n";
    }

    ExitToMenu();
}

//Задание 3 "Функция"
void function()
{
    system_cls();
    float x = 0, y = 0, b = 0;

    cout << "Задание 'Функция'\n" << "Введите значения для переменных x, y, b: ";

    cin >> x >> y >> b;

    if (b - y > 0 && b - x >= 0) cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    else if (b - y <= 0) cout << "b-y должна быть больше 0.\n";
    else cout << "b-x должна быть больше, либо равна 0.\n";

    ExitToMenu();
}

//Задание 4 "Порядок"
void sequence()
{
    system_cls();
    int g;
    float N = 0;

    cout << "Задание 'Порядок'\n";
    N = chek(0, "Введите число N: ", false);

    cout << "Последовательность из 10 чисел: " << N - 1;
    for (N, g = 0; g <= 8; N++, g++) cout << ", " << N;

    ExitToMenu();
}

//Задание 5 "Табуляция"
void tabulation()
{
    system_cls();
    float x;

    cout << "Задание 'Табуляция'\n";
    for (x = -4; x <= 4; x += 0.5)
    {
        if (x != 1.0) cout << "При x равном: " << x << " \t" << " Значение выражения равно: " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        else cout << "При x равном: " << x << " \t" << " Значение выражения неопределено.\n";
    }

    ExitToMenu();
}

//Меню дз 2
void menu_HW2()
{
    keyboard KEY;

    int key = 0;

    string cons_out[5] = { "Задание 1 'Конус'", "Задание 2 'Разветвление'", "Задание 3 'Функция'", "Задание 4 'Порядок'", "Задание 5 'Табуляция'" };

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Д/з 2------------" << endl;
            for (int i = 0; i < 5; i++)
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
            if (key == KeyDown && num < 5 - 1) num++;
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
            cone();
            break;
        case 2:
            branching();
            break;
        case 3:
            function();
            break;
        case 4:
            sequence();
            break;
        case 5:
            tabulation();
            break;
        }
    }
}
