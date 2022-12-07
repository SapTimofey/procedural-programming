#include "Pyatnashki.h"

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

bool algorithm(string** data, int SIZEx)
{
	//300: "Left"
	//301: "Up"
	//302: "Right"
	//303: "Down"
	//13:  "Enter"

	unsigned int start_time = clock();
	int cnt_Enter = 0;

	int SIZEy = SIZEx;
	int step = 0;
	int numi = 0, numj = 0;
	int numi_s = 0, numj_s = 0;
	bool flag = false;
	int num_find = 1;

	int action = 0;

	while (true)
	{
		system_cls();
		int cnt = 1;
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
		cout << "step = " << step << " action = " << action << " flag = " << flag;
		Sleep(250);

		for (int i = 0; i < SIZEx; i++)
		{
			for (int j = 0; j < SIZEx; j++)
			{
				if (data[i][j] == to_string(num_find))
				{
					numi = i;
					numj = j;
					if (numi == SIZEx - 1)
					{
						action = 1;
						flag = true;
					}
				}
				if (data[i][j] == " ")
				{
					numi_s = i;
					numj_s = j;
				}
			}
		}

		// action = 0 передвижение пропуска к нужному числу 
		// action = 1 передвижение пропуска к нужному числу (сверху)
		// action = 2 передвижение числа на нужную строчку
		// action = 3 передвижение числа на нужную позицию
		//
		//
		//


		switch (action)
		{
		case 0:
			if (numi_s != numi + 1 || numj_s != numj)
			{
				if (numi_s > numi + 1) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
				else if (numi_s < numi + 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				else if (numj_s < numj) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
				else swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
			}
			else action = 2;
			break;
		case 1:
			if (numi_s != numi - 1 || numj_s != numj)
			{
				if (numi_s < numi - 1) swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				else if (numj_s < numj) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
				else swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
			}
			else action = 2;
			break;
		case 2:
			if (flag)
			{
				swap(data[numi_s][numj_s], data[numi_s + 1][numj_s]);
				flag = false;
			}
			if (step == 0) swap(data[numi_s][numj_s], data[numi_s][numj_s - 1]);
			else if (step == 1 || step == 2) swap(data[numi_s][numj_s], data[numi_s - 1][numj_s]);
			else if (step == 3) swap(data[numi_s][numj_s], data[numi_s][numj_s + 1]);
			if (step < 3) step++;
			else
			{
				action = 0;
				step = 0;
			}

			/*if (numi == num_find / SIZEx && numj != num_find % SIZEx - 1) action = 2;*/
			break;
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

		string cons_out[5] = { "2 x 2", "3 x 3", "4 x 4", "5 x 5", "Свой вариант" };

		int SIZEx = 0;

		do
		{
			system_cls();
			cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Выбор поля------------" << endl;
			for (int i = 0; i < 5; i++)
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
			if (key == KeyDown && SIZEx < 5 - 1) SIZEx++;
			if (key == KeyUp && SIZEx > 0) SIZEx--;
			if (key == KeyExit)
			{
				system_cls();
				return;
			}
		} while (key != KeyEnter);

		if (SIZEx == 4)
		{
			while (true)
			{
				SIZEx = (int)chek(5, "Введите размер поля: ", false);
				if (SIZEx > 10) cout << "Размер не должен превышать 10 х 10." << endl;
				else if (SIZEx < 2) cout << "Размер должен быть не меньше 2 х 2." << endl;
				else break;
			}
		}
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

		// Создание и проверка комбинации на существование решения
		do
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
					if (check_[x_index] != " " && x > stoi(check_[x_index]) && x_index_reserv < x_index) sum++;
					/*cout << "x_index = " << x_index << ", x_index_reserv = " << x_index_reserv << ", x = " << x << ", i_s = " << i_s << ", sum = " << sum << endl;*/
				}
				x_index = x_index_reserv + 1;
				/*cout << endl;*/
			}
			sum += i_s;
			/*cout << "sum = " << sum << endl << endl;*/
		} while (sum % 2 == 1);

		delete[] check_;
		delete[] num;

		string cons_out2[2] = { "Играть самому", "Доверить игру алгоритму" };
		int type = 0;

		// Выбор режима игры
		do
		{
			system_cls();
			cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Выбор поля------------" << endl;
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
			if (algorithm(data, SIZEx)) return;
		}
		else
		{
			int k = 0;
			unsigned int start_time = clock();
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
					unsigned int end_time = clock();
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

					cout << "Игра пройдена!\n" << "Количество перестановок: " << cnt_Enter << "\nВремя игры: " << (end_time - start_time) / 1000.0 << " секунд";
					/*if ((end_time - start_time) / 1000.0 >= 60)
					{
						cout << ((end_time - start_time) / 1000) / 60 << " минут " << ((end_time - start_time) % 60) / 1000.0 << " секунд" << endl;
					}*/
					cout << endl;
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