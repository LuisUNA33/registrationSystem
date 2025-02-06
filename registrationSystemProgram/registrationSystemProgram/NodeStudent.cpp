#include "NodeStudent.h"

NodeStudent::NodeStudent(Student data) {
    this->data = data;
    this->next = nullptr;
}

NodeStudent::~NodeStudent() {}

Student NodeStudent::getData() {
    return this->data;
}

void NodeStudent::setData(Student data) {
    this->data = data;
}

NodeStudent* NodeStudent::getNext() {
    return this->next;
}

void NodeStudent::setNext(NodeStudent* next) {
    this->next = next;
}

StudentList::StudentList() {
    this->head = nullptr;
}

void StudentList::deleteNode(NodeStudent nodoPrev) {
    NodeStudent* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void StudentList::insertAtBeginning(Student data) {
    NodeStudent* newNode = new NodeStudent(data);
    newNode->setNext(head);
    head = newNode;
}

void StudentList::insertAtEnd(NodeStudent* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeStudent* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void StudentList::printList() {
    NodeStudent* current = head;
    while (current != nullptr) {
        current->getData().showStudent();
        current = current->getNext();
    }
}

//Files .txt

void StudentList::writeStudentList() {
    NodeStudent* current = head;
    while (current != nullptr) {
        std::string text = "";
        text += current->getData().getName()+";";
        text += current->getData().getId() + ";";
        text += current->getData().getDegree() + ";";
        text += current->getData().getLevel() + ";";
        writeFile("Students.txt", text);
        current = current->getNext();
    }
}