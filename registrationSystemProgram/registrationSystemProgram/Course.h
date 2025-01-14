#pragma once

class Course {
private:
	std::string name;
	std::string code;
	std::string credits;
	std::string teacher;
	Schedule schedule;

public:
	Course();
	Course(std::string name, std::string code, std::string credits, std::string teacher, Schedule schedule);
	~Course();
	

	std::string getName();
	std::string getCode();
	std::string getCredits();
	std::string getTeacher();
	Schedule getSchedule();
	void setName(std::string name);
	void setCode(std::string code);
	void setCredits(std::string credits);
	void setTeacher(std::string teacher);
	void setSchedule(Schedule schedule);

};


Course::Course() {}
Course::~Course() {}

Course::Course(std::string name, std::string code, std::string credits, std::string teacher, Schedule schedule){
	this->name=name;
	this->code =code ;
	this->credits=credits;
	this->teacher=teacher;
	this->schedule=schedule;

}

std::string Course::getName() {
	return this->name;
}
std::string Course::getCode() {
	return this->code;
}
std::string Course::getCredits() {
	return this->credits;
}
std::string Course::getTeacher() {
	return this->teacher;
}
Schedule Course::getSchedule() {
	return this->schedule;
}

void Course::setName(std::string name) {
	this->name = name;
}
void Course::setCode(std::string code) {
	this->code = code;
}
void Course::setCredits(std::string credits) {
	this->credits = credits;
}
void Course::setTeacher(std::string teacher) {
	this->name = teacher;
}
void Course::setSchedule(Schedule schedule) {
	this->schedule = schedule;
}