#include "processes.h"


void about() {
	std::cout << "***	Sistema de registro de matricula estudiantil	***\n" <<
		"Authors: Luis Sanchez, Mathew Ramirez, John Perez \n" <<
		"Version del Programa: v2.0\n" <<
		"Incio de desarrollo: 18/12/2024\n" <<
		"Fecha de Ultima actualizacion: 18/01/2025\n" <<
		"Lenguaje de programacion: c++\n" << std::endl;
	system("Pause");
}

int getRandomNumber() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 100);
    return dis(gen);
}

std::string enterText() {
	std::string text;
	std::cin >> text;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return text;
}

char enterChar() {
	char text = ' ';
	std::cin >> text;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return text;
}

int enterNum() {
	while (true) {
		int num;
		if (std::cin >> num) {
			return num;
		}
		else {
			std::cout << "Debe ingresar un numero:" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}


void enterStartEndTime(int& startTime, int& endTime) {
	while (true) {
		std::cout << "Hora de inicio:" << std::endl;
		startTime = enterNum();
		std::cout << "Hora de fin:" << std::endl;
		endTime = enterNum();
		if ((startTime >= 0 && startTime <= 24) && (endTime >= 0 && endTime <= 24))
		{
			if (startTime < endTime) {
				return;
			}
		}
		std::cout << "No ingreso horas coherentes\nRecuerde solo formato de 24 horas\n Solo se admiten horas en punto." << std::endl;
	}
}

std::string enterDay() {
	std::string days[7] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo" };
	for (int x = 0; x < 7; x++) {
		std::cout << "(" << x + 1 << ") " << days[x] << std::endl;
	}
	while (true) {
		std::cout << "Ingrese el numero correpondinete al dia: " << std::endl;
		int num = enterNum();
		if (num > 0 and num < 8) {
			return days[num - 1];
		}

	}

}
std::string enterCarrer() {
	std::string carrer[7] = { "Ing en sistemas", "Ing topografia", "Ense�anza de ingles", "Administracion", "Planificacion", "Ing civil", "Ing Quimica" };
	for (int x = 0; x < 7; x++) {
		std::cout << "(" << x + 1 << ") " << carrer[x] << std::endl;
	}
	while (true) {
		std::cout << "Ingrese el numero correpondiente a la carrera: " << std::endl;
		int num = enterNum();
		if (num > 0 and num < 8) {
			return carrer[num - 1];
		}

	}

}
bool enterCondition() {
	while (true) {
		cout << "Opciones" << endl;
		cout << "1. Aprobado\n2. Reprobado" << endl;

		int option = enterNum();
		if (option == 1) {
			return true;
		}
		if (option == 2) {
			return false;
		}

	}

}


//Registrar---------------------------
void registerStudent(StudentList& studentList){
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::cout << "Ingrese el nombre:" << std::endl;
	std::string name = enterText();
	std::cout << "Ingrese el numero de cedula:" << std::endl;
	std::string id = enterText();
	std::cout << "Ingrese la carrera:" << std::endl;
	std::string degree = enterCarrer();
	std::cout << "Ingrese el nivel:" << std::endl;
	std::string level = enterText();
	studentList.insertAtBeginning(Student(name, id, degree, level));
	std::cout << "Estudiante agregado a la lista" << std::endl;
}

void registerSchedule(ScheduleList& scheduleList) {
	std::cout << "Ingrese los datos del Horario" << std::endl;
	std::cout << "Ingrese codigo de Horario: " << std::endl;
	string codSchedule = enterText();
	std::cout << "Ingrese codigo de Curso: " << std::endl;
	std::string codCourse = enterText();
	std::cout << "Dia:" << std::endl;
	std::string day = enterDay();
	int startTime;
	int endTime;
	enterStartEndTime(startTime, endTime);
	std::cout << "Salon de clase:" << std::endl;
	std::string classRoom = enterText();
	scheduleList.insertAtBeginning(Schedule(codSchedule,codCourse, day, startTime, endTime, classRoom));
	std::cout << "Horario agregado a la lista. " << std::endl;
}

ScheduleList selectSchedules(ScheduleList schedules) {
	ScheduleList list;
	string text;
	while (true) {
		std::cout << "Ingrese el codigo del horario \nMarque (s) para dejar de agregar horaios " << std::endl;
		text = enterText();
		if (text == "s") {
			return list;
		}
		if (schedules.searchingSchedule(text)) {
			list.insertAtBeginning(schedules.getSchedule(text));
		}
		else {
			std::cout << "Ese horario no se escuentra registrado." << std::endl;
		}
	}
}

void registerGroup(GroupList& groupList,ScheduleList schedules) {
	std::cout << "Ingrese los datos del grupo" << std::endl;
	std::cout << "NRC:" << std::endl;
	std::string NRC = enterText();
	std::cout << "Nombre del profesor:" << std::endl;
	std::string codProfessor = enterText();
	std::cout << "Codigo de Curso:" << std::endl;
	std::string codCourse = enterText();
	groupList.insertAtBeginning(Group(NRC, codCourse, codProfessor, selectSchedules(schedules)));
	std::cout << "Grupo agregado a la lista. " << std::endl;
}

GroupList selectGroups(GroupList groups) {
	GroupList list;
	string text;
	while (true) {
		std::cout << "Ingrese el codigo del Grupo(NRC) \nMarque (s) para dejar de agregar grupo " << std::endl;
		text = enterText();
		if (text == "s") {
			return list;
		}
		if (groups.searchingGroup(text)) {
			list.insertAtBeginning(groups.getGroup(text));
		}
		else {
			std::cout << "Ese grupo no se escuentra registrado." << std::endl;
		}
	}
}

void registerCourse(CourseList& courseList,GroupList& groupList,RequirementList& requirementList) {
	char option;
	std::cout << "Ingrese los datos del Curso" << std::endl;
	std::cout << "Ingrese codigo de curso: " << std::endl;
	std::string code = enterText();
	std::cout << "Nombre del curso:" << std::endl;
	std::string name = enterText();
	std::cout << "Cantidad de creditos:" << std::endl;
	int credits = enterNum();
	std::cout << "Carrera:" << std::endl;
	std::string carrer = enterCarrer();
	std::cout << "el curso tiene requerimientos?:" << std::endl;
	std::cout << "S o N:" << std::endl;
	std::cin >> option;
	if (option == 'S') {
		registerRequeriment(requirementList);
	}
	courseList.insertAtBeginning(Course(code,name, credits, carrer,selectGroups(groupList)));
	std::cout << "Curso agregado a la lista. " << std::endl;
}

void registerRequeriment(RequirementList& requirementList) {
	std::cout << "Ingrese los requisitos del curso,\nSi el requisito es '0', se asume que no tiene requisitos:" << std::endl; 
	std::cout << "Codigo de curso:" << std::endl;
	std::string codCourse = enterText();
	std::cout << "Requerimiento:" << std::endl;
	std::string requirements = enterText();
	//requirementList.insertAtBeginning(Requirement(codCourse, requirements));
	std::cout << "Requerimientos de curso agregados a la lista. " << std::endl;

}

void registerApprovedCourse(ApprovedCourseList& approvedCourseList) {
	std::cout << "Ingrese el estudiante y su curso:" << std::endl;
	std::cout << "ID del estudiante:" << std::endl;
	std::string codStudent = enterText();
	std::cout << "Codigo del curso:" << std::endl;
	std::string codCourse = enterText();
	std::cout << "Condicion del estudiante en el curso:" << std::endl;
	approvedCourseList.insertAtBeginning(ApprovedCourse(codStudent, codCourse,enterCondition()));
	std::cout << "Requerimientos de curso agregados a la lista. " << std::endl;
}

void registration(RegistrationList& registrations,StudentList students) {
	//Matricula
	std::cout << "Ingrese datos de matricula:" << std::endl;
	string codStudent = enterStudent(students);
	std::cout << "Ingrese el codigo de matricula:" << std::endl;
	string codRegistration = enterText();
	std::cout << "Ingrese el a�o cursado:" << std::endl;
	string codYear = enterText();
	std::cout << "Ingrese el semestre:" << std::endl;
	string codSemester = enterText();
	Registration newRegistration = Registration(codRegistration, codStudent, codYear, codSemester);
	registrations.insertAtBeginning(newRegistration);
	std::cout << "Matricula Agregada. " << std::endl;
}
//registro de matricula
//
//void showCourseGroups(std::string codCourse, GroupList groups){
//	NodeGroup* currentG = groups.getHead();
//	while (currentG != nullptr) {
//		if (currentG->getData().getCodeCourses() == codCourse) {
//			currentG->getData().showGroup();
//		}
//		currentG = currentG->getNext();
//	}
//}
//
string  enterStudent(StudentList students){
	while (true) {
		std::cout << "ID del estudiante: " << std::endl;
		std::string codStudent = enterText();
		if (students.searchingStudent(codStudent)) {
			return codStudent;
		}
		std::cout << "El estudiante no esta registrado." << std::endl;
	}
}

//string  enterCourse(CourseList courses) {
//	while (true) {
//		std::cout << "Codigo del curso: " << std::endl;
//		std::string codCourse = enterText();
//		if (courses.searchingCourse(codCourse)) {
//			return codCourse;
//		}
//		std::cout << "El curso no esta registrado." << std::endl;
//	}
//}
string  enterCourse(CourseList courses,string carrer,RequirementList requirements) {
	while (true) {
		std::cout << "Codigo del curso:" << std::endl;
		std::string codCourse = enterText();
		if (requirements.searchingsRequeriments(codCourse)){
			NodeRequirement requirement = requirements.getRequeriments(codCourse);
			if (courses.searchingCourse(codCourse)) {
				if (courses.getCourse(codCourse).getCarrer() == carrer) {
					if (courses.getCourse(codCourse).getCode() == requirement.getData().getCodCourse()) {
						std::cout << "Falta de requisitos: " << std::endl;
						requirement.getData().showRequirement();
						break;
					}
					else {
						return codCourse;
					}
				}
				std::cout << "El curso no pertenece a la carrera del estudiante." << std::endl;
			}
			std::cout << "El curso no esta registrado." << std::endl;
		}
		cout << "No tiene requisitos" << endl;
		return "";
	}
}
//
bool conflictSchedule(Schedule schedule1, Schedule schedule2){
	if (schedule1.getCode() == schedule2.getCode()) { return true; }
	if (schedule1.getDay() == schedule2.getDay()) {
		if (schedule2.getEndTime() >= schedule1.getStartTime()) {
			return true;
		}
		if (schedule2.getStartTime() <= schedule1.getEndTime()){
			return true;
		}
	}
	return false;
}

bool conflictScheduleList(ScheduleList list, ScheduleList listN) {
	NodeSchedule* currentN = listN.getHead();
	while (currentN != nullptr) {
		NodeSchedule* current = list.getHead();
		while (current != nullptr) {
			if (conflictSchedule(current->getData(), currentN->getData()) == false) {
				return false;
			}
			current = current->getNext();
		}
		currentN = currentN->getNext();
	}
	return true;
}


bool validationGroup(RegistrationDetailsList registrationDetails,GroupList groups,ScheduleList schedules,
	string codRegistraion,Group newGroup) {
	NodeRegistrationDetails* current = registrationDetails.getHead();
	while (current != nullptr) {
		if (current->getData().getRegistrationCode() == codRegistraion) {
			if (current->getData().getCodeGroup()!= newGroup.getNRC()){
				NodeGroup* currentG = groups.getHead();
				while (currentG != nullptr) {
					if (currentG->getData().getNRC() == current->getData().getCodeGroup()) {
						currentG->getData().getSchedule();						
						if (conflictScheduleList( currentG->getData().getSchedule(), newGroup.getSchedule() )== false) {
							cout << "Conflicto de horarios" << endl;
							return false;

						}
					}
					currentG = currentG->getNext();
				}
				
				
			}
			else {
				cout << "Grupo ya matriculado" << endl;
				return false;
			}
		}
		current = current->getNext();
	}
	return true;


}

string  enterGroup(GroupList groups, RegistrationDetailsList registrationDetails, ScheduleList schedules,
	string codRegistraion) {
	while (true) {
		std::cout << "Ingrese el NRC:" << std::endl;
		std::string NRC = enterText();
		if (groups.searchingGroup(NRC)){
			if (validationGroup(registrationDetails, groups, schedules, codRegistraion, groups.getGroup(NRC))){
				return NRC;
			}
		}
		std::cout << "El grupo no esta registrado." << std::endl;
	}
}
//
void registerRegistration(RegistrationDetailsList& registrationDetails, RegistrationList registrations,
	StudentList students, ScheduleList schedules,
	CourseList courses, GroupList groups,
	RequirementList requirements, ApprovedCourseList approvedCourses) {

	//Matricula
	std::cout << "Ingrese datos de Matricula:" << std::endl;
	string codStudent = enterStudent(students);
	std::cout << "Ingrese el codigo de matricula:" << std::endl;
	string codRegistration = enterText();
	std::cout << "Ingrese el a�o cursado:" << std::endl;
	string codYear = enterText();
	std::cout << "Ingrese el semestre:" << std::endl;
	string codSemester = enterText();

	//Detalle de matricula
	Student student = students.getStudent(codStudent);
	courses.printList();
	std::cout << "Ingrese el codigo del curso:" << std::endl;
	string codCourse = " ";
	codCourse = enterCourse(courses, student.getDegree(),requirements);

	//showCourseGroups(codCourse,groups);
	string NCR = enterGroup(groups, registrationDetails, schedules, codRegistration);
	
	Registration newRegistration =Registration(codRegistration,codStudent,codYear,codSemester) ;
	registrations.insertAtBeginning(newRegistration);
	RegistrationDetails newRegistrationDetail = RegistrationDetails(codRegistration,NCR,12500.15, getRandomNumber());
	registrationDetails.insertAtBeginning(newRegistrationDetail);
	int credits = 0;
	float cost = 0.0;
	registrationDetails.getCreditsTotal(credits,cost,codRegistration,groups,courses);
	cout << "Creditos totales del estudiante matriculado: " << credits << endl;
	cout << "Costo total de la matricula del estudiante matriculado: " << cost << endl;
}

//Show
void ShowCoursesGroup(CourseList courses,GroupList groups){
	NodeCourse* current =courses.getHead();
	while (current != nullptr) {
		current->getData().showCourse();

		NodeGroup* currentG = groups.getHead();
		while (currentG != nullptr) {
			if(currentG->getData().getCodeCourses()==current->getData().getCode()){
				currentG->getData().showGroup();
			}
			currentG = currentG->getNext();
		}
		current = current->getNext();
	}


}

void showRegistration(RegistrationList registrations, RegistrationDetailsList registrationDestails) {
	NodeRegistration* current = registrations.getHead();
	while (current != nullptr) {
		NodeRegistrationDetails* currentD = registrationDestails.getHead();
		current->getData().showRegistration();
		while (currentD != nullptr) {
			if (current->getData().getCode() == currentD->getData().getRegistrationCode()) {
				currentD->getData().showRegistrationDetails();
			}
			currentD = currentD->getNext();
		}

		current = current->getNext();
	}
}

