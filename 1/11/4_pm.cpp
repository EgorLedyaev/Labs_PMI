//Удалить из строки слово заданной длины. Если таких слов несколько, удалить первое из них.
//Не используя string, а используя массив символов

#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <algorithm>


using namespace std;

//Функция для принятия и проверки длины слова
int check_n(){
    while (true){
        cout <<"Введите длину слова:";
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
                cout << "Число не может быть отрицательным или меньше 1!" << endl;
            }
            else{
                return stoi(n);
            }
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //вводим размер слова
    int n = check_n();
    char str[100];
    cout << "Введите строку: ";
    cin.ignore();
    cin.getline(str, 100);
    char* p = strtok(str, " ");
    while (p != NULL)
    {
        if (strlen(p) != n)
        {
            cout << p << " ";
        }
        p = strtok(NULL, " ");
    }
    return 0;
}
