#ifndef REGISTRY_H
#define REGISTRY_H

#include "Person.h"
#include "Course.h"
#include "Professor.h"
#include "Student.h"
#include <vector>
#include <string>

class Registry{
private:
    std::vector<Person* > uniMembers;
    std::vector<Course* > courses;
public:
    Registry();
    ~Registry();
    Registry(const Registry& other) = delete;
    Registry& operator=(const Registry& other) = delete;
    void addMember(Person* member);
    void addCourse(Course* course);
    void deleteMember(const char* ID);
    void deleteCourse(const char* ID);
    void updateStudent(const char* ID, const std::string& newName, char newGender, int newSemester);
    void updateProfessor(const char* ID, const std::string& newName, char newGender, const std::string& newSpecialty);
    void updateCourse(const char* ID, const std::string& newDescription, int newSemester);
    void sendEmailToStudents() const;
    void sendEmailToProfessors() const;
    Person* findMember(const char* ID ) const;
    Course* findCourse(const char* ID) const;
    void enrollStudentInCourse(const char* studentID, const char* courseID);
    void unenrollStudentFromCourse(const char* studentID, const char* courseID);
    void assignProfessorToCourse(const char* professorID, const char* courseID);
    void unassignProfessorFromCourse(const char* professorID, const char* courseID);
    void saveToCSV() const;
    void loadFromCSV();
    void printAllMembers() const;
    void printAllCourses() const;
    const std::vector<Person*>& getMembers() const;
    const::std::vector<Course*>& getCourses() const;
};

#endif
