// Найти алгебраическую сумму для выражения 1^k + 2^k + 3^k + ... + n^k. Для вовзведения в степень написать свою функцию без pow

#include <iostream>

using namespace std;

int stepen(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c *= a;
    }
    return c;
}

int main()
{
    while (true) {
        int n, k, sum = 0;
        cout << "Введите n: ";
        cin >> n;
        cout << "Введите k: ";
        cin >> k;
        for (int i = 1; i <= n; i++) {
            int temp = 1;
            temp = stepen(i, k);
            sum += temp;
        }
        cout << "Sum = " << sum << endl;
        // Спрашиваем пользователя, хочет ли он повторить программу
        cout << "Начнем заново? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            return 0;
        }
    }
}
