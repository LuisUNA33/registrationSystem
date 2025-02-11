#include "NodeRegistration.h"

NodeRegistration::NodeRegistration(Registration data) {
    this->data = data;
    this->next = nullptr;
}

NodeRegistration::~NodeRegistration() {}

Registration NodeRegistration::getData() {
    return this->data;
}

void NodeRegistration::setData(Registration data) {
    this->data = data;
}

NodeRegistration* NodeRegistration::getNext() {
    return this->next;
}

void NodeRegistration::setNext(NodeRegistration* next) {
    this->next = next;
}

RegistrationList::RegistrationList() {
    this->head = nullptr;
}

void RegistrationList::deleteNode(NodeRegistration nodoPrev) {
    NodeRegistration* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void RegistrationList::insertAtBeginning(Registration data) {
    NodeRegistration* newNode = new NodeRegistration(data);
    newNode->setNext(head);
    head = newNode;
}

void RegistrationList::insertAtEnd(NodeRegistration* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeRegistration* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void RegistrationList::printList() {
    NodeRegistration* current = head;
    while (current != nullptr) {
        current->getData().showRegistration();
        current = current->getNext();
    }
}

void RegistrationList::writeRegistrationList() {
    NodeRegistration* current = head;
    while (current != nullptr) {
        string text = "";
        text += current->getData().getCode() + ";";
        text += current->getData().getCodeStudent() + ";";
        text += current->getData().getYear() + ";";
		text += current->getData().getSemester() + ";";
        writeFile("Registrations.txt", text);
        current = current->getNext();
    }
}

void RegistrationList::loadRegistrationList(RegistrationList& list) {
    std::string text = readFile("Registrations.txt");
    int cont = 0;
    int cont2 = 0;
    int index = 0;
    std::string textList[4];
    for (int x = 0; x < text.size(); x++) {
        cont2++;
        if (text[x] == ';') {
            textList[index] = text.substr(cont, cont2 - 1);
            cont = x + 1;
            index++;
            cont2 = 0;
        }
        if (index == 4) {
            Registration registration = Registration(textList[0], textList[1], textList[2], textList[3]);
            list.insertAtBeginning(registration);
            index = 0;
        }
    }
}


