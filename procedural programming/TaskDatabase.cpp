#include "TaskDatabase.h"

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;


void miniCalc()
{
    system_cls();
    keyboard KEY;

    int num1 = 0;
    int num2 = 0;
    int key = 0;
    const int volume = 4;

    string cons_out[volume] = { "��������", "���������", "���������", "�������" };

    int num = 0;

    cout << "�����������:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - ��� ������������\n- " << KEY.Key_translation(KeyEnter) << " - ��� ������\n- " << KEY.Key_translation(KeyExit) << " - ��� ������\n----------�.�.�. 5------------" << endl;

    num1 = chek(0, "������� ������ �����: ", false);
    while (num2 == 0)
    {
        num2 = chek(0, "������� ������ �����: ", false);
        if (num2 == 0) cout << "����� �� ����� ��������� 0.\n";
    }


    while (true)
    {
        do
        {
            system_cls();
            cout << "�����������:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - ��� ������������\n- " << KEY.Key_translation(KeyEnter) << " - ��� ������\n- " << KEY.Key_translation(KeyExit) << " - ��� ������\n----------�.�.�. 5------------" << endl << "�������� �������� ��� �������: " << num1 << " � " << num2 << "\n----------------------------\n";
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

            key = KEY.get_key();
            if (key == KeyDown && num < volume - 1) num++;
            if (key == KeyUp && num > 0) num--;
            if (key == KeyExit)
            {
                system_cls();
                return;
            }
        } while (key != KeyEnter);
        switch (num + 1)
        {
        case 1:
            system_cls();
            cout << "�����������:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - ��� ������������\n- " << KEY.Key_translation(KeyEnter) << " - ��� ������\n- " << KEY.Key_translation(KeyExit) << " - ��� ������\n----------�.�.�. 5------------" << endl;

            cout << "����� ����� " << num1 << " � " << num2 << " �����: " << num1 + num2 << endl;
            ExitToMenu();
            return;
        case 2:
            system_cls();
            cout << "�����������:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - ��� ������������\n- " << KEY.Key_translation(KeyEnter) << " - ��� ������\n- " << KEY.Key_translation(KeyExit) << " - ��� ������\n----------�.�.�. 5------------" << endl;

            cout << "�������� ����� " << num1 << " � " << num2 << " �����: " << num1 - num2 << endl;
            ExitToMenu();
            return;
        case 3:
            system_cls();
            cout << "�����������:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - ��� ������������\n- " << KEY.Key_translation(KeyEnter) << " - ��� ������\n- " << KEY.Key_translation(KeyExit) << " - ��� ������\n----------�.�.�. 5------------" << endl;

            cout << "������������ ����� " << num1 << " � " << num2 << " �����: " << num1 * num2 << endl;
            ExitToMenu();
            return;
        case 4:
            system_cls();
            cout << "�����������:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - ��� ������������\n- " << KEY.Key_translation(KeyEnter) << " - ��� ������\n- " << KEY.Key_translation(KeyExit) << " - ��� ������\n----------�.�.�. 5------------" << endl;

            cout << "������� ����� " << num1 << " � " << num2 << " �����: " << num1 / num2 << endl;
            ExitToMenu();
            return;
        }
    }

}


//���� ���� �������
void menu_TD()
{
    keyboard KEY;

    int key = 0;
    const int volume = 5;

    string cons_out[volume] = { "������� 1 '�.�.�. 5'", "������� 2 '������ ����������'", "������� 3 '��������� ��������� ������'", "������� 4 '��������� ��������� ������'", "������� 5 '����'" };

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();
            cout << "�����������:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - ��� ������������\n- " << KEY.Key_translation(KeyEnter) << " - ��� ������\n- " << KEY.Key_translation(KeyExit) << " - ��� ������\n----------�/� 5------------" << endl;
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

            key = KEY.get_key();
            if (key == KeyDown && num < volume - 1) num++;
            if (key == KeyUp && num > 0) num--;
            if (key == KeyExit)
            {
                system_cls();
                return;
            }
        } while (key != KeyEnter);
        switch (num + 1)
        {
        case 1:
            miniCalc();
            break;
        case 2:
            eratosthenes();
            break;
        case 3:
            file_read_1();
            break;
        case 4:
            file_read_2();
            break;
        case 5:
            rows_1();
            break;
        }
    }
}