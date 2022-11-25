#include "HomeWork5.h"
#define NALLOCS 1000
#define ALLOC_SIZE 1024*100

using namespace std;

extern int TextColor;
extern int TextBackgroundColor;
extern int KeyExit;
extern int KeyEnter;
extern int KeyUp;
extern int KeyDown;

//Задание 1 "Алгоритм Евклида"
void euclid()
{
    system_cls();
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;

    cout << "Задание 'Алгоритм Евклида'\n";
    
    num1 = chek(5, "Введите 1 число: ", false);
    num2 = chek(5, "Введите 2 число: ", false);
    
    num5 = num3 = num1;
    num6 = num4 = num2;

    cout << endl << "Метод вычитания:" << endl << endl << num5 << " " << num6 << endl;

    while (num5 != num6)
    {
        if (num5 > num6) num5 -= num6;
        else num6 -= num5;
        cout << num5 << " " << num6 << endl;
    }

    cout << "НОД (" << num1 << ", " << num2 << ") = " << num5 << endl << endl;


    cout << "Метод деления:" << endl << endl << num3 << " " << num4 << endl;

    while (num4 > 0 && num3 > 0)
    {
        if (num3 > num4) num3 %= num4;
        else num4 %= num3;
        cout << num3 << " " << num4 << endl;
    }

    cout << "НОД (" << num1 << ", " << num2 << ") = ";
    if (num3 != 0) cout << num3 << endl << endl;
    else cout << num4 << endl << endl;
    
    ExitToMenu();
}

//Задание 2 "Решето Эратосфена"
void eratosthenes()
{
    system_cls();
    int n = 0;
    bool flag = false;
    cout << "Задание 'Решето Эратосфена'\n";
    
    while (n < 2 || n > 10000000)
    {
        n = (int)chek(5, "Введите число, до которого нужно найти простые числа: ", false);
        if (n < 2) cout << "Число должно быть не меньше 2.\n";
        else if (n > 10000000) cout << "Число должно быть не больше 10 000 000.\n";
    }

    int* natural_num = new int[n];
    if (n == 2) cout << 2 << "\n";
    else
    {
        for (int i = 0; i <= n; i++)
        {
            natural_num[i] = i;
        }

        for (int i = 2; i * i <= n; i++) if (natural_num[i]) for (int j = i * i; j <= n; j += i) natural_num[j] = 0;
        for (int i = 2; i < n; i++) if (natural_num[i]) cout << natural_num[i] << endl;

        cout << endl;
        delete[] natural_num;
    }

    ExitToMenu();
}

//Задание 3 "Обработка текстовых файлов"
void file_read_1()
{
    system_cls();
    file();
    string str, f_read, output;
    map <char, int> arr {{'q', 0}, {'w', 0}, {'r', 0}, {'t', 0}, {'p', 0}, {'s', 0}, {'d', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'z', 0}, {'x', 0}, {'c', 0}, {'v', 0}, {'b', 0}, {'n', 0}, {'m', 0}, {'Q', 0}, {'W', 0}, {'R', 0}, {'T', 0}, {'P', 0}, {'S', 0}, {'D', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'J', 0}, {'K', 0}, {'L', 0}, {'Z', 0}, {'X', 0}, {'C', 0}, {'V', 0}, {'B', 0}, {'N', 0}, {'M', 0} };
    int len = 0, max = 0;

    cout << "Задание 3.1 'Обработка текстовых файлов'\n" << "Введите строку для записи в файл (для завершения строки введите '.'): ";

    getline(cin, str, '.');
    str.erase(0, 1);
    len = str.length();

    string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
    str.erase(end_pos, str.end());

    //Запись строки в файл
    ofstream fout("test_HW.txt");
    fout << str;
    fout.close();

    //Чтение строки из файла
    ifstream fin("test_HW.txt");
    fin >> f_read;
    fin.close();
    
    for (int i = 0; i < len; i++)
    {
        try
        {
            arr.at(f_read[i]) += 1;
        }
        catch (out_of_range)
        {
            continue;
        }
    }
    
    for (auto i = arr.begin(); i != arr.end(); i++)
    {
        if (i->second > max)
        {
            max = i->second;
            output = i->first;
        }
        else if (i->second == max)
        {
            output = output + ", " + i->first;
        }
    }

    cout << "Часто встречаемые символы: " << output << " = " << max << endl;

    ExitToMenu();
}

