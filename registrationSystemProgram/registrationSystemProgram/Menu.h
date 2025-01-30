#pragma once
#include <iostream>
#include "Student.h"
#include "Schedule.h"
#include "Course.h"
#include "Registration.h"
#include "processes.h"
#include "Menu.h"
#include "loadPreRecords.h"


#include "MethodStatement.h"
bool subMenuA();
void subMenuB(Course* courseList, int& numCourse, Student* studentList, int& numStudents, Schedule* scheduleList, int& numSchedules);
void subMenuC(Registration* registrationList, int& numRegistration, Student* studentList, int numStudents, Course* courseList, int numCourse, Schedule* scheduleList, int numSchedules);
void subMenuD(Registration* registrationList, int numRegistration,Course* courseList, int numCourse,Student* studentList, int numStudents,Schedule* scheduleList, int numSchedules);
void menu(Registration* registrationList, int& numRegistration, Course* courseList, int& numCourse, Student* studentList, int& numStudents, Schedule* scheduleList, int& numSchedules);
	
