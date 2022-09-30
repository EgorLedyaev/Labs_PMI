// Вычислить длину вектора с координатами x,y, z и с основанием y начала координат. Координаты вводит пользователь

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    while (true) {
        float x, y, z, l;
        cout << "Введите x: ";
        cin >> x;
        cout << "Введите y: ";
        cin >> y;
        cout << "Введите z: ";
        cin >> z;
        l = sqrt(x * x + y * y + z * z);
        cout << "Длина вектора : " << l << endl;
        // Спрашиваем пользователя, хочет ли он продолжить
        cout << "Хотите продолжить? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            return 0;
        }
    }
}
