#pragma once
class NodeStudent {
private:
    Student data;
    NodeStudent* next;
public:
    NodeStudent(Student data) {
        this->data = data;
        this->next = nullptr;
    }
    ~NodeStudent() {}
    Student getData() {
        return this->data;
    }
    void setData(Student data) {
        this->data = data;
    }

    NodeStudent* getNext() {
        return this->next;
    }
    void setNext(NodeStudent* next) {
        this->next = next;
    }
};

class StudentList {
private:
    NodeStudent* head;

public:
    StudentList() {
        this->head = nullptr;
    }

    void deleteNode(NodeStudent nodoPrev) {
        NodeStudent* newNext = nodoPrev.getNext()->getNext();
        nodoPrev.setNext(newNext);

    }

    void insertAtBeginning(Student data) {
        NodeStudent* newNode = new NodeStudent(data);
        newNode->setNext(head);
        head = newNode;
    }

    void insertAtEnd(NodeStudent* newNode) {
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
    void printList() {
        NodeStudent* current = head;
        while (current != nullptr) {
            current->getData().showStudent();
            current = current->getNext();
        }
    }
};