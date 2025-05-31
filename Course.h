#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course{
    // attributes
private:
    char * courseID;
    std::string courseName;
    int courseSemester;
    std::string profName;

    //methods
public:
    //constructors
    Course(const char *, const std::string&, int, const std::string& );
    Course(const Course& other); // copy constructor 
    ~Course(); // destructor 
    //setters
    void setCourseID(const char * );
    void setCourseName(const std::string& );
    void setCourseSemester(int );
    void setProfName(const std::string& );
    //getters   
    const char * getCourseID() const;
    const std::string& getCourseName() const;
    int getCourseSemester() const;
    const std::string& getProfName() const;

};

#endif
