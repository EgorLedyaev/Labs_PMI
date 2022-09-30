// возвести, введенное с клавиатуры число, в степень n, степень n вводится с клавиатуры. возведение в степень организовать с использованием циклов
// степень и число может быть отрицательным и не целым


#include <iostream>
using namespace std;

int main()
{
    while (true){
    int n;
    double x, y;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите n: ";
    cin >> n;
    y = 1;
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            y = y * x;
        }
    }
    else if (n < 0)
    {
        for (int i = 1; i <= -n; i++)
        {
            y = y * x;
        }
        y = 1 / y;
    }
    else
    {
        y = 1;
    }
    cout << "x^n = " << y << endl;
    // спрашиваем, хочет ли пользователь повторить программу
    cout << "Хотите повторить программу? (y/n): ";
    char answer;
    cin >> answer;
    if (answer == 'n')
    {
        return 0;
    }
    }
}


