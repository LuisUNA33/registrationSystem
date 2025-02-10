#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "NodeStudent.h"
#include "Schedule.h"
#include "NodeSchedule.h"
#include "Course.h"
#include "NodeCourse.h"
#include "Group.h"
#include "NodeGroup.h"

#include "Requirement.h"
#include "NodeRequirement.h"

#include "ApprovedCourse.h"
#include "NodeApprovedCourse.h"

#include "Files.h"
#include "Processes.h"



int main() {
    //clearFile("Students.txt");
    
    //Agrega Estudiante
    StudentList students;
	ScheduleList schedules;
    CourseList courses;
    GroupList groups;
    RequirementList requirements;
    ApprovedCourseList approvedCourses;

    //txt->lista
    students.loadStudentList(students);
    //students.printList();
    schedules.loadScheduleList(schedules);
    //schedules.printList();
    courses.loadCourseList(courses);
    //courses.printList();
    groups.loadGroupList(groups);
    //groups.printList();
    requirements.loadRequirementList(requirements); 
    //requirements.printList();
    approvedCourses.loadApprovedCourseList(approvedCourses);
    //approvedCourses.printList();

	//registerStudent(students);
	//registerSchedule(schedules);
    //registerCourse(courses);
    //registerGroup(groups);
    //registerRequeriment(requirements);
    //registerApprovedCourse(approvedCourses);

    //list->txt
    clearFile("Students.txt");
    clearFile("Schedules.txt");
    clearFile("Courses.txt");
    clearFile("Groups.txt");
    clearFile("Requirements.txt");
    clearFile("ApprovedCourses.txt");
    students.writeStudentList();
    schedules.writeScheduleList();
    courses.writeCourseList();
    groups.writeGroupList();
    requirements.writeRequirementList();
    approvedCourses.writeApprovedCourseList();


    //Limpiar .txt
    //clearFile("Students.txt");

    std::cout << "Hello World!\n";
    return 0;
}
