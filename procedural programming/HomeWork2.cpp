#include <iostream>    //��� case2
#include <locale>      //��� ������ �������
#include <windows.h>   //��� ����� �������
#include <cmath>       //��� ���������� ���������
#include <string>      //��� �������� string -> int/float
#include "Chek.h"      //������ ��������
#include "ExitToMenu.h"//������ ������

using namespace std;

// �/� 2

//������� 1 "�����"
void cone()
{
    system("cls");
    float R = 0, h = 0, r = 0;
    double l;
    const double PI = 3.141592653589793;

    cout << "������� '�����'\n";
    R = chek(1, "������� �������� ��� ������� ������� R: ", false);

    r = chek(1, "������� �������� ��� �������� ������� r: ", false);

    h = chek(1, "������� �������� ��� ������ h: ", false);

    l = sqrt(pow(h, 2) + pow((R - r), 2)); //������ ����� ����������

    cout << "����� V = " << 1. / 3 * PI * h * (pow(R, 2) + R * r + pow(r, 2)) << endl << "������� S = " << PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    
    ExitToMenu();
}

//������� 2 "������������"
void branching()
{
    system("cls");
    float x = 0, a = 0;

    cout << "������� '������������' (������� ����� ������ ����� �������.)\n";
    
    cout << "������� �������� ��� ���������� x, a: ";
    cin >> x >> a;
        

    if (abs(x) < 1 && x != 0) cout << "w = " << a * log(abs(x)) << endl;
    else
    {
        if ((a - pow(x, 2)) >= 0) cout << "w = " << sqrt(a - pow(x, 2)) << endl;
        else cout << "������ �� �������������� ����� ����������.\n";
    }

    ExitToMenu();
}

//������� 3 "�������"
void function()
{
    system("cls");
    float x = 0, y = 0, b = 0;

    cout << "������� '�������'\n" << "������� �������� ��� ���������� x, y, b: ";

    cin >> x >> y >> b;

    if (b - y > 0 && b - x >= 0) cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    else if (b - y <= 0) cout << "b-y ������ ���� ������ 0.\n";
    else cout << "b-x ������ ���� ������, ���� ����� 0.\n";

    ExitToMenu();
}

//������� 4 "�������"
void sequence()
{
    system("cls");
    int N, g;

    cout << "������� '�������'\n";
    N = chek(0, "������� ����� N: ", false);

    cout << "������������������ �� 10 �����: " << N - 1;
    for (N, g = 0; g <= 8; N++, g++) cout << ", " << N;

    ExitToMenu();
}

//������� 5 "���������"
void tabulation()
{
    system("cls");
    float x;

    cout << "������� '���������'\n";
    for (x = -4; x <= 4; x += 0.5)
    {
        if (x != 1.0) cout << "��� x ������: " << x << " \t" << " �������� ��������� �����: " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        else cout << "��� x ������: " << x << " \t" << " �������� ��������� ������������.\n";
    }

    ExitToMenu();
}

//������� ����� �� 2
int case2()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string cons_out = "������� 1 '�����'\n������� 2 '������������'\n������� 3 '�������'\n������� 4 '�������'\n������� 5 '���������'\n0 ��������� � ������ �/�.\n������� ����� �������: ";
    bool chek_hw2 = true;
    system("cls");
    while (chek_hw2)
    {
        switch ((int)chek(3, cons_out, true))
        {
        default:
            system("cls");
            cout << "��� ������ �������.\n";
            break;
        case 1:
            cone();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 2:
            branching();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 3:
            function();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 4:
            sequence();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 5:
            tabulation();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 0:
            system("cls");
            cout << "�� ��������� �����.\n";
            chek_hw2 = false;
        }
    }
    chek_hw2 = true;
}