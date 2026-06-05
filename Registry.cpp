#include "Registry.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

Registry::Registry(){

}

Registry::~Registry(){
    for(int i = 0; i < (int)uniMembers.size(); i++){
        delete uniMembers[i];
    }

    for(int i = 0; i < (int)courses.size(); i++){
        delete courses[i];
    }

}

void Registry::addMember(Person* member){
    bool flag = false;
    for(int i = 0; i < (int)uniMembers.size(); i++){
        if(!strcmp(uniMembers[i]->getID(), member->getID())){
            flag = true;
            break;
        }
    }
    if(!flag){
        this->uniMembers.push_back(member);
    }else{
        cout << "Το μέλος με αυτό το ID: " << member->getID() <<" υπάρχει ήδη." << endl;
        delete member;
    }  
}

void Registry::addCourse(Course* course){
    bool flag = false;
    for(int i = 0; i < (int)courses.size(); i++){
        if(!strcmp(courses[i]->getID(), course->getID())){
            flag = true;
            break;
        }
    }

    if(!flag){
        this->courses.push_back(course);
    }else{
        cout << "Το μάθημα με αυτό το ID: " << course->getID() << " υπάρχει ηδη." << endl;
        delete course;
    }
}

void Registry::deleteMember(const char* ID){
    if(ID == nullptr){
        throw 1;
    }
    for(int i = 0; i < (int)uniMembers.size(); i++){
        if(!strcmp(uniMembers[i]->getID(), ID)){
            Person* toBeRemoved = uniMembers[i];
            Professor* tmpPr = dynamic_cast<Professor*>(toBeRemoved);

            if(tmpPr != nullptr){
                for(int j = 0; j < (int)courses.size(); j++){
                    if(courses[j]->getCourseManager() == tmpPr){
                        courses[j]->setCourseManager(nullptr);
                    }
                }
            }
            delete toBeRemoved;
            uniMembers.erase(uniMembers.begin() + i);
            return;
        }
    }
    cout << "Το μέλος με αυτό το ID: " << ID << " δεν βρέθηκε." << endl;
}

void Registry::deleteCourse(const char* ID){
    if(ID == nullptr){
        throw 1;
    }

    for(int i = 0; i < (int)courses.size(); i++){
        if(!strcmp(courses[i]->getID(), ID)){
            Course* toBeRemoved = courses[i];
            Student* tmpSt;
            Professor* tmpPr;
            for(int j = 0; j < (int)uniMembers.size(); j++){
                tmpSt = dynamic_cast<Student*>(uniMembers[j]);
                if(tmpSt != nullptr){
                    tmpSt->removeCourse(toBeRemoved);
                }
                tmpPr = dynamic_cast<Professor*>(uniMembers[j]);
                if(tmpPr != nullptr){
                    tmpPr->removeCourse(toBeRemoved);
                }
            }

            delete toBeRemoved;
            courses.erase(courses.begin() + i);
            return;
        }
    }

    cout << "Το μάθημα με αυτό το ID: " << ID << " δεν βρέθηκε." << endl;
}

void Registry::updateStudent(const char* ID, const string& newName, char newGender, int newSemester){
    Student* student = dynamic_cast<Student*>(findMember(ID));

    if(student == nullptr){
        cout <<"Δεν βρέθηκε φοιτητής για ενημέρωση στοιχείων με ID: " << ID << endl;
        return;
    }

    student->setName(newName);
    student->setGender(newGender);
    student->setSemester(newSemester); 
}

void Registry::updateProfessor(const char* ID, const string& newName, char newGender, const string& newSpecialty){
    Professor* professor = dynamic_cast<Professor*>(findMember(ID));

    if(professor == nullptr){
        cout <<"Δεν βρέθηκε καθηγητής για ενημέρωση στοιχείων με ID: " << ID << endl;
        return;
    }

    professor->setName(newName);
    professor->setGender(newGender);
    professor->setSpecialty(newSpecialty);
}

void Registry::updateCourse(const char* ID, const string& newDescription, int newSemester){
    Course* course = findCourse(ID);

    if(course == nullptr){
        cout << "Δεν βρέθηκε μάθημα για ενημέρωση στοιχείων με ID: " << ID << endl;
        return;
    }

    course->setDescription(newDescription);
    course->setSemester(newSemester);
}

void Registry::sendEmailToStudents() const{
    Student* tmpSt;
    for(int i = 0; i < (int)uniMembers.size(); i++){
        tmpSt = dynamic_cast<Student*>(uniMembers[i]);
        if(tmpSt != nullptr){
            tmpSt->sendEmail();
        }
    }
}

void Registry::sendEmailToProfessors() const{
    Professor* tmpPr;
    for(int i = 0; i < (int)uniMembers.size(); i++){
        tmpPr = dynamic_cast<Professor*>(uniMembers[i]);
        if(tmpPr != nullptr){
            tmpPr->sendEmail();
        }
    }
}

Person* Registry::findMember(const char* ID) const{
    if(ID == nullptr){
        throw 1;
    }
    
    for(int i = 0; i < (int)uniMembers.size(); i++){
        if(!strcmp(uniMembers[i]->getID(), ID)){
            return uniMembers[i];
        }
    }

    return nullptr;
}

Course* Registry::findCourse(const char* ID) const{
    if(ID == nullptr){
        throw 1;
    }

    for(int i = 0; i < (int)courses.size(); i++){
        if(!strcmp(courses[i]->getID(), ID)){
            return courses[i];
        }
    }

    return nullptr;
}

