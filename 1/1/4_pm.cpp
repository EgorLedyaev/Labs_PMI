//функция для удаления знаков пробела между первым и вторым вопросительным знаком в векторе char

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

//функция для удаления знаков пробела между первым и вторым вопросительным знаком в векторе char
void delete_space(vector<char>& v)
{
    auto it = find(v.begin(), v.end(), '?');
    if (it != v.end())
    {
        auto it2 = find(it + 1, v.end(), '?');
        if (it2 != v.end())
        {
            v.erase(remove(it + 1, it2, ' '), it2);
        }
    }
}

//функция для принятия строки из файла в вектор символов
void input(vector<char>& v, ifstream& fin)
{
    char c;
    while (fin.get(c))
    {
        if (c == '\n')
        {
            break;
        }
        v.push_back(c);
    }
}



//функция для записи строки в файл output.txt
void write_string_to_file(vector<char>& v)
{
    ofstream file("output.txt");
    if (file.is_open())
    {
        for (auto i : v)
        {
            file << i;
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
}


int main()
{
    vector<char> v;
    ifstream fin("input.txt");
    input(v, fin);
    delete_space(v);
    write_string_to_file(v);
    return 0;
}
