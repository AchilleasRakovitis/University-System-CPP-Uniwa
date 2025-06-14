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
        Registry(const Registry&);
        ~Registry();

        // add methods
        void addPerson(Person*);
        void addCourse(Course*);

        // delete methods
        bool deletePerson(const char*);
        bool deleteCourse(const char*);

        //update methods
        bool updatePerson(const char*, const std::string&, int, const std::string&, const std::string&, const std::string&, float);
        bool updateCourse(const char*, const std::string&, int, const std::string&);        //send email method
        void sendEmailToAll();

        bool addGrade(const char*, float, const char*);
        bool updateGrade(const char*, float, const char*);
        
        //save to CSV files
        bool savePeopleToCSV(const std::string&) const;
        bool saveCoursesToCSV(const std::string&) const;
        bool saveGradesToCSV(const std::string&) const;
        bool loadPeopleFromCSV(const std::string&);
        bool loadCoursesFromCSV(const std::string&);
        bool loadGradesFromCSV(const std::string&);
};

#endif