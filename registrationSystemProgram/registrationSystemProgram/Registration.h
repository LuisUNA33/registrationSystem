#pragma once

class Registration {
private:
	Course courseList[10];
	Student student;

public:
	Registration();
	~Registration();

	Course getCourseList(int index);
	Student getStudent();
	void setCourseList(Course course, int index);
	void setStudent(Student student);
};

Registration::Registration() {}

Registration::~Registration() {}

Course Registration::getCourseList(int index) {
	return this->courseList[index];
}
Student Registration::getStudent() {
	return this->student;
}

void Registration::setCourseList(Course course,int index) {
	this->courseList[index] = course;
}
void Registration::setStudent(Student student) {
	this->student = student;
}