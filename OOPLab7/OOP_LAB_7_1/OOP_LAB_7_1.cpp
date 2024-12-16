#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Group
{
public:
    // Nested Student class
    class Student
    {
    private:
        string name;
        int studentID;

    public:
        Student(string name, int studentID)
        {
            this->name = name;
            this->studentID = studentID;
        }

        void display()
        {
            cout << "  Student Name: " << name << ", ID: " << studentID << endl;
        }
    };

private:
    string groupName;
    vector<Student> students; // List of students in the group

public:
    Group(string groupName)
    {
        this->groupName = groupName;
    }

    void addStudent(string name, int studentID)
    {
        students.push_back(Student(name, studentID)); // Add a new student to the list
    }

    void display()
    {
        cout << "Group Name: " << groupName << endl;

        if (students.size() == 0)
            cout << "  No students in this group." << endl;
        else
        {
            for (int i = 0; i < students.size(); i++)
                students[i].display();
        }
    }
};

int main()
{
    Group group1("Engineering");
    Group group2("Philosophy");

    group1.addStudent("Ana", 101);
    group1.addStudent("Robert", 102);

    group2.addStudent("Andrew", 201);
    group2.addStudent("Jamal", 202);

    cout << "Groups + Students:" << endl;

    group1.display();
    group2.display();

    return 0;
}