//Задание 4 "Обработка текстовых файлов"
void find_str(string str, string str_find)
{
    int len = 0, len_find = 0;
    string str_begin, str_end;

    len_find = str_find.length();
    str_begin = str_end = str;
    len = str.length();

    str_end.erase(0, str.find(str_find) + len_find);
    str_begin.erase(str.find(str_find), len - str.find(str_find));

    cout << str_begin;
    setColor(TextBackgroundColor, TextColor);
    cout << str_find;
    setColor(TextColor, TextBackgroundColor);
    if (str_end.find(str_find) == -1) cout << str_end << " ";
    else find_str(str_end, str_find);
}
void file_read_2()
{
    system_cls();
    string str;
    string str_find;

    cout << "Задание 'Обработка текстовых файлов'\n" << "Введите строку (для завершения строки введите '#'): ";
    getline(cin, str, '#');

    cout << "\nВведите строку, которую нужно найти (для завершения строки введите '#'): ";
    getline(cin, str_find, '#');
    cout << "\n";
    
    str.erase(0, 1);
    str_find.erase(0, 1);


    if (str.find(str_find) == -1 || str.length() == 0 || str_find.length() == 0) cout << "Такой строки нет.";
    else find_str(str, str_find);
    cout << endl;

        ////Запись строки в файл
        //fout.open("test_HW.txt");
        //fout << str << endl;
        //fout.close();

        ////Чтение строки из файла
        //ifstream fin("test_HW.txt");
        //fin >> f_read;
        //fin.close();
        //cout << f_read << endl;

    ExitToMenu();
}

//Задание 5 "Ряды"
string interpreter(int num)
{
    string numS = to_string(num);
    int i = numS.length() - 1, j = 0;
    int res_10 = 0;
    string res;
    int a = 0;
    if (num == 0) return "0";
    else
    {
        for (j, i; j < numS.length(); i--, j++)
        {
            char x = numS[j];
            a = x - 48;
            res_10 += a * pow(3, i);
        }
        while (res_10 > 0)
        {
            res = to_string(res_10 % 6) + res;
            res_10 /= 6;
        }
        return res;
    }
}
void rows_1()
{
    system_cls();
    int a = 0, n = 0;
    
    string input_num;
    int cnt = 0;
    bool flag = true;

    cout << "Задание 'Ряды'\n";

    n = (int)chek(5, "Введите количество чисел в массиве: ", false);
    
    int* num_3 = new int[n + 1] {};
    string* num_6 = new string[n] {};

    while (cnt < n)
    {
        cin >> input_num;
        for (int j = 0; j < input_num.length(); j++)
        {
            if (isdigit(input_num[j]))
            {
                char x = input_num[j];
                a = x - 48;
            }
            else
            {
                char x = input_num[j];
                a = x;
                if (a < 97) a -= 55;
                else a -= 87;
            }
            if (a >= 3)
            {
                cout << "Число не соответствует 3 системе счисления." << endl << "Осталось ввести " << n - cnt;
                if ((n - cnt) % 10 == 0 || (n - cnt) % 10 == 5 || (n - cnt) % 10 == 6 || (n - cnt) % 10 == 7 || (n - cnt) % 10 == 8 || (n - cnt) % 10 == 9 || (n - cnt >=10 && n - cnt <= 19)) cout << " чисел: ";
                else if ((n - cnt) % 10 == 2 || (n - cnt) % 10 == 3 || (n - cnt) % 10 == 4) cout << " числа: ";
                else cout << " число: ";
                flag = false;
                break;
            }
        }
        if (flag)
        {
            num_3[cnt] = stoi(input_num);
            cnt++;
        }
        flag = true;
    }

    cout << "Массив из чисел в 3 СС: [";
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1) cout << num_3[i] << ", ";
        else cout << num_3[i];
    }
    cout << "]" << endl;


    for (int i = 0; i < n; i++)
    {
        num_6[i] = interpreter(num_3[i]);
    }

    cout << "Массив из чисел в 6 СС: [";
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1) cout << num_6[i] << ", ";
        else cout << num_6[i];
    }
    cout << "]" << endl;

    ExitToMenu();
}

