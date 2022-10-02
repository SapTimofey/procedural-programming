#include <iostream> //��� case2
#include <locale>   //��� ������ �������
#include <windows.h>//��� ����� �������
#include <cmath>    //��� ���������� ���������
#include <string>   //��� �������� string -> int/float
#include "Chek.h"   //������ ��������

using namespace std;

// �/� 2

//������� "�����"
void cone()
{
    system("cls");
    string R_test, h_test, r_test, i = "no";
    float R = 0, h = 0, r = 0;
    double l;
    bool R_TF, h_TF, r_TF;
    const double PI = 3.141592653589793;

    cout << "������� '�����'\n";
    
    //������ �������� ������������ ����� R
    do
    {
        cout << "������� �������� ��� ������� ������� R: ";
        cin >> R_test;
        R_TF = chek(R_test, false);
        if (R_TF)
        {
            R = stof(R_test);
            if (R <= 0)
            {
                cout << "R ������ ���� ������ 0.\n";
                R_TF = false;
            }
        }
    } while (R_TF == false);

    //������ �������� ������������ ����� r
    do
    {
        cout << "������� �������� ��� �������� ������� r: ";
        cin >> r_test;
        r_TF = chek(r_test, false);
        if (r_TF)
        {
            r = stof(r_test);
            if (r <= 0)
            {
                cout << "r ������ ���� ������ 0.\n";
                r_TF = false;
            }
        }
    } while (r_TF == false);

    //������ �������� ������������ ����� h
    do
    {
        cout << "������� �������� ��� ������ h: ";
        cin >> h_test;
        h_TF = chek(h_test, false);
        if (h_TF)
        {
            h = stof(h_test);
            if (h <= 0)
            {
                cout << "h ������ ���� ������ 0.\n";
                h_TF = false;
            }
        }
    } while (h_TF == false);

    l = sqrt(pow(h, 2) + pow((R - r), 2)); //������ ����� ����������

    cout << "����� V = " << 1. / 3 * PI * h * (pow(R, 2) + R * r + pow(r, 2)) << endl << "������� S = " << PI * (pow(R, 2) + (R + r) * l + pow(r, 2)) << endl;
    
    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� "������������"
void branching()
{
    system("cls");
    string i = "no";
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

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� "�������"
void function()
{
    system("cls");
    string i = "no";
    float x = 0, y = 0, b = 0;


    cout << "������� '�������'\n";

    cout << "������� �������� ��� ���������� x, y, b: ";
    cin >> x >> y >> b;


    if (b - y > 0 && b - x >= 0) cout << "z = " << log(b - y) * sqrt(b - x) << endl;
    else if (b - y <= 0) cout << "b-y ������ ���� ������ 0.\n";
    else cout << "b-x ������ ���� ������, ���� ����� 0.\n";

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");

}

//������� "�������"
void sequence()
{

    system("cls");
    string N_test, i = "no";
    int N, g;
    bool N_TF;

    cout << "������� '�������'\n";
    
    //������ �������� ������������ ����� N
    do
    {
        cout << "������� ����� N: ";
        cin >> N_test;
        N_TF = chek(N_test, false);
        if (N_TF) N = stoi(N_test);
    } while (N_TF == false);

    cout << "������������������ �� 10 �����: " << N - 1;
    for (N, g = 0; g <= 8; N++, g++) cout << ", " << N;

    //������ ������ � ����
    do
    {
        cout << endl << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� "���������"
void tabulation()
{
    system("cls");
    float x;
    string i = "no";

    cout << "������� '���������'\n";
    for (x = -4; x <= 4; x += 0.5)
    {
        if (x != 1.0) cout << "��� x ������: " << x << " \t" << " �������� ��������� �����: " << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        else cout << "��� x ������: " << x << " \t" << " �������� ��������� ������������.\n";
    }
    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� ����� �� 2
int case2()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string hw2;
    bool chek_hw2 = true;
    system("cls");
    while (chek_hw2)
    {
        cout << "������� 1 '�����'\n" << "������� 2 '������������'\n" << "������� 3 '�������'\n" << "������� 4 '�������'\n" << "������� 5 '���������'\n" << "0 ��������� � ������ �/�.\n" << "������� ����� �������: ";
        cin >> hw2;
        if (chek(hw2, true))
        {
            switch (stoi(hw2))
            {
            default:
                system("cls");
                cout << stoi(hw2) << " - ��� ������ �������.\n";
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
    }
    chek_hw2 = true;
}