#include <iostream>
#include <string>
#include "Person.h"
#include <string.h>

using namespace std; 

Person::Person(const char *ID, const string& name, int birthYear, const string& street, const string& telephoneNumber, const string& email, float height) {
    //check for ID (char *) and initialize if necessary 
    if (ID == nullptr) {
        this->ID = new char[1];
        this->ID[0] = '\0'; // empty string 
    } else {
        this->ID = new char[strlen(ID) + 1];
        strcpy(this->ID, ID);
    }
    this->name = name;
    this->birthYear = birthYear;
    this->street = street;

    //check if telephone number has "+30" in front or else add it 
    if(telephoneNumber.length() >= 3 && telephoneNumber.substr(0,3) == "+30") {
        this->telephoneNumber = telephoneNumber;
    } else {
        this->telephoneNumber = "+30" + telephoneNumber;
    }
    this->email = email;
    this->height = height;
}

Person::Person(const string& name, int birthYear, float height){
    this->ID = new char[1];
    this->ID[0] = '\0';
    this->name = name;
    // initialize birthYear 
    if(birthYear < 2007){
        this->birthYear = birthYear;
    }else{
        this->birthYear = 2007;
    }
    this->height = height;

    this->street = "";
    this->email = "";
    this->telephoneNumber = "";
}

Person::Person(const string& name, const string& street, const string& telephoneNumber, const string& email) {
    this->ID = new char[1];
    this->ID[0] = '\0';
    
    this->name = name;
    this->street = street;
    if(telephoneNumber.length() >= 3 && telephoneNumber.substr(0,3) == "+30") {
        this->telephoneNumber = telephoneNumber;
    } else {
        this->telephoneNumber = "+30" + telephoneNumber;
    }
    this->email = email;
    
    this->birthYear = 0;
    this->height = 0.0f;
}

Person::Person(const Person& other){
    // other -> object to be copied 
    if(other.ID == nullptr){
        this->ID = new char[1];
        this->ID[0] = '\0';
    }else{
        this->ID = new char[strlen(other.ID) + 1];
        strcpy(this->ID, other.ID);
    }
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->street = other.street;
    this->telephoneNumber = other.telephoneNumber;
    this->email = other.email;
    this->height = other.height;    
}

Person::~Person(){
    if(this->ID != nullptr){
    delete[] ID;
    }
}

Person* Person::clone() const{
    return new Person(*this);
}

void Person::setID(const char *ID) {
    if(ID == nullptr) {
        this->ID = new char[1];
        this->ID[0] = '\0'; // initialize to empty string 
    }else{
        if(this->ID){
            delete[] this->ID; //delete garbage 
        }
        this->ID = new char[strlen(ID) + 1];
        strcpy(this->ID, ID);
    }
}

void Person::setName(const string& name){
    this->name = name;
}

void Person::setBirthYear(int birthYear) {
    if (birthYear < 2007) {
        this->birthYear = birthYear;
    } else {
        this->birthYear = 2007;
    }
}

void Person::setStreet(const string& street){
    this->street = street;
}

void Person::setTelephoneNumber(const string& telephoneNumber){
    if(telephoneNumber.length() >= 3 && telephoneNumber.substr(0,3) == "+30"){
        this->telephoneNumber = telephoneNumber;
    }else{
        this->telephoneNumber = "+30"+telephoneNumber;
    }
    
}

void Person::setEmail(const string& email){
    this->email = email;
}

void Person::setHeight(float height){
    this->height = height;
}

const char * Person::getId() const{
    return this->ID;
}

const string& Person::getName() const{
    return this->name;
}

int Person::getBirthYear() const{
    return this->birthYear;
}

const string& Person::getStreet() const{
    return this->street;
}

const string& Person::getTelephoneNumber() const{
    return this->telephoneNumber;
}

const string& Person::getEmail() const{
    return this->email;
}

float Person::getHeight() const{
    return this->height;
}

int Person::returnAge() const {
    return 2025 - this->birthYear;
}




