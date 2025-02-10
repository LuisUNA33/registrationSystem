#pragma once
#include "Registration.h"
#include "Files.h"
class NodeRegistration {
private:
    Registration data;
    NodeRegistration* next = nullptr;
public:
    NodeRegistration(Registration data);
    ~NodeRegistration();
    Registration getData();
    void setData(Registration data);
    NodeRegistration* getNext();
    void setNext(NodeRegistration* next);
};

class RegistrationList {
private:
    NodeRegistration* head;
public:
    RegistrationList();
    void deleteNode(NodeRegistration nodoPrev);
    void insertAtBeginning(Registration data);
    void insertAtEnd(NodeRegistration* newNode);
    void printList();
    void writeRegistrationList();
    void loadRegistrationList(RegistrationList& list);

};
