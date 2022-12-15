#include "Pyatnashki.h"

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

bool algorithm(string** data, int SIZEx, int animation)
{
	time_t start_time = clock();	// Время начала запуска алгоритма
	int cnt_Enter = 0;				// Счётчик перестановок
	int cnt = 1;					// Переменная для проверки, что число стоит на нужном месте

	int step = 0;                   // Переключатель шага в действии
	int numi = 0, numj = 0;         // Координаты искомого числа: i - по вертикали, j - по горизонтали (от 0 до SIZEx - 1)
	int numi_s = 0, numj_s = 0;     // Координаты пробела: i - по вертикали, j - по горизонтали (от 0 до SIZEx - 1)
	int num_find = 1;               // Искомое число

	int SIZEx_for_move_j = SIZEx;   // Переменная для переопредиления размера поля при переключении на сбор строки
	int SIZEx_for_move_i = SIZEx;   // Переменная для переопредиления размера поля при переключении на сбор столбца
	int num_find_reserv =
		SIZEx + 1;                  // Переменная для переопредиления искомого числа при переключении между сбором строки или столбца

	int numj_reserv = SIZEx - 3;
	int numi_SIZEx_reserv = 0;
	int numj_SIZEx_reserv = 0;

	int switcher = 0;               // Переключение между сбором столбца или строки:
									// switcher = 0 сбор строки
									// switcher = 1 сбор столбца

	int action = 0;                 // Переключение между действиями:
									// action = 0 передвижение пропуска к нужному числу (снизу)
									// action = 1 передвижение пропуска к нужному числу (сверху)
									// action = 2 передвижение числа вправо до конца
									// action = 3 передвижение числа на нужную строчку вверх (слева)
									// action = 4 передвижение числа на нужную строчку вниз (слева)
									// action = 5 передвижение числа на нужную позицию (снизу)
									// action = 6 передвижение числа на нужную позицию (последнего в столбце)
									// action = 7 передвижение последнего числа в строке
									// action = 8 передвижение последнего числа в столбце

	bool flag_win = true;

	while (true)
	{
		cnt = 1;

		// Вывод поля на экран с анимацией
		if (animation == 1)
		{
			system_cls();
			for (int i = 0; i < SIZEx; i++)
			{
				for (int j = 0; j < SIZEx; j++)
				{
					if (data[i][j] == to_string(cnt))
					{
						setColor(2, TextBackgroundColor);
						cout << setw(4) << data[i][j];
						setColor(TextColor, TextBackgroundColor);
					}
					else if (data[i][j] == to_string(num_find))
					{
						setColor(14, TextBackgroundColor);
						cout << setw(4) << data[i][j];
						setColor(TextColor, TextBackgroundColor);
					}
					else cout << setw(4) << data[i][j];
					cnt++;
				}
				cout << "\n";
			}
		}

		// Сбор поля до 3 х 3
		if (SIZEx_for_move_i > 3 || SIZEx_for_move_j > 2)
		{
			if (animation == 1)
			{
				cout << "\nЗначения до шага:\n";
				cout << "step = " << step << " \naction = " << action << " \nswitcher = " << switcher << " \nnum_find_reserv = " << num_find_reserv << "\nnumi = " << numi << " numj = " << numj << "\nnumi_s = " << numi_s << " numj_s = " << numj_s << " \nnum_find = ";
				setColor(14, TextBackgroundColor);
				cout << num_find;
				setColor(TextColor, TextBackgroundColor);
				cout << "\nSIZEx_for_move_i = " << SIZEx_for_move_i << "\n";
			}

			// Опредиления координат искомого числа и пробела
			for (int i = 0; i < SIZEx; i++)
			{
				for (int j = 0; j < SIZEx; j++)
				{
					if (data[i][j] == to_string(num_find))
					{
						numi = i;
						numj = j;
						if (numi == SIZEx - 1 && action == 0)
						{
							action = 1;
						}
					}
					else if (data[i][j] == " ")
					{
						numi_s = i;
						numj_s = j;
					}
				}
			}

			// Выбор действий
			switch (action)
			{
			case 0: // action = 0 передвижение пропуска к нужному числу (снизу)
				if ((numi == num_find / SIZEx && numj == num_find % SIZEx - 1) || (numj == SIZEx - 1 && num_find % SIZEx == 0 && numi == num_find / SIZEx - 1))
				{
					if (num_find == SIZEx * (SIZEx - 1) + 1 + SIZEx - SIZEx_for_move_i)
					{
						num_find = num_find_reserv + 1;
						num_find_reserv += SIZEx + 1;
						SIZEx_for_move_i--;
						switcher = 0;
					}
					else if (num_find % SIZEx == 0)
					{
						num_find = num_find_reserv;
						SIZEx_for_move_j--;
						switcher = 1;
					}
					else
					{
						if (switcher == 0) num_find++;
						else num_find += SIZEx;
					}
					break;
				}
				if (numi_s != numi + 1 || numj_s != numj)
				{
					if (numi_s > numi + 1) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (numi_s < numi + 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (numj_s < numj) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				}
				else action = 2;
				break;
			case 1: // action = 1 передвижение пропуска к нужному числу (сверху)
				if ((numi == num_find / SIZEx && numj == num_find % SIZEx - 1) || (numj == SIZEx - 1 && num_find % SIZEx == 0 && numi == num_find / SIZEx - 1))
				{
					action = 0;
					if (num_find == SIZEx * (SIZEx - 1) + 1 + SIZEx - SIZEx_for_move_i)
					{
						num_find = num_find_reserv + 1;
						num_find_reserv += SIZEx + 1;
						SIZEx_for_move_i--;
						switcher = 0;
					}
					else if (num_find % SIZEx == 0)
					{
						num_find = num_find_reserv;
						SIZEx_for_move_j--;
						switcher = 1;
					}
					else
					{
						if (switcher == 0) num_find++;
						else num_find += SIZEx;
					}
					break;
				}
				if (numi_s != numi - 1 || numj_s != numj)
				{
					if (numi_s == numi) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (numi_s < numi - 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (numj_s < numj) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				}
				else
				{
					swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					action = 2;
				}
				break;
			case 2: // action = 2 передвижение числа вправо до конца
				if (numj_s != SIZEx - 1 || numj != SIZEx - 1)
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else if (step == 1) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (step == 2) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 3) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);

					if (step < 4) step++;
					else step = 0;
				}
				else
				{
					step = 0;
					if (numi == num_find / SIZEx && numi_s == num_find / SIZEx) action = 5;
					else if (numi > num_find / SIZEx || numi_s > num_find / SIZEx) action = 3;
					else
					{
						if (num_find / SIZEx == SIZEx - 1 && numi_s == SIZEx - 1) action = 3;
						else action = 4;
					}
				}
				break;
			case 3: // action = 3 передвижение числа на нужную строчку вверх (слева)
				if (num_find / SIZEx != SIZEx - 1 && (numi_s != num_find / SIZEx || numi != num_find / SIZEx))
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 1 || step == 2) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (step == 3) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);

					if (step < 4) step++;
					else step = 0;
				}
				else if (num_find / SIZEx == SIZEx - 1 && (numi_s != num_find / SIZEx - 1 || numi != num_find / SIZEx - 1))
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 1 || step == 2) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (step == 3) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);

					if (step < 4) step++;
					else step = 0;
				}
				else
				{
					step = 0;
					if (num_find / SIZEx == SIZEx - 1) action = 6;
					else if (num_find % SIZEx == 0) action = 7;
					else action = 5;
				}
				break;
			case 4: // action = 4 передвижение числа на нужную строчку вниз (слева)
				if (num_find / SIZEx != SIZEx - 1 && (numi_s != num_find / SIZEx || numi != num_find / SIZEx))
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (step == 1) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 2 || step == 3) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);

					if (step < 4) step++;
					else step = 0;
				}
				else if (num_find / SIZEx == SIZEx - 1 && (numi_s != num_find / SIZEx - 1 || numi != num_find / SIZEx - 1))
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (step == 1) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 2 || step == 3) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);

					if (step < 4) step++;
					else step = 0;
				}
				else
				{
					step = 0;
					if (num_find / SIZEx == SIZEx - 1) action = 6;
					else if (num_find % SIZEx == 0) action = 7;
					else action = 5;
				}
				break;
			case 5: // action = 5 передвижение числа на нужную позицию (снизу)
				if (numj != num_find % SIZEx - 1)
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else if (step == 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (step == 2 || step == 3) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);

					if (step < 4) step++;
					else
					{
						step = 0;
					}
				}
				else
				{
					step = 0;
					if (switcher == 0) num_find++;
					else num_find += SIZEx;
					action = 0;
				}
				break;
			case 6: // action = 6 передвижение числа на нужную позицию (последнего в столбце)
				if (numj != num_find % SIZEx || numj_s != num_find % SIZEx)
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else if (step == 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (step == 2 || step == 3) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);

					if (step < 4) step++;
					else
					{
						step = 0;
					}
				}
				else
				{
					step = 0;
					action = 8;
				}
				break;
			case 7: // action = 7 передвижение последнего числа в строке
				if (step != SIZEx_for_move_j + SIZEx_for_move_j + SIZEx_for_move_j)
				{
					if (step < SIZEx_for_move_j - 2)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					}
					else if (step == SIZEx_for_move_j - 2)
					{
						swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					}
					else if (step < SIZEx_for_move_j + SIZEx_for_move_j - 2)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					}
					else if (step == SIZEx_for_move_j + SIZEx_for_move_j - 2)
					{
						swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					}
					else if (step == SIZEx_for_move_j + SIZEx_for_move_j - 1)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					}
					else if (step == SIZEx_for_move_j + SIZEx_for_move_j)
					{
						swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					}
					else if (step < SIZEx_for_move_j + SIZEx_for_move_j + SIZEx_for_move_j - 1)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					}
					else if (step == SIZEx_for_move_j + SIZEx_for_move_j + SIZEx_for_move_j - 1)
					{
						swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					}
					step++;

				}
				else
				{
					step = 0;
					num_find = num_find_reserv;
					SIZEx_for_move_j--;
					switcher = 1;
					action = 0;
				}
				break;
			case 8: // action = 8 передвижение последнего числа в столбце
				if (step != SIZEx_for_move_i + SIZEx_for_move_i + SIZEx_for_move_i - 2)
				{
					if (step < SIZEx_for_move_i - 2)
					{
						swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					}
					else if (step == SIZEx_for_move_i - 2)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					}
					else if (step < SIZEx_for_move_i + SIZEx_for_move_i - 3)
					{
						swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					}
					else if (step == SIZEx_for_move_i + SIZEx_for_move_i - 3)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					}
					else if (step == SIZEx_for_move_i + SIZEx_for_move_i - 2)
					{
						swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					}
					else if (step == SIZEx_for_move_i + SIZEx_for_move_i - 1)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					}
					else if (step < SIZEx_for_move_i + SIZEx_for_move_i + SIZEx_for_move_i - 3)
					{
						swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					}
					else if (step == SIZEx_for_move_i + SIZEx_for_move_i + SIZEx_for_move_i - 3)
					{
						swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					}
					step++;
				}
				else
				{
					step = 0;
					num_find = num_find_reserv + 1;
					num_find_reserv += SIZEx + 1;
					SIZEx_for_move_i--;
					switcher = 0;
					action = 0;
				}
				break;
			}

			if (animation == 1)
			{
				cout << "\nЗначения после шага:\n";
				cout << "step = " << step << " \naction = " << action << " \nswitcher = " << switcher << " \nnum_find_reserv = " << num_find_reserv << "\nnumi = " << numi << " numj = " << numj << "\nnumi_s = " << numi_s << " numj_s = " << numj_s << " \nnum_find = ";
				setColor(14, TextBackgroundColor);
				cout << num_find;
				setColor(TextColor, TextBackgroundColor);
				cout << "\nSIZEx_for_move_i = " << SIZEx_for_move_i << "\n";
				Sleep(75);
			}
		}
		// Сбор оставшегося поля
		else
		{
			if (numj_reserv == SIZEx - 3) num_find = num_find_reserv + SIZEx;
			
			if (animation == 1)
			{
				cout << "\nЗначения до шага:\n";
				cout << "step = " << step << " \naction = " << action << " \nnumj_reserv = " << numj_reserv << " \nnum_find_reserv = " << num_find_reserv << "\nnumi = " << numi << " numj = " << numj << "\nnumi_s = " << numi_s << " numj_s = " << numj_s << " \nnum_find = ";
				setColor(14, TextBackgroundColor);
				cout << num_find;
				setColor(TextColor, TextBackgroundColor);
				cout << "\n";
			}

			// Опредиления координат искомого числа и пробела
			for (int i = 0; i < SIZEx; i++)
			{
				for (int j = 0; j < SIZEx; j++)
				{
					if (data[i][j] == " ")
					{
						numi_s = i;
						numj_s = j;
					}
					else if (data[i][j] == to_string(num_find) && num_find == num_find_reserv && numi_SIZEx_reserv == i - 1 && numj_SIZEx_reserv == j)
					{
						action = 4;
						numi = i;
						numj = j;
					}
					else if (data[i][j] == to_string(num_find))
					{
						numi = i;
						numj = j;
						if (numi == SIZEx - 1 && action == 0)
						{
							action = 1;
						}
						if (num_find == num_find_reserv + SIZEx)
						{
							numi_SIZEx_reserv = i;
							numj_SIZEx_reserv = j;
						}
					}
				}
			}

			if (numi_s == SIZEx - 1 && numj_s == numj_reserv - 1 && numi == SIZEx - 1 && numj == numj_reserv)
			{
				action = 4;
				step = 2;
			}

			// Выбор действий
			switch (action)
			{
			case 0: // action = 0 передвижение пропуска к нужному числу (снизу)
				if (numj == numj_reserv && numi == SIZEx - 2)
				{
					if (num_find != num_find_reserv)
					{
						num_find -= SIZEx;
						numj_reserv++;
					}
					else
					{
						if (numi_s == SIZEx - 1 && numj_s == SIZEx - 2)
						{
							step = 2;
						}
						else if (numi_s == SIZEx - 1 && numj_s == SIZEx - 3)
						{
							step = 3;
						}
						action = 5;
					}
					break;
				}
				if (numi_s != numi + 1 || numj_s != numj)
				{
					if (numi_s > numi + 1) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (numi_s < numi + 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (numj_s < numj) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				}
				else action = 2;
				break;
			case 1: // action = 1 передвижение пропуска к нужному числу (сверху)
				if (numj == numj_reserv && numi == SIZEx - 2)
				{
					if (num_find != num_find_reserv)
					{
						num_find -= SIZEx;
						numj_reserv++;
					}
					else
					{
						if (numi_s == SIZEx - 1 && numj_s == SIZEx - 2)
						{
							step = 2;
						}
						else if (numi_s == SIZEx - 1 && numj_s == SIZEx - 3)
						{
							step = 3;
						}
						action = 5;
					}
					break;
				}
				if (numi_s != numi - 1 || numj_s != numj)
				{
					if (numi_s == numi && numj_s == numj_reserv - 1 && num_find == num_find_reserv) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else if (numi_s == numi) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (numi_s < numi - 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (numj_s < numj) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				}
				else
				{
					swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					action = 2;
					step = 0;
				}
				break;
			case 2: // action = 2 передвижение числа на нужную позицию (снизу)
				if (numj != numj_reserv)
				{
					if (step == 0) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
					else if (step == 1) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
					else if (step == 2) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
					else if (step == 3) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
					else if (step == 4) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);

					if (step < 4) step++;
					else
					{
						step = 0;
					}
				}
				else if (num_find != num_find_reserv)
				{
					step = 0;
					action = 0;
					num_find -= SIZEx;
					numj_reserv++;
				}
				else
				{
					step = 0;
					if (numi_s == SIZEx - 1 && numj_s == SIZEx - 2)
					{
						step = 2;
					}
					else if (numi_s == SIZEx - 1 && numj_s == SIZEx - 3)
					{
						step = 3;
					}
					action = 5;
				}
				break;
			case 4:
				if (step == 0) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				else if (step == 1) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				else if (step == 2) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
				else if (step == 3 || step == 4) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
				else if (step == 5) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				else if (step == 6) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				else if (step == 7) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
				else if (step == 8) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
				else if (step == 9) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				else if (step == 10) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				else if (step == 11) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
				else if (step == 12) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				else if (step == 13) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				else if (step == 14) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
				else if (step == 15) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
				else if (step == 16) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);

				if (step < 16) step++;
				else
				{
					step = 0;
					action = 5;
				}
				break;
			case 5:
				if (step == 0) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				else if (step == 1 || step == 2) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
				else if (step == 3) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
				else if (step == 4) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
				else if (step > 4)
				{
					cnt = 1;
					for (int i = 0; i < SIZEx; i++)
					{
						for (int j = 0; j < SIZEx; j++)
						{
							if (i == SIZEx - 1 && j == SIZEx - 1) continue;
							else if (data[i][j] != to_string(cnt))
							{
								flag_win = false;
								break;
							}
							cnt++;
						}
						if (!flag_win) break;
					}
					if (flag_win)
					{
						time_t end_time = clock();
						int key = 0;
						keyboard KEY;

						if (animation) system_cls();

						for (int i = 0; i < SIZEx; i++)
						{
							for (int j = 0; j < SIZEx; j++)
							{
								setColor(2, TextBackgroundColor);
								cout << setw(4) << data[i][j];
								setColor(TextColor, TextBackgroundColor);
							}
							cout << endl;
						}
						for (int i = 0; i < SIZEx; i++)
							cout << "----";
						cout << "\nГотово!\n" << "Количество перестановок: " << cnt_Enter << "\nВремя сборки: " << (end_time - start_time) / 1000.0 << " секунд";
						if (animation) cout << " (~" << ((end_time - start_time) / 1000.0) - (0.075 * cnt_Enter) << " без учёта пауз)";
						cout << "\n";
						for (int i = 0; i < SIZEx; i++)
							cout << "----";
						cout << "\nИспользуйте:\n- ESC - для выхода\n- R - для рестарта\n";

						for (int i = 0; i < SIZEx; i++)
							delete[] data[i];
						delete[] data;

						while (true)
						{
							key = KEY.get_key();

							if (key == 82 || key == 114)
							{
								return false;
							}
							else if (key == 27)
							{
								return true;
							}
						}
					}
					else
					{
						flag_win = true;
						if (step % 4 == 1) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
						else if (step % 4 == 2) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
						else if (step % 4 == 3) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
						else if (step % 4 == 0) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);

						if (step > 16)
						{
							time_t end_time = clock();
							int key = 0;
							keyboard KEY;
							cnt = 1;
							if (animation) system_cls();

							for (int i = 0; i < SIZEx; i++)
							{
								for (int j = 0; j < SIZEx; j++)
								{
									if (data[i][j] == to_string(cnt))
									{
										setColor(2, TextBackgroundColor);
										cout << setw(4) << data[i][j];
										setColor(TextColor, TextBackgroundColor);
									}
									else cout << setw(4) << data[i][j];
									cnt++;
								}
								cout << endl;
							}

							for (int i = 0; i < SIZEx; i++)
								cout << "----";
							cout << "\nНе удалось решить.\n" << "Количество перестановок: " << cnt_Enter << "\nВремя сборки: " << (end_time - start_time) / 1000.0 << " секунд";
							if (animation) cout << " (~" << ((end_time - start_time) / 1000.0) - (0.075 * cnt_Enter) << " без учёта пауз и отрисовки)";
							cout << "\n";
							for (int i = 0; i < SIZEx; i++)
								cout << "----";
							cout << "\nИспользуйте:\n- ESC - для выхода\n- R - для рестарта\n";

							for (int i = 0; i < SIZEx; i++)
								delete[] data[i];
							delete[] data;

							while (true)
							{
								key = KEY.get_key();

								if (key == 82 || key == 114)
								{
									return false;
								}
								else if (key == 27)
								{
									return true;
								}
							}
						}
					}
				}

				step++;
				break;
			}
			
			if (animation == 1)
			{
				cout << "\nЗначения после шага:\n";
				cout << "step = " << step << " \naction = " << action << " \nnumj_reserv = " << numj_reserv << " \nnum_find_reserv = " << num_find_reserv << "\nnumi = " << numi << " numj = " << numj << "\nnumi_s = " << numi_s << " numj_s = " << numj_s << " \nnum_find = ";
				setColor(14, TextBackgroundColor);
				cout << num_find;
				setColor(TextColor, TextBackgroundColor);
				cout << "\n";
				Sleep(75);
			}

		}

		cnt_Enter++;
	}
}

