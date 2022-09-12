//
// Created by EgorLedyaev on 12.09.2022.
//

// Расчет длительности некоторого процесса

//Импортируем необходимые библиотеки
#include <iostream>
#include "string"
#include <Windows.h>
#include <algorithm>

//Используем пространство имен std
using namespace std;

//Функция для принятия и проверки ввода времени начала
int first_time(){

    //Используем дескриптор активного экранного буфера консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col = 12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим время начала
        cout <<"Введите время начала в формате HH:MM:SS" << endl;
        string time_start;
        cin >> time_start;

        //Проверяем на корректность ввода
        if (time_start.length() != 8 || time_start[2] != ':' || time_start[5] != ':'){
            //Очищение входного буфера консоли
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Неверный формат времени начала!" << endl;
            SetConsoleTextAttribute(hConsole, 15);

            //Возвращаем cin в исходное состояние
            cin.clear();
            //Удаляем значения предыдущего ввода из входного буфера
            cin.ignore(32767, '\n');
        }
        else{
            //Преобразуем введенное время в часы,минуты,секунды
            //Переводим string в int с помощью stoi
            //Возвращаем подстроку строки time_start с 0 по 2 символ
            int hours_start = stoi(time_start.substr(0, 2));
            //Возвращаем подстроку строки time_start с 3 по 5 символ
            int minutes_start = stoi(time_start.substr(3, 2));
            //Возвращаем подстроку строки time_start с 6 по 8 символ
            int seconds_start = stoi(time_start.substr(6, 2));

            //Проверяем на корректность ввода
            if (hours_start > 23 || minutes_start > 59 || seconds_start > 59) {
                FlushConsoleInputBuffer(hConsole);
                SetConsoleTextAttribute(hConsole, col);
                cout << "Неверный формат времени начала!" << endl;
                SetConsoleTextAttribute(hConsole, 15);

                //Возвращаем cin в исходное состояние
                cin.clear();
                //Удаляем значения предыдущего ввода из входного буфера
                cin.ignore(32767, '\n');
            }
            else{
                //Возвращаем время начала в секундах
                int all_seconds_start = hours_start * 3600 + minutes_start * 60 + seconds_start;
                return all_seconds_start;
            }
        }
    }
}

//Функция для принятия и проверки ввода времени конца
int second_time(){

    //Используем дескриптор активного экранного буфера консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col=12;
    SetConsoleTextAttribute(hConsole, 15);

    while (true){
        //Вводим время конца
        cout <<"Введите время окончания в формате HH:MM:SS" << endl;
        string time_final;
        cin >> time_final;

        //Проверяем на корректность ввода
        if (time_final.length() != 8 || time_final[2] != ':' || time_final[5] != ':'){
            //Очищение входного буфера консоли
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Неверный формат времени окончания!" << endl;
            SetConsoleTextAttribute(hConsole, 15);

            //Возвращаем cin в исходное состояние
            cin.clear();
            //Удаляем значения предыдущего ввода из входного буфера
            cin.ignore(32767, '\n');
        }
        else{
            //Преобразуем введенное время в часы,минуты,секунды
            //Переводим string в int с помощью stoi
            //Возвращаем подстроку строки time_final с 0 по 2 символ
            int hours_final = stoi(time_final.substr(0, 2));
            //Возвращаем подстроку строки time_final с 3 по 5 символ
            int minutes_final = stoi(time_final.substr(3, 2));
            //Возвращаем подстроку строки time_final с 6 по 8 символ
            int seconds_final = stoi(time_final.substr(6, 2));

            //Проверяем на корректность ввода
            if (hours_final > 23 || minutes_final > 59 || seconds_final > 59) {
                //Очищение входного буфера консоли
                FlushConsoleInputBuffer(hConsole);
                SetConsoleTextAttribute(hConsole, col);
                cout << "Неверный формат времени окончания!" << endl;
                SetConsoleTextAttribute(hConsole, 15);

                //Возвращаем cin в исходное состояние
                cin.clear();
                //Удаляем значения предыдущего ввода из входного буфера
                cin.ignore(32767, '\n');
            }
            else{
                //Возвращаем время конца в секундах
                int all_seconds_final = hours_final * 3600 + minutes_final * 60 + seconds_final;
                return all_seconds_final;
            }
        }
    }
}


int main(int argc, char* argv[]) {
    //Устанавливаем кодировку
    //setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Используем дескриптор активного экранного буфера консоли
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Меняем цвет и формат шрифта
    int col = 12;
    SetConsoleTextAttribute(hConsole, 15);

    //Считаем сколько времени прошло пока пользователь не вышел из программы
    while(true){
        //Инициализируем переменные для хранения общего времени
        int all_seconds_start = first_time();
        int all_seconds_final = second_time();
        int all_seconds = all_seconds_final - all_seconds_start;
        int all_minutes = all_seconds / 60;

        //Проверяем на случай когда время начала больше времени конца
        if (all_seconds < 0 and all_minutes < 0){
            //Очищение входного буфера консоли
            FlushConsoleInputBuffer(hConsole);
            SetConsoleTextAttribute(hConsole, col);
            cout << "Время окончания не может быть меньше времени начала!" << endl;
            SetConsoleTextAttribute(hConsole, 15);
        }
        else{
            //Выводим результат
            cout << "Прошло всего секунд: " << all_seconds << endl;
            cout << "Прошло всего минут: " << all_minutes << endl;
        }
        //Предлагаем начать заново
        cout << "Хотите продолжить? (y/n)" << endl;
        string answer;
        cin >> answer;
        if (answer == "n"){
            return 0;
        }
        cin.clear();
    }
}