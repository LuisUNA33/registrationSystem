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

void CourseList::writeCourseList() {
	NodeCourse* current = head;
	while (current != nullptr) {
		string text = "";
        text += current->getData().getName() + ";";
		text += current->getData().getCode() + ";";
		text += to_string(current->getData().getCredits()) + ";";
		text += current->getData().getTeacher() + ";";
		text += current->getData().getSchedule() + ";";
		writeFile("Courses.txt", text);
		current = current->getNext();
	}
}

void CourseList::loadCourseList(CourseList& list) {
    std::string text = readFile("Courses.txt");
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
            Course course = Course(textList[0], textList[1], std::stoi(textList[2]), textList[3], textList[4]);
            list.insertAtBeginning(course);
            index = 0;
        }
    }
}