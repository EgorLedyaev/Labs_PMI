// Дан одномерный массив, длину массива задает пользователь. Вычислить сумму квадратов тех чисел, модуль которых превышает X , которое ввел пользователь

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    while (true) {
        int n, x;
        cout << "Введите размер массива: ";
        cin >> n;
        int *arr = new int[n];
        cout << "Введите массив: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Введите X: ";
        cin >> x;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (abs(arr[i]) > x) {
                sum += pow(arr[i], 2);
            }
        }
        cout << "Сумма квадратов чисел, модуль которых превышает X: " << sum << endl;
        delete[] arr;
        // Спрашиваем, хочет ли пользователь повторить программу
        cout << "Хотите повторить программу? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            return 0;
        }
    }
}
