#ifndef COURSE_H   
#define COURSE_H
#include <iostream>
#include <string>

#include "Schedule.h"

class Course {
private:
	std::string name;
	std::string code;
	int credits =0;
	std::string carrer;

public:
	Course();
	Course(std::string code, std::string name,int credits, std::string carrer);
	~Course();
	

	std::string getName();
	std::string getCode();
	int getCredits();
	std::string getCarrer();
	int getStartTime();
	int getEndTime();
	void setName(std::string name);
	void setCode(std::string code);
	void setCredits(int credits);
	void setCarrer(std::string teacher);
	void showCourse();

};

#endif
