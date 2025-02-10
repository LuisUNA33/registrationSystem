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

void ApprovedCourse::showApprovedCourse()
{
}
