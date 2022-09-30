//Найти след матрицы ( сумму элементов главной диагонали). Размер матрицы вводит пользователь, матрицу заполнять случайными  числами.

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    while(true) {
        srand(time(0));
        int n;
        cout << "Введите размеры матрицы: ";
        cin >> n;
        int **matrix = new int *[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand() % 10;
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][i];
        }
        cout << "След матрицы " << sum << endl;
        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        //Спросить пользователя, хочет ли он повторить программу
        cout << "Хотите повторить программу? (y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            return 0;
        }
    }
}
