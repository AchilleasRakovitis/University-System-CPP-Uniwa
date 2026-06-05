#include "Professor.h"
#include <iostream>

using namespace std;


Professor::Professor(const char* ID, const string& name, char gender, const string& specialty) : Person(ID, name, gender){
    this->specialty = specialty;
}

Professor::Professor(const char* ID, const string& name) : Person(ID, name){
    this->specialty = "Default";
}

Professor::Professor(const Professor& other) : Person(other){
    this->specialty = other.specialty;
    this->coursesTeaching = other.coursesTeaching;
}

Professor& Professor::operator=(const Professor& other){
    if(this == &other){
        return *this;
    }

    Person::operator=(other);

    this->specialty = other.specialty;
    this->coursesTeaching = other.coursesTeaching;

    return *this;
}

Professor::~Professor(){

}

void Professor::setSpecialty(const string& specialty){
    this->specialty = specialty;
}

const string& Professor::getSpecialty() const{
    return this->specialty;
}

void Professor::addCourse(Course* course){
    this->coursesTeaching.push_back(course);
}

void Professor::removeCourse(Course* course){
    for(int i = 0; i < (int)coursesTeaching.size(); i++){
        if(coursesTeaching[i] == course){
            coursesTeaching.erase(coursesTeaching.begin() + i);
            break;
        }
    }
}

const vector<Course * >& Professor::getCoursesTeaching() const{
    return this->coursesTeaching;
}

void Professor::sendEmail() const{
    cout << "Το email στάλθηκε στον καθηγητή " << this-> name << endl;
}