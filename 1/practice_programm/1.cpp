// по введенному номеру дня недели вывести его название, используя оператор множественного выбора. нумерация дней недели начинается с 1 - поенедльник, 2 - вторник и т.д.

#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int day;
        cout << "Введите номер дня в недели: ";
        cin >> day;
        switch (day) {
            case 1:
                cout << "Понедельник";
                break;
            case 2:
                cout << "Вторник";
                break;
            case 3:
                cout << "Среда";
                break;
            case 4:
                cout << "Четверг";
                break;
            case 5:
                cout << "Пятница";
                break;
            case 6:
                cout << "Суббота";
                break;
            case 7:
                cout << "Воскресенье";
                break;
            default:
                cout << "Ошибка! Нет такого дня недели";
                break;
        }
        //спрашиваем пользователя, хочет ли он продолжить

        char answer;
        cout << "\nХотите продолжить? (y/n): ";
        cin >> answer;
        if (answer == 'n') {
            return 0;
        }
    }
}
