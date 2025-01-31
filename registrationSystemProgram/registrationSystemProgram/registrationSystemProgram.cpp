#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
#include "Schedule.h"
#include "Menu.h"
#include "Nodo.h"

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

    int main() {
        Nodo* lista = nullptr; // Lista enlazada vacía

        // Lista de archivos a leer
        std::string archivos[] = { "archivo.txt" };
        int numArchivos = sizeof(archivos) / sizeof(archivos[0]);

        // Leer archivos y agregar a la lista
        for (int i = 0; i < numArchivos; i++) {
            std::string contenido = leerArchivo(archivos[i]);
            if (!contenido.empty()) {
                insertarNodo(lista, contenido);
            }
        }

        // Mostrar los nodos creados
        mostrarLista(lista);

        // Inicializar estructuras de datos
        Registration* registrationList = new Registration[100];
        int numRegistration = 0;

        Student* studentList = new Student[10];
        int numStudents = 0;

        Schedule* scheduleList = new Schedule[10];
        int numSchedule = 0;

        Course* courseList = new Course[10];
        int numCourses = 0;

        // Registrar estudiante
        registerStudent(studentList, numStudents);

        // Mostrar información del estudiante registrado
        std::cout << "\nInformación del Estudiante:\n";
        for (int i = 0; i < numStudents; i++) {
            studentList[i].showStudent();
        }

        // Cargar datos precargados
        loadPreRecords(registrationList, numRegistration, courseList, numCourses, studentList, numStudents, scheduleList, numSchedule);

        std::cout << "Informacion de datos precargados " << numRegistration << std::endl;
        std::cout << "Cantidad de matriculados: " << numRegistration << std::endl;
        std::cout << "Cantidad en la lista Estudiantes: " << numStudents << std::endl;
        std::cout << "Cantidad en la lista Cursos: " << numCourses << std::endl;
        std::cout << "Cantidad en la lista Horarios: " << numSchedule << std::endl;

        // Menú principal
        menu(registrationList, numRegistration, courseList, numCourses, studentList, numStudents, scheduleList, numSchedule);

        std::cout << "Fin del Programa" << std::endl;

        // Liberar memoria
        liberarLista(lista);
        delete[] registrationList;
        delete[] studentList;
        delete[] scheduleList;
        delete[] courseList;

        return 0;
    }

