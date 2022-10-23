#include <iostream>    //��� case4
#include <locale>      //��� ������ �������
#include <windows.h>   //��� ����� �������
#include <cmath>       //��� ���������� ���������
#include <fstream>     //��� ������ � ������
#include <string>      //��� �������� string -> int/float, int -> string
#include "Chek.h"      //������ ��������
#include <ctime>       //��� ��������� ��������� �����
#include <algorithm>   //��� ����������
#include "HomeWork3.h" //������ �/� 3

using namespace std;

//������� 1 "����"
void file_4()
{
    file();
    system("cls");
    ofstream fout;
    int sum = 0, int_file, num = 0;
    string j = "no";

    cout << "������� '����'\n";


    //��������� � ������ � ���� ��������� �����
    srand(time(0));
    cout << "����� � �����: ";
    fout.open("test_HW.txt");
    for (int i = 0; i < 10; i++)
    {
        num = rand() % 1000;
        fout << num << " ";
        cout << num << " ";
    }
    fout.close();

    //������ ������ �� �����
    ifstream fin("test_HW.txt");
    for (int i = 0; i < 10; i++)
    {
        fin >> int_file;
        sum += int_file;
    }
    fin.close();

    cout << endl << "����� 10 ����� �����: " << sum << endl;

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> j;
    } while (j == "no");
}

