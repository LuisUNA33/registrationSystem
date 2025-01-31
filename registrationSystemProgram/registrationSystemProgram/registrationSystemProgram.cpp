#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
#include "Schedule.h"
#include "Menu.h"


//
//std::string* cargarTextoLista(int size,std::string nombreArchivo){
//    std::string name;
//    std::string code;
//    int credits;
//    std::string teacher;
//    Schedule schedule;
//
//    std::string* fragmentos=new std::string[size];
//
//    std::string cadena = leerArchivo(nombreArchivo);
//    int index=0;
//    int inicio = 0;
//    for (size_t i = 0; i < cadena.size(); ++i) {
//        if (cadena[i] == ';') {
//            fragmentos[index] = cadena.substr(inicio, i-inicio);
//            inicio =i+1;
//            index++;
//        }
//    }
//    
//    return fragmentos;
//    
//}

int main(){
  /*  string* lista= cargarTextoLista(7,"Courses.txt");
    for (int x = 0; x < 7; x++) {
        std::cout << lista[x] << std::endl;
    }*/
    //crearArhivotxt("pruebav2");
    //agregarLineaArchivotxt("pruebav2","fin");
    //
    //std::cout<< leerArchivo("pruebav2")<<std::endl;
    ///***
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
