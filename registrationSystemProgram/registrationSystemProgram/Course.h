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
	std::string codTeacher;
	std::string codSchedule;

public:
	Course();
	Course(std::string name, std::string code,int credits, std::string codTeacher, std::string codSchedule);
	~Course();
	

	std::string getName();
	std::string getCode();
	int getCredits();
	std::string getTeacher();
	std::string getSchedule();
	int getStartTime();
	int getEndTime();
	void setName(std::string name);
	void setCode(std::string code);
	void setCredits(int credits);
	void setTeacher(std::string teacher);
	void setSchedule(std::string codSchedule);
	void showCourse();

};

#endif