//������� 2 "���� �����"
int sign(float x)
{
    if (x > 0) return 1;
    else if (x == 0) return 0;
    else return -1;
}
void number_sign()
{
    system("cls");
    string i = "no";
    float x = 0;

    cout << "������� '���� �����'\n";
    x = chek(0, "������� ����� x: ", false);

    if (sign(x) == 1) cout << "����� �������������.\n";
    else if (sign(x) == 0) cout << "����� ����� 0.\n";
    else cout << "����� �������������.\n";

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� 3 "�������������� ������"
void geometry()
{
    system("cls");
    bool chek_geo = true;
    string i = "no", cons_out = "������� '�������������� ������'\n�������������\t1\n�����������\t2\n����    \t3\n������� ����� ������: ";
    float R = 0, A = 0, B = 0, corner = 0;
    const double PI = 3.141592653589793;               

    //������ ������ �����
    while (chek_geo)
    {
        switch ((int)chek(0, cons_out, true))
        {
        default:
            system("cls");
            cout << "��� ����� ������.\n";
            break;
        case 1:
            system("cls");
            cout << "������� ��������������\n";
            A = chek(1, "������� ����� ������� A: ", false);

            B = chek(1, "������� ����� ������� B: ", false);

            cout << "������� �������������� �����: " << A * B << endl;

            //������ ������ � ����
            cout << "����� ��������� � ������ �����, ������� 0.\n" << "����� ��������� � ������ �������, ������� ����� ������ ������.";
            cin >> i;
            if (i == "0")
            {
                system("cls");
                cout << "�� ��������� � ������ �����.\n";
                break;
            }
            else
            {
                chek_geo = false;
                break;
            }
        case 2:
            system("cls");
            cout << "������� ������������\n";
            A = chek(1, "������� ����� ������� A: ", false);

            B = chek(1, "������� ����� ������� B: ", false);

            corner = chek(2, "������� ���� (� ��������) ����� ����� ���������: ", false);

            cout << "������� ������������ �����: " << 0.5 * A * B * sin(corner * PI / 180) << endl;

            //������ ������ � ����
            cout << "����� ��������� � ������ �����, ������� 0.\n" << "����� ��������� � ������ �������, ������� ����� ������ ������.";
            cin >> i;
            if (i == "0")
            {
                system("cls");
                cout << "�� ��������� � ������ �����.\n";
                break;
            }
            else
            {
                chek_geo = false;
                break;
            }
        case 3:
            system("cls");
            cout << "������� �����\n";
            R = chek(1, "������� �������� ������� R: ", false);

            cout << "������� ����� �����: " << PI * pow(R, 2) << endl;

            //������ ������ � ����
            cout << "����� ��������� � ������ �����, ������� 0.\n" << "����� ��������� � ������ �������, ������� ����� ������ ������.";
            cin >> i;
            if (i == "0")
            {
                system("cls");
                cout << "�� ��������� � ������ �����.\n";
                break;
            }
            else
            {
                chek_geo = false;
                break;
            }
        }
    }
    chek_geo = true;
}

//������� 4 "����� �����"
void glory()
{
    system("cls");
    string i = "no";

    cout << "������� '����� �����'\n";

    for (int i = 0; i < 6; i++)
    {
        for (int i = 0; i < 8; i++) cout << "* ";
        for (int i = 0; i < 24; i++) cout << "-";
        cout << endl;
    }
    for (int i = 0; i < 7; i++)
    {
        for (int i = 0; i < 40; i++) cout << "-";
        cout << endl;
    }

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� 5 "���������"
void sin()
{
    system("cls");
    string i = "no";
    HWND hWnd = GetConsoleWindow();
    HDC hDC = GetDC(hWnd);
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));

    cout << "������� '���������'\n";

    SelectObject(hDC, Pen);
    MoveToEx(hDC, 0, 85, NULL);
    LineTo(hDC, 200, 85);
    MoveToEx(hDC, 100, 0, NULL);
    LineTo(hDC, 100, 170);
    for (float x = -8.0f; x <= 8.0f; x += 0.01f)
    {
        MoveToEx(hDC,10 * x + 100, -10 * sin(x) + 85, NULL);
        LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
    }
    ReleaseDC(hWnd, hDC);
    cin.get();

    //������ ������ � ����
    do
    {
        cout << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� 6 "���������� ��������������"
void recognizer()
{
    system("cls");
    string str_input, str_chek, str;
    string i = "no";
    int num1 = 0, num2 = 0, output_num = 0, c = 0, num_chek = 0;
    cout << "������� '���������� ��������������'\n" << "������� ������: ";
    cin >> str_input;

    str_chek = str_input;

    while (str_input.length() > 0)
    {
        while (c < 2)
        {
            switch (str_input[c])
            {
            case 'I':
                if (c == 0) num1 = 1;
                else num2 = 1;
                break;
            case 'V':
                if (c == 0) num1 = 5;
                else num2 = 5;
                break;
            case 'X':
                if (c == 0) num1 = 10;
                else num2 = 10;
                break;
            case 'L':
                if (c == 0) num1 = 50;
                else num2 = 50;
                break;
            case 'C':
                if (c == 0) num1 = 100;
                else num2 = 100;
                break;
            case 'D':
                if (c == 0) num1 = 500;
                else num2 = 500;
                break;
            case 'M':
                if (c == 0) num1 = 1000;
                else num2 = 1000;
                break;
            }
            c++;
        }
        if (num1 >= num2)
        {
            output_num += num1;
            num1 = 0;
            num2 = 0;
            c = 0;
            str_input.erase(0, 1);
        }
        else
        {
            output_num += (num2 - num1);
            num1 = 0;
            num2 = 0;
            c = 0;
            str_input.erase(0, 1);
            str_input.erase(0, 1);
        }
    }

    num_chek = output_num;

    if (num_chek >= 1000)
    {
        switch (num_chek / 1000)
        {
        case 1:
            str += 'M';
            num_chek -= 1000;
            break;
        case 2:
            str += "MM";
            num_chek -= 2000;
            break;
        case 3:
            str += "MMM";
            num_chek -= 3000;
            break;
        }
    } 
    if (num_chek >= 100)
    {
        switch (num_chek / 100)
        {
        case 1:
            str += 'C';
            num_chek -= 100;
            break;
        case 2:
            str += "CC";
            num_chek -= 200;
            break;
        case 3:
            str += "CCC";
            num_chek -= 300;
            break;
        case 4:
            str += "CD";
            num_chek -= 400;
            break;
        case 5:
            str += 'D';
            num_chek -= 500;
            break;
        case 6:
            str += "DC";
            num_chek -= 600;
            break;
        case 7:
            str += "DCC";
            num_chek -= 700;
            break;
        case 8:
            str += "DCCC";
            num_chek -= 800;
            break;
        case 9:
            str += "CM";
            num_chek -= 900;
            break;
        }
    }
    if (num_chek >= 10)
    {
        switch (num_chek / 10)
        {
        case 1:
            str += 'X';
            num_chek -= 10;
            break;
        case 2:
            str += "XX";
            num_chek -= 20;
            break;
        case 3:
            str += "XXX";
            num_chek -= 30;
            break;
        case 4:
            str += "XL";
            num_chek -= 40;
            break;
        case 5:
            str += 'L';
            num_chek -= 50;
            break;
        case 6:
            str += "LX";
            num_chek -= 60;
            break;
        case 7:
            str += "LXX";
            num_chek -= 70;
            break;
        case 8:
            str += "LXXX";
            num_chek -= 80;
            break;
        case 9:
            str += "XC";
            num_chek -= 90;
            break;
        }
    }
    if (num_chek < 10)
    {
        switch (num_chek)
        {
        case 1:
            str += 'I';
            num_chek -= 1;
            break;
        case 2:
            str += "II";
            num_chek -= 2;
            break;
        case 3:
            str += "III";
            num_chek -= 3;
            break;
        case 4:
            str += "IV";
            num_chek -= 4;
            break;
        case 5:
            str += 'V';
            num_chek -= 5;
            break;
        case 6:
            str += "VI";
            num_chek -= 6;
            break;
        case 7:
            str += "VII";
            num_chek -= 7;
            break;
        case 8:
            str += "VIII";
            num_chek -= 8;
            break;
        case 9:
            str += "IX";
            num_chek -= 9;
            break;
        }
    }

    if (str_chek == str) cout << output_num << endl;
    else cout << "��������, �� ����� � ���� " << str << " ������ " << output_num << "." << endl;

    //������ ������ � ����
    do
    {
        cout << endl << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� 7 "��������� ��������������� �����"
int gen(int m, int b, int c, int a, int s)
{
    if (a > 0)
    {
        gen(m + 1, b + 1, c + 1, a - 1, (m * s + b) % c);
        if (s > 0) cout << s << " ";
    }
    return s;
}
void random_num()
{
    system("cls");
    int s = 0, s1 = 0, m = 37, b = 3, c = 64;
    string i = "no";
    cout << "������� '��������� ��������������� �����'\n" << "I �������\n" << "10 ��������������� �����: " << endl;
    gen(37, 3, 64, 11, 0);
    cout << endl << "II �������\n" << "10 ��������������� �����: ";
    gen(25173, 13849, 65537, 11, 0);
    //������ ������ � ����
    do
    {
        cout << endl << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� 8 "��������� ������"
void matrix()
{
    system("cls");
    cout << "������� '��������� ������'\n";
    string i = "no";
    float arrA[3][4]
    { {5, 2, 0, 10},
      {3, 5, 2, 5},
      {20, 0, 0, 0} };
    float arrB[4][3]
    { {1.2, 0.5},
      {2.8, 0.4},
      {5, 1},
      {2, 1.5} };
    float arrC[3][2]{ 0 };

    //������� �
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arrA[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //������� B
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arrB[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    //������� �
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            for (int inner = 0; inner < 4; inner++)
            {
                arrC[row][col] += arrA[row][inner] * arrB[inner][col];
            }
            cout << arrC[row][col] << "\t";
        }
        cout << "\n";
    }
    
    //������ ������ � ����
    do
    {
        cout << endl << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� 9 "������� ���������"
string interpreter(double num, int base_out)
{
    string res, res_chek;
    int f = 0, last_num = 0;
    bool flag = false, flag_rounding = true;
    int L = 0, L_chek = 0, num_after_dot_chek = 0, num_befor_dot = 0;
    double num_after_dot = 0, num1 = 0;

    if (num < 0)
    {
        num = abs(num);
        flag = true;
    }
    
    num_after_dot = modf(num, &num1);
    num_befor_dot = num1;

    if (num_befor_dot == 0) res = '0';
    else
    {
        cout << "������� ����� �����:" << endl << endl;
        while (num_befor_dot > 0)
        {
            f = num_befor_dot % base_out;
            cout << num_befor_dot << " / " << base_out << " = \t" << num_befor_dot / base_out;
            if (num_befor_dot / base_out >= 10000000) cout << "\t �������: " << f << endl;
            else cout << "\t\t �������: " << f << endl;

            switch (f)
            {
            case 10:
                res = 'a' + res;
                num_befor_dot = num_befor_dot / base_out;
                break;
            case 11:
                res = 'b' + res;
                num_befor_dot = num_befor_dot / base_out;
                break;
            case 12:
                res = 'c' + res;
                num_befor_dot = num_befor_dot / base_out;
                break;
            case 13:
                res = 'd' + res;
                num_befor_dot = num_befor_dot / base_out;
                break;
            case 14:
                res = 'e' + res;
                num_befor_dot = num_befor_dot / base_out;
                break;
            case 15:
                res = 'f' + res;
                num_befor_dot = num_befor_dot / base_out;
                break;
            default:
                res = to_string(f) + res;
                num_befor_dot = num_befor_dot / base_out;
                break;
            }
        }
        cout << endl;
    }
    
    if (num_after_dot > 0)
    {
        cout << "������� ������� �����:" << endl << endl;
        res += '.';
        L = log(pow(10, (to_string(num_after_dot).length() - 3)))/log(base_out);
        cout << "���������� ������ ����� �������, L = " << L << endl << endl;
        L_chek = L;
        L++;
        while (L > 0)
        {
            cout << num_after_dot;
            num_after_dot_chek = num_after_dot * base_out;
            num_after_dot = num_after_dot * base_out;
            cout << " * " << base_out << " = " << num_after_dot << " ����� �����: " << num_after_dot_chek << endl;

            if (num_after_dot_chek > 0) num_after_dot -= num_after_dot_chek;
            res_chek += to_string(num_after_dot_chek);
            if (L == 1) last_num = num_after_dot_chek;
            if (num_after_dot == 0)
            {
                flag_rounding = false;
                break;
            }
            L--;
        }
        if (flag_rounding)
        {
            if (last_num >= base_out / 2)
            {
                for (int i = 0; res_chek[i] == '0'; i++) res += '0';
                res_chek.pop_back();
                res += to_string(stoi(res_chek) + 1);
            }
            else
            {
                res_chek.pop_back();
                res += res_chek;
            }
        }
        else res += res_chek;
        
    }
    cout << endl;
    if (flag) res = '-' + res;
    return res;
}
double interpreter_10(string num, int base_in, bool flag)
{
    double a = 0, res10 = 0;
    int len = 0, c = -1, find_dot = 0;
    bool flag_sign = false, flag_dot = false;
    double* intermediate_num = new double[10 + num.length()] {0};

    len = num.length();

    if (num.find('.') == -1) find_dot = 0;
    else find_dot = num.find('.');
    
    for (int i = 0, j = 0; i < num.length(); i++, j++)
    {
        if (num[i] == '-')
        {
            flag_sign = true;
            if (find_dot > 0) find_dot--;
            len--;
            j--;
            continue;
        }
        else if (isdigit(num[i]))
        {
            char x = num[i];
            a = x - 48;
        }
        else if (num[i] == '.')
        {
            flag_dot = true;
            j--;
            continue;
        }
        else
        {
            char x = num[i];
            a = x;
            if (a < 97) a -= 55;
            else a -= 87;
        }
        if (flag_dot)
        {
            res10 += a * pow(base_in, c);
            cout << a << " * " << base_in << " ^ " << c << " = " << a * pow(base_in, c) << endl;
            intermediate_num[j] = a * pow(base_in, c);
            c--;
        }
        else if (find_dot > 0)
        {
            res10 += a * pow(base_in, find_dot - 1);
            cout << a << " * " << base_in << " ^ " << find_dot - 1 << " = " << a * pow(base_in, find_dot - 1) << endl;
            intermediate_num[j] = a * pow(base_in, find_dot - 1);
            find_dot--;
        }
        else
        {
            res10 += a * pow(base_in, len - 1);
            cout << a << " * " << base_in << " ^ " << len - 1 << " = " << a * pow(base_in, len - 1) << endl;
            intermediate_num[j] = a * pow(base_in, len - 1);
        }
        
        len--;
    }
    if (flag)
    {
        cout << endl << intermediate_num[0];
        for (int i = 1; i < num.length(); i++)
        {
            if (intermediate_num[i] != 0) cout << " + " << intermediate_num[i];
        }
        cout << " = " << to_string(res10) << endl;
    }
    cout << endl;
    if (flag_sign) res10 *= (-1);
    return res10;
}
void number_system()
{
    setlocale(LC_NUMERIC, "eng");
    system("cls");
    string i = "no";
    string input_num;
    int input_base_from = 0, input_base_to = 0, a = 0;
    bool flag = true;
    double num = 0;
    
    cout << "������� '������� ���������'\n" << "������� �����: ";
    cin >> input_num;

    cout << "������� ������� ��������� ��������� �����: ";
    cin >> input_base_from;

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
        if (a >= input_base_from)
        {
            cout << "����� �� ������������� ������� ���������." << endl;
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "������� �������� ������� ���������: ";
        cin >> input_base_to;
        cout << endl;
        if (input_base_from == input_base_to) cout << "����� � " << input_base_to << " ������� ���������: " << input_num << endl;
        else
        {
            if (input_base_from != 10)
            {
                if (input_base_to == 10)
                {
                    cout << "������� �� " << input_base_from << " � 10 ������� ���������:" << endl << endl;
                    num = interpreter_10(input_num, input_base_from, false);
                }
                else
                {
                    cout << "������� �� " << input_base_from << " � 10 ������� ���������:" << endl << endl;
                    num = interpreter_10(input_num, input_base_from, true);
                }
            }
            else num = stof(input_num);
            if (input_base_to == 10) cout << "����� � 10 ������� ���������: " << num << endl;
            else
            {
                cout << "������� �� 10 � " << input_base_to << " ������� ���������:" << endl << endl;
                cout << "�������� ����� � " << input_base_to << " ������� ���������: " << interpreter(num, input_base_to) << endl;
            }
        }
    }


    //������ ������ � ����
    do
    {
        cout << endl << "����� ��������, ������� ����� ������.";
        cin >> i;
    } while (i == "no");
}

//������� ����� �� 4
int case4()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    
    string cons_out = "������� 1 '����'\n������� 2 '���� �����'\n������� 3 '�������������� ������'\n������� 4 '����� �����'\n������� 5 '���������'\n������� 6 '���������� ��������������'\n������� 7 '��������� ��������������� �����'\n������� 8 '��������� ������'\n������� 9 '������� ���������'\n0 ��������� � ������ �/�.\n������� ����� �������: ";
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
            file_4();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 2:
            number_sign();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 3:
            geometry();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 4:
            glory();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 5:
            sin();
            system("cls");
            /*cout << "�� ������.\n";*/
            break;
        case 6:
            recognizer();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 7:
            random_num();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 8:
            matrix();
            system("cls");
            cout << "�� ��������� � ������ �������.\n";
            break;
        case 9:
            number_system();
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