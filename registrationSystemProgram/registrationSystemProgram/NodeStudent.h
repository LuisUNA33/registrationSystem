#pragma once
#include "Student.h"
class NodeStudent {
private:
    Student data;
    NodeStudent* next;
public:
    NodeStudent(Student data);
    ~NodeStudent();
    Student getData();
    void setData(Student data);
    NodeStudent* getNext();
    void setNext(NodeStudent* next);
};

class StudentList {
private:
    NodeStudent* head;
public:
    StudentList();
    void deleteNode(NodeStudent nodoPrev);
    void insertAtBeginning(Student data);
    void insertAtEnd(NodeStudent* newNode);
    void printList();
};
