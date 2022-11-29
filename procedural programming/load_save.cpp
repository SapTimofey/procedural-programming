#include "load_save.h";  

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

list <string> error_load;

// 1 - успешная загрузка
// 2 - частичная загрузка сохранения
// 3 - не удалось открыть файл сохранения

int load_save()
{
    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;
    int* KeyU = &KeyUp;
    int* KeyD = &KeyDown;
    int* KeyEx = &KeyExit;
    int* KeyEn = &KeyEnter;

    string set;
    int i = 0;
    int chek = 0;
    bool flag = true;
    bool KeyEnF = true, KeyExF = true, KeyUF = true, KeyDF = true;
    ifstream fin("Save.txt");

    if (!fin.is_open()) return 3;
    else
    {
        for (i; i < 20; i++)
        {
            fin >> set;
            switch (i)
            {
            case 0:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("TextColor");
                        break;
                    }
                if (flag) *ColorText = stoi(set);
                else flag = true;
                break;
            }
            case 2:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("TextBackgroundColor");
                        break;
                    }
                if (flag) *ColorBackground = stoi(set);
                else flag = true;
                break;
            }
            case 4:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyExit");
                        KeyExF = false;
                        break;
                    }
                if (flag) *KeyEx = stoi(set);
                else flag = true;
                break;
            }
            case 6:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyEnter");
                        KeyEnF = false;
                        break;
                    }
                if (flag) *KeyEn = stoi(set);
                else flag = true;
                break;
            }
            case 8:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyUp");
                        KeyUF = false;
                        break;
                    }
                if (flag) *KeyU = stoi(set);
                else flag = true;
                break;
            }
            case 10:
            {
                for (int j = 0; j < set.length(); j++)
                    if (isdigit(set[j]) == 0)
                    {
                        chek += 1;
                        flag = false;
                        error_load.push_back("KeyDown");
                        KeyDF = false;
                        break;
                    }
                if (flag) *KeyD = stoi(set);
                else flag = true;
                break;
            }
            }
        }
    }

    fin.close();

    if (chek < 10 && chek > 0) return 2;
    else return 1;
}