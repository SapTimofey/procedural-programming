#include <iostream> //Для case1
#include <locale>   //Для вывода русским
#include <string>   //Для перевода string -> int/float

using namespace std;

//Проверка на ввод
int chek(string s, bool i)
{
    int f;
    try
    {
        f = stoi(s);
        return true;
    }
    catch (std::out_of_range)
    {
        if (i) system("cls");
        cout << "Слишком большое число.\n";
        return false;
    }
    catch (...)
    {
        if (i) system("cls");
        cout << s << " - это не число.\n";
        return false;
    }
}
