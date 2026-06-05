#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
protected:
    char* ID;
    std::string name;
    char gender;

public:
    //Constructors, Assignment operator, Destructor
    Person(const char* ID, const std::string& name, char gender);
    Person(const char* ID, const std::string& name);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();

    //Setters
    void setID(const char* ID);
    void setName(const std::string& name);
    void setGender(char gender);

    //Getters
    const char* getID() const;
    const std::string& getName() const;
    char getGender() const;

    //το προσθέτω απλά για να δείξω το concept του πολυμορφισμού
    // θα χρησιμοποιήσω dynamic_cast εν τέλει
    virtual void sendEmail() const;
};

#endif