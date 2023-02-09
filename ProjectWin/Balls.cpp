#include "Balls.h"

String^ balls_allpermut(String^ str)
{
	int cnt = 0;
	cnt = (int)check_num(0, str);
	if (cnt > 12)
	{
		MessageBox::Show("Число не может быть больше 12.", "Ошибка", MessageBoxButtons::OK);
		return "";
	}
	else if (cnt == 0) return "";
	int res = 1;
	for (int i = 1; i <= cnt; i++)
		res = res * i;

	return Convert::ToString(res);
}

String^ balls_right(String^ str)
{
	int cnt = Convert::ToInt32(str);
	int* arr = new int[cnt];

	for (int i = 0; i < cnt; i++)
		arr[i] = i;

	int res = 1;
	for (int i = 1; i <= cnt; i++)
		res = res * i;

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
	} while (std::next_permutation(arr, arr + cnt));
	delete[] arr;
	return Convert::ToString(num);
}