#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<cmath>
#include <cfloat>
//#include <Windows.h>

using namespace std;


long double check_x(){
    while (true){
        cout <<"Введите значение x :";
        string x;
        //ввод с помощью getlines
        getline(cin, x);
        //проверяем, что в строке содержится только число
        if (x.find_first_not_of("0123456789.-") != string::npos || x.empty()){
            cout << "Неверный формат числа!" << endl;
        }
        else{
            //проверяем, что число не отрицательное
            if (stold(x) >= 1 or stold(x) <= -1 or stold(x) == 0){
                cout << "Число не может быть меньше -1, равно 0 и быть больше 1" << endl;
            }
            else{
                return stold(x);
            }
        }
    }
}


long double check_a(){
    while (true){
        cout <<"Введите введите значение a :";
        string a;
        //ввод с помощью getlines
        getline(cin, a);
        //проверяем, что в строке содержится только число
        if (a.find_first_not_of("0123456789.-") != string::npos || a.empty()){
            cout << "Неверный формат числа!" << endl;
        }
        else{
            return stold(a);

        }
    }
}


//функция для запроса хочет ли пользователь продолжить работу с программой
bool continue_work(){
    while (true){
        cout << "Хотите продолжить работу с программой? (y/n): ";
        string answer;
        getline(cin, answer);
        if (answer == "y"){
            return true;
        }
        else if (answer == "n"){
            return false;
        }
        else{
            cout << "Неверный формат ответа!" << endl;
        }
    }
}

long double calcElemPosled(long double x, long long n, long long factor){
    return (pow(2, n / 2) * sin(2 * asin(1) * n / 4) * pow(x, n)) / factor;
}

void output(long long n, long double a, long double s, long double r) {
    cout << "n = " << setw(2) << n << " | " << "An = " << setw(5) << a << " | " << "S = " << setw(5) << s << " | " << "En = " << setw(5) << r << '\n';
}



//очистка векторов a, s, r, n
void clear_vectors(vector<long double> &a, vector<long double> &s, vector<long double> &r, vector<long long> &n){
    a.clear();
    s.clear();
    r.clear();
    n.clear();
}

//функция для push_back векторов a, s, r, n
void push_back_vectors(vector<long double> &a, vector<long double> &s, vector<long double> &r, vector<long long> &n, long double a_elem, long double s_elem, long double r_elem, long long n_elem){
    a.push_back(a_elem);
    s.push_back(s_elem);
    r.push_back(r_elem);
    n.push_back(n_elem);
}



int main() {
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);


    int f = 0;
    long long i = 0, fact = 1, n = 0;
    long double x0=LDBL_MAX, x, alpha, a0, a = 0.0, s = 0.0, r=LDBL_MAX;

    vector <long double> A, S, R; //Объявление векторов для хранения данных
    vector <long long> N;

    while (true){
        x = check_x();
        alpha = check_a();

        if (x == x0) {            //Проверка для старого параметра
            cout << "Параметр x не изменился" << endl;
            if (alpha == long(alpha)) { //Определение, целое ли Альфа?
                //cout << "Альфа целое число" << endl;
                if (A.size() < alpha) {//Проверка, нужны ли новые данные?
                    cout << "Старые данные:" << endl;
                    for (n = 0; n <= (A.size() - 1); n++) { //Вывод старых данных
                        output(N[n], A[n], S[n], R[n]);
                    }

                    s = S[S.size() - 1];
                    cout << "Новые данные:" << endl;
                    for (n = A.size(); n <= (long (alpha) - 1); n++) {
                        //Подсчет новых данных
                        fact *= (n + 1);

                        a0 = calcElemPosled(x, n + 1, fact);
                        s += a0;

                        a = calcElemPosled(x, n + 2, fact * (n + 2));
                        r = a / s;

                        output(n + 1, a0, s, abs(r)); //Вывод новых данных
                        push_back_vectors(A, S, R, N, a0, s, abs(r), n + 1); //Запись новых данных в вектора
                    }
                }
                else {
                    cout << "Старые данные:" << endl;
                    for (n = 0; n < alpha; n++) {    //Вывод старых данных
                        output(N[n], A[n], S[n], R[n]);
                    }
                }
            }
            else {  //Заходим сюда, если Альфа - погрешность
                //cout << "Альфа погрешность" << endl;
                n = 0;
                while ((R[n] >= alpha) && (n < A.size() - 1)) { //Выводим старые данные
                    output(N[n], A[n], S[n], R[n]);
                    n++;
                }
                output(N[n], A[n], S[n], R[n]); //Первая погрешность меньше введенной, если прошлый цикл закончился по 1-ому условию
                if (R[n] > alpha) {            //Проверяем, нужны ли новые
                    cout << "Новые данные:" << endl;
                    s = S[n];
                    r = R[n];
                    n++;
                    while (abs(r) > alpha) {   //Подсчет новых данных
                        fact *= n;

                        a0 = calcElemPosled(x, n, fact);
                        s += a0;

                        a = calcElemPosled(x, n + 1, fact * (n + 1));
                        r = a / s;

                        output(n, a0, s, abs(r));   //Вывод новых данных
                        push_back_vectors(A, S, R, N, a0, s, abs(r), n); //Запись новых данных в вектора
                        n++;
                    }
                }
            }
        }
        else {         //Заходим сюда если параметр новый
            clear_vectors(A, S, R, N); //Очистка векторов
            fact = 1;  //Обнуление значений факториала и суммы
            s = 0;
            if (alpha == long(alpha)) { //Проверяем, целое ли Альфа?
                for (i = 1; i <= long(alpha); i++) {
                    fact *= i;

                    a0 = calcElemPosled(x, i, fact); //Подсчет новых данных
                    s += a0;
                    a = calcElemPosled(x, i + 1, fact * (i + 1));
                    r = a / s;

                    output(i, a0, s, abs(r));         //Вывод новых данных
                    push_back_vectors(A, S, R, N, a0, s, abs(r), i); //Запись новых данных в вектора
                }
            }
            else {  //Заходим сюда, если Альфа - погрешность
                i = 1;
                while (abs(r) >= alpha) {     //Подсчет новых данных
                    fact *= i;

                    a0 = calcElemPosled(x, i, fact);
                    s += a0;

                    a = calcElemPosled(x, i + 1, fact * (i + 1));
                    r = a / s;

                    output(i, a0, s, abs(r));  //Вывод новых данных
                    push_back_vectors(A, S, R, N, a0, s, abs(r), i); //Запись новых данных в вектора
                    i++;
                }
            }
            x0 = x; //Запись старого X для последующей проверки
        }

        //уточняем хочет ли пользователь продолжить

        if (!continue_work()) {
            return 0;
        }
    }
}
