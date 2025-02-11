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

void StudentList::loadStudentList(StudentList& list) {
    std::string text = readFile("Students.txt");
    int cont = 0;
    int cont2 = 0;
    int index = 0;
    std::string textList[4];
    for (int x= 0; x < text.size(); x++) {
        cont2++;
        if (text[x] == ';') {
            textList[index] = text.substr(cont, cont2 - 1);
            cont = x+1;
            index++;
            cont2 = 0;
        }
        if (index == 4) {
            Student student = Student(textList[0], textList[1], textList[2], textList[3]);
            list.insertAtBeginning(student);
            index = 0;
            
        }
    }
    

}

bool StudentList::searchingStudent(std::string idStudent)
{
    NodeStudent* current = head;
    while (current != nullptr) {
        if (idStudent == current->getData().getId()) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

Student StudentList::getStudent(string idStudent) {
    NodeStudent* current = head;
    while (current != nullptr) {
        if (idStudent == current->getData().getId()) {
            return current->getData();
        }
        current = current->getNext();
    }
}
