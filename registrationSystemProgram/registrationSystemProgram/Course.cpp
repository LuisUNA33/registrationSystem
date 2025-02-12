#include "Course.h"
Course::Course() {}
Course::~Course() {}

Course::Course(std::string code, std::string name, int credits, std::string carrer, GroupList listG) {
	this->name = name;
	this->code = code;
	this->credits = credits;
	this->carrer = carrer;
	this->listG = listG;

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
std::string Course::getCarrer() {
	return this->carrer;
}

GroupList Course::getGroupList()
{
	return this->listG;
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
void Course::setCarrer(std::string carrer) {
	this->carrer = carrer;
}

void Course::setGroupList(GroupList listG){
	this->listG = listG;
}

void Course::showCourse() {
	std::cout << "\nCurso " << std::endl;
	std::cout << "Nombre del curso: ";
	std::cout << this->name << std::endl;
	std::cout << "Codigo: ";
	std::cout << this->code << std::endl;
	std::cout << "Creditos: ";
	std::cout << this->credits << std::endl;
	std::cout << "Carrera: ";
	std::cout << this->carrer << std::endl;
}
