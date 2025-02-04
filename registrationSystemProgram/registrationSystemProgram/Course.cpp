#include "Course.h"
Course::Course() {}
Course::~Course() {}

Course::Course(std::string name, std::string code, int credits, std::string teacher, std::string codSchedule) {
	this->name = name;
	this->code = code;
	this->credits = credits;
	this->codTeacher = teacher;
	this->codSchedule = codSchedule;

}

std::string Course::getName() {
	return this->name;
}
std::string Course::getCode() {
	return this->code;
}
int Course::getCredits() {
	return this->credits;
}
std::string Course::getTeacher() {
	return this->codTeacher;
}
std::string Course::getSchedule() {
	return this->codSchedule;
}

//int Course::getStartTime() {
//	return this->schedule.getStartTime();
//}
//int Course::getEndTime() {
//	return this->schedule.getEndTime();
//}

void Course::setName(std::string name) {
	this->name = name;
}
void Course::setCode(std::string code) {
	this->code = code;
}
void Course::setCredits(int credits) {
	this->credits = credits;
}
void Course::setTeacher(std::string codTeacher) {
	this->name = codTeacher;
}
void Course::setSchedule(std::string codSchedule) {
	this->codSchedule = codSchedule;
}

void Course::showCourse() {
	std::cout << "\nCurso " << std::endl;
	std::cout << "Nombre del curso: ";
	std::cout << this->name << std::endl;
	std::cout << "Codigo: ";
	std::cout << this->code << std::endl;
	std::cout << "Creditos: ";
	std::cout << this->credits << std::endl;
	std::cout << "Preofesor: ";
	std::cout << this->codTeacher << std::endl;
	std::cout << "Codigo Horario: ";
	std::cout << this->codSchedule << std::endl;
}