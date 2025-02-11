#include "NodeRequirement.h"
NodeRequirement::NodeRequirement(Requirement data) {
    this->data = data;
    this->next = nullptr;
}

NodeRequirement::~NodeRequirement() {}

Requirement NodeRequirement::getData() {
    return this->data;
}

void NodeRequirement::setData(Requirement data) {
    this->data = data;
}

NodeRequirement* NodeRequirement::getNext() {
    return this->next;
}

void NodeRequirement::setNext(NodeRequirement* next) {
    this->next = next;
}

RequirementList::RequirementList() {
    this->head = nullptr;
}

void RequirementList::deleteNode(NodeRequirement nodoPrev) {
    NodeRequirement* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void RequirementList::insertAtBeginning(Requirement data) {
    NodeRequirement* newNode = new NodeRequirement(data);
    newNode->setNext(head);
    head = newNode;
}

void RequirementList::insertAtEnd(NodeRequirement* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeRequirement* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void RequirementList::printList() {
    NodeRequirement* current = head;
    while (current != nullptr) {
        current->getData().showRequirement();
        current = current->getNext();
    }
}

void RequirementList::writeRequirementList() {
    NodeRequirement* current = head;
    while (current != nullptr) {
        string text = "";
        text += current->getData().getCodCourse() + "{";
        text += current->getData().getRequirements() + "}";
        writeFile("Requirements.txt", text);
        current = current->getNext();
    }
}

void RequirementList::loadRequirementList(RequirementList& list) {
    std::string text = readFile("Requirements.txt");
    int cont = 0;
    int cont2 = 0;
    int index = 0;
    std::string textList[2];
    for (int x = 0; x < text.size(); x++) {
        cont2++;
        if (text[x] == ';' || text[x] == '{') {
            textList[index] = text.substr(cont, cont2 - 1);
            cont = x + 1;
            index++;
            cont2 = 0;
        }

    }
    if (index == 2) {
        Requirement requirement = Requirement(textList[0], textList[1]);
        list.insertAtBeginning(requirement);
        index = 0;
    }
}

bool RequirementList::searchingsRequeriments(std::string codeCourse)
{
    NodeRequirement* current = head;
    while (current != nullptr) {
        if (codeCourse == current->getData().getCodCourse()) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

Requirement RequirementList::getRequeriments(string codeCourse)
{
    NodeRequirement* current = head;
    while (current != nullptr) {
        if (codeCourse == current->getData().getCodCourse()) {
            return current->getData();
        }
        current = current->getNext();
    }
}
