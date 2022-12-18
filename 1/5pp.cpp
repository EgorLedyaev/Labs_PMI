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

//example input
//group : 6101
//Number of students : 3
//Ivanov 3 4 5
//Petrov 5 5 5
//Sidorov 2 3 4

//example output
//group : 6101
//Number of students : 3
//Ivanov 3 4 5 5
//Petrov 5 5 5
//Sidorov 2 3 3
//Average grade Ivanov : 4,25
//Average grade Petrov : 5
//Average grade Sidorov : 2,6
//Average grade group : 3,95

//select writing to file or output to console.

//class for student
//Here we store the name of the student and the vector of grades, as well as calculate the average grade and store it

//class for group
//Here we store the group number of students that we will handle and calculate the average grade for the group using the class student
//output id group, students, student grades, average grade of student, average grade of group

//function if it is an error in the last name of the student offer the user the choice to enter a replacement or replace it with the default value. The last name must begin with a capital letter and contain only the letters
//function if it is an error in the grade of the student offer the user the choice to enter a replacement or replace it with the default value. The grade must be a number in the range 1-5

//input from file or console
//output to file or console

//input checks


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <locale>
#include <sstream>
#include <iterator>
#include <numeric>
#include <functional>

using namespace std;

class Student
{
private:
    string name;
    vector<int> grades;
    double average_grade;
public:
    Student() : name("Default"), grades(3, 0), average_grade(0) {}
    Student(string name, vector<int> grades) : name(name), grades(grades), average_grade(0) {}
    Student(const Student& other) : name(other.name), grades(other.grades), average_grade(other.average_grade) {}
    ~Student() {}

    void set_name(string name) { this->name = name; }
    void set_grades(vector<int> grades) { this->grades = grades; }
    void set_average_grade(double average_grade) { this->average_grade = average_grade; }

    string get_name() const { return name; }
    vector<int> get_grades() const { return grades; }
    double get_average_grade() const { return average_grade; }

    void calculate_average_grade()
    {
        average_grade = accumulate(grades.begin(), grades.end(), 0) / (double)grades.size();
    }

    friend istream& operator>>(istream& in, Student& student);
    friend ostream& operator<<(ostream& out, const Student& student);
};

class Group
{
private:
    int group_id;
    int number_of_students;
    vector<Student> students;
    double average_grade;
public:
    Group() : group_id(0), number_of_students(0), students(0), average_grade(0) {}
    Group(int group_id, int number_of_students, vector<Student> students) : group_id(group_id), number_of_students(number_of_students), students(students), average_grade(0) {}
    Group(const Group& other) : group_id(other.group_id), number_of_students(other.number_of_students), students(other.students), average_grade(other.average_grade) {}
    ~Group() {}

    void set_group_id(int group_id) { this->group_id = group_id; }
    void set_number_of_students(int number_of_students) { this->number_of_students = number_of_students; }
    void set_students(vector<Student> students) { this->students = students; }
    void set_average_grade(double average_grade) { this->average_grade = average_grade; }

    int get_group_id() const { return group_id; }
    int get_number_of_students() const { return number_of_students; }
    vector<Student> get_students() const { return students; }
    double get_average_grade() const { return average_grade; }

    void calculate_average_grade()
    {
        double sum = 0;
        for (int i = 0; i < students.size(); i++)
        {
            sum += students[i].get_average_grade();
        }
        average_grade = sum / (double)students.size();
    }

    friend istream& operator>>(istream& in, Group& group);
    friend ostream& operator<<(ostream& out, const Group& group);

    //overload function callculate average grade
    void calculate_average_grade(vector<Student> students)
    {
        double sum = 0;
        for (int i = 0; i < students.size(); i++)
        {
            sum += students[i].get_average_grade();
        }
        average_grade = sum / (double)students.size();
    }
};

