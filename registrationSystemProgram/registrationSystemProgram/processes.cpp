#include "processes.h"
#include <iostream>
#include <limits>
#include <fstream>
void about() {
	std::cout << "***	Sistema de registro de matricula estudiantil	***\n" <<
		"Author: Luis Sanchez, Mathew Ramirez, John Perez \n" <<
		"Version del Programa: v2.0\n" <<
		"Incio de desarrollo: 18/12/2024\n" <<
		"Fecha de Ultima actualizacion: 18/01/2025\n" <<
		"Lenguaje de programacion: c++\n" << std::endl;
	system("Pause");
}

void showEnrolledStudents(Registration* registrationList, int numRegistration) {
	for (int x = 0; x < numRegistration; x++) {
		registrationList[x].showRegistration();
	}
}

void showStudentsList(Student* studentList, int numStudent) {
	for (int x = 0; x < numStudent; x++) {
		studentList[x].showStudent();
	}
}

void showCourseList(Course* courseList, int numCourses) {
	for (int x = 0; x < numCourses; x++) {
		courseList[x].showCourse();
	}
}

void showScheduleList(Schedule* scheduleList, int numSchedule) {
	for (int x = 0; x < numSchedule; x++) {
		scheduleList[x].showSchedule();
	}
}

std::string enterText() {
	std::string text;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, text);
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

void registerStudent(Student* studentList, int& numStudents) {
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::string fileName = "archivo.txt";


	std::ifstream checkFile(fileName);
	if (checkFile.is_open()) {
		std::cout << "El archivo ya existe. No se crear� uno nuevo." << std::endl;
		checkFile.close();
	}
	else {
	
		std::ofstream file(fileName);
		if (!file) {
			std::cerr << "Error al crear el archivo." << std::endl;
			return;
		}
		file << "Nombre;ID;Carrera;Nivel\n"; 
		file.close();
		std::cout << "Archivo creado correctamente." << std::endl;
	}

	std::ofstream file("archivo.txt", std::ios::app); 
	if (!file.is_open()) {
		std::cerr << "Error: No se pudo abrir el archivo 'studentsSaveInfo.txt'." << std::endl;
		system("PAUSE");
		return;
	}

	std::string name, id, degree, level;
	char option;

	do {
		std::cout << "Ingrese el nombre del estudiante: ";
		std::getline(std::cin, name);

		std::cout << "Ingrese el ID del estudiante: ";
		std::getline(std::cin, id);

		std::cout << "Ingrese la carrera del estudiante: ";
		std::getline(std::cin, degree);

		std::cout << "Ingrese el nivel del estudiante: ";
		std::getline(std::cin, level);

		file << name << ";" << id << ";" << degree << ";" << level << "\n";
		file.flush(); 

		std::cout << "�Desea agregar otro estudiante? (s/n): ";
		std::cin >> option;

	} while (option == 's' || option == 'S');

	file.close();
	std::cout << "Datos guardados correctamente en 'studentsSaveInfo.txt'.\n";

	studentList[numStudents] = Student(name, id, degree, level);
	numStudents++;
	std::cout << "Estudiante agregado a la lista" << std::endl;

	system("PAUSE");
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

void registerSchedule(Schedule* scheduleList, int& numSchedules) {
	std::cout << "Ingrese los datos del Horario" << std::endl;
	std::string fileName = "Schedule.txt";

	std::ifstream checkFile(fileName);
	bool fileExists = checkFile.good(); 
	checkFile.close();

	std::ofstream file(fileName, std::ios::app);
	if (!file) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return;
	}

	if (!fileExists) {
		file << "codigo;dia;horaInicial;horaFinal;salon\n";
	}


	std::cout << "Ingrese codigo de horario: ";
	int code = enterNum();

	std::cout << "Dia: ";
	std::string day = enterDay();

	int startTime, endTime;
	enterStartEndTime(startTime, endTime);

	std::cout << "Salon de clase: ";
	std::string classRoom = enterText();


	file << code << ";" << day << ";" << startTime << ";" << endTime << ";" << classRoom << "\n";


	file.close();


	scheduleList[numSchedules] = Schedule(code, day, startTime, endTime, classRoom);
	numSchedules++;

	std::cout << "Horario agregado correctamente al archivo y a la lista." << std::endl;
	system("PAUSE");
}


Schedule searchSchedule(Schedule* scheduleList, int numSchedules) {
	while (true) {
		std::cout << "Ingrese el codigo del horario:" << std::endl;
		int code = enterNum();
		for (int x = 0; x < numSchedules; x++) {
			if (scheduleList[x].getCode() == code) {
				return scheduleList[x];
			}
		}
		std::cout << "Horario no encontrado en la lista." << std::endl;
	}
}

