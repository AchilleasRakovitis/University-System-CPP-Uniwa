#include "ui.h"
#include <ncurses.h>
#include <cstring>
#include <vector>
#include <cstdlib>


using namespace std;

void addMemberScreen(Registry& reg){
    drawFrame("Προσθήκη Μέλους");
    
    mvprintw(3, 2, "%s", "Γράψε S για φοιτητή, P για καθηγητή: ");
    refresh();
    int type = getch();

    char* id = new char[50];
    char* name = new char[100];
    char* gender_string = new char[20];

    echo();
    curs_set(1);

    mvprintw(4, 2, "%s", "Κωδικός: ");
    getnstr(id, 49);

    mvprintw(5, 2, "%s", "Ονοματεπώνυμο: ");
    getnstr(name, 99);

    mvprintw(6, 2, "%s", "Φύλο: ");
    getnstr(gender_string, 19);

    char gender = gender_string[0];

    Person* member = reg.findMember(id);

    if(type == 'S'){
        char* semester_string = new char[10];
        mvprintw(7, 2, "%s", "Εξάμηνο Φοιτητή: ");
        getnstr(semester_string, 9);
        int semester = atoi(semester_string);

        if(member == nullptr){
            Student* student = new Student(id, name, gender, semester);
            reg.addMember(student);
        }

        delete[] semester_string;
    }else if(type == 'P'){
        char* specialty = new char[50];
        mvprintw(7, 2, "%s", "Ειδικότητα: ");
        getnstr(specialty, 49);

        if(member == nullptr){
            Professor* professor = new Professor(id, name, gender, specialty);
            reg.addMember(professor);
        }

        delete[] specialty;
    }

    noecho();
    curs_set(0);

    if(member == nullptr){
        mvprintw(10, 2, "%s", "Το μέλος έχει προστεθεί!");
    }else{
        mvprintw(10, 2, "Υπάρχει ήδη μέλος με κωδικό %s", id);
    }

    delete[] id;
    delete[] name;
    delete[] gender_string;

    refresh();
    getch();
}

void deleteMemberScreen(Registry& reg){
    drawFrame("Διαγραφή Μέλους");
    
    char* id = new char[50];

    echo();
    curs_set(1);
    
    mvprintw(3, 2, "%s", "Κωδικός μέλους προς διαγραφή: ");
    getnstr(id, 49);
    
    noecho();
    curs_set(0);

    Person* member = reg.findMember(id);

    if(member == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε κάποιο μέλος με κωδικό %s", id);
    }else{
        reg.deleteMember(id);
        mvprintw(5, 2, "%s", "Η διαγραφή του μέλους ολοκληρώθηκε επιτυχώς!");
    }

    delete[] id;

    refresh();
    getch();
}

void updateMemberScreen(Registry& reg){
    drawFrame("Ενημέρωση Στοιχείων Μέλους");

    mvprintw(3, 2, "%s", "Γράψε S για φοιτητή, P για καθηγητή: ");
    refresh();
    int type = getch();

    char* id = new char[50];
    char* name = new char[100];
    char* gender_string = new char[20];

    echo();
    curs_set(1);

    mvprintw(4, 2, "%s", "Kωδικός μέλους: ");
    getnstr(id, 49);

    mvprintw(5, 2, "%s", "Νέο όνομα μέλους: ");
    getnstr(name, 99);

    mvprintw(6, 2, "%s", "Νέο φύλο μέλους: ");
    getnstr(gender_string, 19);

    char gender = gender_string[0];

    Person* member = reg.findMember(id);
    Student* student = nullptr;
    Professor* professor = nullptr;

    if(type == 'S'){
        char* semester_string = new char[20];
        mvprintw(7, 2, "%s", "Νέο εξάμηνο: ");
        getnstr(semester_string, 19);
        int semester = atoi(semester_string);

        student = dynamic_cast<Student*>(member);
        if(student != nullptr){
            reg.updateStudent(id, name, gender, semester);
        }

        delete[] semester_string;
    }else if(type == 'P'){
        char* spec = new char[40];
        mvprintw(7, 2, "%s", "Νέα Ειδικότητα: ");
        getnstr(spec, 39);

        professor = dynamic_cast<Professor*>(member);
        if(professor != nullptr){
            reg.updateProfessor(id, name, gender, spec);
        }

        delete[] spec;
    }

    noecho();
    curs_set(0);

    if(student == nullptr && professor == nullptr){
        mvprintw(10, 2, "Δεν βρέθηκε μέλος με κωδικό %s", id);
    }else{
        mvprintw(10, 2, "%s", "Η ενημέρωση του μέλους ολοκληρώθηκε επιτυχώς!");
    }

    delete[] id;
    delete[] name;
    delete[] gender_string;

    refresh();
    getch();
}

