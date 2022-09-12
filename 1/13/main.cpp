//
// Created by user on 12.09.2022.
//

//Перевод скорости в другую единицу измерения

#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

//Функция для принятия и проверки ввода скорости

int speed(){
    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим скорость
        cout <<"Введите скорость" << endl;
        int speed;
        cin >> speed;

        //Проверяем на корректность ввода
        if (speed <= 0){
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Неверный формат скорости!" << endl;
            SetConsoleTextAttribute(hConsole, 15);

            //Очищаем буфер ввода
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else{
            return speed;
        }
    }
}

//Функция для принятия и проверки ввода единицы измерения

int unit(){
    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим единицу измерения
        cout <<"Введите единицу измерения" << endl;
        cout <<"1 - метры в секунду" << endl;
        cout <<"2 - километры в час" << endl;
        cout <<"3 - мили в час" << endl;
        int unit;
        cin >> unit;

        //Проверяем на корректность ввода
        if (unit <= 0 || unit > 3){
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Неверный формат единицы измерения!" << endl;
            SetConsoleTextAttribute(hConsole, 15);

            //Очищаем буфер ввода
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else{
            return unit;
        }
    }
}

//Функция для принятия и проверки ввода единицы измерения, в которую нужно перевести

int unit2(){
    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим единицу измерения
        cout <<"Введите единицу измерения, в которую нужно перевести" << endl;
        cout <<"1 - метры в секунду" << endl;
        cout <<"2 - километры в час" << endl;
        cout <<"3 - мили в час" << endl;
        int unit2;
        cin >> unit2;

        //Проверяем на корректность ввода
        if (unit2 <= 0 || unit2 > 3){
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Неверный формат единицы измерения!" << endl;
            SetConsoleTextAttribute(hConsole, 15);

            //Очищаем буфер ввода
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else{
            return unit2;
        }
    }
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    //Вводим скорость
    int speed_t = speed();

    //Вводим единицу измерения
    int unit_t = unit();

    //Вводим единицу измерения, в которую нужно перевести
    int unit2_t = unit2();

    //Переводим скорость
    if (unit_t == 1 && unit2_t == 2){
        cout << "Скорость в километрах в час: " << speed_t * 3.6 << endl;
    }
    else if (unit_t == 1 && unit2_t == 3){
        cout << "Скорость в милях в час: " << speed_t * 2.23694 << endl;
    }
    else if (unit_t == 2 && unit2_t == 1){
        cout << "Скорость в метрах в секунду: " << speed_t / 3.6 << endl;
    }
    else if (unit_t == 2 && unit2_t == 3){
        cout << "Скорость в милях в час: " << speed_t / 1.60934 << endl;
    }
    else if (unit_t == 3 && unit2_t == 1){
        cout << "Скорость в метрах в секунду: " << speed_t / 2.23694 << endl;
    }
    else if (unit_t == 3 && unit2_t == 2){
        cout << "Скорость в километрах в час: " << speed_t * 1.60934 << endl;
    }
    else{
        cout << "Скорость не изменилась" << endl;
    }

    return 0;
}