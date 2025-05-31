#include <iostream>
#include "Person.h"
#include "Student.h"

using namespace std;

int main(){

    unsigned int size = 5;
    Person **people = new Person*[size];

    Person* alex = new Person("000000010", "Αλέξανδρος", 1999, "Αθήνα", "2101234567", "alex@example.com", 1.75f);
    Person* maria = new Person("Μαρία", 1963, 1.68f);
    Person* nikos = new Person("Νίκος", "Πάτρα", "2610123456", "nikos@example.com");
    Person* ioanna = new Person("000000016", "Ιωάννα", 2005, "Ηράκλειο", "2810123456", "ioanna@example.com", 1.65f);
    Person* ioanna2 = new Person(*ioanna);

    Student stud1("000000020", "Γιάννης", 2002, "Θεσσαλονίκη", "2310123456", "giannis@student.com", 1.80f, "19390200", 7, 3);

    cout << stud1.returnAge() << endl;
}
    /*
    people[0] = alex;
    people[1] = maria;
    people[2] = nikos;
    people[3] = ioanna;
    people[4] = ioanna2;

    cout << alex->getTelephoneNumber() << endl;
    maria->setID("000000012");
    cout << "Maria's new ID: " << maria->getId() << endl;

    
    for(unsigned int i = 0; i < size; i++){
        delete people[i];
    }
    delete[] people;

    return 0;
}
    */