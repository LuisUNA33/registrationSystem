#include "Registration.h"

Registration::Registration() {}
Registration::~Registration() {}

Registration::Registration(string code, string codStudent, string year, string semester) {
	this->code = code;
	this->codStudent = codStudent;
	this->year = year;
	this->semester = semester;
}

string Registration::getCode() {
	return this->code;
}
string Registration::getCodeStudent(){
	return this->codStudent;
}
string Registration::getYear(){
	return this->year;
}
string Registration::getSemester(){
	return this->semester;
}

void Registration::setCode(string code) {
	this->code = code;
}
void Registration::setCodeStudent(string codStudent){
	this->codStudent = codStudent;
}
void Registration::setYear(string year){
	this->year = year;
}
void Registration::setSemester(string semester){
	this->semester = semester;
}

void Registration::showRegistration(){
	std::cout << "\nMatricula:" << std::endl;
	std::cout << "Codigo de matricula: ";
	std::cout << this->code << std::endl;
	std::cout << "Codigo Estudiante: ";
	std::cout << this->codStudent << std::endl;
	std::cout << "Anio: ";
	std::cout << this->year << std::endl;
	std::cout << "Ciclo: ";
	std::cout << this->semester << std::endl;
}
