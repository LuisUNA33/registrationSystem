#include "Schedule.h"

Schedule::Schedule() {}

Schedule::~Schedule() {}

Schedule::Schedule(int code, std::string day, int startTime, int endTime, std::string classRoom) {
	this->code = code;
	this->day = day;
	this->startTime = startTime;
	this->endTime = endTime;
	this->classRoom = classRoom;
}
int Schedule::getCode() {
	return this->code;
}
std::string Schedule::getDay() {
	return this->day;
}
int Schedule::getStartTime() {
	return this->startTime;
}
int Schedule::getEndTime() {
	return this->endTime;
}
std::string Schedule::getClassRoom() {
	return this->classRoom;
}

void Schedule::setCode(int Code) {
	this->code = code;
}
void Schedule::setDay(std::string day) {
	this->day = day;
}
void Schedule::setStartTime(int startTime) {
	this->startTime = startTime;
}
void Schedule::setEndTime(int endTime) {
	this->endTime = endTime;
}
void Schedule::setClassRoom(std::string classRoom) {
	this->classRoom = classRoom;
}

void Schedule::showSchedule() {
	std::cout << "\nHorario: " << std::endl;
	std::cout << "Codigo del horario: ";
	std::cout << this->code << std::endl;
	std::cout << "Dia: ";
	std::cout << this->day << std::endl;
	std::cout << "Hora de inicio: ";
	std::cout << this->startTime << std::endl;
	std::cout << "Hora de salida: ";
	std::cout << this->endTime << std::endl;
	std::cout << "Salon de clase: ";
	std::cout << this->classRoom << std::endl;
}