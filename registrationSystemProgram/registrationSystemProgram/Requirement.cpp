#include "Requirement.h"

Requirement::Requirement()
{
}

Requirement::Requirement(std::string CodeCourse, std::string Requirements_A, std::string Requirements_B)
{
	this->codeCourse = codeCourse;
	this->requirement_A = requirement_A;
	this->requirement_B = requirement_B;
}

std::string Requirement::getRequirement_A()
{
	return this->requirement_A;
}

std::string Requirement::getRequirement_B()
{
	return this->requirement_B;
}

std::string Requirement::codCourse()
{
	return this->codeCourse;
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

void Requirement::showRequirements()
{
	
}
