#ifndef SCHEDULE_H   
#define SCHEDULE_H
#include <iostream>
#include <string>

class Schedule {
private:
	int code=0;
	std::string day;
	int startTime=0;
	int endTime=0;
	std::string classRoom;

public:
	Schedule();
	~Schedule();

	Schedule(int code,std::string day, int startTime, int endTime, std::string classRoom);
	int getCode();
	std::string getDay();
	int getStartTime();
	int getEndTime();
	std::string getClassRoom();
	
	void setCode(int code);
	void setDay(std::string day);
	void setStartTime(int startTime);
	void setEndTime(int endTime);
	void setClassRoom(std::string classRoom);

	void showSchedule();

};

#endif
