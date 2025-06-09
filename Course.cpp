#include <iostream>
#include <string>
#include <string.h>
#include "Course.h"

using namespace std;

Course::Course(const char * courseID,const string& courseName, int courseSemester, const string& profName ){
    if(courseID == nullptr){
        this->courseID = new char[1];
        this->courseID[0] = '\0';
    }else{
        this->courseID = new char[strlen(courseID) + 1];
        strcpy(this->courseID, courseID);
    }

    this->courseName = courseName;

    if(courseSemester > 10 || courseSemester < 1){
        cout << "Semester count is out of limits" << endl;
        this->courseSemester = 1; //set default value
    }else{
        this->courseSemester = courseSemester;
    }

    this->profName = profName;
}

Course::Course(const Course& other){
    if(other.courseID == nullptr){
        this->courseID = new char[1];
        this->courseID[0] = '\0';
    }else{
        this->courseID = new char[strlen(other.courseID) + 1];
        strcpy(this->courseID, other.courseID);
    }

    this->courseName = other.courseName;
    this->courseSemester = other.courseSemester;
    this->profName = other.profName;
}

Course * Course::clone() const{
    return new Course(*this);
}

Course::~Course(){
    if(this->courseID != nullptr){
        delete[] courseID;
    }
}

void Course::setCourseID(const char * courseID){
    if(courseID == nullptr){
        if(this->courseID){
            delete[] this->courseID;
        }
        this->courseID = new char[1];
        this->courseID[0] = '\0';
    }else{
        if(this->courseID){
            delete[] this->courseID; 
        }
        this->courseID = new char[strlen(courseID) + 1];
        strcpy(this->courseID, courseID);
    }
}

void Course::setCourseName(const string& courseName){
    this->courseName = courseName;
}

void Course::setCourseSemester(int courseSemester){
    if(courseSemester >= 1 && courseSemester <= 10){
        this->courseSemester = courseSemester;
    }else{
        cout << "Course semester is out of limits (1-10)" << endl;
    }
}

void Course::setProfName(const string& profName){
    this->profName = profName;
}

const char * Course::getCourseID() const{
    return this->courseID;
}

const string& Course::getCourseName() const{
    return this->courseName;
}

int Course::getCourseSemester() const{
    return this->courseSemester;
}

const string& Course::getProfName() const{
    return this->profName;
}