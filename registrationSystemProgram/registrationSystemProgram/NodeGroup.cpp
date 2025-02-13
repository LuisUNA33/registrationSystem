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
        text += current->getData().getNRC() + ";";
        text += current->getData().getCodeCourses() + ";";
        text += current->getData().getProfessor() + ";";
        NodeSchedule* currentS = current->getData().getSchedule().getHead();
        text += "[";
        while (currentS != nullptr) {
            text += currentS->getData().getCodSchedule()+";";
            currentS = currentS->getNext();
        }
        text += "]";
        writeFile("Groups.txt", text);
        current = current->getNext();
    }
}

void GroupList::loadGroupList(GroupList& groupList, ScheduleList schedulelist) {
    std::ifstream file("Groups.txt");
    std::string line;

    if (!file) {
        std::cerr << "Error al abrir el archivo: " << "Groups.txt" << std::endl;
        return;
    }

    while (getline(file, line)) {
        if (line.size() > 8) {
            std::string textList[3];
            ScheduleList temlist;
            int cont = 0, cont2 = 0, index = 0;
            std::string codSchedule;

            int startBracket = line.find('[');
            int endBracket = line.find(']');

            for (int x = 0; x < startBracket; x++) {
                cont2++;
                if (line[x] == ';' && index < 3) {
                    if (cont2 > 1) {
                        textList[index] = line.substr(cont, cont2 - 1);
                    }
                    cont = x + 1;
                    index++;
                    cont2 = 0;
                }
            }

            cont = startBracket + 1;
            cont2 = 0;

            for (int x = cont; x < endBracket; x++) {
                cont2++;
                if (line[x] == ';') {
                    if (cont2 > 1) {
                        codSchedule = line.substr(cont, cont2 - 1);
                        temlist.insertAtBeginning(schedulelist.getSchedule(codSchedule));
                    }
                    cont = x + 1;
                    cont2 = 0;
                }
            }

            groupList.insertAtBeginning(Group(textList[0], textList[1], textList[2], temlist));
        }
    }

    file.close();
}

bool GroupList::searchingGroup(std::string codCourse) {
    NodeGroup* current = head;
    while (current != nullptr) {
        if (codCourse == current->getData().getNRC()) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

Group GroupList::getGroup(std::string codGroup) {
    NodeGroup* current = head;
    while (current != nullptr) {
        if (codGroup == current->getData().getNRC()) {
            return current->getData();
        }
        current = current->getNext();
    }
}
