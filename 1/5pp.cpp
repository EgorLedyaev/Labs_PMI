//Implement a console application designed to work with an array of class instances. Input data: the number of array elements, class instances. Output data: an array of class instances and an array of results of the method of data processing.
//Features:
//The class must have overloaded operators for taking from the stream and putting into the stream;
//A member function must be created, which implements the class instance data processing according to the variant;
//it must be possible to choose reading from a file or a console;

//it should be possible to select writing to file or output to console.

//The input checks must be implemented
//The program must be implemented in accordance with the requirements of the C ++ language standard.
//the last name must contain only letters
//grades must contain only digits

//name of the class : grade data
//input format : Name Evaluation1 Evaluation2 Evaluation3
//input example : Ivanov 3 4 5
//output : Output average grade
//output example : Average grade : 4

//select writing to file or output to console.

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <locale>
#include <codecvt>
#include <windows.h>

using namespace std;

class GradeData
{
private:
    int id;
    string name;
    vector<int> grades;
public:
    GradeData() {}
    GradeData(string name, vector<int> grades) : name(std::move(name)), grades(std::move(grades)) {}
    GradeData(const GradeData& other) : name(other.name), grades(other.grades) {}
    GradeData& operator=(const GradeData& other)
    {
        if (this != &other)
        {
            name = other.name;
            grades = other.grades;
        }
        return *this;
    }
    friend istream& operator>>(istream& in, GradeData& gradeData);
    friend ostream& operator<<(ostream& out, const GradeData& gradeData);
    double getAverageGrade() const
    {
        double sum = 0;
        for (int grade : grades)
        {
            sum += grade;
        }
        return sum / grades.size();
    }
};

istream& operator>>(istream& in, GradeData& gradeData)
{
    in >> gradeData.name;
    int grade;
    while (in >> grade)
    {
        gradeData.grades.push_back(grade);
    }
    return in;
}

ostream& operator<<(ostream& out, const GradeData& gradeData)
{
    out << gradeData.name << " ";
    for (int grade : gradeData.grades)
    {
        out << grade << " ";
    }
    return out;
}

bool isNumber(const string& str)
{
    for (char i : str)
    {
        if (!isdigit(i))
        {
            return false;
        }
    }
    return true;
}

bool isLetter(const string& str)
{
    for (char i : str)
    {
        if (!isalpha(i))
        {
            return false;
        }
    }
    return true;
}

//function to check the correctness of the input
bool checkInput(const string& str)
{
    vector<string> words;
    string word;
    stringstream ss(str);
    while (ss >> word)
    {
        words.push_back(word);
    }
    if (words.size() < 2)
    {
        return false;
    }
    if (!isLetter(words[0]))
    {
        return false;
    }
    for (int i = 1; i < words.size(); i++)
    {
        if (!isNumber(words[i]))
        {
            return false;
        }
    }
    return true;
}

//function to answer input from console or file
bool answer()
{
    char answer;
    cout << "Do you want to read from file? (y/n)" << endl;
    cin >> answer;
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to answer output to console or file
bool answer2()
{
    char answer;
    cout << "Do you want to write to file? (y/n)" << endl;
    cin >> answer;
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to calculate the average grade from group students
double getAverageGrade(vector<GradeData> gradeDatas)
{
    double sum = 0;
    for (auto & gradeData : gradeDatas)
    {
        sum += gradeData.getAverageGrade();
    }
    return sum / gradeDatas.size();
}

//function to answer continue or not
bool answer3()
{
    char answer;
    cout << "Do you want to continue? (y/n)" << endl;
    cin >> answer;
    if (answer == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to answer id of group
int answer4()
{
    int answer;
    cout << "Enter id of group" << endl;
    cin >> answer;
    return answer;
}
//function to take id of group from file
int answer5()
{
    int answer;
    ifstream fin("input.txt");
    fin >> answer;
    return answer;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        vector<GradeData> gradeDatas;
        string str;
        //int id;
        if (answer()) {
            ifstream in("input.txt");
            if (!in.is_open()) {
                cout << "File not found" << endl;
                return 1;
            }
            while (getline(in, str)) {
                if (checkInput(str)) {
                    //input id of group
                    //id = answer5();
                    stringstream ss(str);                    
                    string name;
                    ss >> name;
                    vector<int> grades;
                    int grade;
                    while (ss >> grade) {
                        grades.push_back(grade);
                    }
                    gradeDatas.emplace_back(name, grades);
                }
            }
            in.close();
        } else {
            //enter id of group
            //id = answer4();
            //cout << "Enter the number of students" << endl;
            //int n;
            //cin >> n;
            cin.ignore();
            for (int i = 0; i < 1; i++) {
                while (true) {
                    cout << "Enter the name and grades of the student" << endl;
                    getline(cin, str);
                    if (checkInput(str)) {
                        stringstream ss(str);
                        string name;
                        ss >> name;
                        vector<int> grades;
                        int grade;
                        while (ss >> grade) {
                            grades.push_back(grade);
                        }
                        gradeDatas.emplace_back(name, grades);
                        break;
                    } else {
                        cout << "Incorrect input" << endl;
                    }
                }
            }
        }
        if (answer2()) {
            ofstream out("output.txt");
            //out << "Group " << id << endl;
            for (auto & gradeData : gradeDatas) {
                out << gradeData << "Average grade : " << gradeData.getAverageGrade() << endl;
            }
            //out << "Average grade of the group : " << getAverageGrade(gradeDatas) << endl;
            out.close();
        } else {
            //cout << "id of group : " << id << endl;
            for (auto & gradeData : gradeDatas) {
                cout << gradeData << "Average grade : " << gradeData.getAverageGrade() << endl;
            }
            //cout << "Average grade of the group : " << getAverageGrade(gradeDatas) << endl;
        }

        if (!answer3()) {
            break;
        }
    }
}
