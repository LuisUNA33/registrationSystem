#include "NodeSchedule.h"

NodeSchedule::NodeSchedule(Schedule data) {
    this->data = data;
    this->next = nullptr;
}

NodeSchedule::~NodeSchedule() {}

Schedule NodeSchedule::getData() {
    return this->data;
}

void NodeSchedule::setData(Schedule data) {
    this->data = data;
}

NodeSchedule* NodeSchedule::getNext() {
    return this->next;
}

void NodeSchedule::setNext(NodeSchedule* next) {
    this->next = next;
}

ScheduleList::ScheduleList() {
    this->head = nullptr;
}

void ScheduleList::deleteNode(NodeSchedule nodoPrev) {
    NodeSchedule* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void ScheduleList::insertAtBeginning(Schedule data) {
    NodeSchedule* newNode = new NodeSchedule(data);
    newNode->setNext(head);
    head = newNode;
}

void ScheduleList::insertAtEnd(NodeSchedule* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeSchedule* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void ScheduleList::printList() {
    NodeSchedule* current = head;
    while (current != nullptr) {
        current->getData().showSchedule();
        current = current->getNext();
    }
}

void ScheduleList::writeScheduleList() {
	NodeSchedule* current = head;
	while (current != nullptr) {
        string text = "";
		text += to_string(current->getData().getCode()) + ";";
		text += current->getData().getDay() + ";";
		text += to_string(current->getData().getStartTime()) + ";";
		text += to_string(current->getData().getEndTime()) + ";";
		text += current->getData().getClassRoom() + ";";
		writeFile("Schedule.txt", text);
		current = current->getNext();
	}
}