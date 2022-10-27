#include <iostream>    //��� case5
#include <locale>      //��� ������ �������
#include <windows.h>   //��� ����� �������
#include <cmath>       //��� ���������� ���������
#include <fstream>     //��� ������ � ������
#include <map>         //��� map
#include <algorithm>   //��� ����������
#include <string>      //��� �������� string -> int/float, int -> string
#include "Chek.h"      //������ ��������
#include "HomeWork3.h" //������ �/� 3
#include "HomeWork4.h" //������ �/� 4
#include "ExitToMenu.h"//������ ������

using namespace std;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

//������� 1 "�������� �������"
void euclid()
{
    system("cls");
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;

    cout << "������� '�������� �������'\n";
    
    num1 = chek(1, "������� 1 �����: ", false);
    num2 = chek(1, "������� 2 �����: ", false);
    
    num5 = num3 = num1;
    num6 = num4 = num2;

    cout << endl << "����� ���������:" << endl << endl << num5 << " " << num6 << endl;

    while (num5 != num6)
    {
        if (num5 > num6) num5 -= num6;
        else num6 -= num5;
        cout << num5 << " " << num6 << endl;
    }

    cout << "��� (" << num1 << ", " << num2 << ") = " << num5 << endl << endl;


    cout << "����� �������:" << endl << endl << num3 << " " << num4 << endl;

    while (num4 > 0 && num3 > 0)
    {
        if (num3 > num4) num3 %= num4;
        else num4 %= num3;
        cout << num3 << " " << num4 << endl;
    }

    cout << "��� (" << num1 << ", " << num2 << ") = ";
    if (num3 != 0) cout << num3 << endl << endl;
    else cout << num4 << endl << endl;
    
    ExitToMenu();
}

//������� 2 "������ ����������"
void eratosthenes()
{
    system("cls");
    int n = 0;
    bool flag = false;

    cout << "������� '������ ����������'\n";
    
    do
    {
        cout << "������� �����, �� �������� ����� ����� ������� �����: ";
        cin >> n;
        if (n < 2)
        {
            cout << "����� ������ ���� �� ������ 2." << endl;
        }
        else flag = true;
    } while (flag == false);
    int* natural_num = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        natural_num[i] = i;
    }

    for (int i = 2; i * i <= n; i++) if (natural_num[i]) for (int j = i * i; j <= n; j += i) natural_num[j] = 0;
    int sz = 0;
    if (n < 100000) for (int i = 2; i < n; i++) if (natural_num[i]) cout << natural_num[i] << " ";
    else for (int i = 2; i < n; i++) if (natural_num[i]) sz++;

    if (n >= 100000) cout << "���������� ������� �����: " << sz << endl;
    else cout << endl;

    ExitToMenu();
}

//������� 3.1 "��������� ��������� ������"
void file_read_1()
{
    system("cls");
    file();
    ofstream fout;
    string str;
    char f_read[100];
    string output;
    map <char, int> arr { {'q', 0}, {'w', 0}, {'r', 0}, {'t', 0}, {'p', 0}, {'s', 0}, {'d', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'z', 0}, {'x', 0}, {'c', 0}, {'v', 0}, {'b', 0}, {'n', 0}, {'m', 0}};
    int len = 0, max = 0;

    cout << "������� 3.1 '��������� ��������� ������'\n" << "������� ������ ��� ������ � ����: ";

    cin >> str;
    len = str.length();

    //������ ������ � ����
    fout.open("test_HW.txt");
    fout << str << endl;
    fout.close();

    //������ ������ �� �����
    ifstream fin("test_HW.txt");
    fin >> f_read;
    fin.close();

    for (int i = 0; i < len; i++)
    {
        try
        {
            arr.at(f_read[i]) += 1;
        }
        catch (out_of_range)
        {
            continue;
        }
    }

    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        if (i->second > max)
        {
            max = i->second;
            output = i->first;
        }
        else if (i->second == max)
        {
            output = output + ", " + i->first;
        }
    }

    cout << "����� ����������� �������: " << output << " = " << max << endl;

    ExitToMenu();
}

