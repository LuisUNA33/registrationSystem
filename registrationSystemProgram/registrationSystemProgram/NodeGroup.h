#pragma once
#include "Group.h"
#include "Files.h"
class NodeGroup{
private:
    Group data;
    NodeGroup* next=nullptr;
public:
    NodeGroup(Group data);
    ~NodeGroup();
    Group getData();
    void setData(Group data);
    NodeGroup* getNext();
    void setNext(NodeGroup* next);
};

class GroupList {
private:
    NodeGroup* head;
public:
    GroupList();
    void deleteNode(NodeGroup nodoPrev);
    void insertAtBeginning(Group data);
    void insertAtEnd(NodeGroup* newNode);
    void printList();
    void writeGroupList();
    void loadGroupList(GroupList& list);

};

