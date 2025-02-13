#include "NodeRequirement.h"
#include "NodeCourse.h"
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
        text += current->getData().getCodCourse()+";[";
        NodeCourse* currentC = current->getData().getCourseList().getHead();
        while (currentC != nullptr) {
            text += currentC->getData().getCode() + ";";
            currentC = currentC->getNext();
        }
        text += "]";
        writeFile("Requirements.txt", text);
        current = current->getNext();
    }
}

void RequirementList::loadRequirementList(RequirementList& requerimentsList, CourseList courselist) {
    std::ifstream file("Requirements.txt");
    std::string line;

    if (!file) {
        std::cerr << "Error al abrir el archivo: " << "Requirements.txt" << std::endl;
        return;
    }

    while (getline(file, line)) {
        if (line.size() > 8) {
            std::string textList[1];
            CourseList temlist;
            int cont = 0, cont2 = 0, index = 0;
            std::string codCourse;

            int startBracket = line.find('[');
            int endBracket = line.find(']');

            for (int x = 0; x < startBracket; x++) {
                cont2++;
                if (line[x] == ';' && index < 1) {
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
                        codCourse = line.substr(cont, cont2 - 1);
                        temlist.insertAtBeginning(courselist.getCourse(codCourse));
                    }
                    cont = x + 1;
                    cont2 = 0;
                }
            }

            requerimentsList.insertAtBeginning(Requirement(textList[0],temlist));
        }
    }

    file.close();
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
        cout << "x" << endl;
        current = current->getNext();
    }
}
