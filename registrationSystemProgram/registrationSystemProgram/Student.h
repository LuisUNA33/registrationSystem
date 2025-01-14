#pragma once

class Student {
	private:
		std::string name;
		std::string id;
		std::string degree;
		std::string level;

	public:
		Student();
		~Student();
		Student(std::string name, std::string id, std::string degree, std::string level);
		std::string getName();
		std::string getId();
		std::string getDegree();
		std::string getLevel();
		void setName(std::string name);
		void setId(std::string id);
		void setDegree(std::string degree);
		void setLevel(std::string level);				

};

Student::Student(){}
Student::~Student(){}

Student::Student(std::string name,std::string id, std::string degree, std::string level){
	this->name = name;
	this->id = id;
	this->degree=degree;
	this->level=level;
}

std::string Student::getName() {
	return this->name;
}
std::string Student::getId() {
	return this->id;
}
std::string Student::getDegree() {
	return this->degree;
}
std::string Student::getLevel() {
	return this->level;
}

void Student::setName(std::string name) {
	this->name=name;
}
void Student::setId(std::string id) {
	this->id = id;
}
void Student::setDegree(std::string degree) {
	this->degree = degree;
}
void Student::setLevel(std::string level) {
	this->name = level;
}

