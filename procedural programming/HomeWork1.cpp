#include <iostream> //��� case1
#include <locale>   //��� ������ �������
#include <cmath>    //��� ���������� ���������
#include <windows.h>//��� ����� �������
#include <string>   //��� �������� string -> int/float
#include "Chek.h"   //������ ��������

using namespace std;

// �/� 1

//������� "���"
void Name()
{
    string i = "no";
    system("cls");
    cout << "������� '���'\n" << "�������\n";
    
    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� "����������"
void arithmetic()
{
    system("cls");
    string i = "no";
    float a = 0, b = 0;

    cout << "������� '����������' (������� ����� ������ ����� �������.)\n";
    

    cout << "������� ����� a, b: ";
    cin >> a >> b;

    

    cout << "a+b=" << a + b << endl << "a-b=" << a - b << endl << "a*b=" << a * b << endl;
    if (b != 0) cout << "a/b=" << a / b << endl;
    else cout << "������ �� ���� ������.\n";

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� "���������"
void equation()
{
    system("cls");
    string i = "no";
    float b = 0, c = 0;


    cout << "������� '���������' (������� ����� ������ ����� �������.)\n";
    

    cout << "������� �������� ��� ���������� b, c: ";
    cin >> b >> c;
    
    if (b == 0 && c == 0) cout << "x ����� ��������� ����� ��������.\n";
    else if (b == 0) cout << "��� �������.\n";
    else cout << "x=" << -c / b << endl;


    
    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� "��� ���������"
void another_equation()
{
    system("cls");
    string i = "no";
    float a = 0, b = 0, c = 0;
    double D;

    cout << "������� '��� ���������'\n";

    cout << "������� �������� ��� ���������� a, b, c: ";
    cin >> a >> b >> c;
    
    if (a == 0 && b == 0 && c == 0) cout << "x ����� ��������� ����� ��������.\n";
    else if (a == 0 && c == 0) cout << "��� �������.\n";
    else if (a == 0) cout << "x=" << -c / b << endl;
    else
    {
        D = pow(b, 2) - 4 * a * c;//������ �������������

        if (D > 0) cout << "x1=" << (-b + sqrt(D)) / (2 * a) << endl << "x2=" << (-b - sqrt(D)) / (2 * a) << endl;
        else if (D == 0) cout << "x=" << -b / (2 * a);
        else cout << "��� ������ ����� ������������ �����.\n";
    }
    
    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� "����� �� ������"
void lamp()
{
    system("cls");
    string day, curtains, lamp, d, c, l, i = "no";
    bool day1 = false, curtains1 = false, lamp1 = false, res, chek_d = false, chek_c = false, chek_l = false;
    
    cout << "������� '����� �� ������'\n";
    
    //������ �������� ������������ ����� day
    do
    {
        cout << "�� ����� ����? (��, ���): ";
        cin >> d;
        if (d == "��" || d == "���")
        {
            day = d;
            chek_d = true;
        }
        else cout << "� ������ �������� �� ��� ���.\n";
    } while (chek_d == false);

    //������ �������� ������������ ����� curtains
    do
    {
        cout << "����� ����������? (��, ���): ";
        cin >> c;
        if (c == "��" || c == "���")
        {
            curtains = c;
            chek_c = true;
        }
        else cout << "� ������ �������� �� ��� ���.\n";
    } while (chek_c == false);

    //������ �������� ������������ ����� lamp
    do
    {
        cout << "���� �������? (��, ���): ";
        cin >> l;
        if (l == "��" || l == "���")
        {
            lamp = l;
            chek_l = true;
        }
        else cout << "� ������ �������� �� ��� ���.\n";
    } while (chek_l == false);

    if (day == "��") day1 = true;
    if (curtains == "��") curtains1 = true;
    if (lamp == "��") lamp1 = true;

    res = (day1 and curtains1) or lamp1;

    if (res) cout << "� ������� ������.\n";
    else cout << "� ������� �����.\n";

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� ����� �� 1
int case1()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string hw1;
    bool chek_hw1 = true;
    system("cls");
    while (chek_hw1)
    {
        cout << "������� 1 '���'\n" << "������� 2 '����������'\n" << "������� 3 '���������'\n" << "������� 4 '��� ���������'\n" << "������� 5 '����� �� ������'\n" << "0 ��������� � ������ �/�.\n" << "������� ����� �������: ";
        cin >> hw1;
        if (chek(hw1, true))
        {
            switch (stoi(hw1))
            {
            default:
                system("cls");
                cout << stoi(hw1) << " - ��� ������ �������.\n";
                break;
            case 1:
                Name();
                system("cls");
                cout << "�� ��������� � ������ �������.\n";
                break;
            case 2:
                arithmetic();
                system("cls");
                cout << "�� ��������� � ������ �������.\n";
                break;
            case 3:
                equation();
                system("cls");
                cout << "�� ��������� � ������ �������.\n";
                break;
            case 4:
                another_equation();
                system("cls");
                cout << "�� ��������� � ������ �������.\n";
                break;
            case 5:
                lamp();
                system("cls");
                cout << "�� ��������� � ������ �������.\n";
                break;
            case 0:
                system("cls");
                cout << "�� ��������� �����.\n";
                chek_hw1 = false;
            }
        }
    }
    chek_hw1 = true;
}
