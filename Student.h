#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Person.h"

class Student : public Person{
private:
    char *AM;
    int semester;
    int declaredCourses;

public:
    
    Student(const char *ID, const std::string& name, int birthYear, 
            const std::string& street, const std::string& telephoneNumber, 
            const std::string& email, float height,
            const char *AM, int semester, int declaredCourses);
    Student(const Student& other );
    virtual Person* clone() const override;
    ~Student();
    
    void setAM(const char * );
    void setSemester(int );
    void setDeclaredCourses(int );
    const char* getAM() const;
    const char* getId() const override;
    int getSemester() const;
    int getDeclaredCourses() const;
};

#endif