void Pyatnashki()
{
	keyboard KEY;
	while (true)
	{
		system_cls();
		bool flag_R = false;
		int key = 0;
		srand(time(NULL));

		string cons_out[6] = { "2 x 2", "3 x 3", "4 x 4", "5 x 5", "10 x 10", "Свой вариант" };

		int SIZEx = 0;

		// Выбор размера поля
		do
		{
			system_cls();
			cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Выбор поля------------" << endl;
			for (int i = 0; i < 6; i++)
			{
				if (i == SIZEx)
				{
					setColor(TextBackgroundColor, TextColor);
					cout << cons_out[i];
					setColor(TextColor, TextBackgroundColor);
					cout << endl;
				}
				else cout << cons_out[i] << endl;
			}

			key = KEY.get_key();
			if (key == KeyDown && SIZEx < 6 - 1) SIZEx++;
			if (key == KeyUp && SIZEx > 0) SIZEx--;
			if (key == KeyExit)
			{
				system_cls();
				return;
			}
		} while (key != KeyEnter);
		if (SIZEx == 5)
		{
			while (true)
			{
				SIZEx = (int)chek(5, "Введите размер поля: ", false);
				if (SIZEx > 50) cout << "Размер не должен превышать 50 х 50." << endl;
				else if (SIZEx < 2) cout << "Размер должен быть не меньше 2 х 2." << endl;
				else break;
			}
		}
		else if (SIZEx == 4) SIZEx = 10;
		else SIZEx += 2;

		string** data = new string * [SIZEx];
		for (int i = 0; i < SIZEx; i++)
			data[i] = new string[SIZEx];

		string* num = new string[SIZEx * SIZEx];
		string* check_ = new string[SIZEx * SIZEx];

		int numi = 0, numj = 0;

		for (int i = 0; i < SIZEx * SIZEx; i++)
		{
			if (i == 0) num[i] = " ";
			else num[i] = to_string(i);
		}

		int sum = 0;
		int y = 0;
		int i_s = 0;
		int x_index = 0, x_index_reserv = 0;
		int x = 0;
		int num1 = 0;
		string check;
		int cnt = 1;

		// Создание и проверка комбинации на существование решения (для чётных полей)
		if (SIZEx % 2 == 0) do
		{
			sum = 0, y = 0, i_s = 0, x_index = 0, x_index_reserv = 0, x = 0, num1 = 0, check = ""; // Сброс значений

			for (int i = 0; i < SIZEx; i++)
			{
				for (int j = 0; j < SIZEx; j++)
				{
					do num1 = rand() % (SIZEx * SIZEx); while (check.find("(" + num[num1] + ")") != -1);
					check += "(" + num[num1] + ")";
					data[i][j] = num[num1];
					check_[y] = num[num1];
					if (check_[y] == " ") i_s = i + 1;
					y++;
				}
			}
			for (int i = 0; i < SIZEx * SIZEx; i++)
			{
				if (check_[i] != " ")
				{
					x = stoi(check_[i]);
					x_index = i;
				}
				else x = 0;
				x_index_reserv = x_index;
				for (x_index; x_index < SIZEx * SIZEx; x_index++)
				{
					if (check_[x_index] != " " && x > stoi(check_[x_index]) && x_index_reserv < x_index)
					{
						sum++;
						/*cout << "x_index = " << x_index << ", x_index_reserv = " << x_index_reserv << ", x = " << x << ", i_s = " << i_s << ", sum = " << sum << endl;*/
					}
				}
				/*x_index = x_index_reserv + 1;
				cout << endl;*/
			}
			sum += i_s;
			/*cout << "sum = " << sum << endl << endl;
			ExitToMenu();*/
		} while (sum % 2 == 1);

		// Создание и проверка комбинации на существование решения (для нечётных полей)
		else do
		{
			sum = 0, y = 0, i_s = 0, x_index = 0, x_index_reserv = 0, x = 0, num1 = 0, check = ""; // Сброс значений

			for (int i = 0; i < SIZEx; i++)
			{
				for (int j = 0; j < SIZEx; j++)
				{
					do num1 = rand() % (SIZEx * SIZEx); while (check.find("(" + num[num1] + ")") != -1);
					check += "(" + num[num1] + ")";
					data[i][j] = num[num1];
					check_[y] = num[num1];
					if (check_[y] == " ") i_s = i + 1;
					y++;
				}
			}
			for (int i = 0; i < SIZEx * SIZEx; i++)
			{
				if (check_[i] != " ")
				{
					x = stoi(check_[i]);
					x_index = i;
				}
				else x = 0;
				x_index_reserv = x_index;
				for (x_index; x_index < SIZEx * SIZEx; x_index++)
				{
					if (check_[x_index] != " " && x > stoi(check_[x_index]) && x_index_reserv < x_index)
					{
						sum++;
						/*cout << "x_index = " << x_index << ", x_index_reserv = " << x_index_reserv << ", x = " << x << ", i_s = " << i_s << ", sum = " << sum << endl;*/
					}
				}
				/*x_index = x_index_reserv + 1;
				cout << endl;*/
			}
			sum += i_s;
			/*cout << "sum = " << sum << endl << endl;
			ExitToMenu();*/
		} while (sum % 2 == 0);

		delete[] check_;
		delete[] num;

		string cons_out2[2] = { "Играть самому", "Доверить игру алгоритму" };
		int type = 0;

		// Выбор режима игры
		do
		{
			system_cls();
			cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Выбор режима игры------------" << endl;
			for (int i = 0; i < 2; i++)
			{
				if (i == type)
				{
					setColor(TextBackgroundColor, TextColor);
					cout << cons_out2[i];
					setColor(TextColor, TextBackgroundColor);
					cout << endl;
				}
				else cout << cons_out2[i] << endl;
			}

			key = KEY.get_key();
			if (key == KeyDown && type < 2 - 1) type++;
			if (key == KeyUp && type > 0) type--;
			if (key == KeyExit)
			{
				system_cls();
				return;
			}
		} while (key != KeyEnter);

		bool flag_win = true;
		
		for (int i = 0; i < SIZEx; i++)
		{
			for (int j = 0; j < SIZEx; j++)
			{
				if (i == SIZEx - 1 && j == SIZEx - 1) continue;
				else if (data[i][j] != to_string(cnt))
				{
					flag_win = false;
					break;
				}
				cnt++;
			}
			if (!flag_win) break;
		}
		if (flag_win)
		{
			system_cls();
			cout << "Используйте:\n- стрелки вверх, вниз - для передвижения по вертикали\n- стрелки вправо, влево - для передвижения по горизонтали\n- Enter - для выбора\n- ESC - для выхода\n- R - для рестарта\n---------Пятнашки------------\n";
			for (int i = 0; i < SIZEx; i++)
			{
				for (int j = 0; j < SIZEx; j++)
				{
					setColor(2, TextBackgroundColor);
					cout << setw(4) << data[i][j];
					setColor(TextColor, TextBackgroundColor);
				}
				cout << endl;
			}
			for (int i = 0; i < SIZEx; i++)
				delete[] data[i];
			delete[] data;
			cout << "Вам сказачно повезло!" << endl;
			while (true)
			{
				key = KEY.get_key();

				if (key == 82 || key == 114)
				{
					flag_R = true;
					break;
				}
				else if (key == 27)
				{
					return;
				}
			}
		}
		else if (type == 1)
		{
			key = 0;
			int animation = 0;
			string cons_out3[2] = { "Без анимации", "С анимацией" };
			bool flag = true;
			do
			{
				system_cls();
				cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n-------Выбор режима игры--------" << endl;
				for (int i = 0; i < 2; i++)
				{
					if (i == type)
					{
						setColor(TextBackgroundColor, TextColor);
						cout << cons_out2[i];
						setColor(TextColor, TextBackgroundColor);
						cout << endl;
					}
					else cout << cons_out2[i] << endl;
				}
				cout << "--------------------------------" << endl;
				for (int i = 0; i < 2; i++)
				{
					if (i == animation)
					{
						setColor(TextBackgroundColor, TextColor);
						if (key == KeyEnter)
						{
							if (SIZEx > 10 && i == 1) cout << cons_out3[i] << " - Нельзя использовать при размере поля большего 10 х 10.";
							else flag = false;
						}
						else cout << cons_out3[i];
						setColor(TextColor, TextBackgroundColor);
						cout << endl;
					}
					else cout << cons_out3[i] << endl;
				}
				if (!flag) break;

				key = KEY.get_key();
				if (key == KeyDown && animation < 2 - 1) animation++;
				if (key == KeyUp && animation > 0) animation--;
				if (key == KeyExit)
				{
					system_cls();
					return;
				}
			} while (true);
			system_cls();

			cout << "Размер поля: " << SIZEx << " x " << SIZEx << endl;
			cnt = 1;
			for (int i = 0; i < SIZEx; i++)
			{
				for (int j = 0; j < SIZEx; j++)
				{
					if (data[i][j] == to_string(cnt))
					{
						setColor(2, TextBackgroundColor);
						cout << setw(4) << data[i][j];
						setColor(TextColor, TextBackgroundColor);
					}
					else cout << setw(4) << data[i][j];
					cnt++;
				}
				cout << endl;
			}
			for (int i = 0; i < SIZEx; i++)
				cout << "----";
			cout << endl;

			if (algorithm(data, SIZEx, animation)) return;
			else flag_R = true;
		}
		else
		{
			int k = 0;
			time_t start_time = clock();
			int cnt_Enter = 0;
			while (true)
			{
				if (cnt_Enter == 0)
				{
					start_time = clock();
				}

				do
				{
					system_cls();

					cout << "Используйте:\n- стрелки вверх, вниз - для передвижения по вертикали\n- стрелки вправо, влево - для передвижения по горизонтали\n- Enter - для выбора\n- ESC - для выхода\n- R - для рестарта\n---------Пятнашки------------\n";
					int cnt = 1;
					for (int i = 0; i < SIZEx; i++)
					{
						for (int j = 0; j < SIZEx; j++)
						{
							if (i == numi && j == numj)
							{
								if (data[i][j] == to_string(cnt))
								{
									setColor(2, TextColor);
									cout << setw(4) << data[i][j];
									setColor(TextColor, TextBackgroundColor);
								}
								else
								{
									setColor(TextBackgroundColor, TextColor);
									cout << setw(4) << data[i][j];
									setColor(TextColor, TextBackgroundColor);
								}
							}
							else if (data[i][j] == to_string(cnt))
							{
								setColor(2, TextBackgroundColor);
								cout << setw(4) << data[i][j];
								setColor(TextColor, TextBackgroundColor);
							}
							else cout << setw(4) << data[i][j];
							cnt++;
						}
						cout << endl;

					}
					key = KEY.get_key();

					if (key == 302 && numj < SIZEx - 1) numj++;
					else if (key == 303 && numi < SIZEx - 1) numi++;
					else if (key == 300 && numj > 0) numj--;
					else if (key == 301 && numi > 0) numi--;
					else if (key == 82 || key == 114 || key == 138 || key == 170)
					{
						flag_R = true;
						for (int i = 0; i < SIZEx; i++)
							delete[] data[i];
						delete[] data;
						cnt_Enter = 0;
						break;
					}
					else if (key == 27)
					{
						for (int i = 0; i < SIZEx; i++)
							delete[] data[i];
						delete[] data;
						return;
					}
				} while (key != 13);
				if (flag_R) break;
				cnt_Enter++;

				if (numi != 0 && numj != 0 && numi != SIZEx - 1 && numj != SIZEx - 1)
				{
					if (data[numi + 1][numj] == " ") swap(data[numi + 1][numj], data[numi][numj]);
					else if (data[numi - 1][numj] == " ") swap(data[numi - 1][numj], data[numi][numj]);
					else if (data[numi][numj + 1] == " ") swap(data[numi][numj + 1], data[numi][numj]);
					else if (data[numi][numj - 1] == " ") swap(data[numi][numj - 1], data[numi][numj]);
				}
				else if (numi == 0 && numj == 0)
				{
					if (data[numi + 1][numj] == " ") swap(data[numi + 1][numj], data[numi][numj]);
					else if (data[numi][numj + 1] == " ") swap(data[numi][numj + 1], data[numi][numj]);
				}
				else if (numi == SIZEx - 1 && numj == 0)
				{
					if (data[numi - 1][numj] == " ") swap(data[numi - 1][numj], data[numi][numj]);
					else if (data[numi][numj + 1] == " ") swap(data[numi][numj + 1], data[numi][numj]);
				}
				else if (numi == 0 && numj == SIZEx - 1)
				{
					if (data[numi + 1][numj] == " ") swap(data[numi + 1][numj], data[numi][numj]);
					else if (data[numi][numj - 1] == " ") swap(data[numi][numj - 1], data[numi][numj]);
				}
				else if (numi == SIZEx - 1 && numj == SIZEx - 1)
				{
					if (data[numi - 1][numj] == " ") swap(data[numi - 1][numj], data[numi][numj]);
					else if (data[numi][numj - 1] == " ") swap(data[numi][numj - 1], data[numi][numj]);
				}
				else if (numi == 0)
				{
					if (data[numi + 1][numj] == " ") swap(data[numi + 1][numj], data[numi][numj]);
					else if (data[numi][numj + 1] == " ") swap(data[numi][numj + 1], data[numi][numj]);
					else if (data[numi][numj - 1] == " ") swap(data[numi][numj - 1], data[numi][numj]);
				}
				else if (numi == SIZEx - 1)
				{
					if (data[numi - 1][numj] == " ") swap(data[numi - 1][numj], data[numi][numj]);
					else if (data[numi][numj + 1] == " ") swap(data[numi][numj + 1], data[numi][numj]);
					else if (data[numi][numj - 1] == " ") swap(data[numi][numj - 1], data[numi][numj]);
				}
				else if (numj == 0)
				{
					if (data[numi + 1][numj] == " ") swap(data[numi + 1][numj], data[numi][numj]);
					else if (data[numi - 1][numj] == " ") swap(data[numi - 1][numj], data[numi][numj]);
					else if (data[numi][numj + 1] == " ") swap(data[numi][numj + 1], data[numi][numj]);
				}
				else if (numj == SIZEx - 1)
				{
					if (data[numi + 1][numj] == " ") swap(data[numi + 1][numj], data[numi][numj]);
					else if (data[numi - 1][numj] == " ") swap(data[numi - 1][numj], data[numi][numj]);
					else if (data[numi][numj - 1] == " ") swap(data[numi][numj - 1], data[numi][numj]);
				}

				bool flag_win = true;
				int cnt = 1;

				for (int i = 0; i < SIZEx; i++)
				{
					for (int j = 0; j < SIZEx; j++)
					{
						if (i == SIZEx - 1 && j == SIZEx - 1) continue;
						else if (data[i][j] != to_string(cnt))
						{
							flag_win = false;
							break;
						}
						cnt++;
					}
					if (!flag_win) break;
				}
				if (flag_win)
				{
					time_t end_time = clock();
					system_cls();
					cout << "Используйте:\n- стрелки вверх, вниз - для передвижения по вертикали\n- стрелки вправо, влево - для передвижения по горизонтали\n- Enter - для выбора\n- ESC - для выхода\n- R - для рестарта\n---------Пятнашки------------\n";
					for (int i = 0; i < SIZEx; i++)
					{
						for (int j = 0; j < SIZEx; j++)
						{
							setColor(2, TextBackgroundColor);
							cout << setw(4) << data[i][j];
							setColor(TextColor, TextBackgroundColor);
						}
						cout << endl;
					}
					for (int i = 0; i < SIZEx; i++)
						delete[] data[i];
					delete[] data;

					cout << "Игра пройдена!\n" << "Количество перестановок: " << cnt_Enter << "\nВремя игры: " << (end_time - start_time) / 1000.0 << " секунд\n";

					cnt_Enter = 0;
					while (true)
					{
						key = KEY.get_key();

						if (key == 82 || key == 114 || key == 138 || key == 170)
						{
							flag_R = true;
							break;
						}
						else if (key == 27)
						{
							return;
						}
					}
					break;
				}
			}
		}
	}
}
