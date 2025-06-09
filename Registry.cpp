#include <iostream>
#include <fstream>
#include "Registry.h"
#include <string.h>

using namespace std;

Registry::Registry(){

}

Registry::Registry(const Registry& other){
    for(auto i : other.uniMembers){
        uniMembers.push_back(i->clone());
    }

    for(auto i : other.courses){
        courses.push_back(i->clone());
    }
}

Registry::~Registry(){
    //delete all person objects
    for(auto& person : uniMembers){
        delete person;
    }
    uniMembers.clear();

    //delete all courses objects
    for(auto& course : courses){    
        delete course;
    }
    courses.clear();

}

void Registry::addCourse(Course* course){
    this->courses.push_back(course);
}

void Registry::addPerson(Person* person){
    this->uniMembers.push_back(person);
}

bool Registry::deleteCourse(const char* courseID) {
    if(courseID == nullptr){
        return false;
    }
    for(int i = 0; i < courses.size(); ++i){
        if(strcmp(courses[i]->getCourseID(), courseID) == 0){
            delete courses[i];
            courses.erase(courses.begin() + i);
            return true;
        }
    }
    return false;
}

bool Registry::deletePerson(const char* ID){
    if(ID == nullptr){
        return false;
    }

    for(int i = 0; i < uniMembers.size(); ++i){
        if(strcmp(uniMembers[i]->getId(), ID) == 0){
            delete uniMembers[i];
            uniMembers.erase(uniMembers.begin() + i);
            return true;
        }
    }
    return false;
}