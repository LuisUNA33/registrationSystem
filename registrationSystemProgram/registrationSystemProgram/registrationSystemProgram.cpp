#include <iostream>

#include "Student.h"
#include "Schedule.h"
#include "Course.h"
#include "Registration.h"

#include "processes.h"
#include "Menu.h"

#include "loadPreRecords.h"


int main(){
    
    Registration *registrationList= new Registration[100];
    int numRegistration=0;

    Student *studentList = new Student[10];
    int numStudents = 0;

    Schedule* scheduleList = new Schedule[10];
    int numSchedule = 0;

    Course* courseList = new Course[10];
    int numCourses = 0;

    loadPreRecords(registrationList,numRegistration,
        courseList,numCourses,
        studentList,numStudents,
        scheduleList, numSchedule);
    std::cout <<"Cantidad de matriculados previamente: " << numRegistration << std::endl;
    std::cout << "Cantidad de Cursos creados: " << numCourses << std::endl;
    std::cout << "Cantidad de Estudiantes: " << numStudents << std::endl;

    //scheduleList[0].showSchedule();
    
    menu(registrationList, numRegistration,courseList, numCourses, 
        studentList, numStudents, scheduleList, numSchedule);
    std::cout << "Fin del Programa" << std::endl;
    

    return 0;
}
