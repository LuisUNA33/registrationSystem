#pragma once

class Schedule {
private:
	std::string day;
	std::string startTime;
	std::string endTime;
	std::string classRoom;

public:
	Schedule();
	~Schedule();

	Schedule(std::string day, std::string startTime, std::string endTime, std::string classRoom);

	std::string getDay();
	std::string getStartTime();
	std::string getEndTime();
	std::string getClassRoom();
	void setDay(std::string day);
	void setStartTime(std::string startTime);
	void setEndTime(std::string endTime);
	void setClassRoom(std::string classRoom);

};

Schedule::Schedule() {}

Schedule::~Schedule() {}

Schedule::Schedule(std::string day, std::string startTime, std::string endTime, std::string classRoom){
	this->day = day;
	this->startTime = startTime;
	this->endTime = endTime;
	this->classRoom = classRoom;
}

std::string Schedule::getDay() {
	return this->day;
}
std::string Schedule::getStartTime() {
	return this->startTime;
}
std::string Schedule::getEndTime() {
	return this->endTime;
}
std::string Schedule::getClassRoom() {
	return this->classRoom;
}

void Schedule::setDay(std::string day) {
	this->day = day;
}
void Schedule::setStartTime(std::string startTime) {
	this->startTime = startTime;
}
void Schedule::setEndTime(std::string endTime) {
	this->endTime = endTime;
}
void Schedule::setClassRoom(std::string classRoom) {
	this->classRoom = classRoom;
}