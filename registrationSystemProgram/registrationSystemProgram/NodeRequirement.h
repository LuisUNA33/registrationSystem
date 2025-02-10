#pragma once
#include "Requirement.h"
#include "Files.h"
class NodeRequirement
{
 private:
        Requirement data;
        NodeRequirement* next = nullptr;
    public:
        NodeRequirement(Requirement data);
        ~NodeRequirement();
        Requirement getData();
        void setData(Requirement data);
        NodeRequirement* getNext();
        void setNext(NodeRequirement* next);
};

    class RequirementList {
    private:
        NodeRequirement* head;
    public:
        RequirementList();
        void deleteNode(NodeRequirement nodoPrev);
        void insertAtBeginning(Requirement data);
        void insertAtEnd(NodeRequirement* newNode);
        void printList();
        void writeRequirementList();
        void loadRequirementList(RequirementList& list);

    };


