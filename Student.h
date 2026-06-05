#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>

class Course;


class Student : public Person{
private:
    int semester;
    std::vector<Course*> coursesAttend;

public:
    //Constructors, Assignment Operator, Destructor
    Student(const char* ID, const std::string& name);
    Student(const char* ID, const std::string& name, char gender, int semester);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    void addCourse(Course* course);
    void removeCourse(Course* course);

    void setSemester(int semester);

    int getSemester() const;
    const std::vector<Course *>&  getCoursesAttending() const;

    void sendEmail() const;

};

#endif