//Задание 6 "Ряды"
void rows_2()
{
    system_cls();
    int SIZEx = 0, SIZEy = 0;
    float a = 0;
    string cons_out;
    float sum1 = 0;
    cout << "Задание 'Ряды'" << endl;
    srand(time(NULL));

    SIZEy = (int)chek(5, "Введите количество столбцов в массиве: ", false);
    SIZEx = (int)chek(5, "Введите количество строк в массиве: ", false);

    float* sum = new float[SIZEx] {0};
    /*float** arr = new float*[SIZEy];
    for (int i = 0; i < SIZEx; i++)
        arr[i] = new float[SIZEx];*/
    for (int i = 0; i < SIZEx; i++)
    {
        for (int j = 0; j < SIZEy; j++)
        {
            cons_out = "Введите элемент [" + to_string(j) + "][" + to_string(i) + "]: ";
            /*a = chek(0, cons_out, false);*/
            a = rand() % 1000;
            sum1 += a;
        }
        /*sum[i] = sum1;*/
        cout << "Сумма " << i + 1 << " столбца равна: " << sum1 << endl;
        sum1 = 0;
    }

    /*for (int i = 0; i < SIZEy; i++)
    {
        for (int j = 0; j < SIZEx; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }*/
    

    /*for (int i = 0; i < SIZEx; i++)
        cout << "Сумма " << i + 1 << " столбца равна: " << sum[i] << endl;*/


    ExitToMenu();
}

