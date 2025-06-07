#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
    // attributes
private:
    char *ID;
    std::string name;
    int birthYear;
    std::string street;
    std::string telephoneNumber;
    std::string email;
    float height; 
    // prototypes of class methods 
public:
    // general constructors 
    Person(const char *, const std::string&, int, const std::string&, const std::string&, const std::string&, float); 
    Person(const std::string&, int, float);
    Person(const std::string&, const std::string&, const std::string&, const std::string& );
    
    Person(const Person& other); // copy constructor 
    virtual ~Person(); //destructor 
    virtual Person* clone() const;

    //setters
    void setID(const char *);
    void setName(const std::string& );
    void setBirthYear(int );
    void setStreet(const std::string& );
    void setTelephoneNumber(const std::string& );
    void setEmail(const std::string& );
    void setHeight(float);
    //getters
    const char* getId() const;
    const std::string& getName() const;
    int getBirthYear() const;
    const std::string& getStreet() const;
    const std::string& getTelephoneNumber() const;
    const std::string& getEmail() const;
    float getHeight() const;
    //general methods
    int returnAge() const;
    
};

#endif
