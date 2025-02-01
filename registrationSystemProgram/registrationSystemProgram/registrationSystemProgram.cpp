#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
#include "Schedule.h"
#include "Menu.h"
#include "Nodo.h"
#include "Student.h"


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

        menu(registrationList,courseList,studentList,scheduleList);

        std::cout << "Fin del Programa" << std::endl;

        // Liberar memoria
        liberarLista(lista);
        delete[] registrationList;
        delete[] studentList;
        delete[] scheduleList;
        delete[] courseList;

        return 0;
    }

