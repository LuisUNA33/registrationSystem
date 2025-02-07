#pragma once
#include "Course.h"
#include "Files.h"
class NodeCourse {
private:
    Course data;
    NodeCourse* next;
public:
    NodeCourse(Course data);
    ~NodeCourse();
    Course getData();
    void setData(Course data);
    NodeCourse* getNext();
    void setNext(NodeCourse* next);
};

class CourseList {
private:
    NodeCourse* head;
public:
    CourseList();
    void deleteNode(NodeCourse nodoPrev);
    void insertAtBeginning(Course data);
    void insertAtEnd(NodeCourse* newNode);
    void printList();
	void writeCourseList();
	void loadCourseList(CourseList& list);
};

