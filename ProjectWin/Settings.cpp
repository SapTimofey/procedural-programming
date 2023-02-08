#include "Settings.h"

// Чёрный - 0
// Синий - 1
// Зелёный - 2
// Голубой - 3
// Красный - 4
// Пурпурный - 5
// Коричневый - 6
// Светло-серый - 7
// Тёмно-серый - 8
// Светло-синий - 9
// Светло-зелёный - 10
// Светло-голубой - 11
// Светло-красный - 12
// Светло-пурпурный - 13
// Жёлтый - 14
// Белый - 15

using namespace std;


int TextColor = 15;
int TextBackgroundColor = 0;
int KeyExit = 27;
int KeyEnter = 13;
int KeyUp = 301;
int KeyDown = 303;

int save = 1;

void system_cls()
{
    setColor(15, 0);
    system("cls");
    setColor(TextColor, TextBackgroundColor);
}

void Color_setting(int type)
{
    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;

    bool flag = true;
    int key = 0;

    int* s = &save;

    keyboard KEY;

    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string cons_out[16] = { 
         "Чёрный",
         "Синий",
         "Зелёный",
         "Голубой",
         "Красный",
         "Пурпурный",
         "Коричневый",
         "Светло-серый",
         "Тёмно-серый",
         "Светло-синий",
         "Светло-зелёный",
         "Светло-голубой",
         "Светло-красный",
         "Светло-пурпурный",
         "Жёлтый",
         "Белый" };

    int num = 0;
    do
    {
        system_cls();
        cout << "Используйте:\n- " << KEY.Key_translation(*KeyU) << ", " << KEY.Key_translation(*KeyD) << " - для передвижения\n- " << KEY.Key_translation(*KeyEn) << " - для выбора\n- " << KEY.Key_translation(*KeyEx) << " - для выхода\n";
        if (type == 1) cout << "--------Выбор цвета текста---------" << endl;
        else cout << "------Выбор цвета фона текста-------" << endl;
        
        for (int i = 0; i < 16; i++)
        {
            if (i == num)
            {
                setColor(TextBackgroundColor, TextColor);
                if (i == *ColorText && type == 1 || i == *ColorBackground && type == 2) cout << cons_out[i] << " - выбран.";
                else if (key == *KeyEn)
                {
                    if (*ColorBackground == num || *ColorText == num) cout << cons_out[i] << " - Нельзя использовать одинаковые цвета для текста и фона.";
                    else
                    {
                        flag = false;
                    }
                }
                else cout << cons_out[i];
                setColor(TextColor, TextBackgroundColor);
                cout << endl;
            }
            else if (i == *ColorText && type == 1 || i == *ColorBackground && type == 2) cout << cons_out[i] << " - выбран." << endl;
            else cout << cons_out[i] << endl;
        }
        if (flag == false) break;

        key = KEY.get_key();
        if (key == *KeyD && num < 16 - 1) num++;
        if (key == *KeyU && num > 0) num--;
        if (key == *KeyEx)
        {
            system_cls();
            return;
        }
    } while (flag);

    if (type == 1) *ColorText = num;
    if (type == 2) *ColorBackground = num;

    ofstream fout("Save.txt");

    fout << *ColorText << "\t\tTextColor" <<
        endl << *ColorBackground << "\t\tTextBackgroundColor" <<
        endl << *KeyEx << "\t\tKeyExit" <<
        endl << *KeyEn << "\t\tKeyEnter" <<
        endl << *KeyU << "\t\tKeyUp" <<
        endl << *KeyD << "\t\tKeyDown";
    fout.close();

    *s = 0;
}

