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

    float num1 = 0;
    float num2 = 0;
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

void array_1D()
{
    system_cls();
    srand(time(NULL));
    const int SIZE = 50;
    float arr_1[SIZE]{ 0 };
    float arr_2[SIZE]{ 0 };

    for (int i = 0; i < SIZE; i++)
    {
        if (rand() % 2)
            arr_1[i] = rand() % 100;
        else arr_1[i] = rand() % 100 * (-1);
    }
    cout << "�������� ������: [";
    for (int i = 0; i < SIZE; i++)
    {
        if (i != SIZE - 1) cout << arr_1[i] << ", ";
        else cout << arr_1[i] << "]" << endl;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if (i != 0 && i != SIZE - 1)
        {
            arr_2[i] = (arr_1[i - 1] + arr_1[i] + arr_1[i + 1]) / 3;
        }
        else if (i == 0) arr_2[i] = arr_1[i];
        else if (i == SIZE - 1) arr_2[i] = arr_1[i];

    }
    cout << endl << "���������� ������: [";
    for (int i = 0; i < SIZE; i++)
    {
        if (i != SIZE - 1) cout << arr_2[i] << ", ";
        else cout << arr_2[i] << "]" << endl;
    }
    cout << endl;
    ExitToMenu();
}

void array_2D()
{
    system_cls();
    srand(time(NULL));
    int SIZEx = 0;
    int SIZEy = 0;
    cout << "������� 3 \"��������� ������ 57\"" << endl;
    while (SIZEx > 100 || SIZEx < 1)
    {
        SIZEx = (int)chek(5, "������� ���������� ��������: ", false);
        if (SIZEx > 100) cout << "���������� �������� ������ �� ������ 100.\n";
        /*else if (SIZEx < 2) cout << "���������� �������� ������ ���� �� ������ 1.\n";*/
    }
    while (SIZEy > 100 || SIZEy < 1)
    {
        SIZEy = (int)chek(5, "������� ���������� �����: ", false);
        if (SIZEy > 100) cout << "���������� ����� ������ �� ������ 100.\n";
        /*else if (SIZEy < 2) cout << "���������� ����� ������ ���� �� ������ 1.\n";*/
    }
    float a = 0;
    float* arr_2 = new float[SIZEx];
    float** arr = new float* [SIZEy];
    for (int i = 0; i < SIZEy; i++)
        arr[i] = new float[SIZEx];

    string cons_out;

    for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
        {
            if (rand() % 2)
                arr[i][j] = rand() % 100;
            else arr[i][j] = rand() % 100 * (-1);
        }
    }
    cout << endl << "������� [" << SIZEy << " x " << SIZEx << "]" << endl;
    for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
        {
            cout << setw(5) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < SIZEx; i++)
    {
        a = 0;
        cons_out = "";
        cout << right << "������� �������������� " << setw(3) << i + 1 <<" �������: ";
        for (int j = 0; j < SIZEy; j++)
        {
            a += arr[j][i];
            if (j == 0)
            {
                if (arr[j][i] < 0)
                    cons_out += "((" + to_string((int)arr[j][i]) + ") + ";
                else cons_out += "(" +to_string((int)arr[j][i]) + " + ";
            }
            else if (j != SIZEy - 1)
            {
                if (arr[j][i] < 0)
                    cons_out += "(" + to_string((int)arr[j][i]) + ") + ";
                else cons_out += to_string((int)arr[j][i]) + " + ";
            }
                
            else
            {
                if (arr[j][i] < 0)
                    cons_out += "(" + to_string((int)arr[j][i]) + ")";
                else cons_out += to_string((int)arr[j][i]);
            }
        }
        arr_2[i] = a / SIZEy;
        cons_out += ") / " + to_string(SIZEy);
        cout << left << setw(SIZEy * 5 + (SIZEy-1) * 3 + 2) << cons_out << " = " << arr_2[i] << endl;
    }

    

    for (int i = 0; i < SIZEy; i++)
        delete[] arr[i];
    delete[] arr;
    

    cout << endl << "������ ������� ��������������: [";
    for (int i = 0; i < SIZEx; i++)
    {
        if (i != SIZEx - 1) cout << arr_2[i] << ", ";
        else cout << arr_2[i] << "]" << endl;
    }
    cout << endl;
    delete[] arr_2;
    ExitToMenu();
}

