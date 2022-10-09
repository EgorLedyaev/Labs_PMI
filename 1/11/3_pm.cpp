//сортировка пузырьком вектора без библиотек
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
        if (el.find_first_not_of("0123456789.") != string::npos || el.empty()){
            cout << "Неверный формат числа!" << endl;
        }
        else{
            return stoi(el);
        }
    }
}

//функция для ввода элементов вектора
vector<int> input_vector(int n){
    vector<int> v;
    for (int i = 0; i < n; i++){
        v.push_back(check_el(i));
    }
    return v;
}

//функция для вывода элементов вектора до сортировки
void print_vector(const vector<int>& v){
    cout << "Вектор до сортировки: ";
    for (int i : v){
        cout << i << ' ';
    }
    cout << endl;
}

//функция для сортировки пузырьком
void bubble_sort(vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size() - i - 1; j++){
            if (v[j] > v[j+1]){
                int b = v[j];
                v[j] = v[j + 1];
                v[j + 1] = b;
            }
        }
    }
}

//функция для вывода элементов вектора после сортировки
void print_vector_sorted(const vector<int>& v){
    cout << "Вектор после сортировки: ";
    for (int i : v){
        cout << i << ' ';
    }
    cout << endl;
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

int main()
{
    setlocale(LC_ALL, "");
    while (true){
        int n = check_n();
        vector<int> v = input_vector(n);
        print_vector(v);
        bubble_sort(v);
        print_vector_sorted(v);
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
