#pragma once
#pragma once
#include "Student.h"
#include "Course.h"
#include "Schedule.h"
#include "Registration.h"
#include <string>

void about();
void showEnrolledStudents(Registration* registrationList, int numRegistration);
void showStudentsList(Student* studentList, int numStudent);
void showCourseList(Course* courseList, int numCourses);
void showScheduleList(Schedule* scheduleList, int numSchedule);
std::string enterText();
char enterChar();
int enterNum();
void registerStudent(Student* studentList, int& numStudents);
void enterStartEndTime(int& startTime, int& endTime);
std::string enterDay();
void registerSchedule(Schedule* scheduleList, int& numSchedules);
Schedule searchSchedule(Schedule* scheduleList, int numSchedules);
void registerCourse(Course* courseList, int& numCourse, Schedule* scheduleList, int& numSchedules);
Student searchStudent(Student* studentList, int numStudents);
Course searchCourse(Course* courseList, int numCourse);
bool checkConflict(Course* list, int index, Course course);
Course* addCoursesList(Course* courseList, int numCourse, int& index, int& totalCredits);
bool isRegistered(Registration* registrationList, int& numRegistration, std::string id);
void addRegistration(Registration* registrationList, int& numRegistration,
	Student* studentList, int numStudents, Course* courseList, int numCourse, Schedule* scheduleList, int numSchedules);