int** func(int** arr,  char type, int** arr_A, int** arr_B, int** arr_C, int** arr_E)
{
    const int SIZEx = 5;
    const int SIZEy = 2;
    int a[10]{ -3, -2, -1, 0, 1, 2, 3, 4, 5, 6 };
    string cons_out;
    srand(time(NULL));

    

    for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
        {
            switch (type)
            {
            case 'A':
                cons_out = "������� [" + to_string(i) + "][" + to_string(j) + "] ������� ������� A: ";
                arr[i][j] = (int)chek(5, cons_out, false);
                break;
            case 'B':
                arr[i][j] = i * j - (5 - i - j);
                break;
            case 'C':
                arr[i][j] = a[rand() % 10];
                break;
            case 'E':
                arr[i][j] = 1;
                break;
            case 'D':
                arr[i][j] = 6 * arr_E[i][j] - arr_C[i][j] - 2 * arr_B[i][j] - 3 * arr_A[i][j];
                break;
            }
        }
    }
    return arr;
}
void func_cout(int** arr, char type)
{
    const int SIZEx = 5;
    const int SIZEy = 2;
    int a[10]{ -3, -2, -1, 0, 1, 2, 3, 4, 5, 6 };
    string cons_out;
    srand(time(NULL));

    switch (type)
    {
    case 'A':
        system_cls();
        cout << "������� 4 \"������� 66\"" << endl;
        cout << "������� A: " << endl;
        break;
    case 'B':
        cout << "������� B: " << endl;
        break;
    case 'C':
        cout << "������� C: " << endl;
        break;
    case 'D':
        cout << "������� D: " << endl;
        break;
    case 'E':
        cout << "������� E: " << endl;
        break;
    }

    for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
        {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void func_delete(int** arr)
{
    for (int i = 0; i < 2; i++)
        delete[] arr[i];
    delete[] arr;
}
void functions()
{
    system_cls();
    cout << "������� 4 \"������� 66\"" << endl;

    const int SIZEx = 5;
    const int SIZEy = 2;

    int** arr_A = new int* [SIZEy];
    for (int i = 0; i < SIZEy; i++)
        arr_A[i] = new int[SIZEx];
    int** arr_B = new int* [SIZEy];
    for (int i = 0; i < SIZEy; i++)
        arr_B[i] = new int[SIZEx];
    int** arr_C = new int* [SIZEy];
    for (int i = 0; i < SIZEy; i++)
        arr_C[i] = new int[SIZEx];
    int** arr_D = new int* [SIZEy];
    for (int i = 0; i < SIZEy; i++)
        arr_D[i] = new int[SIZEx];
    int** arr_E = new int* [SIZEy];
    for (int i = 0; i < SIZEy; i++)
        arr_E[i] = new int[SIZEx];

    arr_A = func(arr_A, 'A', NULL, NULL, NULL, NULL);
    arr_B = func(arr_B, 'B', NULL, NULL, NULL, NULL);
    arr_C = func(arr_C, 'C', NULL, NULL, NULL, NULL);
    arr_E = func(arr_E, 'E', NULL, NULL, NULL, NULL);
    arr_D = func(arr_D, 'D', arr_A, arr_B, arr_C, arr_E);

    func_cout(arr_A, 'A');
    func_cout(arr_B, 'B');
    func_cout(arr_C, 'C');
    func_cout(arr_D, 'D');
    func_cout(arr_E, 'E');

    func_delete(arr_A);
    func_delete(arr_B);
    func_delete(arr_C);
    func_delete(arr_D);
    func_delete(arr_E);

    ExitToMenu();
}

//���� ���� �������
void menu_TD()
{
    keyboard KEY;

    int key = 0;
    const int volume = 5;

    string cons_out[volume] = { "������� 1 \"��������� �������������� ������ 5\"", "������� 2 \"���������� ������� 36\"", "������� 3 \"��������� ������ 57\"", "������� 4 \"������� 66\"", "������� 5 '����'" };

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
            array_1D();
            break;
        case 3:
            array_2D();
            break;
        case 4:
            functions();
            break;
        case 5:
            rows_1();
            break;
        }
    }
}