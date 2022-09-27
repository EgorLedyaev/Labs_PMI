//Транспонирование матрицы без дополнительных массивов.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;



//Функция для приема размера матрицы x и y
void size(int &x, int &y) {
    cout << "Введите размер ебаной матрицы" << endl;
    cin >> x >> y;
    //Проверка на корректность ввода
    if (x <= 0 || y <= 0 || (cin.peek() != '\n') || cin.fail() || cin.bad() || x >= 99999 || y >= 99999) {
        {
            cout << "Во еблан. Неверный формат размера матрицы!" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            size(x, y);
        }
    }
}

//Функция для приема матрицы размера x*y
void matrix(int **a, int x, int y){
    cout << "Хуила введи матрицу" << endl;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cin >> a[i][j];
            //Проверка на корректность ввода
            if (cin.fail()){
                cout << "Ты че долбаеб? Неверный формат матрицы!" << endl;
                cin.clear();
                cin.ignore(32767, '\n');
                matrix(a, x, y);
            }
        }
    }
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true) {
        //Меняем цвет и формат шрифта
        int col = 12;
        SetConsoleTextAttribute(hConsole, 15);

        //Вводим размер матрицы
        int x, y;
        size(x, y);

        //Создаем матрицу
        int **a = new int *[x];
        for (int i = 0; i < x; i++) {
            a[i] = new int[y];
        }

        //Вводим матрицу
        matrix(a, x, y);

        //Выводим матрицу
        cout << "Твоя ебучая матрица" << endl;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }

        //Транспонируем матрицу
        for (int i = 0; i < x; i++) {
            for (int j = i; j < y; j++) {
                swap(a[i][j], a[j][i]);
            }
        }

        //Выводим транспонированную матрицу
        cout << "На подавись твоя транспонированная матрица" << endl;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }

        //Очищаем память
        for (int i = 0; i < x; i++) {
            delete[] a[i];
        }
        delete[] a;

        //Спрашиваем, хочет ли пользователь продолжить
        cout << "Хочешь продолжить? (y/n)" << endl;
        char c;
        cin >> c;
        if (c == 'n') {
            break;
        }
    }
    return 0;
}
