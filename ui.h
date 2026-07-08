#ifndef UI_H
#define UI_H

#include "Registry.h"

void addMemberScreen(Registry& reg);
void deleteMemberScreen(Registry& reg);
void updateMemberScreen(Registry& reg);
void searchMemberScreen(Registry& reg);
void emailStudentsScreen(Registry& reg);
void emailProfessorsScreen(Registry& reg);
void enrollStudentScreen(Registry& reg);
void assignProfessorScreen(Registry& reg);
void showMembersScreen(Registry& reg);
void addCourseScreen(Registry& reg);
void deleteCourseScreen(Registry& reg);
void updateCourseScreen(Registry& reg);
void searchCourseScreen(Registry& reg);
void showCoursesScreen(Registry& reg);
void saveScreen(Registry& reg);
void loadScreen(Registry& reg);
void drawFrame(const char* title);

#endif