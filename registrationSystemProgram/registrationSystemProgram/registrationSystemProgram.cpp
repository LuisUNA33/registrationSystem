#include <iostream>
#include <limits>

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
    std::cout << "Informacion de datos precargados " << numRegistration << std::endl;
    std::cout <<"Cantidad de matriculados: " << numRegistration << std::endl;
    std::cout << "Cantidad en la lista Estudiantes: " << numStudents << std::endl;
    std::cout << "Cantidad en la lista Cursos: " << numCourses << std::endl;
    std::cout << "Cantidad en la lista Horarios: " << numSchedule << std::endl;

    menu(registrationList, numRegistration,courseList, numCourses, 
        studentList, numStudents, scheduleList, numSchedule);
    std::cout << "Fin del Programa" << std::endl;
    

    return 0;
}
