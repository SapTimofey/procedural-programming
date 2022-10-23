#include <iostream> //Для chek
#include <locale>   //Для вывода русским
#include <string>   //Для перевода string -> int/float

using namespace std;

//Проверка на ввод
float chek(int type, string cons_out, bool main)
{
    string num;
    float Fnum = 0;
    float s = 0, n1 = 0, n2 = 0;
    
    do
    {
        try
        {
            cout << cons_out;
            cin >> num;
            Fnum = stof(num);
            n1 = Fnum;
            n2 = modf(n1, &s);
            switch (type)
            {
            case 1: // Для числа большего 0.
                if (Fnum > 0) return Fnum;
                else
                {
                    cout << "Число должно быть больше 0.\n";
                    break;
                }
            case 2: // Для угла.
                if (Fnum > 0 && Fnum < 180) return Fnum;
                else
                {
                    cout << "Угол должен быть в пределах (0, 180).\n";
                    break;
                }
            case 3: // Для меню.
                if (n2 == 0) return Fnum;
                else
                {
                    system("cls");
                    cout << "Число должно быть целым.\n";
                    break;
                }
            default:// Для остальных случаев.
                return Fnum;
            }
        }
        catch (out_of_range)
        {
            if (main) system("cls");
            cout << "Слишком большое число.\n";
        }
        catch (...)
        {
            if (main) system("cls");
            cout << num << " - это не число.\n";
        }
    } while (true);
}