void Key_setting()
{
    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;
    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    int* s = &save;

    keyboard KEY;

    bool flag = true;
    int key = 0;
    const int volume = 4;
    string cons_out[volume] = { "Ввод - ", "Выход - ", "Вверх - ", "Вниз - " };
    int num = 0;

    while (true)
    {
        
        do
        {
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(*KeyU) << ", " << KEY.Key_translation(*KeyD) << " - для передвижения\n- " << KEY.Key_translation(*KeyEn) << " - для выбора\n- " << KEY.Key_translation(*KeyEx) << " - для выхода\n-------Меню назначения клавиш--------" << endl;
            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    cout << cons_out[i];
                    if (i == 0) cout << KEY.Key_translation(*KeyEn);
                    else if (i == 1) cout << KEY.Key_translation(*KeyEx);
                    else if (i == 2) cout << KEY.Key_translation(*KeyU);
                    else if (i == 3) cout << KEY.Key_translation(*KeyD);
                    setColor(TextColor, TextBackgroundColor);
                    cout << endl;
                }
                else
                {
                    cout << cons_out[i];
                    if (i == 0) cout << KEY.Key_translation(*KeyEn) << endl;
                    else if (i == 1) cout << KEY.Key_translation(*KeyEx) << endl;
                    else if (i == 2) cout << KEY.Key_translation(*KeyU) << endl;
                    else if (i == 3) cout << KEY.Key_translation(*KeyD) << endl;
                }
            }
            key = KEY.get_key();
            if (key == *KeyD && num < volume - 1) num++;
            if (key == *KeyU && num > 0) num--;
            if (key == *KeyEx)
            {
                system_cls();
                return;
            }


        } while (key != *KeyEn);

        while (true)
        {
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(*KeyU) << ", " << KEY.Key_translation(*KeyD) << " - для передвижения\n- " << KEY.Key_translation(*KeyEn) << " - для выбора\n- " << KEY.Key_translation(*KeyEx) << " - для выхода\n-------Меню назначения клавиш--------" << endl;
            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    cout << cons_out[i];
                    if (!flag)
                    {
                        setColor(TextColor, TextBackgroundColor);
                        cout << "      ";
                        setColor(TextBackgroundColor, TextColor);
                        if (key == *KeyEn) cout << KEY.Key_translation(*KeyEn);
                        else if (key == *KeyEx) cout << KEY.Key_translation(*KeyEx);
                        else if (key == *KeyU) cout << KEY.Key_translation(*KeyU);
                        else if (key == *KeyD) cout << KEY.Key_translation(*KeyD);
                        cout << " - эта клавиша уже занята.";
                        flag = true;
                    }
                    setColor(TextColor, TextBackgroundColor);
                    cout << endl;
                }
                else
                {
                    cout << cons_out[i];
                    if (i == 0) cout << KEY.Key_translation(*KeyEn) << endl;
                    else if (i == 1) cout << KEY.Key_translation(*KeyEx) << endl;
                    else if (i == 2) cout << KEY.Key_translation(*KeyU) << endl;
                    else if (i == 3) cout << KEY.Key_translation(*KeyD) << endl;
                }
            }
            key = KEY.get_key();

            if (num == 0 && key != *KeyD && key != *KeyU && key != *KeyEx)
            {
                *KeyEn = key;
                break;
            }
            else if (num == 1 && key != *KeyEn && key != *KeyD && key != *KeyU)
            {
                *KeyEx = key;
                break;
            }
            else if (num == 2 && key != *KeyEx && key != *KeyD && key != *KeyEn)
            {
                *KeyU = key;
                break;
            }
            else if (num == 3 && key != *KeyEx && key != *KeyEn && key != *KeyU)
            {
                *KeyD = key;
                break;
            }
            else flag = false;
        }

        ofstream fout("Save.txt");

        fout << *ColorText << "\t\tTextColor" <<
            endl << *ColorBackground << "\t\tTextBackgroundColor" <<
            endl << *KeyEx << "\t\tKeyExit" <<
            endl << *KeyEn << "\t\tKeyEnter" <<
            endl << *KeyU << "\t\tKeyUp" <<
            endl << *KeyD << "\t\tKeyDown";
        fout.close();

        *s = 0;
    }
}

void Settings()
{
    int key = 0;
    const int volume = 5;
    string cons_out[volume] = {"Цвет текста", "Цвет фона текста", "Назначение клавиш", "------------------------------", "Сброс настроек"};

    int* s = &save;

    keyboard KEY;

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n--------Меню настроек---------" << endl;

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
            if (*s == 0)
            {
                *s = 1;
                cout << "--------------------" << endl;
                cout << "Изменения сохранены." << endl;
                cout << "--------------------" << endl;
            }

            key = KEY.get_key();

            if (key == KeyDown && num < volume - 1)
            {
                if (num == volume - 3) num += 2;
                else num++;
            }
            if (key == KeyUp && num > 0)
            {
                if (num == volume - 1) num -= 2;
                else num--;
            }
            if (key == KeyExit)
            {
                system_cls();
                return;
            }

        } while (key != KeyEnter);
        switch (num + 1)
        {
        case 1:
            Color_setting(1);
            break;
        case 2:
            Color_setting(2);
            break;
        case 3:
            Key_setting();
            break;
        case 5: // Сброс настроек
            *s = 0;
            int* ColorText = &TextColor;
            int* ColorBackground = &TextBackgroundColor;

            int* KeyU = &KeyUp;
            int* KeyD = &KeyDown;
            int* KeyEx = &KeyExit;
            int* KeyEn = &KeyEnter;

            *ColorText = 15;
            *ColorBackground = 0;

            *KeyU = 301;
            *KeyD = 303;
            *KeyEx = 27;
            *KeyEn = 13;

            ofstream fout("Save.txt");

            fout << 15 << "\t\tTextColor" <<
                endl << 0 << "\t\tTextBackgroundColor" <<
                endl << 27 << "\t\tKeyExit" <<
                endl << 13 << "\t\tKeyEnter" <<
                endl << 301 << "\t\tKeyUp" <<
                endl << 303 << "\t\tKeyDown";
            
            fout.close();
        }
        
    }
}
