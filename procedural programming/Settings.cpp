#include <iostream>    //��� cin/cout
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

using namespace std;

int TextColor;
int TextBackgroundColor;

enum ConsoleColor {
    Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
    DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

//������� �����
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int key = 0;

    string cons_out[3] = {"���� ������", "���� ���� �������"};

    while (true)
    {
        int num = 0;
        do
        {
            setColor(TextColor, TextBackgroundColor);
            cout << "�����������:\n- ������� �����, ���� - ��� ������������\n- enter - ��� ������\n- escape - ��� ������\n----------����� �/�------------" << endl;
            for (int i = 0; i < 5; i++)
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
            if (key == 80 && num < 4) num++;
            if (key == 72 && num > 0) num--;
            if (key == 27)
            {
                cout << "�� ��������� ������.\n";
                exit(EXIT_SUCCESS);
            }
            system("cls");

        } while (key != 13);
        switch (num + 1)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        }
    }
}