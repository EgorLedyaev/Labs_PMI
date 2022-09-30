// Вычислить значение x^m * sin(x^m)^m без pow

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    while (true) {
        double x, m, result = 1;
        cout << "Введите x: ";
        cin >> x;
        cout << "Введите m: ";
        cin >> m;
        // Вычисляем x^m
        for (int i = 0; i < m; i++) {
            result *= x;
        }
        // Вычисляем sin(x^m)^m без pow
        double sin_x_m = sin(result);
        for (int i = 0; i < m; i++) {
            result *= sin_x_m;
        }
        cout << "Результат: " << result << endl;
        //Спрашиваем, хочет ли пользователь продолжить
        cout << "Продолжаем? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            return 0;
        }
    }

}

