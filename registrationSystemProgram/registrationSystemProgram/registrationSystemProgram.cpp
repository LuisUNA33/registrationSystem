#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "NodeStudent.h"
#include "Schedule.h"
#include "NodeSchedule.h"
#include "Course.h"
#include "NodeCourse.h"
#include "Files.h"
#include "Processes.h"

int main() {
    //clearFile("Students.txt");
    
    //Agrega Estudiante
    StudentList students;
    /*Student studiante1 = Student("Juan","687875", "12", "100");
    Student studiante2 = Student("Fili", "687875", "12", "100");
    studiantes.insertAtBeginning(studiante1);
    studiantes.insertAtBeginning(studiante2);
    studiantes.printList();*/
    
    //Agregar horario
    /*Schedule horario1 = Schedule(1, "Martes", 1, 4, "Aula 2");
    ScheduleList horarios;
    horarios.insertAtBeginning(horario1);
    horarios.printList();*/

    //Agregar Curso
   /* Course curso1 = Course("Fundamentos", "F01", 2, "Michell", "horario1");
    CourseList cursos;
    cursos.insertAtBeginning(curso1);
    cursos.printList();*/

    //txt->lista
    students.loadStudentList(students);
    students.printList();

    registerStudent(students);

    //list->txt
    clearFile("Students.txt");

    //Limpiar .txt
    //clearFile("Students.txt");

    std::cout << "Hello World!\n";
    return 0;
}
