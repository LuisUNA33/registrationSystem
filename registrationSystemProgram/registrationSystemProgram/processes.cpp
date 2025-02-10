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

//Registar---------------------------
void registerStudent(StudentList& studentList){
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::cout << "Ingrese el nombre:" << std::endl;
	std::string name = enterText();
	std::cout << "Ingrese el numero de cedula:" << std::endl;
	std::string id = enterText();
	std::cout << "Ingrese la carrera:" << std::endl;
	std::string degree = enterText();
	std::cout << "Ingrese el nivel:" << std::endl;
	std::string level = enterText();
	studentList.insertAtBeginning(Student(name, id, degree, level));
	std::cout << "Estudiante agregado a la lista" << std::endl;
}

void registerSchedule(ScheduleList& scheduleList) {
	std::cout << "Ingrese los datos del Horario" << std::endl;
	std::cout << "Ingrese codigo de horario: " << std::endl;
	int code = enterNum();
	std::cout << "Dia:" << std::endl;
	std::string day = enterDay();
	int startTime;
	int endTime;
	enterStartEndTime(startTime, endTime);
	std::cout << "Salon de clase:" << std::endl;
	std::string classRoom = enterText();
	scheduleList.insertAtBeginning(Schedule(code, day, startTime, endTime, classRoom));
	std::cout << "Horario agregado a la lista. " << std::endl;
}

void registerCourse(CourseList& courseList){
	std::cout << "Ingrese los datos del Curso" << std::endl;
	std::cout << "Ingrese codigo de curso: " << std::endl;
	std::string code = enterText();
	std::cout << "Nombre del curso:" << std::endl;
	std::string name = enterText();
	std::cout << "Cantidad de creditos:" << std::endl;
	int credits = enterNum();
	std::cout << "Carrera:" << std::endl;
	std::string carrer = enterText();
	courseList.insertAtBeginning(Course(code,name, credits, carrer));
	std::cout << "Curso agregado a la lista. " << std::endl;
}

void registerGroup(GroupList& groupList) {
	std::cout << "Ingrese los datos del Grupo" << std::endl;
	std::cout << "NCR:" << std::endl;
	std::string NCR = enterText();
	std::cout << "Codigo del curso:" << std::endl;
	std::string codCourse = enterText();
	std::cout << "Nombre del profesor:" << std::endl;
	std::string codProfessor = enterText();
	groupList.insertAtBeginning(Group(NCR, codCourse, codProfessor));
	std::cout << "Grupo agregado a la lista. " << std::endl;
}
void registerRequeriment(RequirementList& requirementList) {
	std::cout << "Ingrese los requerimientos del curso,\nSi el requerimiento es '0' se asume que no tiene requerimiento:" << std::endl;
	std::cout << "Codigo de curso:" << std::endl;
	std::string codCourse = enterText();
	std::cout << "Requerimiento_A:" << std::endl;
	std::string requirement_A = enterText();
	std::cout << "Requerimiento_B:" << std::endl;
	std::string requirement_B = enterText();
	requirementList.insertAtBeginning(Requirement(codCourse, requirement_A, requirement_B));
	std::cout << "Requerimientos de curso agregados a la lista. " << std::endl;

}