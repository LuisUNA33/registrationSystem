#include "Requirement.h"

Requirement::Requirement()
{
}

Requirement::Requirement(std::string carrerDefine,std::string codeCourse, std::string requirement_A, std::string requirement_B)
{
	this->carrerDefine = carrerDefine;
	this->codeCourse = codeCourse;

	this->requirement_A = requirement_A;
	this->requirement_B = requirement_B;
}

std::string Requirement::getCarrerDefine()
{
	return this->carrerDefine;
}

std::string Requirement::getRequirement_A()
{
	return this->requirement_A;
}

std::string Requirement::getRequirement_B()
{
	return this->requirement_B;
}

std::string Requirement::getCodCourse()
{
	return this->codeCourse;
}

void Requirement::setCarrerDefine()
{
	this->carrerDefine = carrerDefine;
}

void Requirement::setRequirement_A(std::string requirement_A)
{
	this->requirement_A = requirement_A;
}

void Requirement::setRequirement_B(std::string requirement_B)
{
	this->requirement_B = requirement_B;
}

void Requirement::setCodCourse(std::string codeCourse)
{
	this->codeCourse = codeCourse;
}

void Requirement::showRequirement()
{
	std::cout << "\nRequerimientos " << std::endl;
	std::cout << "Carrera dirigida: ";
	std::cout << this->carrerDefine << std::endl;
	std::cout << "codigo de curso: ";
	std::cout << this->codeCourse<< std::endl;
	std::cout << "requerimiento 1: ";
	std::cout << this->requirement_A<< std::endl;
	std::cout << "requerimiento 2: ";
	std::cout << this->requirement_B << std::endl;

}
