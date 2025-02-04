#pragma once
class NodeCourse {
private:
    Course data;
    NodeCourse* next;
public:
    NodeCourse(Course data) {
        this->data = data;
        this->next = nullptr;
    }
    ~NodeCourse() {}
    Course getData() {
        return this->data;
    }
    void setData(Course data) {
        this->data = data;
    }

    NodeCourse* getNext() {
        return this->next;
    }
    void setNext(NodeCourse* next) {
        this->next = next;
    }
};

class CourseList {
private:
    NodeCourse* head;

public:
    CourseList() {
        this->head = nullptr;
    }

    void deleteNode(NodeCourse nodoPrev) {
        NodeCourse* newNext = nodoPrev.getNext()->getNext();
        nodoPrev.setNext(newNext);

    }

    void insertAtBeginning(Course data) {
        NodeCourse* newNode = new NodeCourse(data);
        newNode->setNext(head);
        head = newNode;
    }

    void insertAtEnd(NodeCourse* newNode) {
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
    void printList() {
        NodeCourse* current = head;
        while (current != nullptr) {
            current->getData().showCourse();
            current = current->getNext();
        }
    }
};