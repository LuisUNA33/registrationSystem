#include <iostream>

#include "Student.h"
#include "Schedule.h"
#include "Course.h"
#include "Registration.h"

#include "processes.h"
#include "Menu.h"

#include "loadPreRecords.h"


int main(){
    int columns = 10;
    int rows = 10;
    Registration **registrationList=initializeArray(rows,columns);
    int recordedAmount=0;

    Student *studentList = new Student[rows+columns];
    int numStudents = 0;

    Course* courseList = new Course[10];
    int numCourses = 0;

    loadPreRecords(registrationList,recordedAmount,courseList,numCourses,studentList,numStudents);
    std::cout <<"Cantidad de matriculados previamente: " << recordedAmount << std::endl;
    std::cout << "Cantidad de Cursos creados: " << numCourses << std::endl;
    std::cout << "Cantidad de Estudiantes: " << numStudents << std::endl;
    
    menu(registrationList,rows,columns, recordedAmount, courseList, numCourses, studentList, numStudents);
    std::cout << "Fin del Programa" << std::endl;
    

    return 0;
}