//overloading input and output operators for class Student
istream& operator>>(istream& in, Student& student)
{
    in >> student.name;
    for (int i = 0; i < student.grades.size(); i++)
    {
        in >> student.grades[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Student& student)
{
    out << student.name << " ";
    for (int i = 0; i < student.grades.size(); i++)
    {
        out << student.grades[i] << " ";
    }
    out << student.average_grade;
    return out;
}

//overloading input and output operators for class Group
istream& operator>>(istream& in, Group& group)
{
    in >> group.group_id;
    in >> group.number_of_students;
    for (int i = 0; i < group.students.size(); i++)
    {
        in >> group.students[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Group& group)
{
    out << "group : " << group.group_id << endl;
    out << "Number of students : " << group.number_of_students << endl;
    for (int i = 0; i < group.students.size(); i++)
    {
        out << group.students[i] << endl;
    }
    out << "Average grade group : " << group.average_grade << endl;
    return out;
}

//overloading function callculate_average_grade for class Student
void calculate_average_grade(Student& student)
{
    student.calculate_average_grade();
}

//overloading function callculate_average_grade for class Group
void calculate_average_grade(Group& group)
{
    group.calculate_average_grade();
}

//function to answer from file or console
bool input_from_file()
{
    string answer;
    cout << "Do you want to read from file? (y/n) ";
    cin >> answer;
    if (answer == "y")
    {
        return true;
    }
    else if (answer == "n")
    {
        return false;
    }
    else
    {
        cout << "Incorrect answer. Try again." << endl;
        return input_from_file();
    }
}

//function to answer to file or console
bool output_to_file()
{
    string answer;
    cout << "Do you want to write to file? (y/n) ";
    cin >> answer;
    if (answer == "y")
    {
        return true;
    }
    else if (answer == "n")
    {
        return false;
    }
    else
    {
        cout << "Incorrect answer. Try again." << endl;
        return output_to_file();
    }
}

//function to check if the last name is correct
bool check_name(string name)
{
    if (isupper(name[0]))
    {
        for (int i = 1; i < name.size(); i++)
        {
            if (!isalpha(name[i]))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

//function to check if the grade is correct
bool check_grade(int grade)
{
    if (grade >= 1 && grade <= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function to replace the last name if it is incorrect
string replace_name(string name)
{
    string answer;
    cout << "The last name is incorrect. You enter - " << name <<". Do you want to replace it? (y/n) ";
    cin >> answer;
    if (answer == "y")
    {
        cout << "Enter the last name: ";
        cin >> name;
        if (check_name(name))
        {
            return name;
        }
        else
        {
            cout << "The last name is incorrect. Try again." << endl;
            return replace_name(name);
        }
    }
    else if (answer == "n")
    {
        return "Default";
    }
    else
    {
        cout << "Incorrect answer. Try again." << endl;
        return replace_name(name);
    }
}

//function to replace the grade if it is incorrect
int replace_grade(int grade)
{
    string answer2;
    cout << "The grade is incorrect. You enter - " << grade <<". Do you want to replace it? (y/n) ";
    cin >> answer2;
    if (answer2 == "y")
    {
        cout << "Enter the grade: ";
        cin >> grade;
        if (check_grade(grade))
        {
            return grade;
        }
        else
        {
            cout << "The grade is incorrect. Try again." << endl;
            return replace_grade(grade);
        }
    }
    else if (answer2 == "n")
    {
        return 1;
    }
    else
    {
        cout << "Incorrect answer. Try again." << endl;
        return replace_grade(grade);
    }
}

//function to read from file
void read_from_file(vector<Group>& groups)
{
    ifstream in("input.txt");
    if (in.is_open())
    {
        //считываем данные пока не встретим последнюю группу
        while (!in.eof())
        {
            int group_id;
            in >> group_id;
            int number_of_students;
            in >> number_of_students;
            vector<Student> students;
            for (int j = 0; j < number_of_students; j++)
            {
                string name;
                in >> name;
                //cout << name << endl;
                if (!check_name(name))
                {
                    name = replace_name(name);
                }
                vector<int> grades;
                for (int k = 0; k < 3; k++)
                {
                    string grade;
                    in >> grade;
                    //cout << grade << endl;
                    if (!isdigit(grade[0]))
                    {
                        int grade2 = replace_grade(0);
                        grades.push_back(grade2);
                    }
                    else
                    {
                        int grade2 = stoi(grade);
                        if (!check_grade(grade2))
                        {
                            grade2 = replace_grade(grade2);
                        }
                        grades.push_back(grade2);
                    }
                }
                Student student(name, grades);
                student.calculate_average_grade();
                students.push_back(student);
            }
            Group group(group_id, number_of_students, students);
            group.calculate_average_grade();
            groups.push_back(group);
        }
        in.close();
    }
    else
    {
        cout << "File is not open." << endl;
    }
    in.close();
}

//function to read from console
void read_from_console(vector<Group>& groups)
{
    int number_of_groups;
    cout << "Enter the number of groups: ";
    cin >> number_of_groups;
    for (int i = 0; i < number_of_groups; i++)
    {
        int group_id;
        cout << "Enter the group id: ";
        cin >> group_id;
        int number_of_students;
        cout << "Enter the number of students: ";
        cin >> number_of_students;
        vector<Student> students;
        for (int j = 0; j < number_of_students; j++)
        {
            string name;
            cout << "Enter the last name: ";
            cin >> name;
            if (!check_name(name))
            {
                name = replace_name(name);
            }
            vector<int> grades;
            for (int k = 0; k < 3; k++)
            {
                string grade;
                cout << "Enter the grade: ";
                cin >> grade;
                //если не число, то спрашиваем заменить или нет
                if (!isdigit(grade[0]))
                {
                    int grade2 = replace_grade(0);
                    grades.push_back(grade2);
                }
                else
                {
                    int grade2 = stoi(grade);
                    if (!check_grade(grade2))
                    {
                        grade2 = replace_grade(grade2);
                    }
                    grades.push_back(grade2);
                }
            }
            Student student(name, grades);
            student.calculate_average_grade();
            students.push_back(student);
        }
        Group group(group_id, number_of_students, students);
        group.calculate_average_grade();
        groups.push_back(group);
    }
}

//function to write to file
void write_to_file(vector<Group> groups)
{
    ofstream out("output.txt");
    if (out.is_open())
    {
        for (int i = 0; i < groups.size(); i++)
        {
            out << "Group id: " << groups[i].get_group_id() << endl;
            out << "Number of students: " << groups[i].get_number_of_students() << endl;
            out << "Average grade of group: " << groups[i].get_average_grade() << endl;
            for (int j = 0; j < groups[i].get_number_of_students(); j++)
            {
                out << "Last name: " << groups[i].get_students()[j].get_name() << endl;
                out << "Grades: ";
                for (int k = 0; k < 3; k++)
                {
                    out << groups[i].get_students()[j].get_grades()[k] << " ";
                }
                out << endl;
                out << "Average grade: " << groups[i].get_students()[j].get_average_grade() << endl;
            }
            out << endl;
        }
    }
    else
    {
        cout << "File is not open." << endl;
    }
    out.close();
}

//function to write to console
void write_to_console(vector<Group> groups)
{
    for (int i = 0; i < groups.size(); i++)
    {
        cout << "Group id: " << groups[i].get_group_id() << endl;
        cout << "Number of students: " << groups[i].get_number_of_students() << endl;
        cout << "Average grade of group: " << groups[i].get_average_grade() << endl;
        for (int j = 0; j < groups[i].get_number_of_students(); j++)
        {
            cout << "Last name: " << groups[i].get_students()[j].get_name() << endl;
            cout << "Grades: ";
            for (int k = 0; k < 3; k++)
            {
                cout << groups[i].get_students()[j].get_grades()[k] << " ";
            }
            cout << endl;
            cout << "Average grade: " << groups[i].get_students()[j].get_average_grade() << endl;
        }
        cout << endl;
    }
}

int main()
{
    while (true) {
        vector<Group> groups;
        string answer;
        cout << "Do you want to read from file? (y/n): ";
        cin >> answer;
        if (answer == "y") {
            read_from_file(groups);
        } else if (answer == "n") {
            read_from_console(groups);
        } else {
            cout << "Incorrect answer. Try again." << endl;
            return 0;
        }
        cout << "Do you want to write to file? (y/n): ";
        cin >> answer;
        if (answer == "y") {
            write_to_file(groups);
        } else if (answer == "n") {
            write_to_console(groups);
        } else {
            cout << "Incorrect answer. Try again." << endl;
            return 0;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> answer;
        while (answer != "y" && answer != "n") {
            cout << "Incorrect answer. Try again." << endl;
            cin >> answer;
        }
        if (answer == "n") {
            break;
        }
    }
}
