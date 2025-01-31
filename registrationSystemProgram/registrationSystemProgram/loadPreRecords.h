#pragma once
#include "Student.h"
#include "Course.h"
#include "Schedule.h"
#include "Registration.h"

void loadPreRecords(Registration* registrationList, int& numRegistration,
	Course* courseList, int& numCourse,
	Student* studentList, int& numStudents,
	Schedule* scheduleList, int& numSchedule);
