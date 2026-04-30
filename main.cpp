#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Registry.h"

using namespace std;

int main(){

//φτιάχνω ένα registry object
Registry reg1;

//Δημιουργία αντικειμένων Person με τυχαίες τιμές-παραδείγματα
Person* person1 = new Person("ΑΑ23Μ", "Μαρία Χ.", 2002, "Αιγάλεω", "69232323", "maria@gmail.com", 1.56);
Person* student1 = new Student("ΓΔ05Π", "Νίκος Π.", 2003, "Περιστέρι", "69121212", "nikos@example.com", 1.78, "19390300", 4, 5);
Person* professor1 = new Professor("ΚΛ30Ζ", "Ελένη Κ.", 1975, "Χαλάνδρι", "69454545", "eleni.k@university.gr", 1.65, "20001", "Πληροφορική");

//Προσθήκη των αντικειμένων στο vector uniMembers
reg1.addPerson(person1);
reg1.addPerson(student1);
reg1.addPerson(professor1);

// Δημιουργία νέου Student αντικειμένου
Person* student2 = new Student("ΕΖ08Ρ", "Άννα Β.", 2004, "Κηφισιά", "69777777", "anna.v@example.com", 1.62, "2024001", 2, 3);
reg1.addPerson(student2); 

//Δημιουργία αντικειμένων Course με τυχαίες τιμές-παραδείγματα
Course* course1 = new Course("ΜΑΘ101", "Διακριτά Μαθηματικά", 1, "Ελένη Κ.", 0.0f);
Course* course2 = new Course("ΠΛΗ202", "Δομές Δεδομένων", 3, "Γιάννης Α.", 1.0f);
Course* course3 = new Course("ΦΥΣ303", "Κβαντική Φυσική", 5, "Μιχάλης Π.", 5.6f);

//Προσθήκη των αντικειμένων στο vector courses
reg1.addCourse(course1);
reg1.addCourse(course2);
reg1.addCourse(course3);

bool peopleSaved = reg1.savePeopleToCSV("example.csv");
bool retrv = reg1.loadDataFromCSV("example.csv");



reg1.sendEmailToAll();

}