void searchMemberScreen(Registry& reg){
    drawFrame("Αναζήτηση Μέλους");

    char* id = new char[50];

    echo();
    curs_set(1);

    mvprintw(3, 2, "%s", "Κωδικός Μέλους: ");
    getnstr(id, 49);
    
    noecho();
    curs_set(0);

    Person* member = reg.findMember(id);
    if(member == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε κάποιο μέλος με κωδικό %s", id);
    }else{
        Student* student = dynamic_cast<Student*>(member);
        if(student != nullptr){
            mvprintw(5, 2, "Φοιτητής: %s, %s, %c, εξάμηνο %d", 
                     student->getID(), student->getName().c_str(), 
                     student->getGender(), student->getSemester());
        }

        Professor* professor = dynamic_cast<Professor*>(member);
        if(professor != nullptr){
            mvprintw(5, 2, "Καθηγητής: %s, %s, %c, %s",
                     professor->getID(), professor->getName().c_str(),
                     professor->getGender(), professor->getSpecialty().c_str());
        }
    }

    delete[] id;
    refresh();
    getch();
}

void emailStudentsScreen(Registry& reg){
    drawFrame("Αποστολή email σε φοιτητές");
    reg.sendEmailToStudents();
    mvprintw(3, 2, "%s", "Τα email στάλθηκαν σε όλους τους φοιτητές!");
    refresh();
    getch();
}

void emailProfessorsScreen(Registry& reg){
    drawFrame("Αποστολή email σε καθηγητές");
    reg.sendEmailToProfessors();
    mvprintw(3, 2, "%s", "Τα email στάλθηκαν σε όλους τους καθηγητές!");
    refresh();
    getch();
}

void enrollStudentScreen(Registry& reg){
    drawFrame("Εγγραφή Φοιτητή σε Μάθημα");
    
    char* studentID = new char[50];
    char* courseID = new char[50];

    echo();
    curs_set(1);

    mvprintw(3, 2, "%s", "Κωδικός Φοιτητή: ");
    getnstr(studentID, 49);

    mvprintw(4, 2, "%s", "Κωδικός Μαθήματος: ");
    getnstr(courseID, 49);

    noecho();
    curs_set(0);

    Student* student = dynamic_cast<Student*>(reg.findMember(studentID));
    Course* course = reg.findCourse(courseID);

    if(student == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε φοιτητής με κωδικό %s", studentID);
    }else if(course == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε μάθημα με κωδικό %s", courseID);
    }else{
        reg.enrollStudentInCourse(studentID, courseID);
        mvprintw(5, 2, "%s", "Η εγγραφή ολοκληρώθηκε επιτυχώς!");
    }

    delete[] studentID;
    delete[] courseID;

    refresh();
    getch();
}

void assignProfessorScreen(Registry& reg){
    drawFrame("Ανάθεση Υπεύθυνου Καθηγητή");

    char* professorID = new char[50];
    char* courseID = new char[50];

    echo();
    curs_set(1);

    mvprintw(3, 2, "%s", "Κωδικός Καθηγητή: ");
    getnstr(professorID, 49);

    mvprintw(4, 2, "%s", "Κωδικός Μαθήματος: ");
    getnstr(courseID, 49);

    noecho();
    curs_set(0);

    Professor* professor = dynamic_cast<Professor*>(reg.findMember(professorID));
    Course* course = reg.findCourse(courseID);

    if(professor == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε καθηγητής με κωδικό %s", professorID);
    }else if(course == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε μάθημα με κωδικό %s", courseID);
    }else{
        reg.assignProfessorToCourse(professorID, courseID);
        mvprintw(5, 2, "%s", "Η ανάθεση του καθηγητή ως υπεύθυνο μαθήματος έγινε επιτυχώς!");
    }

    delete[] professorID;
    delete[] courseID;

    refresh();
    getch();
}

void showMembersScreen(Registry& reg){
    drawFrame("Εμφάνιση Μελών");

    const vector<Person*>& members = reg.getMembers();
    
    int row = 3;

    for(int i = 0; i < (int)members.size(); i++){
        Student* student = dynamic_cast<Student*>(members[i]);
        if(student != nullptr){
            mvprintw(row, 2, "Φοιτητής: %s, %s, %c, εξάμηνο %d",
                     student->getID(), student->getName().c_str(),
                     student->getGender(), student->getSemester());
            row++;
        }

        Professor* professor = dynamic_cast<Professor*>(members[i]);
        if(professor != nullptr){
            mvprintw(row, 2, "Καθηγητής: %s, %s, %c, %s",
                     professor->getID(), professor->getName().c_str(),
                     professor->getGender(), professor->getSpecialty().c_str());
            row++;
        }
    }
    refresh();
    getch();
}

