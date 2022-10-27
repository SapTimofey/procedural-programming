#include <iostream> //��� chek
#include <locale>   //��� ������ �������
#include <string>   //��� �������� string -> int/float

using namespace std;

//�������� �� ����
float chek(int type, string cons_out, bool main)
{
    setlocale(LC_NUMERIC, "eng");
    string num;
    float Fnum = 0;
    float s = 0, n = 0;
    
    do
    {
        try
        {
            cout << cons_out;
            cin >> num;
            Fnum = stof(num);
            n = modf(Fnum, &s);
            switch (type)
            {
            case 1: // ��� ����� �������� 0.
                if (Fnum > 0) return Fnum;
                else
                {
                    cout << num << " - ����� ������ ���� ������ 0.\n";
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
                if (n == 0) return Fnum;
                else
                {
                    system("cls");
                    cout << num << " - ����� ������ ���� �����.\n";
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
