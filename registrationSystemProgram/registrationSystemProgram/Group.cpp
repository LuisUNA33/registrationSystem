#include "Group.h"

Group::Group()
{
}

Group::Group(std::string NRC, std::string codCourse, std::string professor, ScheduleList listS){
	this->NRC = NRC;
	this->codCourse=codCourse;
	this->professor = professor;
	this->listS=listS;
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

ScheduleList Group::getSchedule(){
	return this->listS;
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



void Group::showGroup() {
	std::cout << "\nGrupo:" << std::endl;
	std::cout << "NRC: ";
	std::cout << this->NRC << std::endl;
	std::cout << "Codigo de curso: ";
	std::cout << this->codCourse << std::endl;
	std::cout << "Profesor: ";
	std::cout << this->professor << std::endl;
	NodeSchedule* current = this->getSchedule().getHead();
	while (current != nullptr) {
		current->getData().showSchedule();
		current = current->getNext();
	}
}