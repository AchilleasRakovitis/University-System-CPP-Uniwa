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
    Person* clone() const override; // Για πολυμορφισμό στον copy constructor του φοιτητολογίου
    ~Student();
    
    void setAM(const char * );
    void setSemester(int );
    void setDeclaredCourses(int );
    const char* getAM() const;
    const char* getId() const override; // για πολυμορφισμό - να επιστρέψει ΑΜ 
    int getSemester() const;
    int getDeclaredCourses() const;
    void sendEmail() const override;  // Override for Student-specific email
};

#endif