//������� 3.2 "��������� ��������� ������"
void file_read_2()
{
    system("cls");
    ofstream fout;
    string str, f_read, str_find, f_read2, f_end, f_read3;
    int len = 0, len_find = 0;
    string new_str;

    cout << "������� 3.2 '��������� ��������� ������'\n" << "������� ������ ��� ������ � ����: ";

    cin >> str;
    len = str.length();

    cout << "������� ������, ������� ����� �����: ";
    cin >> str_find;
    len_find = str_find.length();

    //������ ������ � ����
    fout.open("test_HW.txt");
    fout << str << endl;
    fout.close();

    //������ ������ �� �����
    ifstream fin("test_HW.txt");
    fin >> f_read;
    fin.close();

    f_read2 = f_read3 = f_read;

    f_end = f_read3.erase(0, f_read.find(str_find) + len_find);
    if (f_read.find(str_find) == -1) cout << "����� ������ ��� � ��������.\n";
    else
    {
        f_read2.erase(f_read.find(str_find), len - f_read.find(str_find));
        cout << f_read2;
        setColor(LightGreen, Black);
        cout << str_find;
        setColor(LightGray, Black);
        cout << f_end << endl;
    }
    

    ExitToMenu();
}

void file_read()
{
    system("cls");
    bool flag = true;
    string cons_out = "������� 1 '��������� ��������� ������'\n������� 2 '��������� ��������� ������'\n0 ��������� � ������ �������.\n������� ������� �������: ";
    while (flag)
    {
        switch ((int)chek(3, cons_out, true))
        {
        default:
            system("cls");
            cout << "��� ������ �������.\n";
            break;
        case 1:
            file_read_1();
            system("cls");
            break;
        case 2:
            file_read_2();
            system("cls");
            break;
        case 0:
            flag = false;
            break;
        }
    }
}

//������� 4 "����"
string interpreter(int num)
{
    string numS = to_string(num);
    int i = numS.length() - 1, j = 0;
    int res_10 = 0;
    string res;
    int a = 0;

    for (j, i; j < numS.length(); i--, j++)
    {
        char x = numS[j];
        a = x - 48;
        res_10 += a * pow(3, i);
    }
    while (res_10 > 0)
    {
        res = to_string(res_10 % 6) + res;
        res_10 /= 6;
    }

    return res;
}
void rows()
{
    system("cls");
    int a = 0, n = 0;
    

    string input_num;
    int cnt = 0;
    bool flag = true;


    cout << "������� '����'\n" << "������� 5 ����� � 3 ��: ";

    n = (int)chek(5, "������� ���������� ����� � �������: ", false);
    
    int* num_3 = new int[n] {};
    string* num_6 = new string[n] {};

    while (cnt < 5)
    {
        cin >> input_num;
        for (int j = 0; j < input_num.length(); j++)
        {
            if (isdigit(input_num[j]))
            {
                char x = input_num[j];
                a = x - 48;
            }
            else
            {
                char x = input_num[j];
                a = x;
                if (a < 97) a -= 55;
                else a -= 87;
            }
            if (a >= 3)
            {
                cout << "����� �� ������������� 3 ������� ���������." << endl << "�������� ������ " << 5 - cnt;
                if (5 - cnt < 5 && 5 - cnt > 1) cout << " �����: ";
                else if (5 - cnt == 5) cout << " �����: ";
                else cout << " �����: ";
                flag = false;
                break;
            }
        }
        if (flag)
        {
            num_3[cnt] = stoi(input_num);
            cnt++;
            if (5 - cnt != 0)
            {
                cout << "�������� ������ " << 5 - cnt;
                if (5 - cnt < 5 && 5 - cnt > 1) cout << " �����: ";
                else if (5 - cnt == 5) cout << " �����: ";
                else cout << " �����: ";
            }
        }
        flag = true;
    }

    cout << "������ �� ����� � 3 ��: [";
    for (int i = 0; i < 5; i++)
    {
        if (i < 4) cout << num_3[i] << ", ";
        else cout << num_3[i];
    }
    cout << "]" << endl;


    for (int i = 0; i < 5; i++)
    {
        num_6[i] = interpreter(num_3[i]);
    }

    cout << "������ �� ����� � 6 ��: [";
    for (int i = 0; i < 5; i++)
    {
        if (i < 4) cout << num_6[i] << ", ";
        else cout << num_6[i];
    }
    cout << "]" << endl;

    ExitToMenu();
}

//������� ����� �� 5
int case5()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string cons_out = "������� 1 '�������� �������'\n������� 2 '������ ����������'\n������� 3 '��������� ��������� ������'\n������� 4 '����'\n0 ��������� � ������ �/�.\n������� ����� �������: ";
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
            euclid();
            system("cls");
            cout << "�� ��������� �����.\n";
            break;
        case 2:
            eratosthenes();
            system("cls");
            cout << "�� ��������� �����.\n";
            break;
        case 3:
            file_read();
            system("cls");
            cout << "�� ��������� �����.\n";
            break;
        case 4:
            rows();
            system("cls");
            cout << "�� ��������� �����.\n";
            break;
        case 0:
            system("cls");
            cout << "�� ��������� �����.\n";
            chek_hw3 = false;
        }
    }
    chek_hw3 = true;
}
