// Определить, является ли введенное пятизначное число палиндромом.

#include <iostream>

using namespace std;

int main()
{
    while (true) {
        int n, a, b, c, d, e;
        cout << "Введите пятизначное число: ";
        cin >> n;
        a = n / 10000;
        b = n / 1000 % 10;
        c = n / 100 % 10;
        d = n / 10 % 10;
        e = n % 10;
        if (a == e && b == d)
            cout << "Число палиндром.";
        else
            cout << "Число не палиндром.";
        //Спрашиваем, хочет ли пользователь повторить программу(y,n)
        cout << endl << "Хотите повторить программу? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n')
            return 0;
    }
}
