#include <iostream>
#include <string>
#include "Student.h"
#include "NodeStudent.h"
#include "Schedule.h"
#include "NodeSchedule.h"
#include "Course.h"
#include "NodeCourse.h"
#include "Files.h"
#include "Processes.h"

using namespace std;

int main() {

    //Agrega Estudiante
    Student studiante1 = Student("Mario", "604710465", "1", "2");
    StudentList studiantes;
    studiantes.insertAtBeginning(studiante1);
    studiantes.printList();
    //Agregar horario
    Schedule horario1 = Schedule(1, "Martes", 1, 4, "Aula 2");
    ScheduleList horarios;
    horarios.insertAtBeginning(horario1);
    horarios.printList();
    //Agregar Curso
    Course curso1 = Course("Fundamentos", "F01", 2, "Michell", "horario1");
    CourseList cursos;
    cursos.insertAtBeginning(curso1);
    cursos.printList();
    //Escribir Archivo
    //writeFile("Students.txt", "4");


    //Guardar list en txt
    studiantes.writeStudentList();

    //Leer Archivo
    string texto = readFile("Students.txt");
    cout << texto << endl;

    //Limpiar .txt
    //clearFile("Students.txt");

    std::cout << "Hello World!\n";
    return 0;
}