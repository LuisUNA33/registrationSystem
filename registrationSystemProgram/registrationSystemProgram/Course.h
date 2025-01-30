#pragma once
#include <iostream>
#include "Schedule.h"
class Course {
private:
	std::string name;
	std::string code;
	int credits;
	std::string teacher;
	Schedule schedule;

public:
	Course();
	Course(std::string name, std::string code,int credits, std::string teacher, Schedule schedule);
	~Course();
	

	std::string getName();
	std::string getCode();
	int getCredits();
	std::string getTeacher();
	Schedule getSchedule();
	int getStartTime();
	int getEndTime();
	void setName(std::string name);
	void setCode(std::string code);
	void setCredits(int credits);
	void setTeacher(std::string teacher);
	void setSchedule(Schedule schedule);
	void showCourse();

};


