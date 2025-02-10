#include "NodeApprovedCourse.h"

NodeApprovedCourse::NodeApprovedCourse(ApprovedCourse data) {
    this->data = data;
    this->next = nullptr;
}

NodeApprovedCourse::~NodeApprovedCourse() {}

ApprovedCourse NodeApprovedCourse::getData() {
    return this->data;
}

void NodeApprovedCourse::setData(ApprovedCourse data) {
    this->data = data;
}

NodeApprovedCourse* NodeApprovedCourse::getNext() {
    return this->next;
}

void NodeApprovedCourse::setNext(NodeApprovedCourse* next) {
    this->next = next;
}

ApprovedCourseList::ApprovedCourseList() {
    this->head = nullptr;
}

void ApprovedCourseList::deleteNode(NodeApprovedCourse nodoPrev) {
    NodeApprovedCourse* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void ApprovedCourseList::insertAtBeginning(ApprovedCourse data) {
    NodeApprovedCourse* newNode = new NodeApprovedCourse(data);
    newNode->setNext(head);
    head = newNode;
}

void ApprovedCourseList::insertAtEnd(NodeApprovedCourse* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeApprovedCourse* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void ApprovedCourseList::printList() {
    NodeApprovedCourse* current = head;
    while (current != nullptr) {
        current->getData().showApprovedCourse();
        current = current->getNext();
    }
}

void ApprovedCourseList::writeApprovedCourseList() {
    NodeApprovedCourse* current = head;
    while (current != nullptr) {
        string text = "";
        text += current->getData().getCodeStudent() + ";";
        text += current->getData().getCodeCourse() + ";";
        string condition = current->getData().getCondition() ? "Aprobado" : "Desaprobado";
        text +=condition+ ";"; 
        writeFile("ApprovedCourses.txt", text);
        current = current->getNext();
    }
}

void ApprovedCourseList::loadApprovedCourseList(ApprovedCourseList& list) {
    std::string text = readFile("ApprovedCourses.txt");
    int cont = 0;
    int cont2 = 0;
    int index = 0;
    bool condition=true;
    std::string textList[3];
    for (int x = 0; x < text.size(); x++) {
        cont2++;
        if (text[x] == ';') {
            textList[index] = text.substr(cont, cont2 - 1);
            cont = x + 1;
            index++;
            cont2 = 0;
        }
        if (index == 3) {
            if (textList[2] != "Aprobado") {
                 condition = false;
            }
 

            ApprovedCourse approvedCourse = ApprovedCourse(textList[0], textList[1],condition);
            list.insertAtBeginning(approvedCourse);
            index = 0;
        }
    }
        
        
    
}