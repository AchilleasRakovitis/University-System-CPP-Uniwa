#include "Person.h"
#include <string.h>

using namespace std;

Person::Person(const char* ID, const string& name, char gender){
    if(ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(ID) + 1];
        strcpy(this->ID, ID);
    }

    this->name = name;
    this->gender = gender;
}

Person::Person(const char* ID, const string& name){
    if(ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(ID) + 1];
        strcpy(this->ID, ID);
    }

    this->name = name;
    this->gender = '-';
}

Person::Person(const Person& other){
    if(other.ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(other.ID) + 1];
        strcpy(this->ID, other.ID);
    }

    this->name = other.name;
    this->gender = other.gender;
}

Person& Person::operator=(const Person& other){
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

    this->name = other.name;
    this->gender = other.gender;

    return *this;
}

Person::~Person(){
    delete[] this->ID;
}

void Person::setID(const char* ID){
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

void Person::setName(const string& name){
    this->name = name;
}

void Person::setGender(char gender){
    this->gender = gender;
}

const char* Person::getID() const{
    return this->ID;
}

const string& Person::getName() const{
    return this->name;
}

char Person::getGender() const{
    return this->gender;
}

void Person::sendEmail() const{
    
}