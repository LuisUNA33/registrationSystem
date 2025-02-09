#include "Group.h"

Group::Group()
{
}

Group::Group(std::string NCR, std::string codCourse, std::string professor){
	this->NCR = NCR;
	this->codCourse=codCourse;
	this->professor = professor;
}

std::string Group::getNCR()
{
	return this->NCR;
}

std::string Group::getCodeCourses()
{
	return this->codCourse;
}

std::string Group::getProfessor()
{
	return this->professor;
}

void Group::setNCR(std::string NCR)
{
	this->NCR = NCR;
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
	std::cout << "NCR: ";
	std::cout << this->NCR << std::endl;
	std::cout << "Codigo de curso: ";
	std::cout << this->codCourse << std::endl;
	std::cout << "Profesor: ";
	std::cout << this->professor << std::endl;
}