#ifndef COURSE_H
#define COURSE_H

#include <string>

class Professor;

class Course{
private:
    char* ID;
    std::string description;
    int semester;
    const Professor* courseManager;
public:
    //Constructors, Assignment operator, Destructor
    Course(const char* ID, const std::string& description, int semester, const Professor* courseManager);
    Course(const char* ID, int semester);
    Course(const Course& other);
    Course& operator=(const Course& other);
    ~Course();

    //Setters
    void setID(const char* ID);
    void setDescription(const std::string& description);
    void setSemester(int semester);
    void setCourseManager(const Professor* courseManager);

    //Getters
    const char* getID() const;
    const std::string& getDescription() const;
    int getSemester() const;
    const Professor* getCourseManager() const;
};

#endif