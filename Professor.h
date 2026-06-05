#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include <string>
#include <vector>

class Course;

class Professor : public Person{
private:
    std::string specialty;
    std::vector<Course* > coursesTeaching;

public:
    Professor(const char* ID, const std::string& name, char gender, const std::string& specialty);
    Professor(const char* ID, const std::string& name);
    Professor(const Professor& other);
    Professor& operator=(const Professor& other);
    ~Professor();

    void setSpecialty(const std::string& specialty);
    void addCourse(Course* course);
    void removeCourse(Course* course);

    const std::string& getSpecialty() const;
    const std::vector<Course* >& getCoursesTeaching() const;

    void sendEmail() const;
};

#endif