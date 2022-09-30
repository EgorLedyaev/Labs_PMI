// Определить номер четверти плоскости, в которой находится точка с координатами (x, y), причем xy != 0. координаты вводить с клавиатуры

#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int x, y;
        cout << "Введите x: ";
        cin >> x;
        cout << "Введите y: ";
        cin >> y;
        if (x > 0 && y > 0)
            cout << "1 четверть";
        else if (x < 0 && y > 0)
            cout << "2 четверть";
        else if (x < 0 && y < 0)
            cout << "3 четверть";
        else if (x > 0 && y < 0)
            cout << "4 четверть";
        else
            cout << "Ошибка";
        // Спрашииваем пользователя, хочет ли он продолжить
        cout << endl << "Хотите продолжить? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n')
            return 0;
    }
}
