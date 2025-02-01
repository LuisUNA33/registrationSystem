#pragma once
#include <iostream>
#include "Student.h"
#include "Schedule.h"
#include "Course.h"
#include "Registration.h"
#include "processes.h"
#include "Menu.h"
#include "loadPreRecords.h"
#include "Nodo.h"

#include "MethodStatement.h"
bool subMenuA();
void subMenuB(CourseNode*& courseList, StudentNode*& studentList, ScheduleNode*& scheduleList);
void subMenuC(RegistrationNode*& registrationList, StudentNode*& studentList,CourseNode*& courseList, ScheduleNode*& scheduleList);
void subMenuD(RegistrationNode*& registrationList, CourseNode*& courseList,StudentNode*& studentList, ScheduleNode*& scheduleList);
void menu(RegistrationNode*& registrationList, CourseNode*& courseList, StudentNode*& studentList, ScheduleNode*& scheduleList);
