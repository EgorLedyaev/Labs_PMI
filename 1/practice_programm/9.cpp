// Определить, пройдет ли кирпич в отверстие. Размеры отверстия ( длина и высота) и габориты кирпича ( значения длины, ширины и высоты ) вводит пользователь.

#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int a, b, c, x, y;
        cout << "Введите размеры отверстия ( длина и ширина): ";
        cin >> x >> y;
        cout << "Введите размеры кирпича (длина, ширина и высота): ";
        cin >> a >> b >> c;
        if ((a <= x && b <= y) || (a <= y && b <= x) || (a <= x && c <= y) || (a <= y && c <= x) ||
            (b <= x && c <= y) || (b <= y && c <= x))
            cout << "Кирпич проходит в отверстие";
        else
            cout << "Кирпич не проходит в отверстие";
        // Спрашиваем пользователя, хочет ли он повторить программу
        cout << endl << "Хотите повторить программу? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n')
            return 0;
    }
}
