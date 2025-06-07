#include <iostream>
#include <fstream>
#include "Registry.h"

using namespace std;

Registry::Registry(){

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