#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(const char* ID, const string& name) : Person(ID, name){
    this->semester = 1;
}

Student::Student(const char* ID, const string& name, char gender, int semester) : Person(ID, name, gender){
    this->semester = semester;
}

Student::Student(const Student& other) : Person(other){
    this->semester = other.semester;
    this->coursesAttend = other.coursesAttend;
}

Student& Student::operator=(const Student& other){
    if(this == &other){
        return *this;
    }

    Person::operator=(other);

    this->semester = other.semester;
    this->coursesAttend = other.coursesAttend;

    return *this;
}

Student::~Student(){

}

void Student::setSemester(int semester){
    this->semester = semester;
}

int Student::getSemester() const{
    return this->semester;
}

void Student::addCourse(Course* course){
    this->coursesAttend.push_back(course);
}

void Student::removeCourse(Course* course){
    bool found = false;
    for(int i = 0; i < (int)coursesAttend.size() && !found; i++){
        if(coursesAttend[i] == course){
            coursesAttend.erase(coursesAttend.begin() + i);
            found = true;
        }
    }
}

const std::vector<Course* >& Student::getCoursesAttending() const{
    return this->coursesAttend;
}

void Student::sendEmail() const{
    cout << "Το email στάλθηκε στον φοιτητή " << this->name <<  endl;
}