void registerCourse(Course* courseList, int& numCourse, Schedule* scheduleList, int& numSchedules) {
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::string fileName = "Course.txt";

	std::ifstream checkFile(fileName);
	bool fileExists = checkFile.good(); 
	checkFile.close();

	std::ofstream file(fileName, std::ios::app);
	if (!file) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return;
	}

	if (!fileExists) {
		file << "nombreDelCurso;codigo;creditos;nombreDelProfesor;codigoHorario\n";
	}

	std::cout << "Ingrese el nombre del curso:" << std::endl;
	std::string name = enterText();

	std::cout << "Ingrese el c�digo:" << std::endl;
	std::string code = enterText();

	std::cout << "Ingrese la cantidad de cr�ditos:" << std::endl;
	int credits = enterNum();

	std::cout << "Nombre del Profesor:" << std::endl;
	std::string teacher = enterText();

	std::string option;
	Schedule selectedSchedule;

	while (true) {
		std::cout << "(a) Crear horario y agregarlo a la lista \n(b) Usar Horario existente" << std::endl;
		option = enterText();
		if (option == "a") {
			registerSchedule(scheduleList, numSchedules);
			selectedSchedule = scheduleList[numSchedules - 1]; 
			break;
		}
		if (option == "b") {
			showScheduleList(scheduleList, numSchedules);
			selectedSchedule = searchSchedule(scheduleList, numSchedules);
			break;
		}
	}


	courseList[numCourse] = Course(name, code, credits, teacher, selectedSchedule);
	numCourse++;

	file << name << ";" << code << ";" << credits << ";" << teacher << ";" << selectedSchedule.getCode() << "\n";

	file.close();

	std::cout << "Curso agregado correctamente al archivo y a la lista." << std::endl;
	system("PAUSE");
}


Student searchStudent(Student* studentList, int numStudents) {
	showStudentsList(studentList, numStudents);
	while (true) {
		std::cout << "Ingrese el numero de cedula del estudiante a matricular:" << std::endl;
		std::string id;
		id = enterText();
		for (int x = 0; x < numStudents; x++) {
			if (studentList[x].getId() == id) {
				return studentList[x];
			}
		}
		std::cout << "Estudiante no encontrado en la lista." << std::endl;
	}
}

Course searchCourse(Course* courseList, int numCourse) {
	while (true) {
		std::cout << "Ingrese el codigo del curso: " << std::endl;
		std::string code = enterText();
		for (int x = 0; x < numCourse; x++) {
			if (courseList[x].getCode() == code) {
				return courseList[x];
			}
		}
		std::cout << "Curso no encontrado. Intente nuevamente." << std::endl;
	}
}

bool checkConflict(Course* list, int index, Course course) {
	if (index == 0) {
		return true;
	}
	for (int x = 0; x < index; x++) {
		if (list[x].getSchedule().getCode() == course.getSchedule().getCode()) { return false; }
		if (list[x].getSchedule().getDay() == course.getSchedule().getDay()) {
			if (course.getEndTime() >= list[x].getStartTime()) {
				return false;
			}
			if (course.getStartTime() <= list[x].getEndTime()) {
				return false;
			}
		}
	}
	return true;
}

Course* addCoursesList(Course* courseList, int numCourse, int& index, int& totalCredits) {
	Course* list = new Course[10];
	showCourseList(courseList, numCourse);
	std::string option = "a";
	while (true) {
		if (option == "a") {
			Course course = searchCourse(courseList, numCourse);
			if (checkConflict(list, index, course)) {
				list[index] = course;
				totalCredits += course.getCredits();
				index++;
			}
			else {
				std::cout << "Conflicto de horarios\n No se agrego el curso" << std::endl;
			}

		}
		if (option == "b") {
			return list;
		}
		std::cout << "\n(a) Agregar otro curso\n(b) Terminar: " << std::endl;
		option = enterText();
	}
}

bool isRegistered(Registration* registrationList, int& numRegistration, std::string id) {
	for (int x = 0; x < numRegistration; x++) {
		if (registrationList[x].getStudent().getId() == id) {
			return true;
		}
	}
	return false;
}

void addRegistration(Registration* registrationList, int& numRegistration,
	Student* studentList, int numStudents, Course* courseList, int numCourse, Schedule* scheduleList, int numSchedules) {

	Student student = searchStudent(studentList, numStudents);
	if (isRegistered(registrationList, numRegistration, student.getId()) == true) {
		std::cout << "Este estudiante ya esta matriculado" << std::endl;
		return;
	}
	int courseIndex = 0;
	int totalCredits = 0;
	Course* list = addCoursesList(courseList, numCourse, courseIndex, totalCredits);
	registrationList[numRegistration] = Registration(list, courseIndex, student);
	numRegistration += 1;
	std::cout << "El total de creditos matriculados:" << totalCredits << std::endl;
	std::cout << "A 12700 por credito: " << totalCredits * 12700 << "colones" << std::endl;
	std::cout << "Matricula completada. " << std::endl;

}


