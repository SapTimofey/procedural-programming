#include "Pyatnashki.h"

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

void Pyatnashki()
{
	system_cls();
	keyboard KEY;


	int key = 0;



	int SIZEx = (int)chek(5, "Введите размер матрицы: ", false);

	int** data = new int* [SIZEx] {0};
	for (int i = 0; i < SIZEx; i++)
		data[i] = new int[SIZEx] {0};


	int* num = new int[SIZEx * SIZEx];
	string check;
	bool flag = false;
	int cnt = 0;
	int num1 = 0;
	for (int i = 0; i < SIZEx * SIZEx; i++)
	{
		num[i] = i + 1;
	}

	for (int i = 0; i < SIZEx; i++)
	{
		for (int j = 0; j < SIZEx; j++)
		{
			while (check.find(to_string(num[num1]) + "!") != -1) num1 = rand() % (SIZEx * SIZEx);

			check += to_string(num[num1]) + "!";
			cout << check << endl;
			data[i][j] = num[num1];
		}


	}
	int numi = 0, numj = 0;

	//while (true)
	//{
	//	do
	//	{
	//		system_cls();

	//		std::cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Выбор Д/з------------\n";

	//		for (int i = 0; i < SIZEx; i++)
	//		{
	//			for (int j = 0; j < SIZEx; j++)
	//			{
	//				if (i == numi && j == numj)
	//				{
	//					setColor(TextBackgroundColor, TextColor);
	//					cout << data[i][j];
	//					setColor(TextColor, TextBackgroundColor);
	//					cout << " ";
	//				}
	//				else cout << data[i][j] << " ";
	//			}
	//			cout << endl;

	//		}



	//		key = KEY.get_key();
	//		if (key == 302 && numj < SIZEx - 1) numj++;
	//		if (key == 303 && numi < SIZEx - 1) numi++;
	//		if (key == 300 && numj > 0) numj--;
	//		if (key == 301 && numi > 0) numi--;
	//		/*if (key == KeyExit)
	//		{
	//			std::cout << "Вы завершили работу.\n";
	//			exit(EXIT_SUCCESS);
	//		}*/
	//	} while (true);


	//}
	ExitToMenu();
}