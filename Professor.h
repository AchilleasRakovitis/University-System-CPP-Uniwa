#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include "Person.h"

class Professor : public Person{
    private:
        char *profID; 
        std::string specialty;
    public:
        Professor(const char *ID, const std::string& name, int birthYear, 
            const std::string& street, const std::string& telephoneNumber, 
            const std::string& email, float height,
            const char *profID, const std::string& specialty);
        Professor(const Professor& other );
        Person * clone() const override;
        ~Professor();

        void setProfID(const char * );
        void setSpecialty(const std::string& );
        const char * getProfID() const; 
        const char * getId() const override;
        const std::string& getSpecialty() const;
        void sendEmail() const override;  // Override for Professor-specific email
};

#endif
