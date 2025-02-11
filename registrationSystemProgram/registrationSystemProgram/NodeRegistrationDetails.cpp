#include "NodeRegistrationDetails.h"

NodeRegistrationDetails::NodeRegistrationDetails(registrationDetails data) {
    this->data = data;
    this->next = nullptr;
}

NodeRegistrationDetails::~NodeRegistrationDetails() {}

registrationDetails NodeRegistrationDetails::getData() {
    return this->data;
}

void NodeRegistrationDetails::setData(registrationDetails data) {
    this->data = data;
}

NodeRegistrationDetails* NodeRegistrationDetails::getNext() {
    return this->next;
}

void NodeRegistrationDetails::setNext(NodeRegistrationDetails* next) {
    this->next = next;
}

RegistrationDetailsList::RegistrationDetailsList() {
    this->head = nullptr;
}

NodeRegistrationDetails* RegistrationDetailsList::getHead()
{
    return this->head;
}

void RegistrationDetailsList::deleteNode(NodeRegistrationDetails nodoPrev) {
    NodeRegistrationDetails* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void RegistrationDetailsList::insertAtBeginning(registrationDetails data) {
    NodeRegistrationDetails* newNode = new NodeRegistrationDetails(data);
    newNode->setNext(head);
    head = newNode;
}

void RegistrationDetailsList::insertAtEnd(NodeRegistrationDetails* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeRegistrationDetails* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void RegistrationDetailsList::printList() {
    NodeRegistrationDetails* current = head;
    while (current != nullptr) {
        current->getData().showRegistrationDetails();
        current = current->getNext();
    }
}

void RegistrationDetailsList::writeRegistrationDetailsList() {
    NodeRegistrationDetails* current = head;
    while (current != nullptr) {
        string text = "";
        text += current->getData().getRegistrationCode() + ";";
        text += current->getData().getCodeGroup() + ";";
        text += to_string(current->getData().getCost()) + ";";
        text += to_string(current->getData().getScore()) + ";";
        writeFile("RegistrationDetails.txt", text);
        current = current->getNext();
    }
}

void RegistrationDetailsList::loadRegistrationDetailsList(RegistrationDetailsList& list) {
    std::string text = readFile("RegistrationDetails.txt");
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
            registrationDetails regDetails = registrationDetails(textList[0], textList[1], std::stof(textList[2]), std::stof(textList[3]));
            list.insertAtBeginning(regDetails);
            index = 0;
        }
    }
}
