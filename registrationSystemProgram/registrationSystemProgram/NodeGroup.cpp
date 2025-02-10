#include "NodeGroup.h"

NodeGroup::NodeGroup(Group data) {
    this->data = data;
    this->next = nullptr;
}

NodeGroup::~NodeGroup() {}

Group NodeGroup::getData() {
    return this->data;
}

void NodeGroup::setData(Group data) {
    this->data = data;
}

NodeGroup* NodeGroup::getNext() {
    return this->next;
}

void NodeGroup::setNext(NodeGroup* next) {
    this->next = next;
}

GroupList::GroupList() {
    this->head = nullptr;
}

NodeGroup* GroupList::getHead()
{
    return this->head;
}

void GroupList::deleteNode(NodeGroup nodoPrev) {
    NodeGroup* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void GroupList::insertAtBeginning(Group data) {
    NodeGroup* newNode = new NodeGroup(data);
    newNode->setNext(head);
    head = newNode;
}

void GroupList::insertAtEnd(NodeGroup* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else {
        NodeGroup* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}

void GroupList::printList() {
    NodeGroup* current = head;
    while (current != nullptr) {
        current->getData().showGroup();
        current = current->getNext();
    }
}

void GroupList::writeGroupList() {
    NodeGroup* current = head;
    while (current != nullptr) {
        string text = "";
        text += current->getData().getNCR() + ";";
        text += current->getData().getCodeCourses() + ";";
        text += current->getData().getProfessor() + ";";
        writeFile("Groups.txt", text);
        current = current->getNext();
    }
}

void GroupList::loadGroupList(GroupList& list) {
    std::string text = readFile("Groups.txt");
    int cont = 0;
    int cont2 = 0;
    int index = 0;
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
            Group group = Group(textList[0], textList[1],textList[2]);
            list.insertAtBeginning(group);
            index = 0;
        }
    }
}
