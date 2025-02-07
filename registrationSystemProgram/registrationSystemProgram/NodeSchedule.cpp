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

void ScheduleList::loadScheduleList(ScheduleList& list) {
    std::string text = readFile("Schedule.txt");
    int cont = 0;
    int cont2 = 0;
    int index = 0;
    std::string textList[5];
    for (int x = 0; x < text.size(); x++) {
        cont2++;
        if (text[x] == ';') {
            textList[index] = text.substr(cont, cont2 - 1);
            cont = x + 1;
            index++;
            cont2 = 0;
        }
        if (index == 5) {
            Schedule schedule = Schedule(std::stoi(textList[0]), textList[1], std::stoi(textList[2]), std::stoi(textList[3]), textList[4]);
            list.insertAtBeginning(schedule);
            index = 0;
        }
    }
}