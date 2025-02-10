#ifndef SCHEDULE_H   
#define SCHEDULE_H
#include <iostream>
#include <string>

class Schedule {
private:
	std::string codGroup;
	std::string day;
	int startTime=0;
	int endTime=0;
	std::string classRoom;

public:
	Schedule();
	~Schedule();

	Schedule(std::string codGroup, std::string day, int startTime, int endTime, std::string classRoom);
	std::string getCode();
	std::string getDay();
	int getStartTime();
	int getEndTime();
	std::string getClassRoom();
	
	void setCode(std::string codGroup);
	void setDay(std::string day);
	void setStartTime(int startTime);
	void setEndTime(int endTime);
	void setClassRoom(std::string classRoom);

	void showSchedule();

};

#endif
