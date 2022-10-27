#include <iostream>    //��� case3
#include <locale>      //��� ������ �������
#include <windows.h>   //��� ����� �������
#include <cmath>       //��� ���������� ���������
#include <fstream>     //��� ������ � ������
#include <string>      //��� �������� string -> int/float, int -> string
#include "Chek.h"      //������ ��������
#include <ctime>       //��� ��������� ��������� �����
#include <algorithm>   //��� ����������
#include "ExitToMenu.h"//��� ������

using namespace std;

//�������� �����
void file()
{
    ofstream fout("test_HW.txt");
    fout.close();
}

// �/� 3

//������� 1 "���"
void loan()
{
    system("cls");
    float S = 0, n = 0, p = 0, r = 0, m = 0, n_chek = 0, n_chek2 = 0;
    cout << "������� '���'\n";

    S = chek(1, "������� S: ", false);
    n = chek(1, "������� n: ", false);
    p = chek(0, "������� p: ", false);

    n_chek = modf(n, &n_chek2);

    r = p / 100; //����
    if (S >= 0 && n > 0 && ((n_chek == 0 && p != -200) || (n_chek != 0 && p >= -100)))
    {
        m = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
        cout << "���� �������� ������� ���������� " << m << " ������.\n";
    }
    else if (p == 0)
    {
        m = S / (12 * n);
        cout << "���� �������� ������� ���������� " << m << " ������.\n";
    }
    else if (n == 0) cout << "���� ������� ���������� " << S << " ������.\n";
    else if (n_chek != 0 && p < -100) cout << "��� ������� n � p ������ -100, ��������� �� ��������.\n";
    else if (p == -200)
    {
        m = (-1) * S / (12 * n);
        cout << "���� �������� ������� ���������� " << m << " ������.\n";
    }
    else cout << "S, n ������ ���� ������ 0.\n";

    ExitToMenu();
}

//������� 2 "�����"
void loan2()
{
    system("cls");
    float S = 0, n = 0, m = 0, p = 0;
    double r = 0.1, m_chek = 0;

    cout << "������� '�����'\n";

    cout << "������� S, n, m: ";
    cin >> S >> n >> m;
    if (m == S / (n * 12)) cout << "�������, ��� ������� ���� ���, �����:  " << 0 << endl;
    else if (S > 0 && n > 0 && m > 0)
    {
        m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));

        if (m > m_chek)
        {
            while (m > m_chek)
            {
                if (m - m_chek > 1)
                {
                    r += 0.1;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
                else
                {
                    r += 0.0001;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
            }
        }
        else if (m < m_chek)
        {
            while (m < m_chek)
            {
                if (m_chek - m > 1)
                {
                    r -= 0.1;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
                else
                {
                    r -= 0.0001;
                    m_chek = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));
                }
            }
        }
        cout << "�������, ��� ������� ���� ���, �����:  " << r * 100 << endl;
    }
    else if (S == 0) cout << "�� �� ����� ������.\n";
    else cout << "S ������ ���� ���������������, n, m - ������ 0.\n";

    ExitToMenu();
}

//������� 3 "����������� �����"
void copying_file()
{
    file();
    system("cls");
    char f_read[100];
    string str;
    ofstream fout;
    int len = 0;
    
    cout << "������� '����������� �����'\n" << "������� ������ ��� ������ � ����: ";
    
    cin >> str;
    //������ 1 ������ � ����
    fout.open("test_HW.txt");
    fout << str << endl;
    fout.close();
    
    //������ 1 ������ �� �����
    ifstream fin("test_HW.txt");
    fin >> f_read;
    fin.close();
    len = str.length();
    cout << "������ ������: " << f_read << endl;

    //������ 2 ������ � ����
    cout << "������� 2 ������ ��� ������ � ����: ";
    cin >> str;
    fout.open("test_HW.txt", ios::app);
    fout << str;
    fout.close();

    //������ 2 ������ �� �����
    ifstream fin2("test_HW.txt");
    fin2.seekg(len);
    fin2 >> f_read;
    fin2.close();
    cout << "������ ������: " << f_read << endl;

    ExitToMenu();
}

//������� 4 "������"
void filter()
{
    file();
    system("cls");
    ofstream fout;
    string str_output, str_file, str;
    bool flag = false;
    cout << "������� '������'\n" << "������� ������: ";
    
    cin >> str;

    //������ ������ � ����
    fout.open("test_HW3.txt");
    fout << str;
    fout.close();
    
    //������ ������ �� �����
    ifstream fin("test_HW3.txt");
    fin >> str_file;
    fin.close();
    
    //���������� ������
    for (int i = 0; i < str.length(); i++)
    {
        do
        {
            if (isdigit(str_file[i]))
            {
                flag = true;
                str_output += str_file[i];
                break;
            }
            else if (flag)
            {
                str_output += " ";
                flag = false;
                break;
            }
            else break;
            
        } while (true);
    }
    cout << "������ ����� ����������: " << str_output;

    ExitToMenu();
}

//������� 5 "���������� ����"
void sorting_letters()
{
    file();
    system("cls");

    ofstream fout;
    int const SIZE = 30;
    int arr[SIZE]{}, num_ENG = 65, num_eng = 97, num_RUS = -64, num_rus = -32, flag_ENG = 0, flag_RUS = 0, a = 0;
    string str_output, str, str_file;

    cout << "������� '���������� ����'\n" << "������� ������: ";

    cin >> str;

    //������ ������ � ����
    fout.open("test_HW.txt");
    fout << str;
    fout.close();

    //������ ������ �� �����
    ifstream fin("test_HW.txt");
    fin >> str_file;
    fin.close();

    //������� ������� � ����� ASCII
    for (int i = 0; i < SIZE; i++)
    {
        char x = str_file[i];
        a = x;
        arr[i] = a;
        if (i >= SIZE)
            arr[i] = 1000;
    }

    //����������
    while (flag_ENG < SIZE)
    {
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_ENG) str_output += (char)arr[i];
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_eng) str_output += (char)arr[i];
        num_ENG++;
        num_eng++;
        flag_ENG++;
    }
    while (flag_RUS < SIZE)
    {
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_RUS) str_output += (char)arr[i];
        for (int i = 0; i < SIZE; i++) if (arr[i] == num_rus) str_output += (char)arr[i];
        num_RUS++;
        num_rus++;
        flag_RUS++;
    }
        
    cout << "������ ����� ����������: " << str_output;

    ExitToMenu();
}

//������� ����� �� 3
int case3()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string cons_out = "������� 1 '���'\n������� 2 '�����'\n������� 3 '����������� �����'\n������� 4 '������'\n������� 5 '���������� ����'\n0 ��������� � ������ �/�.\n������� ����� �������: ";
    bool chek_hw3 = true;
    system("cls");
    while (chek_hw3)
    {
        switch ((int)chek(3, cons_out, true))
        {
        default:
            system("cls");
            cout << "��� ������ �������.\n";
            break;
        case 1:
            loan();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 2:
            loan2();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 3:
            copying_file();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 4:
            filter();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 5:
            sorting_letters();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 0:
            system("cls");
            cout << "�� ��������� �����.\n";
            chek_hw3 = false;
        }
    }
    chek_hw3 = true;
}
