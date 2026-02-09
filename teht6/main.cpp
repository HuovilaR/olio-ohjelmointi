#include <iostream>
#include <vector>
#include "student.h"
#include <algorithm>

using namespace std;


int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:{
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.

            string name;
            int age;

            cout << "Anna nimi: "; cin >> name;
            cout << "Anna ika: "; cin >> age;

            studentList.push_back(Student(name, age));

            break;
}
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.

            for (const Student& s : studentList){
            s.printStudentInfo();
            }

            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), []( Student& a, Student& b){
                return a.getName() < b.getName();
            });

            for (const Student& s : studentList){
            s.printStudentInfo();
            }

            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat

            sort(studentList.begin(), studentList.end(), []( Student& a, Student& b){
                return a.getAge() < b.getAge();
            });

            for (const Student& s : studentList){
            s.printStudentInfo();
                 }

            break;
        case 4:{
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.

            string search;
            cout << "Anna nimi jota etsit: ";
            cin >> search;

            auto it = find_if(studentList.begin(), studentList.end(),[&](const Student& s) {
                    return s.getName() == search;
            });

            if (it != studentList.end()) {
                it->printStudentInfo();
            } else {
                cout << "Ei tuloksia" << endl;
            }
            break;

        }
    }
}
    while (selection < 5);

return 0;
}
