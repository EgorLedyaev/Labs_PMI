// Даны следующие уравнения: y = ax^2 + bx + c, y = dx +k. Найти точку пересечения представленных линий, на введенных пользователем параметрах a, b, c, d, k.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    while (true) {
        float a, b, c, d, k, x, y;
        cout << "Введите a b c d k: ";
        cin >> a >> b >> c >> d >> k;
        x = (k - b) / (a - d);
        y = a * pow(x, 2) + b * x + c;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        // спрашиваем, хочет ли пользователь повторить
        cout << "Хотите повторить? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            return 0;
        }
    }
}
