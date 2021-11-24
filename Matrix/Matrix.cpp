// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <windows.h>
#include <mutex>
static std::mutex barrier;
using namespace std;
int const N = 4;
int MATRX [N][N];
unsigned int CountOfTwoDigit = 0;
int max = 0;
int min = 999;

void  MAX_MIN()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MATRX[i][j] >::max)
            {
                ::max = MATRX[i][j];
            }

            if (MATRX[i][j] < ::min)
            {
                ::min = MATRX[i][j];
            }
        }
    }
}
void loop1()
{
    lock_guard<mutex> lck(barrier);
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
            MATRX[0][i] = rand() % 1000; // от 0 до 999
            cout << MATRX[0][i] << " ";

            if ((MATRX[0][i] / 10) > 0 && (MATRX[0][i] / 10) <= 10)
            {
                CountOfTwoDigit++;
            }
    }
    cout << endl;
}

void loop2()
{
    lock_guard<mutex> lck(barrier);
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        MATRX[1][i] = rand() % 1000; // от 0 до 999
        cout << MATRX[1][i] << " ";
        if ((MATRX[1][i] / 10) > 0 && (MATRX[1][i] / 10) <= 10)
        {
            CountOfTwoDigit++;
        }
    }
    cout << endl;
}

void loop3()
{
    lock_guard<mutex> lck(barrier);
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        MATRX[2][i] = rand() % 1000; // от 0 до 999
        cout << MATRX[2][i] << " ";
        if ((MATRX[2][i] / 10) > 0 && (MATRX[2][i] / 10) <= 10)
        {
            CountOfTwoDigit++;
        }
    }
    cout << endl;
}

void loop4()
{
    lock_guard<mutex> lck(barrier);
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        MATRX[3][i] = rand() % 1000; // от 0 до 999
        cout << MATRX[3][i] << " ";
        if ((MATRX[3][i] / 10) > 0 && (MATRX[3][i] / 10) <= 10)
        {
            CountOfTwoDigit++;
        }
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Матрица имеет вид: " << endl;
    Sleep(500);

    thread thr1(loop1);
    thr1.join();
    Sleep(500);
    thread thr2(loop2);
    thr2.join();
    Sleep(500);
    thread thr3(loop3);
    thr3.join();
    Sleep(500);
    thread thr4(loop4);
    thr4.join();

    MAX_MIN();
    cout << "Кол-во двухзначных чисел: " << CountOfTwoDigit << endl;
    cout << "Максимальное число: " << ::max << endl;
    cout << "Минимальное число: " << ::min << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
