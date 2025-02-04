#include "Registration.h"

Registration::Registration() {}
Registration::~Registration() {}

Registration::Registration(string code, string codStudent, string anio, string ciclo) {
	this->code = code;
	this->codStudent = codStudent;
	this->anio = anio;
	this->ciclo = ciclo;
}

string Registration::getCode() {
	return this->code;
}
string Registration::getCodeStudent(){
	return this->codStudent;
}
string Registration::getAnio(){
	return this->anio;
}
string Registration::getCiclo(){
	return this->ciclo;
}

void Registration::setCode(string code) {
	this->code = code;
}
void Registration::setCodeStudent(string codStudent){
	this->codStudent = codStudent;
}
void Registration::setAnio(string anio){
	this->anio = anio;
}
void Registration::setCiclo(string ciclo){
	this->ciclo = ciclo;
}

void Registration::showRegistration(){
	std::cout << "\nMatricula:" << std::endl;
	std::cout << "Codigo de matricula: ";
	std::cout << this->code << std::endl;
	std::cout << "Codigo Estudiante: ";
	std::cout << this->codStudent << std::endl;
	std::cout << "Anio: ";
	std::cout << this->anio << std::endl;
	std::cout << "Ciclo: ";
	std::cout << this->ciclo << std::endl;
}