void Registry::enrollStudentInCourse(const char* studentID, const char* courseID){
    Person* person = findMember(studentID);
    Course* course = findCourse(courseID);

    Student* student = dynamic_cast<Student*>(person);

    if(student == nullptr){
        cout << "Δεν βρέθηκε φοιτητής με ID: " << studentID << endl;
        return;
    }

    if(course == nullptr){
        cout << "Δεν βρέθηκε μάθημα με ID: " << courseID << endl;
        return;
    }

    student->addCourse(course);
}

void Registry::unenrollStudentFromCourse(const char* studentID, const char* courseID){
    Person* person = findMember(studentID);
    Course* course = findCourse(courseID);

    Student* student = dynamic_cast<Student*>(person);

    if(student == nullptr){
        cout << "Δεν βρέθηκε φοιτητής με ID: " << studentID << endl;
        return;
    }

    if(course == nullptr){
        cout << "Δεν βρέθηκε μάθημα με ID: " << courseID << endl;
        return;
    }

    student->removeCourse(course);
}

void Registry::assignProfessorToCourse(const char* professorID, const char* courseID){
    Person* person = findMember(professorID);
    Course* course = findCourse(courseID);

    Professor* professor = dynamic_cast<Professor*>(person);

    if(professor == nullptr){
        cout << "Δεν βρέθηκε καθηγητής με ID: " << professorID << endl;
        return;
    }

    if(course == nullptr){
        cout << "Δεν βρέθηκε μάθημα με ID: " << courseID << endl;
        return;
    }

    professor->addCourse(course);
    course->setCourseManager(professor);
}

void Registry::unassignProfessorFromCourse(const char* professorID, const char* courseID){
    Person* person = findMember(professorID);
    Course* course = findCourse(courseID);

    Professor* professor = dynamic_cast<Professor*>(person);

    if(professor == nullptr){
        cout << "Δεν βρέθηκε καθηγητής με ID: " << professorID << endl;
        return;
    }

    if(course == nullptr){
        cout << "Δεν βρέθηκε μάθημα με ID: " << courseID << endl;
        return;
    }

    professor->removeCourse(course);
    //Παρατήρησα bug όπου όταν αφαιρώ οποιονδήποτε καθηγητή 
    //αυτόματα σβήνεται ο υπεύθυνος χωρίς να ήταν πάντα αυτός που έσβηνα.
    //Πολλοί καθηγητές μπορούν να διδάσκουν ένα μάθημα σύμφωνα με την εκφώνηση.
    //Ο έλεγχος στο if διορθώνει αυτό το bug.
    if(course->getCourseManager() == professor){
        course->setCourseManager(nullptr);
    }

}

void Registry::saveToCSV(const string& filename) const{
    ofstream fileOut(filename);
    if(!fileOut){
        throw 1;
    }

    for(int i = 0; i < (int)uniMembers.size(); i++){
        Student* student = dynamic_cast<Student*>(uniMembers[i]);
        if(student != nullptr){
            fileOut << "S," << student->getID() << "," << student->getName()
                    << "," << student->getGender() << "," << student->getSemester() << endl;
        }

        Professor* professor = dynamic_cast<Professor*>(uniMembers[i]);
        if(professor != nullptr){
            fileOut << "P," << professor->getID() << "," << professor->getName()
                    << "," << professor->getGender() << "," << professor->getSpecialty() << endl;
        }
    }

    for(int i = 0; i < (int)courses.size(); i++){
        fileOut << "C," << courses[i]->getID() << "," << courses[i]->getDescription()
                << "," << courses[i]->getSemester() << endl;
    }
}

void Registry::loadFromCSV(const string& filename){
    ifstream fileIn(filename);

    if(!fileIn){
        throw 1;
    }

    string line;
    while(getline(fileIn, line)){
        stringstream ss(line);
        string substr;
        vector<string> parts;
        while(getline(ss, substr, ',')){
            parts.push_back(substr);
        }

        if(parts.empty()){
            throw 2;
        }

        if(parts[0] == "S"){
            if(parts.size() != 5){
                 throw 2; 
            }
            Student* student = new Student(parts[1].c_str(), parts[2], parts[3][0], stoi(parts[4]));
            this->addMember(student);
        }else if(parts[0] == "P"){
            if(parts.size() != 5){ 
                throw 2; 
            }
            Professor* professor = new Professor(parts[1].c_str(), parts[2], parts[3][0], parts[4]);
            this->addMember(professor);
        }else if(parts[0] == "C"){
            if(parts.size() != 4){
                 throw 2; 
            }
            Course* course = new Course(parts[1].c_str(), parts[2], stoi(parts[3]), nullptr);
            this->addCourse(course);
        }else{
            throw 2;
        }
    }
}

void Registry::printAllMembers() const{
    for(int i = 0; i < (int)uniMembers.size(); i++){
        Student* student = dynamic_cast<Student*>(uniMembers[i]);
        if(student != nullptr){
            cout << "Φοιτητής: " << student->getID() << ", " << student->getName()
                 << ", " << student->getGender() << ", εξάμηνο " << student->getSemester() << endl;
        }

        Professor* professor = dynamic_cast<Professor*>(uniMembers[i]);
        if(professor != nullptr){
            cout << "Καθηγητής: " << professor->getID() << ", " << professor->getName()
                 << ", " << professor->getGender() << ", ειδικότητα: " << professor->getSpecialty() << endl;
        }
    }
}

void Registry::printAllCourses() const{
    for(int i = 0; i < (int)courses.size(); i++){
        cout << "Μάθημα: " << courses[i]->getID() << ", " << courses[i]->getDescription()
             << ", εξάμηνο " << courses[i]->getSemester() << endl;
    }
}



