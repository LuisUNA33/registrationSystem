#include "Student.h"

Student::Student() {}
Student::~Student() {}

Student::Student(std::string name, std::string id, std::string degree, std::string level) {
	this->name = name;
	this->id = id;
	this->degree = degree;
	this->level = level;

}

std::string Student::getName() {
	return this->name;
}
std::string Student::getId() {
	return this->id;
}
std::string Student::getDegree() {
	return this->degree;
}
std::string Student::getLevel() {
	return this->level;
}


void Student::setName(std::string name) {
	this->name = name;
}
void Student::setId(std::string id) {
	this->id = id;
}
void Student::setDegree(std::string degree) {
	this->degree = degree;
}
void Student::setLevel(std::string level) {
	this->name = level;
}

void Student::showStudent() {
	std::cout << "\nEstudiante:" << std::endl;
	std::cout << "Nombre: ";
	std::cout << this->name << std::endl;
	std::cout << "Cedula: ";
	std::cout << this->id << std::endl;
	std::cout << "Carrera: ";
	std::cout << this->degree << std::endl;
	std::cout << "Nivel: ";
	std::cout << this->level << std::endl;

}
