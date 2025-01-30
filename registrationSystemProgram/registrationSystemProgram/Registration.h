#pragma once
#include "Course.h"
#include "Student.h"
class Registration {
private:
	Course* courseList=new Course[10];
	int courseIndex = 0;
	Student student; 

public:
	Registration();
	~Registration();

	Registration(Course* courseList,int courseIndex ,Student student);

	Course* getCourseList();
	int getCourseIndex();
	Student getStudent();
	void setCourseList(Course* course);
	void setCourseIndex(int courseIndex);
	void setStudent(Student student);

	void showRegistration();
};