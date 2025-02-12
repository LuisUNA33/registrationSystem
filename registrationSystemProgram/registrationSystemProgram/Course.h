#ifndef COURSE_H   
#define COURSE_H
#include <iostream>
#include <string>

#include "Schedule.h"
#include "NodeGroup.h"

class Course {
private:
	std::string name;
	std::string code;
	int credits =0;
	std::string carrer;
	GroupList listG;

public:
	Course();
	Course(std::string code, std::string name,int credits, std::string carrer, GroupList listG);
	~Course();
	

	std::string getName();
	std::string getCode();
	int getCredits();
	std::string getCarrer();
	GroupList getGroupList();
	//int getStartTime();
	//int getEndTime();
	void setName(std::string name);
	void setCode(std::string code);
	void setCredits(int credits);
	void setCarrer(std::string teacher);
	void setGroupList(GroupList listG);
	void showCourse();

};

#endif
