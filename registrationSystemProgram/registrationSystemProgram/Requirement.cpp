#include "Requirement.h"

Requirement::Requirement()
{
}

Requirement::Requirement(std::string codeCourse, CourseList  courseList)
{
	this->codeCourse = codeCourse;
	this->courseList = courseList;
}

std::string Requirement::getCodCourse()
{
	return this->codeCourse;
}

CourseList Requirement::getCourseList()
{
	return this->courseList;
}

void Requirement::setCodCourse(std::string codCourse){
	this->codeCourse=codCourse;
}

void Requirement::setCourseList(CourseList courseList){
	this->courseList = courseList;
}


void Requirement::showRequirement()
{
	std::cout << "\nRequerimientos " << std::endl;
	std::cout << "codigo de curso: ";
	std::cout << this->codeCourse<< std::endl;
	std::cout << "Requisitos del curso: ";
	NodeCourse* current = this->courseList.getHead();
	while (current != nullptr) {
		cout << current->getData().getCode() << endl;
		current = current->getNext();
	}


}
