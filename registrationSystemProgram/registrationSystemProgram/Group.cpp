#include "Group.h"

Group::Group()
{
}

Group::Group(std::string NRC, std::string codCourse, std::string professor, string schedule_A, string schedule_B){
	this->NRC = NRC;
	this->codCourse=codCourse;
	this->professor = professor;
	this->schedule_A = schedule_A;
	this->schedule_B = schedule_B;
}

std::string Group::getNRC()
{
	return this->NRC;
}

std::string Group::getCodeCourses()
{
	return this->codCourse;
}

std::string Group::getProfessor()
{
	return this->professor;
}

string Group::getSchedule_A(){
	return this->schedule_A;
}

string Group::getSchedule_B()
{
	return this->schedule_B;
}

void Group::setNRC(std::string NRC)
{
	this->NRC = NRC;
}

void Group::setCodeCourse(std::string codeCourse)
{
	this->codCourse = codeCourse;
}

void Group::setProfessor(std::string Professor)
{
	this->professor = professor;
}

void Group::setSchedule_A(string schedule_A)
{
	this->schedule_A = schedule_A;
}

void Group::setSchedule_B(string schedule_B)
{
	this->schedule_B = schedule_B;
}

void Group::showGroup() {
	std::cout << "\nGrupo:" << std::endl;
	std::cout << "NRC: ";
	std::cout << this->NRC << std::endl;
	std::cout << "Codigo de curso: ";
	std::cout << this->codCourse << std::endl;
	std::cout << "Profesor: ";
	std::cout << this->professor << std::endl;
}