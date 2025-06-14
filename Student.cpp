#include <iostream>
#include <string>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(const char *ID, const string& name, int birthYear, const string& street,
                 const string& telephoneNumber, const string& email, float height,
                const char *AM, int semester, int declaredCourses) 
    : Person(ID, name, birthYear, street, telephoneNumber, email, height) {
    
    if(AM == nullptr) {
        this->AM = new char[1];
        this->AM[0] = '\0';
    } else {
        this->AM = new char[strlen(AM) + 1];
        strcpy(this->AM, AM);
    }
    
    if(semester >= 1) {
        this->semester = semester;
    } else {
        cout << "Invalid semester value" << endl;
        this->semester = 1;
    }
    
    if(declaredCourses < 0) {
        cout << "Declared courses cannot be negative" << endl;
        this->declaredCourses = 0;
    } else if(this->semester > 10) {
        this->declaredCourses = declaredCourses;
    } else if(declaredCourses <= 9) {
        this->declaredCourses = declaredCourses;
    } else {
        cout << "Too many declared courses" << endl;
        this->declaredCourses = 9;
    }
}

Student::Student(const Student& other) : Person(other) {
    if(other.AM == nullptr){
        this->AM = new char[1];
        this->AM[0] = '\0';
    }else{
        this->AM = new char[strlen(other.AM) + 1];
        strcpy(this->AM, other.AM);
    }
    this->semester = other.semester;
    this->declaredCourses = other.declaredCourses;
}

// θα χρησιμοποιηθεί στον copy constructor του φοιτητολογίου
// επιστρέφει αντικείμενο τύπου Student όταν ζητηθεί απο pointer.
Person * Student::clone() const {
    return new Student(*this);
}

Student::~Student(){
    if(this->AM != nullptr){
        delete[] this->AM;
    }
}

void Student::setAM(const char *AM){
    if(AM == nullptr){
        if(this->AM){
            delete[] this->AM;
        }
        this->AM = new char[1];
        this->AM[0] = '\0';
    }else{
        if(this->AM){
            delete[] this->AM;
        }
        this->AM = new char[strlen(AM) + 1];
        strcpy(this->AM, AM);
    }
}

void Student::setSemester(int semester){
    if(semester >= 1){
        this->semester = semester;
    }else{
        cout << "Invalid semester value" << endl;
    }
}

void Student::setDeclaredCourses(int declaredCourses){
    if(declaredCourses < 0){
        cout << "Declared courses cannot be negative" << endl;
        return;
    }
    
    if(this->semester > 10){
        this->declaredCourses = declaredCourses;
    }else if(declaredCourses <= 9){
        this->declaredCourses = declaredCourses;
    }else{
        cout << "Too many declared courses" << endl;
        this->declaredCourses = 9;
    }
}

const char * Student::getAM() const{
    return this->AM;
}

//επιστρέφω για το ΑΜ attribute(Πολυμορφισμός)
//για να επιστραφεί το σωστό ID που είναι AM.
const char * Student::getId() const{
    return this->AM;
}

int Student::getSemester() const{
    return this->semester;
}

int Student::getDeclaredCourses() const{
    return this->declaredCourses;
}

void Student::sendEmail() const {

    cout << "Email sent to the student!" << endl;
}