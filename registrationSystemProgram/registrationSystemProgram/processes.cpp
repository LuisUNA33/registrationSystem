#include "processes.h"


void about() {
	std::cout << "***	Sistema de registro de matricula estudiantil	***\n" <<
		"Author: Luis Sanchez, Mathew Ramirez, John Perez \n" <<
		"Version del Programa: v2.0\n" <<
		"Incio de desarrollo: 18/12/2024\n" <<
		"Fecha de Ultima actualizacion: 18/01/2025\n" <<
		"Lenguaje de programacion: c++\n" << std::endl;
	system("Pause");
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
			std::cout << "Deve ingresar un numero:" << std::endl;
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
		std::cout << "No ingreso horas coherentes\nrecuerde solo formato de 24 horas\n solo horas en punto." << std::endl;
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
	std::string carrer[7] = { "Ing en sistemas", "Ing topografia", "Enseñanza de ingles", "Administracion", "Planificacion", "Ing civil", "Ing Quimica" };
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
		cout << "1. Aprobado\n2. Desaprobado" << endl;

		int option = enterNum();
		if (option == 1) {
			return true;
		}
		if (option == 2) {
			return false;
		}

	}

}
//validar registros
//	bool checkConflict(Course * list, int index, Course course) {
//		if (index == 0) {
//			return true;
//		}
//		for (int x = 0; x < index; x++) {
//			if (list[x].getSchedule().getCode() == course.getSchedule().getCode()) { return false; }
//			if (list[x].getSchedule().getDay() == course.getSchedule().getDay()) {
//				if (course.getEndTime() >= list[x].getStartTime()) {
//					return false;
//				}
//				if (course.getStartTime() <= list[x].getEndTime()) {
//					return false;
//				}
//			}
//		}
//		return true;
//	}





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

void registerGroup(GroupList& groupList, string codCourse) {
	std::cout << "Ingrese los datos del Grupo" << std::endl;
	std::cout << "NRC:" << std::endl;
	std::string NRC = enterText();
	std::cout << "Nombre del profesor:" << std::endl;
	std::string codProfessor = enterText();
	std::cout << "Codigo de Horario_A:" << std::endl;
	std::string codSchedule_A = enterText();
	std::cout << "Codigo de Horario_B:" << std::endl;
	std::string codSchedule_B = enterText();
	groupList.insertAtBeginning(Group(NRC, codCourse, codProfessor, codSchedule_A,codSchedule_B));
	std::cout << "Grupo agregado a la lista. " << std::endl;
}

void registerCourse(CourseList& courseList,GroupList& groupList){
	std::cout << "Ingrese los datos del Curso" << std::endl;
	std::cout << "Ingrese codigo de curso: " << std::endl;
	std::string code = enterText();
	std::cout << "Nombre del curso:" << std::endl;
	std::string name = enterText();
	std::cout << "Cantidad de creditos:" << std::endl;
	int credits = enterNum();
	std::cout << "Carrera:" << std::endl;
	std::string carrer = enterCarrer();
	//Grupos para curso
	registerGroup(groupList,code);
	registerGroup(groupList, code);
	//
	courseList.insertAtBeginning(Course(code,name, credits, carrer));
	std::cout << "Curso agregado a la lista. " << std::endl;
}

void registerGroup(GroupList& groupList) {
	std::cout << "Ingrese los datos del Grupo" << std::endl;
	std::cout << "NRC:" << std::endl;
	std::string NRC = enterText();
	std::cout << "Codigo del curso:" << std::endl;
	std::string codCourse = enterText();
	std::cout << "Nombre del profesor:" << std::endl;
	std::string codProfessor = enterText();
	std::cout << "Codigo de Horario_A:" << std::endl;
	std::string codSchedule_A = enterText();
	std::cout << "Codigo de Horario_B:" << std::endl;
	std::string codSchedule_B = enterText();
	groupList.insertAtBeginning(Group(NRC, codCourse, codProfessor, codSchedule_A, codSchedule_B));
	std::cout << "Grupo agregado a la lista. " << std::endl;
}

void registerRequeriment(RequirementList& requirementList) {
	std::cout << "Ingrese los requerimientos del curso,\nSi el requerimiento es '0' se asume que no tiene requerimiento:" << std::endl; 
	std::string carrerDefine = enterCarrer();
	std::cout << "Codigo de curso:" << std::endl;
	std::string codCourse = enterText();
	std::cout << "Requerimiento_A:" << std::endl;
	std::string requirement_A = enterText();
	std::cout << "Requerimiento_B:" << std::endl;
	std::string requirement_B = enterText();
	requirementList.insertAtBeginning(Requirement(carrerDefine,codCourse, requirement_A, requirement_B));
	std::cout << "Requerimientos de curso agregados a la lista. " << std::endl;

}

