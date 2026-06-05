#include "Course.h"
#include <string.h>

using namespace std;

Course::Course(const char* ID, const string& description, int semester, const Professor* courseManager){
    if(ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(ID) + 1];
        strcpy(this->ID, ID);
    }

    this->description = description;
    this->semester = semester;
    this->courseManager = courseManager;
}

Course::Course(const char* ID, int semester){
    if(ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(ID) + 1];
        strcpy(this->ID, ID);
    }
    
    this->description = "";
    this->semester = semester;
    this->courseManager = nullptr;
}

Course::Course(const Course& other){
    if(other.ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(other.ID) + 1];
        strcpy(this->ID, other.ID);
    }

    this->description = other.description;
    this->semester = other.semester;
    this->courseManager = other.courseManager;
}

Course& Course::operator=(const Course& other){
    if(this == &other){
        return *this;
    }

    if(this->ID != nullptr){
        delete[] this->ID;
    }

    if(other.ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(other.ID) + 1];
        strcpy(this->ID, other.ID);
    }

    this->description = other.description;
    this->semester = other.semester;
    this->courseManager = other.courseManager;

    return *this;
}

Course::~Course(){
    delete[] this->ID;
}

void Course::setID(const char* ID){
    if(this->ID){
        delete[] this->ID;
    }
     
    if(ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(ID) + 1];
        strcpy(this->ID, ID);
    }
}

void Course::setDescription(const string& description){
    this->description = description;
}

void Course::setSemester(int semester){
    this->semester = semester;
}

void Course::setCourseManager(const Professor* courseManager){
    this->courseManager = courseManager;
}

const char* Course::getID() const{
    return this->ID;
}

const string& Course::getDescription() const{
    return this->description;
}

int Course::getSemester() const{
    return this->semester;
}

const Professor* Course::getCourseManager() const{
    return this->courseManager;
}