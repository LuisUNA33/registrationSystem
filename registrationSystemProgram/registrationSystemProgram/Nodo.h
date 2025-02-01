#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Schedule.h"
#include "Course.h"
#include "Registration.h"
// Definición del nodo
// Definición del nodo genérico (si realmente lo necesitas)
struct Nodo {
    std::string contenido;
    Nodo* siguiente;

    Nodo(const std::string& texto) : contenido(texto), siguiente(nullptr) {}
};

struct StudentNode {
    Student student;
    StudentNode* next;


    StudentNode(const Student& s, StudentNode* n = nullptr) {};
};

struct ScheduleNode {
    Schedule schedule;
    ScheduleNode* next;
    ScheduleNode(const Schedule& s) : schedule(s), next(nullptr) {}
};

struct CourseNode {
    Course course;
    CourseNode* next;
    CourseNode(const Course& c) : course(c), next(nullptr) {}
};

struct RegistrationNode {
    Registration registration;
    RegistrationNode* next;
    RegistrationNode(const Registration& r) : registration(r), next(nullptr) {}
};

// Funciones para manipular la lista
std::string leerArchivo(const std::string& nombreArchivo);
void insertarNodo(Nodo*& cabeza, const std::string& contenido);
void mostrarLista(Nodo* cabeza);
void liberarLista(Nodo*& cabeza);

