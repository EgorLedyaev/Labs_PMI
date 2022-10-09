#include<string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cfloat>


using namespace std;

long double check_x(){
    long double num;

    while (!(cin >> num) || (cin.peek() != '\n' || (num > 1) || (num < -1) || num == 0 )){
        cin.clear();
        while (cin.get() != '\n');
        cout << "Неверно введены данные.";
        cout << "Введите значения заново :";
    }
    if (num == 0 and isdigit(num)){
        return num;
    }
}

long double check_a(){
    long double num;

    while (!(cin >> num) || (cin.peek() != '\n')){
        cin.clear();
        while (cin.get() != '\n');
        cout << "Неверно введены данные.";
        cout << "Введите значения заново :";
    }
    return num;
}

long double calc_elem_posled(long double x, long long n, long long factor){
    return (pow(2, n / 2) * sin(2 * asin(1) * n / 4) * pow(x, n)) / factor;
}

void output(long long n, long double a, long double s, long double r) {
    cout << "n = " << setw(2) << n << " | " << "An = " << setw(5) << a << " | " << "S = " << setw(5) << s << " | " << "En = " << setw(5) << r << '\n';
}



int main() {
    setlocale(LC_ALL, "RUS");

    const long long one = 1;
    int f = 0;
    long long i = 0, fact = 1, n = 0;
    long double x0=LDBL_MAX, x, alpha, a0, a = 0.0, s = 0.0, r=LDBL_MAX;

    vector <long double> A, S, R; //Объявление векторов для хранения данных
    vector <long long> N;

    while (true){
        cout << "Введите значение x :";
        x = check_x();
        cout << "Введите введите значение a :";
        alpha = check_a();
        if (x == x0) {            //Проверка для старого параметра
            if (alpha == long(alpha)) { //Определение, целое ли Альфа?
                if (A.size() < alpha) {      //Проверка, нужны ли новые данные?
                    for (n = 0; n <= (A.size() - 1); n++) { //Вывод старых данных
                        output(N[n], A[n], S[n], R[n]);
                    }
                    s = S[S.size() - 1];
                    for (n = A.size(); n <= (long (alpha) - one); n++) {
                        fact *= (n + one);           //Подсчет новых данных
                        a0 = calc_elem_posled(x, n + one, fact);
                        s += a0;
                        a = calc_elem_posled(x, n + 2 * one, fact * (n + 2 * one));
                        r = a / s;
                        output(n + 1, a0, s, abs(r)); //Вывод новых данных
                        A.push_back(a0);             //Запись новых данных
                        S.push_back(s);
                        R.push_back(abs(r));
                        N.push_back(n + 1);
                    }
                }
                else {
                    for (n = 0; n < alpha; n++) {    //Вывод старых данных
                        output(N[n], A[n], S[n], R[n]);
                    }
                }
            }
            else {  //Заходим сюда, если Альфа - погрешность
                n = 0;
                while ((R[n] >= alpha) && (n < A.size() - 1)) { //Выводим старые данные
                    output(N[n], A[n], S[n], R[n]);
                    n++;
                }
                output(N[n], A[n], S[n], R[n]); //Первая погрешность меньше введенной, если прошлый цикл закончился по 1-ому условию
                if (R[n] > alpha) {            //Проверяем, нужны ли новые вычисления
                    s = S[n];
                    r = R[n];
                    n++;
                    while (abs(r) > alpha) {   //Подсчет новых данных
                        fact *= n;
                        a0 = calc_elem_posled(x, n, fact);
                        s += a0;
                        a = calc_elem_posled(x, n + one, fact * (n + one));
                        r = a / s;
                        output(n, a0, s, abs(r));   //Вывод новых данных
                        A.push_back(a0);           //Запись новых данных
                        S.push_back(s);
                        R.push_back(abs(r));
                        N.push_back(n + one);
                        n++;
                    }
                }
            }
        }
        else {         //Заходим сюда если параметр новый
            A.clear(); //Убираем все прошлые данные из векторов
            S.clear();
            R.clear();
            N.clear();
            fact = 1;  //Обнуление значений факториала и суммы
            s = 0;
            if (alpha == long(alpha)) { //Проверяем, целое ли Альфа?
                for (i = 1; i <= long(alpha); i++) {
                    fact *= i;
                    a0 = calc_elem_posled(x, i, fact); //Подсчет новых данных
                    s += a0;
                    a = calc_elem_posled(x, i + one, fact*(i + one));
                    r = a / s;
                    output(i, a0, s, abs(r));         //Вывод новых данных
                    A.push_back(a0);                 //Запись новых данных
                    S.push_back(s);
                    R.push_back(abs(r));
                    N.push_back(i);
                }
            }
            else {  //Заходим сюда, если Альфа - погрешность
                i = 1;
                while (abs(r) >= alpha) {     //Подсчет новых данных
                    fact *= i;
                    a0 = calc_elem_posled(x, i, fact);
                    s += a0;
                    a = calc_elem_posled(x, i + one, fact*(i + one));
                    r = a / s;
                    output(i, a0, s, abs(r));  //Вывод новых данных
                    A.push_back(a0);          //Запись новых данных
                    S.push_back(s);
                    R.push_back(abs(r));
                    N.push_back(i);
                    i++;
                }
            }
            x0 = x; //Запись старого X для последующей проверки
        }
        cout << "Хотите продолжить?(y/n)" << endl;

        string answer;

        cin >> answer;

        if (answer == "n") {return 0;}
    }
}
