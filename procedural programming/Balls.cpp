#include "Balls.h";

using namespace std;

//vector <int> GenerateBalls(const size_t count)
//{
//	vector <int> out;
//	for (int i = 0; i < count; ++i)
//		out.emplace_back(i);
//	return out;
//}
//
//bool CheckVariant(const vector <int>& balls)
//{
//	for (size_t i = 0; i < balls.size(); ++i)
//		if (balls[i] == i)
//			return true;
//	return false;
//}
//
//size_t CalculateALLPossibleVariants(vector <int> balls)
//{
//	size_t ct = 0;
//	do
//	{
//		if (CheckVariant(balls))
//			ct++;
//	} while (next_permutation(balls.begin(), balls.end()));
//	return ct;
//}

int balls()
{
	system_cls();
	/*size_t count = 10;
	cout << CalculateALLPossibleVariants(GenerateBalls(count)) << endl;*/
	int cnt = 0;
	cnt = (int)chek(5, "Введите количество шариков: ", false);
	string* arr = new string[cnt];

	for (int i = 0; i < cnt; i++)
	{
		arr[i] = to_string(i + 1);
	}
	/*for (int i = 0; i < cnt; i++)
	{
		cout <<arr[i] << " ";
	}*/
	int i;
	int res;



	res = 1;
	for (i = 1; i <= cnt; i++) {
		res = res * i;
	}
	cout << res << endl;
	int num = 0;
	do
	{
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << " ";
		cout << endl;
		if (num == res) break;
		num++;
	} while (next_permutation(arr, arr + cnt));
	cout << num << endl;
	ExitToMenu();
}