#include "Balls.h";

using namespace std;

void balls()
{
	system_cls();
	int cnt = 0;
	while (true)
	{
		cnt = (int)chek(5, "������� ���������� �������: ", false);
		if (cnt > 12) cout << "���������� ������� �� ������ ��������� 12." << endl;
		else break;
	}
	int* arr = new int[cnt];

	for (int i = 0; i < cnt; i++)
		arr[i] = i;

	int res = 1;
	for (int i = 1; i <= cnt; i++)
		res = res * i;

	cout << "����� ���������� ������������: " << res << endl;
	int num = 0;
	do
	{
		for (int i = 0; i < cnt; i++)
		{
			if (arr[i] == i)
			{
				num++;
				break;
			}
		}
	} while (next_permutation(arr, arr + cnt));
	delete[] arr;
	cout << "���������� ������������, ��������������� �������: " << num << endl;
	ExitToMenu();
	//2293839
}