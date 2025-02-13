#ifndef Requirement_H
#define Requirement_H
#include <iostream>
#include <string>
#include "NodeCourse.h"
class Requirement
{
private:
	std::string codeCourse = "";
	CourseList  courseList;
	
public:
	Requirement();
	Requirement(std::string CodeCourse, CourseList  courseList);
	std::string getCodCourse();
	CourseList getCourseList();
	void setCodCourse(std::string requirements);
	void setCourseList(CourseList  courseList);
	void showRequirement();

};

#endif