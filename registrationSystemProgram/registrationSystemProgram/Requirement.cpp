#include "Requirement.h"

Requirement::Requirement()
{
}

Requirement::Requirement(std::string codeCourse, std::string requirements)
{

	this->codeCourse = codeCourse;
	this->requirement = requirements;
}

std::string Requirement::getRequirements()
{
	return this->requirement;
}


std::string Requirement::getCodCourse()
{
	return this->codeCourse;
}

void Requirement::setRequirements(std::string requirements)
{
	this->requirement = requirements;
}


void Requirement::setCodCourse(std::string codeCourse)
{
	this->codeCourse = codeCourse;
}

void Requirement::showRequirement()
{
	std::cout << "\nRequerimientos " << std::endl;
	std::cout << "codigo de curso: ";
	std::cout << this->codeCourse<< std::endl;
	std::cout << "requerimiento: ";
	std::cout << this->requirement<< std::endl;


}
