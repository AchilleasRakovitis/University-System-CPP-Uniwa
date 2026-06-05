#include "Registry.h"
#include <iostream>

using namespace std;

int main(){
    Registry reg1;

    Person* student1 = new Student("10010", "Γιάννης Γιαννάκης", 'M', 4);
    Person* student2 = new Student("10011", "Ελένη Ελενάκη", 'F', 6);
    Person* student3 = new Student("10012", "Νίκος Νικολάκης", 'M', 3);

    Person* professor1 = new Professor("10001", "Μανώλης Μανωλάκης", 'M', "Δίκτυα");
    Person* professor2 = new Professor("10002", "Σοφία Σοφιανού", 'F', "Αλγόριθμοι");
    Person* professor3 = new Professor("10003", "Κώστας Κωσταντάκης", 'M', "Βάσεις Δεδομένων");

    Course* course1 = new Course("01", "Δίκτυα: Εξάμηνο 3ο πρώτο σκέλος", 3, dynamic_cast<Professor*>(professor1));
    Course* course2 = new Course("02", "Βάσεις Δεδομένων: Εξάμηνο 5ο πρώτο σκέλος", 5, dynamic_cast<Professor*>(professor3));

    reg1.addMember(student1);
    reg1.addMember(student2);
    reg1.addMember(student3);
    reg1.addMember(professor1);
    reg1.addMember(professor2);
    reg1.addMember(professor3);
    reg1.addCourse(course1);
    reg1.addCourse(course2);


    cout << "===============================================" << endl;
    cout << "Μελη: " << endl;
    reg1.printAllMembers();
    cout << endl;
    cout << "Μαθήματα: " << endl;
    reg1.printAllCourses();
    cout << endl;
    cout << "Δοκιμή διπλότυπου ID:" << endl;
    reg1.addMember(new Student("10010", "τεστ διπλότυπου", 'M', 1));
    
    cout << "===============================================" << endl;
    cout << "Αναζήτηση Μέλους και Μαθήματος:" << endl;
    Person* p = reg1.findMember("10011");
    if(p != nullptr){
        cout << "Βρέθηκε: " << p->getName() << endl;
    }
    cout << endl;
    cout << "Προσπάθεια αναζήτησης μη υπαρκτού ID:" << endl;
    Person* pnot = reg1.findMember("100100");
    if(pnot == nullptr){
        cout << "Δεν βρέθηκε μέλος με ID = 100100" << endl;
    }

    cout << "===============================================" << endl;
    cout << "Εγγραφή φοιτητή σε μάθημα: " << endl;

    Student* student = dynamic_cast<Student*>(reg1.findMember("10010"));
    if(student != nullptr){
        cout << "Εγγεγραμμένα μαθήματα φοιτητή πριν: " << student->getCoursesAttending().size() << endl;
    }

    cout << "Εγγραφή του φοιτητή με ID: 10010 στο μάθημα με ID: 01" << endl;
    reg1.enrollStudentInCourse("10010", "01");

    if(student != nullptr){
    cout << "Εγγεγραμμένα μαθήματα μετά: " << student->getCoursesAttending().size() << endl;
    }

    cout << endl;

    cout<< "Προσπάθεια εγγραφής καθηγητή στην λίστα φοιτητή, απορρίπτεται:" << endl;
    reg1.enrollStudentInCourse("10001", "01");

    cout << endl;

    cout << "Απεγγραφή του ίδιου φοιτητή:" << endl;
    reg1.unenrollStudentFromCourse("10010", "01");
    if(student != nullptr){
        cout << "Μαθήματα μετα την απεγγραφή: " << student->getCoursesAttending().size() << endl;
    }

    cout << endl;

    cout << "===============================================" << endl;
    cout << "Aνάθεση καθηγητή σε μάθημα: " << endl;

    Professor* professor4 = new Professor("10004", "Δημήτρης Δημητράκης", 'M', "Λειτουργικά Συστήματα");
    Course* course3 = new Course("03", 3);
    reg1.addMember(professor4);
    reg1.addCourse(course3);

    const Professor* pbef = reg1.findCourse("03")->getCourseManager();
    if(pbef == nullptr){
        cout << "Το μάθημα 03 αυτή τη στιγμή δεν έχει ακόμα υπεύθυνο καθηγητή" << endl;
    }

    reg1.assignProfessorToCourse("10004", "03");

    cout << "Ανάθεση ως υπεύθυνου τον Δήμητρη Δημητράκη..." << endl;
    const Professor* paft = reg1.findCourse("03")->getCourseManager();
    if(paft != nullptr){
        cout << "Πλέον υπεύθυνος καθηγητής: " << paft->getName () << endl;
    }

    cout << endl;
    cout << "Αφαίρεση του ίδιου καθηγητή απο υπεύθυνο:" << endl;
    reg1.unassignProfessorFromCourse("10004", "03");

    const Professor* paft2 = reg1.findCourse("03")->getCourseManager();
    if(paft2 == nullptr){
        cout << "Το μάθημα δέν έχει ξανά υπεύθυνο καθηγητή" << endl;
    }

    cout << endl;

    cout << "===============================================" << endl;
    cout << "Αποστολή email σε κάθε φοιτητή: " << endl;
    reg1.sendEmailToStudents();
    
    cout << endl;

    cout << "Αποστολή email σε κάθε καθηγητή: " << endl;
    reg1.sendEmailToProfessors();

    cout << endl;

    cout << "===============================================" << endl;
    cout << "Διαγραφή καθηγητή που είναι υπεύθυνος μαθήματος: " << endl;

    const Professor* pbef2 = reg1.findCourse("01")->getCourseManager();
    if(pbef2 != nullptr){
        cout << "Πριν την διαγραφή, υπεύθυνος του μαθήματος είναι ο: " << pbef2->getName() << endl;
    }

    reg1.deleteMember("10001");
    
    const Professor* paft3 = reg1.findCourse("01")->getCourseManager();
    if(paft3 == nullptr){
        cout << "Μετά την διαγραφή, το μάθημα με ID: 01 δεν έχει πλέον υπεύθυνο καθηγητή!" << endl;
    }

    cout << endl;
    cout << "===============================================" << endl;
    cout << "Διαγραφή μαθήματος στο οποίο είναι εγγεγραμμένος φοιτητής:" << endl;

    cout << "Η ελένη εγγράφεται στο μάθημα Βάσεις Δεδομένων: " << endl;
    reg1.enrollStudentInCourse("10011", "02");

    Student* st = dynamic_cast<Student*>(reg1.findMember("10011"));
    if(st != nullptr){
        cout << "Μαθήματα της Ελένης πριν την διαγραφή: " << st->getCoursesAttending().size() << endl;
        const vector<Course*>& list = st->getCoursesAttending();
        for(int i = 0; i < (int)list.size(); i++){
            cout << "  - " << list[i]->getID() << ", " << list[i]->getDescription() << endl;
        }
    }

    reg1.deleteCourse("02");

    if(st != nullptr){
        const vector<Course*>& list = st->getCoursesAttending();
        cout << "Μαθήματα μετά τη διαγραφή (" << list.size() << "):" << endl;
        for(int i = 0; i < (int)list.size(); i++){
            cout << "  - " << list[i]->getID() << ", " << list[i]->getDescription() << endl;
        }
        if(list.size() == 0){
            cout << "Κανένα...  Η λίστα είναι άδεια" << endl;
        }
    }

    cout << endl;
    cout << "===============================================" << endl;
    
    cout << "Αποθήκευση και ανάκτηση πληροφορίας απο αρχεία CSV: " << endl;

    try{
        reg1.saveToCSV("registry.csv");
        cout << "Η πληροφορία του φοιτητολογίου αποθηκεύτηκε στο αρχείο!" << endl;

        Registry reg2;
        reg2.loadFromCSV("registry.csv");
        cout << "Μέλη Φοιτητολογίου που ανακτήθηκαν και απο τα οποία θα φτιαχτεί νεο Registry Object:" << endl;
        reg2.printAllMembers();
        cout << "Μαθήματα Φοιτητολογίου που ανακτήθηκαν και απο τα οποία θα φτιαχτεί νεο Registry Object:" << endl;
        reg2.printAllCourses();
    }catch(int e){
        cerr << "Σφάλμα: " << e << endl;
    }

    cout << "===============================================" << endl;
    cout << "Ενημέρωση Στοιχείων μελών και μαθημάτων: " << endl;

    Student* stud = dynamic_cast<Student*>(reg1.findMember("10012"));
    if(stud != nullptr){
        cout << "Πριν: " << stud->getName() << ", " << stud->getGender()
             << ", εξάμηνο " << stud->getSemester() << endl;
    }

    reg1.updateStudent("10012", "Πέτρος Πέτρου", 'M', 10);

    if(stud != nullptr){
        cout << "Μετά: " << stud->getName() << ", " << stud->getGender()
             << ", εξάμηνο " << stud->getSemester() << endl;
    }

    cout  << endl;

    Professor* proff = dynamic_cast<Professor*>(reg1.findMember("10002"));
    if(proff != nullptr){
        cout << "Πριν: " << proff->getName() << ", " << proff->getSpecialty() << endl;
    }

    reg1.updateProfessor("10002", "Μαρια Μαρ", 'F', "Ρομποτική");

    if(proff != nullptr){
        cout << "Μετά: " << proff->getName() << ", " << proff->getSpecialty() << endl;
    }

    cout << endl;

    Course* cours = reg1.findCourse("01");
    if(cours != nullptr){
        cout << "Πριν: " << cours->getDescription() << ", εξάμηνο " << cours->getSemester() << endl;
    }

    reg1.updateCourse("01", "Λειτουργικά Συστήματα ΙΙ", 4);

    if(cours != nullptr){
        cout << "Μετά: " << cours->getDescription() << ", εξάμηνο " << cours->getSemester() << endl;
    }

    cout << endl;

    cout << "Προσπάθεια διόρθωσης φοιτητή με ID καθηγητή: " << endl;
    reg1.updateStudent("10003", "......", 'M', 2);

    return 0;
}

