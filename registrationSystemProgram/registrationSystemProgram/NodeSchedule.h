#pragma once
class NodeSchedule {
private:
    Schedule data;
    NodeSchedule* next;
public:
    NodeSchedule(Schedule data) {
        this->data = data;
        this->next = nullptr;
    }
    ~NodeSchedule() {}
    Schedule getData() {
        return this->data;
    }
    void setData(Schedule data) {
        this->data = data;
    }

    NodeSchedule* getNext() {
        return this->next;
    }
    void setNext(NodeSchedule* next) {
        this->next = next;
    }
};

class ScheduleList {
private:
    NodeSchedule* head;

public:
    ScheduleList() {
        this->head = nullptr;
    }

    void deleteNode(NodeSchedule nodoPrev) {
        NodeSchedule* newNext = nodoPrev.getNext()->getNext();
        nodoPrev.setNext(newNext);

    }

    void insertAtBeginning(Schedule data) {
        NodeSchedule* newNode = new NodeSchedule(data);
        newNode->setNext(head);
        head = newNode;
    }

    void insertAtEnd(NodeSchedule* newNode) {
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
    void printList() {
        NodeSchedule* current = head;
        while (current != nullptr) {
            current->getData().showSchedule();
            current = current->getNext();
        }
    }
};