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

#include "Files.h"
#include "Processes.h"

int main() {
    //clearFile("Students.txt");
    
    //Agrega Estudiante
    StudentList students;
	ScheduleList schedules;
    CourseList courses;
    
    //txt->lista
    students.loadStudentList(students);
    students.printList();
    schedules.loadScheduleList(schedules);
    schedules.printList();
    courses.loadCourseList(courses);
    courses.printList();

	//registerStudent(students);
	//registerSchedule(schedules);
    //registerCourse(courses);

    //list->txt
    clearFile("Students.txt");
    clearFile("Schedules.txt");
    clearFile("Courses.txt");
    students.writeStudentList();
    schedules.writeScheduleList();
    courses.writeCourseList();


    //Limpiar .txt
    //clearFile("Students.txt");

    std::cout << "Hello World!\n";
    return 0;
}
