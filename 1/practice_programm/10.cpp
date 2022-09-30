//  Найти y, если y = x1 + x2 + ... + xn, x = z^3 - b + ((a^2)/(tg^2beta)). Количество x вводится пользователем программы. Для каждого x  значения z,b,a,beta разные и вводятся пользователем программы.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    while (true){
    int n;
    cout << "Введите x: ";
    cin >> n;
    double y = 0;
    for (int i = 0; i < n; i++)
    {
        double z, b, a, beta;
        cout << "Введите z: ";
        cin >> z;
        cout << "Введите b: ";
        cin >> b;
        cout << "Введите a: ";
        cin >> a;
        cout << "Введите beta: ";
        cin >> beta;
        y += pow(z, 3) - b + pow(a, 2) / pow(tan(beta), 2);
    }
    cout << "y = " << y << endl;
    //Спросить, хочет ли пользователь продолжить
    cout << "Хотите продолжить? (y/n): ";
    char answer;
    cin >> answer;
    if (answer == 'n')
        return 0;
    }
}
