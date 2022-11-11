#include <iostream>    //��� cin/cout
#include <fstream>     //��� �����
#include <windows.h>   //��� �����/������ �������
#include <string>      //��� �������� string -> int/float
#include <stdlib.h>    //��� exit
#include "HomeWork1.h" //������ �/� 1
#include "HomeWork2.h" //������ �/� 2
#include "HomeWork3.h" //������ �/� 3
#include "HomeWork4.h" //������ �/� 4
#include "HomeWork5.h" //������ �/� 4
#include "Chek.h"      //������ ��������
#include <conio.h>     //��� ���������� ������

// ׸���� - 0
// ����� - 1
// ������ - 2
// ������� - 3
// ������� - 4
// ��������� - 5
// ���������� - 6
// ������-����� - 7
// Ҹ���-����� - 8
// ������-����� - 9
// ������-������ - 10
// ������-������� - 11
// ������-������� - 12
// ������-��������� - 13
// Ƹ���� - 14
// ����� - 15

using namespace std;

int TextColor = 15;
int TextBackgroundColor = 0;

void system_cls()
{
    setColor(15, 0);
    system("cls");
    setColor(TextColor, TextBackgroundColor);
}

void Color_set(int type)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int* ColorText = &TextColor;
    int* ColorBackground = &TextBackgroundColor;

    bool flag = true;
    int key = 0;

    string cons_out[16] = { 
         "׸����",
         "�����",
         "������",
         "�������",
         "�������",
         "���������",
         "����������",
         "������-�����",
         "Ҹ���-�����",
         "������-�����",
         "������-������",
         "������-�������",
         "������-�������",
         "������-���������",
         "Ƹ����",
         "�����" };

    int num = 0;
    do
    {
        system_cls();
        if (type == 1) cout << "�����������:\n- ������� �����, ���� - ��� ������������\n- enter - ��� ������\n- escape - ��� ������\n--------����� ����� ������---------" << endl;
        else cout << "�����������:\n- ������� �����, ���� - ��� ������������\n- enter - ��� ������\n- escape - ��� ������\n------����� ����� ���� ������-------" << endl;
        
        for (int i = 0; i < 16; i++)
        {
            if (i == num)
            {
                setColor(TextBackgroundColor, TextColor);
                if (key == 13)
                {
                    if (type == 1 && *ColorBackground == num || type == 2 && *ColorText == num) cout << cons_out[i] << " - ������ ������������ ���������� ����� ��� ������ � ����.";
                    else
                    {
                        flag = false;
                    }
                }
                else cout << cons_out[i];
                setColor(TextColor, TextBackgroundColor);
                cout << endl;
            }
            else cout << cons_out[i] << endl;
        }
        if (flag == false) break;
        key = static_cast<int>(_getch());
        
        if (key == 80 && num < 15) num++;
        if (key == 72 && num > 0) num--;
    } while (flag);

    if (type == 1) *ColorText = num;
    if (type == 2) *ColorBackground = num;

    ofstream fout("Color_setting.txt");
    fout << *ColorText << " - TextColor" <<
    endl << *ColorBackground << " - TextBackgroundColor";
    fout.close();

    system_cls();
}

void Settings()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int key = 0;
    const int volume = 3;
    string cons_out[volume] = {"���� ������", "���� ���� ������", "����� ��������"};

    while (true)
    {
        int num = 0;
        do
        {
            system_cls();
            cout << "�����������:\n- ������� �����, ���� - ��� ������������\n- enter - ��� ������\n- escape - ��� ������\n--------���� ��������---------" << endl;
            for (int i = 0; i < volume; i++)
            {
                if (i == num)
                {
                    setColor(TextBackgroundColor, TextColor);
                    cout << cons_out[i];
                    setColor(TextColor, TextBackgroundColor);
                    cout << endl;
                }
                else cout << cons_out[i] << endl;
            }
            key = static_cast<int>(_getch());
            if (key == 80 && num < volume - 1) num++;
            if (key == 72 && num > 0) num--;
            if (key == 27)
            {
                system_cls();
                cout << "�� ��������� �����.\n";
                return;
            }
            

        } while (key != 13);
        switch (num + 1)
        {
        case 1:
            Color_set(1);
            break;
        case 2:
            Color_set(2);
            break;
        case 3:
            int* ColorText = &TextColor;
            int* ColorBackground = &TextBackgroundColor;
            *ColorText = 15;
            *ColorBackground = 0;
        }
    }
}