void addCourseScreen(Registry& reg){
    drawFrame("Προσθήκη Μαθήματος");
    
    char* id = new char[40];
    char* description = new char[300];
    char* semester_string = new char[20];

    echo();
    curs_set(1);

    mvprintw(3, 2, "%s", "Κωδικός Μαθήματος: ");
    getnstr(id, 39);

    mvprintw(4, 2, "%s", "Περιγραφή Μαθήματος: ");
    getnstr(description, 299);

    mvprintw(5, 2, "%s", "Εξάμηνο Μαθήματος: ");
    getnstr(semester_string, 19);

    noecho();
    curs_set(0);

    int semester = atoi(semester_string);

    Course* existingCourse = reg.findCourse(id);

    if(existingCourse == nullptr){
        Course* course = new Course(id, description, semester, nullptr);
        reg.addCourse(course);
        mvprintw(7, 2, "%s", "Το μάθημα έχει προστεθεί!");
    }else{
        mvprintw(7, 2, "Υπάρχει ήδη μάθημα με κωδικό %s", id);
    }

    delete[] id;
    delete[] description;
    delete[] semester_string;

    refresh();
    getch();
}

void deleteCourseScreen(Registry& reg){
    drawFrame("Διαγραφή Μαθήματος");

    char* id = new char[50];

    echo();
    curs_set(1);

    mvprintw(3, 2, "%s", "Κώδικος μαθήματος προς διαγραφή: ");
    getnstr(id, 49);

    noecho();
    curs_set(0);

    Course* course = reg.findCourse(id);

    if(course == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε μάθημα με κωδικό %s", id);
    }else{
        reg.deleteCourse(id);
        mvprintw(5, 2, "%s", "Η διαγραφή του μαθήματος ολοκληρώθηκε επιτυχώς!");
    }

    delete[] id;

    refresh();
    getch();
}

void updateCourseScreen(Registry& reg){
    drawFrame("Ενημέρωση Μαθήματος");

    char* id = new char[50];
    char* description = new char[400];
    char* semester_string = new char[20];

    echo();
    curs_set(1);

    mvprintw(3, 2, "%s", "Κωδικός Μαθήματος: ");
    getnstr(id, 49);

    mvprintw(4, 2, "%s", "Νέα περιγραφή: ");
    getnstr(description, 399);

    mvprintw(5, 2, "%s", "Νέο εξάμηνο: ");
    getnstr(semester_string, 19);

    noecho();
    curs_set(0);

    int semester = atoi(semester_string);

    Course* course = reg.findCourse(id);

    if(course == nullptr){
        mvprintw(7, 2, "Δεν βρέθηκε μάθημα με κωδικό %s", id);
    }else{
        reg.updateCourse(id, description, semester);
        mvprintw(7, 2, "%s", "Η ενημέρωση των στοιχείων του μαθήματος ολοκληρώθηκε επιτυχώς!");
    }

    delete[] id;
    delete[] description;
    delete[] semester_string;

    refresh();
    getch();
}

void searchCourseScreen(Registry& reg){
    drawFrame("Αναζήτηση Μαθήματος");
    
    char* id = new char[50];

    echo();
    curs_set(1);

    mvprintw(3, 2, "%s", "Κωδικός μαθήματος: ");
    getnstr(id, 49);

    noecho();
    curs_set(0);

    Course* course = reg.findCourse(id);

    if(course == nullptr){
        mvprintw(5, 2, "Δεν βρέθηκε μάθημα με κωδικό %s", id);
    }else{
        mvprintw(5, 2, "Μάθημα: %s, %s, εξάμηνο %d",
                 course->getID(), course->getDescription().c_str(),
                 course->getSemester());
    }

    delete[] id;
    refresh();
    getch();
}

void showCoursesScreen(Registry& reg){
    drawFrame("Εμφάνιση Μαθημάτων");
    const vector<Course*>& courses = reg.getCourses();

    int row = 3;

    for(int i = 0; i < (int)courses.size(); i++){
        mvprintw(row, 2, "Μάθημα: %s, %s, εξάμηνο %d", courses[i]->getID(),
                 courses[i]->getDescription().c_str(), courses[i]->getSemester());
        row++;
    }
    refresh();
    getch();
}

void saveScreen(Registry& reg){
    drawFrame("Αποθήκευση σε CSV");
    try{
        reg.saveToCSV();
        mvprintw(3, 2, "%s", "Τα στοιχεία αποθηκεύτηκαν!");
    }catch(int e){
        mvprintw(3, 2, "%s", "Σφάλμα κατά την προσπάθεια αποθήκευσης!");
    }
    refresh();
    getch();
}

void loadScreen(Registry& reg){
    drawFrame("Φόρτωση από CSV");
    try{
        reg.loadFromCSV();
        mvprintw(3, 2, "%s", "Τα στοιχεία ελήφθησαν!");
    }catch(int e){
        mvprintw(3, 2, "%s", "Σφάλμα κατά την προσπάθεια λήψης των στοιχείων!");
    }
    refresh();
    getch();
}

void drawFrame(const char* title){
    clear();

    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    box(stdscr, 0, 0);
    int title_x = (cols - (int)strlen(title)) / 2;
    mvprintw(1, title_x, "%s", title);

    mvprintw(rows - 2, 2, "%s", "Πάτησε ένα πλήκτρο για επιστροφή");
}