#ifndef PROCESSES_H   
#define PROCESSES_H 
#include <iostream>
#include <string>
#include <limits>

void about();
//void showEnrolledStudents(RegistrationNode*& registrationList);
//void showStudentsList(const StudentNode* studentList);
//void showCourseList(const CourseNode* courseList);
//void showScheduleList(const ScheduleNode* scheduleList);
std::string enterText();
char enterChar();
int enterNum();
//void registerStudent(StudentNode*& studentList);
void enterStartEndTime(int& startTime, int& endTime);
std::string enterDay();
//void registerSchedule(ScheduleNode*& scheduleList);
//Schedule searchSchedule(const ScheduleNode* scheduleList);
//void registerCourse(CourseNode*& courseList, ScheduleNode*& scheduleList);
//Student searchStudent(const StudentNode* studentList);
//Course searchCourse(const CourseNode* courseList);
//bool checkConflict(const CourseNode* list, int index, Course course);
//Course* addCoursesList(const CourseNode* courseList, int numCourse, int& index, int& totalCredits);
//bool isRegistered(const RegistrationNode* registrationList, int& numRegistration, std::string id);
//void addRegistration(RegistrationNode*& registrationList, StudentNode*& studentList, CourseNode*& courseList, ScheduleNode*& scheduleList);

#endif