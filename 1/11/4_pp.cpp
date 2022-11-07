//Удалить из строки слово заданной длины. Если таких слов несколько, удалить первое из них.
//слова могут разделяться пробелами, табуляциями и знаками препинания
//input.txt output.txt

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <chrono>

using namespace std;

//функция для принятия строки из файла в вектор символов и принятия длины слова для удаления из файла
void input(vector<char>& str, int& len, ifstream& fin)
{
    char c;
    while (fin.get(c))
    {
        if (c == '\n')
        {
            break;
        }
        str.push_back(c);
    }
    fin >> len;
}

//функция для записи строки в файл
void writeStringToFile(string fileName, vector<char> str)
{
    ofstream fout(fileName);
    int i = 0;
    while (str[i] != '\0')
    {
        fout << str[i];
        i++;
    }
}

//функция для удаления слова заданной длины
void deleteWordFromStr(vector<char> &str, int wordLength)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        //проверка на пробел
        if (str[i] == ' ' or str[i] == ',' or str[i] == '.')
        {
            //если количество символов в слове равно заданной длине
            if (count == wordLength)
            {
                //удаление слова
                int j = i;
                while (str[j] != '\0')
                {
                    str[j - count - 1] = str[j];
                    j++;
                }
                str[j - count - 1] = '\0';
                i -= count + 1;
                count = 0;

            }
            else
            {
                count = 0;
            }
        }
        else
        {
            count++;
        }
        i++;
    }
    //проверка последнего слова
    if (count == wordLength)
    {
        int j = i;
        while (str[j] != '\0')
        {
            str[j - count - 1] = str[j];
            j++;
        }
        str[j - count - 1] = '\0';
    }
}

//функция для вывода исходной строки
void printStr(vector<char> str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }
}

//функция для вывода того что получилось
void printStr2(vector<char> str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }
}

//функция для удаления слова из строки
string delete_word(string str, int len)
{
    string result;
    string word;
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            word += str[i];
        }
        else
        {
            if (word.length() == len)
            {
                word = "";
            }
            else
            {
                result += word;
                word = "";
            }
            result += str[i];
        }
    }
    if (word.length() == len)
    {
        word = "";
    }
    else
    {
        result += word;
        word = "";
    }
    return result;
}

int main()
{
    ifstream fin("input.txt");

    vector<char> str;
    string str_2;
    int len;
    input(str, len, fin);
    //printStr(str);
    //копируем вектор в строку
    str_2 = string(str.begin(), str.end());
    //удаляем слова разными способами и сравниваем скорость выполнения, 10 знаков после запятой
    auto start = chrono::steady_clock::now();
    deleteWordFromStr(str, len);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    auto start_2 = chrono::steady_clock::now();
    str_2 = delete_word(str_2, len);
    auto end_2 = chrono::steady_clock::now();
    auto diff_2 = end_2 - start_2;
    cout << chrono::duration <double, milli>(diff_2).count() << " ms" << endl;

    //выводим каким методом получилось быстрее и во сколько раз
    if (chrono::duration <double, milli>(diff).count() < chrono::duration <double, milli>(diff_2).count())
    {
        cout << "Method vector is faster than method string in " << chrono::duration <double, milli>(diff_2).count() / chrono::duration <double, milli>(diff).count() << " times" << endl;
    }
    else
    {
        cout << "Method string is faster than method vector in " << chrono::duration <double, milli>(diff).count() / chrono::duration <double, milli>(diff_2).count() << " times" << endl;
    }

    writeStringToFile("output.txt", str);
    return 0;
}
