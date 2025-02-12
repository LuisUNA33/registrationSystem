#ifndef PROCESSES_H   
#define PROCESSES_H 
#include <iostream>
#include <string>
#include <limits>
#include <random>

#include "NodeStudent.h"
#include "NodeSchedule.h"
#include "NodeCourse.h"
#include "NodeGroup.h"
#include "NodeRequirement.h"
#include "NodeApprovedCourse.h"
#include "NodeRegistration.h"
#include "NodeRegistrationDetails.h"
void about();
std::string enterText();
char enterChar();
int enterNum();
string  enterStudent(StudentList students);
void registerStudent(StudentList& studentList);
void enterStartEndTime(int& startTime, int& endTime);
std::string enterDay();
void registerSchedule(ScheduleList& scheduleList);

void registerGroup(GroupList& groupList, string codCourse);
void registerCourse(CourseList& coursesList,GroupList& groupList, RequirementList& requirementList);

void registerGroup(GroupList& groups);
void registration(RegistrationList& registrations, StudentList students);
void registerRequeriment(RequirementList& requirementList);
void registerApprovedCourse(ApprovedCourseList& approvedCourseList);
void registerRegistration(RegistrationDetailsList& registrationDetails, RegistrationList& registrations,
	StudentList students, ScheduleList schedules,
	CourseList courses, GroupList groups,
	RequirementList requirements, ApprovedCourseList approvedCourses);
void ShowCoursesGroup(CourseList courses, GroupList groups);
void showRegistration(RegistrationList registrations, RegistrationDetailsList registrationDestails);
int getRandomNumber();

#endif
