#include <iostream>
#include <fstream>
#include "Registry.h"
#include <string.h>

using namespace std;

Registry::Registry(){

}

Registry::Registry(const Registry& other){
    for(auto& i : other.uniMembers){
        uniMembers.push_back(i->clone());
    }

    for(auto& i : other.courses){
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

bool Registry::updateCourse(const char * courseID, const string& newName, int newSemester, const string& newProfName) {
    if(courseID == nullptr){ 
    return false;
    }

    for(int i = 0; i < courses.size(); ++i){
        if(strcmp(courses[i]->getCourseID(), courseID) == 0){
            courses[i]->setCourseName(newName);
            courses[i]->setCourseSemester(newSemester);
            courses[i]->setProfName(newProfName);
            return true;
        }
    }

    return false;
}

bool Registry::updatePerson(const char* ID, const std::string& newName, int newBirthYear, const std::string& newStreet, const std::string& newTelephoneNumber, const std::string& newEmail, float newHeight) {

    if(ID == nullptr){
        return false;
    }

    for(int i = 0; i<uniMembers.size(); ++i){
        if(strcmp(uniMembers[i]->getId(), ID) == 0){
            uniMembers[i]->setName(newName);
            uniMembers[i]->setBirthYear(newBirthYear);
            uniMembers[i]->setEmail(newEmail);
            uniMembers[i]->setStreet(newStreet);
            uniMembers[i]->setTelephoneNumber(newTelephoneNumber);
            uniMembers[i]->setHeight(newHeight);
            return true;
        }
    }

    return false;
}

void Registry::sendEmailToAll(){
    for(auto& x : uniMembers){
        x->sendEmail();
    }
}

bool Registry::addGrade(const char* courseID, float newGrade){
    if(courseID == nullptr || newGrade < 0 || newGrade > 10){
        return false;
    }

    for(int i = 0; i < courses.size(); ++i){
        if(strcmp(courses[i]->getCourseID(), courseID) == 0){
            courses[i]->setGrade(newGrade);
            return true;
        }
    }

    return false;
}

bool Registry::updateGrade(const char* courseID, float updatedGrade){
    if(courseID == nullptr || updatedGrade < 5 || updatedGrade > 10){
        return false;
    }
    
    for(int i = 0; i < courses.size(); ++i){
        if(strcmp(courses[i]->getCourseID(), courseID) == 0){
            if(courses[i]->getGrade() < 5){
                courses[i]->setGrade(updatedGrade);
                return true;
            }
            return false;
        }
    }

    return false;
}

bool Registry::savePeopleToCSV(const string& filename) const{
    try{
        ofstream file(filename);
        if(!file.is_open()){
            return false;
        }

        file << " For Student: AM, Name, Email, Semester, Declared Courses\n";
        file << "For Professor: ID, Name, Email, Specialty\n";
        file << "For General Person: ID, Name, Email, Birth Year, Telephone Number\n\n";

        for(const auto& person : uniMembers){
            Student* student = dynamic_cast<Student*>(person);
            Professor* professor = dynamic_cast<Professor*>(person);

            if(student){
                file << student->getAM() << ", "
                     << student->getName() << ", " 
                     << student->getEmail() << ", "
                     << student->getSemester() << ", "
                     << student->getDeclaredCourses() << "\n";
            }else if(professor){
                file << professor->getProfID() << ", "
                     << professor->getName() << ", "
                     << professor->getEmail() << ", "
                     << professor->getSpecialty() << "\n";
            }else{
                 file << person->getId() << "," 
                     << person->getName() << "," 
                     << person->getEmail() << "," 
                     << person->getBirthYear() << "," 
                     << person->getTelephoneNumber() << "\n";
            }
        }

        file.close();
        return true;

    }
    catch(const exception& e){
        cerr << "Error saving people to CSV: " << e.what() << endl;
        return false;
    }
    
}

bool Registry::saveCoursesToCSV(const string& filename) const{
    try {
        ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        file << "Course ID, Course Name, Grade, Course Semester, Professor's Name\n";
        
        for (const auto& course : courses) {
            file << course->getCourseID() << "," 
                 << course->getCourseName() << "," 
                 << course->getGrade() << ", "
                 << course->getCourseSemester() << ","
                 << course->getProfName() << "\n";
        }
        
        file.close();
        return true;

    } catch (const exception& e) {
        cerr << "Error saving courses to CSV: " << e.what() << endl;
        return false;
    }

}

bool Registry::loadDataFromCSV(const string& filename) const{
    try{
        ifstream file(filename);
        if(!file.is_open()){
            return false;
        }

        string line;
        while(getline(file, line)){
            cout << line << endl;
        }

        file.close();
        return true;
    }
    catch(const exception& e){
        cerr << "Error retrieving courses to CSV: " << e.what() << endl;
        return false;
    }
    
}

