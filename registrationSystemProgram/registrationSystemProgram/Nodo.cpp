#include "Nodo.h"
// Funci�n para leer un archivo y devolver su contenido
std::string leerArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string contenido, linea;

    if (!archivo) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return "";
    }

    while (getline(archivo, linea)) {
        contenido += linea + "\n";
    }

    archivo.close();
    return contenido;
}

// Funci�n para insertar un nodo al final de la lista
void insertarNodo(Nodo*& cabeza, const std::string& contenido) {
    Nodo* nuevoNodo = new Nodo(contenido);

    if (!cabeza) {
        cabeza = nuevoNodo;
    }
    else {
        Nodo* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Funci�n para mostrar la lista
void mostrarLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp) {
        std::cout << "Contenido del nodo:\n" << temp->contenido << std::endl;
        temp = temp->siguiente;
    }
}

// Liberar memoria de la lista
void liberarLista(Nodo*& cabeza) {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}