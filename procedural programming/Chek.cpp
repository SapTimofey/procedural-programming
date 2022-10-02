#include <iostream> //��� case1
#include <locale>   //��� ������ �������
#include <string>   //��� �������� string -> int/float

using namespace std;

//�������� �� ����
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
        cout << "������� ������� �����.\n";
        return false;
    }
    catch (...)
    {
        if (i) system("cls");
        cout << s << " - ��� �� �����.\n";
        return false;
    }
}
