//Удалить из строки слово заданной длины. Если таких слов несколько, удалить первое из них.
//Не используя string, а используя массив символов

#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include<Windows.h>

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
int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("input.txt");
    vector<char> str;
    int len;
    input(str, len, fin);
    printStr(str);
    deleteWordFromStr(str, len);
    cout << endl;
    printStr2(str);
    writeStringToFile("output.txt", str);
    return 0;
}
