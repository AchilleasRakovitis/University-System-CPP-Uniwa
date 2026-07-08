    #include <ncurses.h>
    #include "Registry.h"
    #include "ui.h"
    #include <clocale>
    #include <cstring>

    int main(){
        setlocale(LC_ALL, "");
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);

        Registry reg;

        const char* menu_options[] ={
            "Προσθήκη Μέλους",
            "Διαγραφή Μέλους",
            "Ενήμερωση Στοιχείων Μέλους",
            "Ενημέρωση Στοιχείων Μαθήματος",
            "Αναζήτηση Μέλους",
            "Ανάζητηση Μαθήματος",
            "Αποστολή email σε Φοιτητές",
            "Αποστολή email σε καθηγητές",
            "Εγγραφή Φοιτητή σε Μάθημα",
            "Ανάθεση Υπεύθυνου Καθηγητή σε Μάθημα",
            "Εμφάνιση μελών",
            "Προσθήκη Μαθήματος",
            "Διαγραφή Μαθήματος",
            "Eμφάνιση Μαθημάτων", 
            "Αποθήκευση των Στοιχείων σε αρχεία CSV",
            "Φόρτωση Στοιχείων από CSV Αρχεία",
            "Έξοδος"
        };

        int n = 17;
        int choice = 0;
        int key;

        while(true){
        clear();
        refresh();
        int rows, cols;
        getmaxyx(stdscr, rows, cols);

        int box_h = n + 4;
        int box_w = 45;

        int box_y = (rows - box_h) / 2;
        int box_x = (cols - box_w) / 2;
        if(box_y < 0){ box_y = 0; }
        if(box_x < 0){ box_x = 0; }

        WINDOW* menu_win = newwin(box_h, box_w, box_y, box_x);
        box(menu_win, 0, 0);

        const char* title = "ΦΟΙΤΗΤΟΛΟΓΙΟ";
        int title_x = (box_w - (int)strlen(title)) / 2;
        wattron(menu_win, A_BOLD);
        mvwprintw(menu_win, 1, title_x, "%s", title);
        wattroff(menu_win, A_BOLD);

        for(int i = 0; i < n; i++){
            int item_y = 3 + i;
            int item_x = 2;

            if(i == choice){
                wattron(menu_win, A_REVERSE);
            }
            mvwprintw(menu_win, item_y, item_x, "%s", menu_options[i]);
            if(i == choice){
                wattroff(menu_win, A_REVERSE);
            }
        }

        wrefresh(menu_win);
        delwin(menu_win);

            key = getch();
            switch (key){
            case KEY_UP:
                choice--;
                if(choice < 0){
                    choice = n - 1;
                }
                break;
            case KEY_DOWN:
                choice++;
                if(choice >= n){
                    choice = 0;
                }
                break;
            case '\n':
                if(choice == 0) addMemberScreen(reg);
                else if(choice == 1) deleteMemberScreen(reg);
                else if(choice == 2) updateMemberScreen(reg);
                else if(choice == 3) updateCourseScreen(reg);
                else if(choice == 4) searchMemberScreen(reg);
                else if(choice == 5) searchCourseScreen(reg);
                else if(choice == 6) emailStudentsScreen(reg);
                else if(choice == 7) emailProfessorsScreen(reg);
                else if(choice == 8) enrollStudentScreen(reg);
                else if(choice == 9) assignProfessorScreen(reg);
                else if(choice == 10) showMembersScreen(reg);
                else if(choice == 11) addCourseScreen(reg);
                else if(choice == 12) deleteCourseScreen(reg);
                else if(choice == 13) showCoursesScreen(reg);
                else if(choice == 14) saveScreen(reg);
                else if(choice == 15) loadScreen(reg);
                // choice == 16 (Έξοδος) -> handled by break check below
                break;
            }

            if(key == '\n' && choice == n - 1){
                break;
            }
        }

        endwin();
        return 0;
    }

