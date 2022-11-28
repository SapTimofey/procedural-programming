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

    float num1 = 0;
    float num2 = 0;
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

void array_1D()
{
    system_cls();
    srand(time(NULL));
    const int SIZE = 50;
    float arr_1[SIZE]{ 0 };
    float arr_2[SIZE]{ 0 };

    for (int i = 0; i < SIZE; i++)
    {
        if (rand() % 2)
            arr_1[i] = rand() % 100;
        else arr_1[i] = rand() % 100 * (-1);
    }
    cout << "Исходный массив: [";
    for (int i = 0; i < SIZE; i++)
    {
        if (i != SIZE - 1) cout << arr_1[i] << ", ";
        else cout << arr_1[i] << "]" << endl;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (i != 0 && i != SIZE - 1)
        {
            arr_2[i] = (arr_1[i - 1] + arr_1[i] + arr_1[i + 1]) / 3;
        }
        else if (i == 0) arr_2[i] = arr_1[i];
        else if (i == SIZE - 1) arr_2[i] = arr_1[i];

    }
    cout << endl << "Сглаженный массив: [";
    for (int i = 0; i < SIZE; i++)
    {
        if (i != SIZE - 1) cout << arr_2[i] << ", ";
        else cout << arr_2[i] << "]" << endl;
    }
    cout << endl;
    ExitToMenu();
}

void array_2D()
{
    system_cls();
    srand(time(NULL));
    int SIZEx = 0;
    int SIZEy = 0;
    cout << "Задание 3 \"Двумерный массив 57\"" << endl;
    while (SIZEx > 100 || SIZEx < 1)
    {
        SIZEx = (int)chek(5, "Введите количество столбцов: ", false);
        if (SIZEx > 100) cout << "Количество столбцов должно не больше 100.\n";
        /*else if (SIZEx < 2) cout << "Количество столбцов должно быть не меньше 1.\n";*/
    }
    while (SIZEy > 100 || SIZEy < 1)
    {
        SIZEy = (int)chek(5, "Введите количество строк: ", false);
        if (SIZEy > 100) cout << "Количество строк должно не больше 100.\n";
        /*else if (SIZEy < 2) cout << "Количество строк должно быть не меньше 1.\n";*/
    }
    float a = 0;
    float* arr_2 = new float[SIZEx];
    float** arr = new float* [SIZEy];
    for (int i = 0; i < SIZEy; i++)
        arr[i] = new float[SIZEx];

    string cons_out;

    for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
        {
            if (rand() % 2)
                arr[i][j] = rand() % 100;
            else arr[i][j] = rand() % 100 * (-1);
        }
    }
    cout << endl << "Матрица [" << SIZEx << " x " << SIZEy << "]" << endl;
    for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
        {
            cout << setw(5) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < SIZEx; i++)
    {
        a = 0;
        cons_out = "";
        cout << right << "Среднее арифметическое " << setw(3) << i + 1 <<" столбца: ";
        for (int j = 0; j < SIZEy; j++)
        {
            a += arr[j][i];
            if (j == 0)
            {
                if (arr[j][i] < 0)
                    cons_out += "((" + to_string((int)arr[j][i]) + ") + ";
                else cons_out += "(" +to_string((int)arr[j][i]) + " + ";
            }
            else if (j != SIZEy - 1)
            {
                if (arr[j][i] < 0)
                    cons_out += "(" + to_string((int)arr[j][i]) + ") + ";
                else cons_out += to_string((int)arr[j][i]) + " + ";
            }
                
            else
            {
                if (arr[j][i] < 0)
                    cons_out += "(" + to_string((int)arr[j][i]) + ")";
                else cons_out += to_string((int)arr[j][i]);
            }
        }
        arr_2[i] = a / SIZEy;
        cons_out += ") / " + to_string(SIZEy);
        cout << left << setw(43) << cons_out << " = " << arr_2[i] << endl;
    }

    

    for (int i = 0; i < SIZEy; i++)
        delete[] arr[i];
    delete[] arr;
    

    cout << endl << "Массив средних арифметических: [";
    for (int i = 0; i < SIZEx; i++)
    {
        if (i != SIZEx - 1) cout << arr_2[i] << ", ";
        else cout << arr_2[i] << "]" << endl;
    }
    cout << endl;
    delete[] arr_2;
    ExitToMenu();
}

//Меню базы заданий
void menu_TD()
{
    keyboard KEY;

    int key = 0;
    const int volume = 5;

    string cons_out[volume] = { "Задание 1 \"Алгоритмы Множественного Выбора 5\"", "Задание 2 \"Одномерные Массивы 36\"", "Задание 3 \"Двумерный массив 57\"", "Задание 4 'Обработка текстовых файлов'", "Задание 5 'Ряды'" };

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
            array_1D();
            break;
        case 3:
            array_2D();
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