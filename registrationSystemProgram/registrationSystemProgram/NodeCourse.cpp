#include "NodeCourse.h"

NodeCourse::NodeCourse(Course data) {
    this->data = data;
    this->next = nullptr;
}

NodeCourse::~NodeCourse() {}

Course NodeCourse::getData() {
    return this->data;
}

void NodeCourse::setData(Course data) {
    this->data = data;
}

NodeCourse* NodeCourse::getNext() {
    return this->next;
}

void NodeCourse::setNext(NodeCourse* next) {
    this->next = next;
}

CourseList::CourseList() {
    this->head = nullptr;
}

void CourseList::deleteNode(NodeCourse nodoPrev) {
    NodeCourse* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void CourseList::insertAtBeginning(Course data) {
    NodeCourse* newNode = new NodeCourse(data);
    newNode->setNext(head);
    head = newNode;
}

void CourseList::insertAtEnd(NodeCourse* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeCourse* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void CourseList::printList() {
    NodeCourse* current = head;
    while (current != nullptr) {
        current->getData().showCourse();
        current = current->getNext();
    }
}
