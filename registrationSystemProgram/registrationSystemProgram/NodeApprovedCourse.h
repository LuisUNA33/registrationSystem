#pragma once
#include "ApprovedCourse.h"
#include "Files.h"
class NodeApprovedCourse
{

    private:
        ApprovedCourse data;
        NodeApprovedCourse* next = nullptr;
    public:
        NodeApprovedCourse(ApprovedCourse data);
        ~NodeApprovedCourse();
        ApprovedCourse getData();
        void setData(ApprovedCourse data);
        NodeApprovedCourse* getNext();
        void setNext(NodeApprovedCourse* next);
    };

    class ApprovedCourseList {
    private:
        NodeApprovedCourse* head;
    public:
        ApprovedCourseList();
        void deleteNode(NodeApprovedCourse nodoPrev);
        void insertAtBeginning(ApprovedCourse data);
        void insertAtEnd(NodeApprovedCourse* newNode);
        void printList();
        void writeApprovedCourseList();
        void loadApprovedCourseList(ApprovedCourseList& list);

    };



