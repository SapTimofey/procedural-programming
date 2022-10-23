#include <iostream> //��� chek
#include <locale>   //��� ������ �������
#include <string>   //��� �������� string -> int/float

using namespace std;

//�������� �� ����
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
            case 1: // ��� ����� �������� 0.
                if (Fnum > 0) return Fnum;
                else
                {
                    cout << "����� ������ ���� ������ 0.\n";
                    break;
                }
            case 2: // ��� ����.
                if (Fnum > 0 && Fnum < 180) return Fnum;
                else
                {
                    cout << "���� ������ ���� � �������� (0, 180).\n";
                    break;
                }
            case 3: // ��� ����.
                if (n2 == 0) return Fnum;
                else
                {
                    system("cls");
                    cout << "����� ������ ���� �����.\n";
                    break;
                }
            default:// ��� ��������� �������.
                return Fnum;
            }
        }
        catch (out_of_range)
        {
            if (main) system("cls");
            cout << "������� ������� �����.\n";
        }
        catch (...)
        {
            if (main) system("cls");
            cout << num << " - ��� �� �����.\n";
        }
    } while (true);
}
