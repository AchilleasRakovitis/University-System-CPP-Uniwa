#include <iostream>
#include <cstring>
#include <string>
#include "Professor.h"

using namespace std;

Professor::Professor(const char *ID, const std::string& name, int birthYear, 
            const std::string& street, const std::string& telephoneNumber, 
            const std::string& email, float height,
            const char *profID, const std::string& specialty) 
        : Person(ID, name, birthYear, street, telephoneNumber, email, height){

        if(profID == nullptr){
            this->profID = new char[1]; 
            this->profID[0] = '\0';
        }else{
            this->profID = new char[strlen(profID) + 1];
            strcpy(this->profID, profID);
        }

        if(specialty.empty()){
            this->specialty = "No specialty";
        }else{
            this->specialty = specialty;
        }
    }

Professor::Professor(const Professor& other) : Person(other){
    if(other.profID == nullptr){
        this->profID = new char[1]; 
        this->profID[0] = '\0';
    }else{
        this->profID = new char[strlen(other.profID) + 1];
        strcpy(this->profID, other.profID);
    }

    this->specialty = other.specialty;
}

Professor::~Professor(){
    if(this->profID != nullptr){
        delete[] profID;
    }
    this->profID = nullptr;
}

void Professor::setProfID(const char * profID){
    if(profID == nullptr){
        if(this->profID){
            delete[] this->profID;
        }
        this->profID = new char[1];
        this->profID[0] = '\0';
    }else{
        if(this->profID){
            delete[] this->profID;
        }
        this->profID = new char[strlen(profID) + 1];
        strcpy(this->profID, profID);
    }
}

void Professor::setSpecialty(const string& specialty){
    if(specialty.empty()){
        this->specialty = "No specialty";
    }else{
        this->specialty = specialty;
    }
}

const char * Professor::getProfID() const{
    return this->profID;
}

const string& Professor::getSpecialty() const{
    return this->specialty;
}