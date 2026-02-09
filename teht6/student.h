#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student
{
private:
    std::string Name;
    int Age;

public:
    Student(std::string, int );
    void setAge(int);
    void setName(std::string);

    std::string getName() const;
    int getAge()const;
    void printStudentInfo() const;
};

#endif // STUDENT_H
