#ifndef REGISTRY_H
#define REGISTRY_H

#include <vector>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"

class Registry{
    private:
        std::vector<Person *> uniMembers;
        std::vector<Course *> courses;
        
    public:
        Registry();
        Registry(const Registry& other);
        ~Registry();

        // add methods
        void addPerson(Person* person);
        void addCourse(Course* course);

        // delete methods
        bool deletePerson(const char *ID);
        bool deleteCourse(const char *courseID);

        //update methods
        bool updatePerson(const char *ID, Person *newPerson);
        bool updateCourse(const char *courseID, Course *newCourse);

        //send email methods
        bool sendEmailToAllProfessors(std::string& email);
        bool sendEmailToAllStudents(std::string& email);

        bool addGrade(const char *AM, float grade, const char *courseID);
        bool updateGrade(const char*AM, float updatedGrade, const char *courseID);
        
        //save to CSV files
        bool savePeopleToCSV(const std::string& csvfile) const;
        bool saveCoursesToCSV(const std::string& csvfile) const;
        bool saveGradesToCSV(const std::string& csvfile) const;

        //load from CSV files
        bool loadPeopleFromCSV(const std::string& csvfile);
        bool loadCoursesFromCSV(const std::string& csvfile);
        bool loadGradesFromCSV(const std::string& csvfile);
};


#endif