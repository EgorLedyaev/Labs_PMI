//Перевод скорости float в другую единицу измерения
#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

//Функция для принятия и проверки ввода скорости

float speed(){
    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим скорость
        cout <<"Введите скорость" << endl;
        float speed;
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
        cout <<"4 - узлы" << endl;
        int unit;
        cin >> unit;

        //Проверяем на корректность ввода
        if (unit <= 0 || unit > 4){
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
        cout <<"4 - узлы" << endl;
        int unit2;
        cin >> unit2;

        //Проверяем на корректность ввода
        if (unit2 <= 0 || unit2 > 4){
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
    //Используем дескриптор консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    //Вводим скорость
    float speed_t = speed();

    //Вводим единицу измерения
    int unit_t = unit();

    //Вводим единицу измерения, в которую нужно перевести
    int unit2_t = unit2();

    //Переводим скорость
    float speed2_t = speed_t;
    if (unit_t == 1){
        if (unit2_t == 2){
            speed2_t = speed_t * 3.6;
        }
        else if (unit2_t == 3){
            speed2_t = speed_t * 2.23694;
        }
        else if (unit2_t == 4){
            speed2_t = speed_t * 1.94384;
        }
    }
    else if (unit_t == 2){
        if (unit2_t == 1){
            speed2_t = speed_t / 3.6;
        }
        else if (unit2_t == 3){
            speed2_t = speed_t * 0.621371;
        }
        else if (unit2_t == 4){
            speed2_t = speed_t * 0.539957;
        }
    }
    else if (unit_t == 3){
        if (unit2_t == 1){
            speed2_t = speed_t / 2.23694;
        }
        else if (unit2_t == 2){
            speed2_t = speed_t / 0.621371;
        }
        else if (unit2_t == 4){
            speed2_t = speed_t * 0.868976;
        }
    }
    else if (unit_t == 4){
        if (unit2_t == 1){
            speed2_t = speed_t / 1.94384;
        }
        else if (unit2_t == 2){
            speed2_t = speed_t / 0.539957;
        }
        else if (unit2_t == 3){
            speed2_t = speed_t / 0.868976;
        }
    }

    //Выводим результат
    cout << "Результат: " << speed2_t << endl;

    return 0;
}