//Задание 7 "Файлы"
string** Dsort(string** data, int f, int g, int SIZEx)
{
    try
    {
        for (int i = 1; i < SIZEx - 1; i++)
            for (int k = 1; k < SIZEx - i; k++)
                if (g == 0)
                {
                    if (stoi(data[k][f]) > stoi(data[k + 1][f]))
                        swap(data[k], data[k + 1]);
                }
                else
                {
                    if (stoi(data[k][f]) < stoi(data[k + 1][f]))
                        swap(data[k], data[k + 1]);
                }
        return data;
    }
    catch (...)
    {
        for (int i = 1; i < SIZEx - 1; i++)
            for (int k = 1; k < SIZEx - i; k++)
                if (g == 0)
                {
                    if (data[k][f] > data[k + 1][f])
                        swap(data[k], data[k + 1]);
                }
                else
                {
                    if (data[k][f] < data[k + 1][f])
                        swap(data[k], data[k + 1]);
                }
        return data;
    }
}
void files()
{
    keyboard KEY;

    int key = 0;
    const int volume = 2;

    string cons_out[volume] = { "Ручной ввод данных", "Случайные данные" };

    int num = 0;
    int SIZEx = 0;
    string s;
    
    //Выбор типа ввода данных
    do
    {
        system_cls();
        cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Задание 'Файлы'------------" << endl;
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
        cout << "-------------------------------------\n";

        key = KEY.get_key();
        if (key == KeyDown && num < volume - 1) num++;
        if (key == KeyUp && num > 0) num--;
        if (key == KeyExit)
        {
            system_cls();
            return;
        }
    } while (key != KeyEnter);
    while (true)
    {
        try
        {
            while (SIZEx > 101 || SIZEx < 2)
            {
                SIZEx = (int)chek(5, "Введите количество стран: ", false) + 1;
                if (SIZEx > 101) cout << "Количество стран должно не больше 100.\n";
                else if (SIZEx < 2) cout << "Количество стран должно быть не меньше 1.\n";
            }
            if (num == 1 && SIZEx > 11) SIZEx = 11;

            string** data = new string * [SIZEx];
            for (int i = 0; i < SIZEx; i++)
                data[i] = new string[7];

            const int cnt_country = 10;

            data[0][0] = "N";
            data[0][1] = "Страна";
            data[0][2] = "Золото";
            data[0][3] = "Серебро";
            data[0][4] = "Бронза";
            data[0][5] = "Сумма медалей";
            data[0][6] = "Сумма очков";

            //Запись данных в файл
            ofstream fout("country.txt");
            if (num == 0)
            {
                for (int i = 1; i < SIZEx; i++)
                {
                    if (i != 1) fout << "\n";
                    for (int j = 0; j < 7; j++)
                    {
                        if (j == 0) data[i][0] = to_string(i);
                        else if (j == 1)
                        {
                            cout << "Введите " << i << "-ую страну: ";
                            cin >> s;
                            fout << s << ": ";
                        }
                        else if (j == 2) fout << to_string((int)chek(5, "Введите количество золотых медалей: ", false)) << " ";

                        else if (j == 3) fout << to_string((int)chek(5, "Введите количество серебрянных медалей: ", false)) << " ";

                        else if (j == 4) fout << to_string((int)chek(5, "Введите количество бронзовых медалей: ", false));

                    }
                }
            }
            else
            {
                srand(time(0));

                string country[cnt_country]{ "Канада", "Китай", "Корея", "Норвегия", "Финляндия", "Россия", "Германия", "США", "Франция", "Япония" };
                string check;
                bool flag = false;
                int cnt = 0;
                int num1 = 0;
                for (int i = 1; i < SIZEx; i++)
                {
                    if (i != 1) fout << "\n";
                    for (int j = 0; j < 7; j++)
                    {
                        if (j == 0) data[i][0] = to_string(i);
                        else if (j == 1)
                        {
                            while (check.find(country[num1]) != -1) num1 = rand() % cnt_country;

                            check += country[num1];

                            cnt++;

                            fout << country[num1] << ": ";
                        }
                        else if (j == 2) fout << to_string(rand() % 20) << " ";

                        else if (j == 3) fout << to_string(rand() % 20) << " ";

                        else if (j == 4) fout << to_string(rand() % 20);
                    }
                    if (cnt_country == cnt) break;
                }
            }
            fout.close();

            //Чтение данных из файла и запись в таблицу
            ifstream fin("country.txt");
            for (int i = 1; i < SIZEx; i++)
            {
                int sum_medal = 0, sum_point = 0;
                for (int j = 0; j < 7; j++)
                {
                    if (j == 0) data[i][0] = to_string(i);
                    else if (j == 1)
                    {
                        fin >> s;
                        data[i][1] = s.erase(s.size() - 1, 1);
                    }
                    else if (j == 2)
                    {
                        fin >> s;
                        sum_medal += stoi(s);
                        sum_point += 7 * stoi(s);
                        data[i][2] = s;
                    }
                    else if (j == 3)
                    {
                        fin >> s;
                        sum_medal += stoi(s);
                        sum_point += 6 * stoi(s);
                        data[i][3] = s;
                    }
                    else if (j == 4)
                    {
                        fin >> s;
                        sum_medal += stoi(s);
                        sum_point += 5 * stoi(s);
                        data[i][4] = s;
                    }
                    else if (j == 5) data[i][5] = to_string(sum_medal);
                    else if (j == 6) data[i][6] = to_string(sum_point);
                }
            }
            fin.close();

            int f = 0;
            while (true)
            {
                do
                {
                    system_cls();
                    cout << "Используйте:\n- " << "Left, Right - для передвижения\n- " << "Up - для выбора\n- " << "ESC - для выхода\n----------Задание 'Файлы'------------" << endl;
                    cout << endl;
                    for (int i = 0; i < SIZEx; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                            if (j == f && i == 0)
                            {
                                setColor(TextBackgroundColor, TextColor);
                                if (j == 0)
                                    cout << left << setw(3) << data[i][j];
                                else if (j == 1)
                                    cout << left << setw(9) << data[i][j];
                                else if (j == 5 || j == 6)
                                    cout << right << setw(15) << data[i][j];
                                else
                                    cout << right << setw(10) << data[i][j];
                                setColor(TextColor, TextBackgroundColor);
                            }
                            else
                            {
                                if (j == 0)
                                    cout << left << setw(3) << data[i][j];
                                else if (j == 1)
                                    cout << left << setw(9) << data[i][j];
                                else if (j == 5 || j == 6)
                                    cout << right << setw(15) << data[i][j];
                                else
                                    cout << right << setw(10) << data[i][j];
                            }
                        }
                        cout << endl;
                    }

                    key = KEY.get_key();
                    if (key == 302 && f < 7 - 1) f++;
                    if (key == 300 && f > 0) f--;
                    if (key == 27)
                    {
                        system_cls();
                        return;
                    }
                } while (key != 301);

                string type[2] = { "Сортировать по возрастанию", "Сортировать по убыванию" };
                int g = 0;
                do
                {
                    system_cls();
                    cout << "Используйте:\n- " << "Left, Right - для передвижения\n- " << "Up - для выбора\n- " << "ESC - для выхода\n----------Задание 'Файлы'------------" << endl;

                    for (int i = 0; i < 2; i++)
                    {
                        if (i == g)
                        {
                            setColor(TextBackgroundColor, TextColor);
                            cout << type[i];
                            setColor(TextColor, TextBackgroundColor);
                        }
                        else cout << type[i];
                        cout << " ";
                    }
                    cout << endl;
                    for (int i = 0; i < SIZEx; i++)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                            if (j == f && i == 0)
                            {
                                setColor(TextBackgroundColor, TextColor);
                                if (j == 0)
                                    cout << left << setw(3) << data[i][j];
                                else if (j == 1)
                                    cout << left << setw(9) << data[i][j];
                                else if (j == 5 || j == 6)
                                    cout << right << setw(15) << data[i][j];
                                else
                                    cout << right << setw(10) << data[i][j];
                                setColor(TextColor, TextBackgroundColor);
                            }
                            else
                            {
                                if (j == 0)
                                    cout << left << setw(3) << data[i][j];
                                else if (j == 1)
                                    cout << left << setw(9) << data[i][j];
                                else if (j == 5 || j == 6)
                                    cout << right << setw(15) << data[i][j];
                                else
                                    cout << right << setw(10) << data[i][j];
                            }
                        }
                        cout << endl;
                    }

                    key = KEY.get_key();
                    if (key == 302 && g < 2 - 1) g++;
                    if (key == 300 && g > 0) g--;
                    if (key == 27)
                    {
                        system_cls();
                        return;
                    }
                } while (key != 301);
                data = Dsort(data, f, g, SIZEx);
            }

            for (int i = 0; i < SIZEx; i++)
                delete[] data[i];
            delete[] data;
        }
        catch (...)
        {
            cout << "Произошла ошибка." << endl;
        }
    }
}

//Меню дз 5
void menu_HW5()
{
    keyboard KEY;

    int key = 0;
    const int volume = 7;

    string cons_out[volume] = { "Задание 1 'Алгоритм Евклида'", "Задание 2 'Решето Эратосфена'", "Задание 3 'Обработка текстовых файлов'", "Задание 4 'Обработка текстовых файлов'", "Задание 5 'Ряды'", "Задание 6 'Ряды'", "Задание 7 'Файлы'"};

    int num = 0;

    while (true)
    {
        do
        {
            system_cls();
            cout << "Используйте:\n- " << KEY.Key_translation(KeyUp) << ", " << KEY.Key_translation(KeyDown) << " - для передвижения\n- " << KEY.Key_translation(KeyEnter) << " - для выбора\n- " << KEY.Key_translation(KeyExit) << " - для выхода\n----------Д/з 5------------" << endl;
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
            euclid();
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
        case 6:
            rows_2();
            break;
        case 7:
            files();
            break;
        }
    }
}
