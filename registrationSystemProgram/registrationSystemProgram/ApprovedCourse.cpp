#include "ApprovedCourse.h"

ApprovedCourse::ApprovedCourse()
{
}

ApprovedCourse::ApprovedCourse(std::string codStudent, std::string codCourse)
{
	this->codCourse = codCourse;
	this->codStudent = codStudent;
}

std::string ApprovedCourse::getCodeStudent()
{
	return this->codStudent;
}

std::string ApprovedCourse::getCodeCourse()
{
	return this->codCourse;
}

void ApprovedCourse::setCodeStudent(std::string codStudent)
{
	this->codStudent = codStudent;
}

void ApprovedCourse::setCodeCourse(std::string codCourse)
{
	this->codCourse = codCourse;
}

void ApprovedCourse::showApprovedCourse() {
	std::cout << "\nCursos Aprobados: " << std::endl;
	std::cout << "ID del estudiante: ";
	std::cout << this->codStudent << std::endl;
	std::cout << "Codigo del curso aprobado: ";
	std::cout << this->codCourse << std::endl;
}