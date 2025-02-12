#include "NodeCourse.h"
//#include "NodeGroup.h"

NodeCourse::NodeCourse(Course data) {
    this->data = data;
    this->next = nullptr;
}

NodeCourse::~NodeCourse() {}

Course NodeCourse::getData() {
    return this->data;
}

void NodeCourse::setData(Course data) {
    this->data = data;
}

NodeCourse* NodeCourse::getNext() {
    return this->next;
}

void NodeCourse::setNext(NodeCourse* next) {
    this->next = next;
}

CourseList::CourseList() {
    this->head = nullptr;
}

NodeCourse* CourseList::getHead()
{
    return this->head;
}

void CourseList::deleteNode(NodeCourse nodoPrev) {
    NodeCourse* newNext = nodoPrev.getNext()->getNext();
    nodoPrev.setNext(newNext);
}

void CourseList::insertAtBeginning(Course data) {
    NodeCourse* newNode = new NodeCourse(data);
    newNode->setNext(head);
    head = newNode;
}

void CourseList::insertAtEnd(NodeCourse* newNode) {
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

void CourseList::printList() {
    NodeCourse* current = head;
    while (current != nullptr) {
        current->getData().showCourse();
        current = current->getNext();
    }
}


void CourseList::writeCourseList() {
	NodeCourse* current = head;
	while (current != nullptr) {
		string text = "";
        text += current->getData().getCode() + ";";
        text += current->getData().getName() + ";";
		text += to_string(current->getData().getCredits()) + ";";
		text += current->getData().getCarrer() + ";";
        NodeGroup* currentG = current->getData().getGroupList().getHead();
        text += "[";
        while (currentG != nullptr) {
            text += currentG->getData().getNRC() + ";";
            currentG = currentG->getNext();
        }
        text += "]";
		writeFile("Courses.txt", text);
		current = current->getNext();
	}
}

void CourseList::loadCourseList(CourseList& courseList, GroupList groupList) {
    std::ifstream file("Courses.txt");
    std::string line;
    if (!file) {
        std::cerr << "Error al abrir el archivo: " << "Courses.txt" << std::endl;
        return;
    }

    while (getline(file, line)) {
        if (line.size() > 8) {
            std::string textList[4];
            GroupList temlist;
            int cont = 0, cont2 = 0, index = 0;
            std::string codCourse;

            int startBracket = line.find('[');
            int endBracket = line.find(']');

            for (int x = 0; x < startBracket; x++) {
                cont2++;
                if (line[x] == ';' && index < 4) {
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
                        temlist.insertAtBeginning(groupList.getGroup(codCourse));
                    }
                    cont = x + 1;
                    cont2 = 0;
                }
            }

            courseList.insertAtBeginning(Course(textList[0], textList[1],stoi(textList[2]),textList[3], temlist));
        }
    }

    file.close();
}

bool CourseList::searchingCourse(std::string codCourse){
    NodeCourse* current = head;
    while (current != nullptr) {
        if (codCourse == current->getData().getCode()) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

Course CourseList::getCourse(std::string codCourse) {
    NodeCourse* current = head;
    while (current != nullptr) {
        if (codCourse == current->getData().getCode()) {
            return current->getData();
        }
        current = current->getNext();
    }
}