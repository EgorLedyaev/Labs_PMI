//сортировка пузырьком вектора без библиотек
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

#include <cstdlib>
#include <random>

using namespace std;

//функция для более правильной рандомизации при помощи алгоритма вихря мерсенна
int random(int min, int max)
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<int>(min, max)(gen);
}

//функция для ввода и проверки ввода числа n
int check_n(){
    while (true){
        cout <<"Введите размер вектора:";
        string n;
        //ввод с помощью getlines
        getline(cin, n);
        //проверяем, что в строке содержится только число int
        if (n.find_first_not_of("0123456789") != string::npos || n.empty()){
            cout << "Неверный формат числа!" << endl;
        }
        else{
            //проверяем, что число не отрицательное
            if (stof(n) < 2){
                cout << "Число не может быть отрицательным или меньше 2!" << endl;
            }
            else{
                return stoi(n);
            }
        }
    }
}

//функция для ввода и проверки ввода элементов вектора
int check_el(int i){
    while (true){
        cout <<"Введите элемент вектора под индексом i = " << i+1 << ':';
        string el;
        getline(cin, el);
        //проверяем, что в строке содержится только число int или float
        //проверяем не пустое ли значение
        if (el.find_first_not_of("0123456789") != string::npos || el.empty()){
            cout << "Неверный формат числа!" << endl;
        }
        else{
            return stoi(el);
        }
    }
}

//функция для заполнения вектора рандомными значениями
void fill_vector(vector<int> &v, int &n, bool random_flag,int random_max){
    for (int i = 0; i < n; i++){
        if (random_flag){
            v.push_back(random(0,random_max));
        }
        else {
            v.push_back(rand() % 100);
        }
    }
}

//функция для вывода вектора, если он больше 10 элементов, то выводятся только первые 10
void print_vector(vector<int> &v){
    cout << "Вектор до сортировки: ";
    if (v.size() > 10){
        for (int i = 0; i < 10; i++){
            cout << v[i] << ' ';
        }
        cout << "..." << endl;
    }
    else{
        for (int i : v){
            cout << i << ' ';
        }
        cout << endl;
    }
}

//функция для сортировки пузырьком
void bubble_sort(vector<int> &v, unsigned int &bubble_time){
    auto start_time = std::chrono::steady_clock::now();

    delete new int(1);
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size() - i - 1; j++){
            if (v[j] > v[j+1]){
                int b = v[j];
                v[j] = v[j + 1];
                v[j + 1] = b;
            }
        }
    }
    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    bubble_time = elapsed_ns.count();
    std::cout << "Пузырьковая сортировка " << bubble_time << " ns\n";
}

//функция для вывода элементов вектора после сортировки, если он больше 10 элементов, то выводятся только первые 10
void print_vector_after(vector<int> &v){
    cout << "Вектор после сортировки: ";
    if (v.size() > 10){
        for (int i = 0; i < 10; i++){
            cout << v[i] << ' ';
        }
        cout << "..." << endl;
    }
    else{
        for (int i : v){
            cout << i << ' ';
        }
        cout << endl;
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

//функция для создания копии исходного вектора
vector<int> copy_vector(vector<int> &v){
    vector<int> copy;
    for (int i : v){
        copy.push_back(i);
    }
    return copy;
}

//функция для сортировки вектора с помощью быстрой стандартной сортировки
void quick_sort(vector<int> &v, unsigned int &quick_time){
    auto start_time = std::chrono::steady_clock::now();

    sort(v.begin(), v.end());

    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    quick_time = elapsed_ns.count();
    std::cout << "Быстрая сортировка " << quick_time << " ns\n";
}

//функция сравнения во сколько раз быстрее была встроенная сортировка
void compare_sorts(unsigned int bubble_time, unsigned int quick_time){
    if (bubble_time > quick_time){
        cout << "Встроенная сортировка быстрее пузырьковой в " << bubble_time / quick_time << " раз" << endl;
    }
    else if (bubble_time < quick_time){
        cout << "Пузырьковая сортировка быстрее встроенной в " << quick_time / bubble_time << " раз" << endl;
    }
    else{
        cout << "Время сортировки одинаковое" << endl;
    }
}



int main()
{
    setlocale(LC_ALL, "");
    unsigned int bubble_time;
    unsigned int quick_time;
    unsigned int random_max = 100;
    bool random_flag;

    cout << "Use mersenne vortex? (y/n): ";
    string answer;
    getline(cin, answer);
    if (answer == "y"){
        random_flag = true;
    }
    else{
        random_flag = false;
    }

    while (true){
        int n = check_n();

        vector<int> v;
        //спрашиваем у пользователя хочет он сам ввести или заполнить рандомными значениями
        while (true){
            cout << "Хотите заполнить вектор рандомными значениями? (y/n): ";
            string answer;
            getline(cin, answer);
            if (answer == "y"){
                //уточняем у пользователя какое заполнение он хочет обычное рандомное или обратноотсортированный массив
                while (true){
                    cout << "Хотите заполнить вектор обычными рандомными значениями или обратноотсортированным массивом? (1/2): ";
                    string answer;
                    getline(cin, answer);
                    if (answer == "1"){
                        fill_vector(v, n,random_flag, random_max);
                        break;
                    }
                    else if (answer == "2"){
                        fill_vector(v, n,random_flag, random_max);
                        sort(v.begin(), v.end(), greater<int>());
                        break;
                    }
                    else{
                        cout << "Неверный формат ответа!" << endl;
                    }
                }
                break;
            }
            else if (answer == "n"){
                for (int i = 0; i < n; i++){
                    int el = check_el(i);
                    v.push_back(el);
                }
                break;
            }
            else{
                cout << "Неверный формат ответа!" << endl;

            }
        }
        print_vector(v);
        //создаем копию вектора для сортировки с помощью быстрой стандартной сортировки
        vector<int> copy = copy_vector(v);
        bubble_sort(v, bubble_time);
        //сортируем копию вектора с помощью быстрой стандартной сортировки
        quick_sort(copy, quick_time);
        print_vector_after(v);
        //сравниваем время сортировки
        compare_sorts(bubble_time, quick_time);
        if (!continue_work()){
            break;
        }
    }
    //сортируем вектор
    /// Так как за первый полный проход циклом по массиву самый большой элемент переместится в конец массива.
    /// Второй по размерам элемент всплывет на предпоследнюю ячейку уже за второй проход цикла и т.д.
    /// Поэтому чтобы лишний раз не сравнивать элементы массива тратя на это время,
    /// мы решили уменьшать отрезок внутреннего цикла на 1, после каждого полного прохода внешнего цикла.
}
