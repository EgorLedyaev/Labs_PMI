//
// Created by EgorLedyaev on 12.09.2022.
//

// Нахождение площади трапеции

// Импортируем необходимые библиотеки
#include <iostream>
#include <Windows.h>

using namespace std;

//Функция для принятия и проверки ввода длины оснований
int base(){

    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим длину основания
        cout <<"Введите длину основания" << endl;
        int base;
        cin >> base;

        //Проверяем на корректность ввода
        if (base <= 0){
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Неверный формат длины основания!" << endl;
            SetConsoleTextAttribute(hConsole, 15);

            //Очищаем буфер ввода
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else{
            return base;
        }
    }
}

//Функция для принятия и проверки ввода длины боковых сторон
int side(){

    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим длину боковой стороны
        cout <<"Введите длину боковой стороны" << endl;
        int side;
        cin >> side;

        //Проверяем на корректность ввода
        if (side <= 0){
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Неверный формат длины боковой стороны!" << endl;
            SetConsoleTextAttribute(hConsole, 15);
            //Очищаем буфер ввода
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else{
            return side;
        }
    }
}

//Функция для нахождения площади трапеции
int area(int base1, int base2, int side){
    //Находим площадь трапеции
    int area = ((base1 + base2) / 2) * side;
    return area;
}

int main() {
    //Устанавливаем кодировку
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while(true){
        //Вводим длины оснований
        int base1 = base();
        int base2 = base();

        //Вводим длину боковой стороны
        int side1 = side();

        //Находим площадь трапеции
        int area1 = area(base1, base2, side1);

        //Выводим площадь трапеции
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Площадь трапеции равна " << area1 << endl;
        SetConsoleTextAttribute(hConsole, 15);

        //Предлагаем начать заново
        cout << "Хотите продолжить? (y/n)" << endl;
        string answer;
        cin >> answer;
        if (answer == "n"){
            break;
        }
        cin.clear();
    }
}