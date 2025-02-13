#pragma once
#include "Schedule.h"
#include "Files.h"
class NodeSchedule {
private:
    Schedule data;
    NodeSchedule* next;
public:
    NodeSchedule(Schedule data);
    ~NodeSchedule();
    Schedule getData();
    void setData(Schedule data);
    NodeSchedule* getNext();
    void setNext(NodeSchedule* next);
};

class ScheduleList {
private:
    NodeSchedule* head;
public:
    ScheduleList();
    NodeSchedule* getHead();
    void deleteNode(NodeSchedule nodoPrev);
    void insertAtBeginning(Schedule data);
    void insertAtEnd(NodeSchedule* newNode);
    void printList();
	void writeScheduleList();
	void loadScheduleList(ScheduleList& list);
    bool searchingSchedule(std::string NRC);
    Schedule getSchedule(std::string NRC);
};