void registerApprovedCourse(ApprovedCourseList& approvedCourseList) {
	std::cout << "Ingrese el estudiante y su curso:" << std::endl;
	std::cout << "ID del estdudiante:" << std::endl;
	std::string codStudent = enterText();
	std::cout << "Codigo del curso:" << std::endl;
	std::string codCourse = enterText();
	std::cout << "Condicion del estudiante en el curso:" << std::endl;
	approvedCourseList.insertAtBeginning(ApprovedCourse(codStudent, codCourse,enterCondition()));
	std::cout << "Requerimientos de curso agregados a la lista. " << std::endl;
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
//string  enterStudent(StudentList students){
//	while (true) {
//		std::cout << "ID del estdudiante." << std::endl;
//		std::string codStudent = enterText();
//		if (students.searchingStudent(codStudent)) {
//			return codStudent;
//		}
//		std::cout << "El estudiante no esta registrado." << std::endl;
//	}
//}
//string  enterCourse(CourseList courses,string carrer) {
//	while (true) {
//		std::cout << "Codigo del curso:" << std::endl;
//		std::string codCourse = enterText();
//		if (courses.searchingCourse(codCourse)) {
//			if(courses.getCourse(codCourse).getCarrer()==carrer){
//				return codCourse;
//			}
//			std::cout << "El curso no pertenece a la carrera del estudiante." << std::endl;
//		}
//		std::cout << "El curso no esta registrado." << std::endl;
//	}
//}
//
//bool conflictSchedule(Schedule schedule,Schedule newSchedule){
//	return false;
//}
//
//
//bool validationGroup(RegistrationDetailsList registrationDetails,ScheduleList schedules,
//	string codRegistraion,string NRC) {
//	NodeRegistrationDetails* current = registrationDetails.getHead();
//	while (current != nullptr) {
//		if (current->getData().getRegistrationCode() == codRegistraion) {
//			if (current->getData().getCodeGroup()!= NRC){
//				NodeSchedule* currentS = schedules.getHead();
//				while (currentS != nullptr) {
//					if (currentS->getData().getCode() == current->getData().getCodeGroup()){
//						Schedule newSchedule = schedules.searchingSchedule(NRC);
//						if (conflictSchedule(currentS->getData(),newSchedule)==false){
//							return true;
//						}
//						cout << "conflito de horarios" << endl;
//					}
//					currentS = currentS->getNext();
//				}
//			}
//			else {
//				cout << "Grupo ya matriculado" << endl;
//			}
//		}
//		current = current->getNext();
//	}
//	current = current->getNext();
//
//
//}
//
//string  enterGroup(GroupList groups, RegistrationDetailsList registrationDetails, ScheduleList schedules,
//	string codRegistraion) {
//	while (true) {
//		std::cout << "Ingrese el NRC:" << std::endl;
//		std::string NRC = enterText();
//		if (groups.searchingGroup(NRC)) {
//			if(validationGroup(registrationDetails,schedules,codRegistraion,NRC))
//			return NRC;
//		}
//		std::cout << "El grupo no esta registrado." << std::endl;
//	}
//}
//
//void registerRegistration(RegistrationDetailsList& registrationDetails, RegistrationList& registration,
//	StudentList students, ScheduleList schedules,
//	CourseList courses, GroupList groups,
//	RequirementList requirements, ApprovedCourseList approvedCourses,
//	RegistrationList registrations){
//
//	while (true) {
//		//Matricula
//		std::cout << "Ingrese datos de Matricula:" << std::endl;
//		string codStudent = enterStudent(students);
//		std::cout << "Ingrese el codigo de matricula:" << std::endl;
//		string codMatricula = enterText();
//		std::cout << "Ingrese el año cursado:" << std::endl;
//		string codYear = enterText();
//		std::cout << "Ingrese el semestre:" << std::endl;
//		string codSemester = enterText();
//
//		//Detalle de matricula
//		Student student = students.getStudent(codStudent);
//		courses.printList();
//		std::cout << "Ingrese el codigo del curso:" << std::endl;
//		string codCourse = enterCourse(courses,student.getDegree());
//		showCourseGroups(codCourse,groups);
//		string NCR = enterGroup(groups);
//
//		
//	}
//
//}

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