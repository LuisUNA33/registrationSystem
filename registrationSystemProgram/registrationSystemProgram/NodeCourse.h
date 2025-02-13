#pragma once
#include "Course.h"
#include "Files.h"
#include "NodeGroup.h"
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
    NodeCourse* getHead();
    void deleteNode(NodeCourse nodoPrev);
    void insertAtBeginning(Course data);
    void insertAtEnd(NodeCourse* newNode);
    void printList();
    void printListExtend();
	void writeCourseList();
    Course getCourse(std::string codCourse);
    void loadCourseList(CourseList& courseList, GroupList groupList);
    bool searchingCourse(std::string codCourse);
    
};

