#pragma once
#include <iostream>
#include <fstream>
#include <string>

// Definición del nodo
struct Nodo {
    std::string contenido;
    Nodo* siguiente;

    // Constructor
    Nodo(const std::string& texto) : contenido(texto), siguiente(nullptr) {}
};

// Funciones para manipular la lista
std::string leerArchivo(const std::string& nombreArchivo);
void insertarNodo(Nodo*& cabeza, const std::string& contenido);
void mostrarLista(Nodo* cabeza);
void liberarLista(Nodo*& cabeza);

