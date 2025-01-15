#pragma once

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

Registration::Registration() {}

Registration::~Registration() {}

Registration::Registration(Course* courseList,int courseIndex, Student student) {
	this->courseList = courseList;
	this->courseIndex = courseIndex;
	this->student = student;
}

Course* Registration::getCourseList() {
	return this->courseList;
}
int Registration::getCourseIndex() {
	return this->courseIndex;
}
Student Registration::getStudent() {
	return this->student;
}

void Registration::setCourseList(Course* course) {
	this->courseList= course;
}
void Registration::setCourseIndex(int courseIndex) {
	this->courseIndex = courseIndex;
}
void Registration::setStudent(Student student) {
	this->student = student;
}

void Registration::showRegistration(){
	this->student.showStudent();
	for (int x = 0; x < this->courseIndex; x++) {
		this->courseList[x].showCourse();
	}
}