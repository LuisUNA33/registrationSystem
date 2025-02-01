#include "processes.h"
#include <iostream>
#include <limits>
#include "loadPreRecords.h"
#include <fstream>
#include "Student.h"
void about() {
	std::cout << "***	Sistema de registro de matricula estudiantil	***\n" <<
		"Author: Luis Sanchez, Mathew Ramirez, John Perez \n" <<
		"Version del Programa: v2.0\n" <<
		"Incio de desarrollo: 18/12/2024\n" <<
		"Fecha de Ultima actualizacion: 18/01/2025\n" <<
		"Lenguaje de programacion: c++\n" << std::endl;
	system("Pause");
}

void showEnrolledStudents(RegistrationNode*& registrationList) {
	RegistrationNode* current = registrationList; // Apunta al primer nodo
	while (current != nullptr) {
		current->registration.showRegistration(); // Llamamos a la funci�n para mostrar el registro
		current = current->next; // Avanzamos al siguiente nodo
	}
}

void showStudentsList(StudentNode* head) {
	if (!head) {
		std::cout << "No hay estudiantes registrados.\n";
		return;
	}

	std::cout << "Lista de Estudiantes:\n";
	std::cout << "------------------------------------------------------\n";
	std::cout << "Nombre\t\tID\t\tCarrera\t\tA�o\n";
	std::cout << "------------------------------------------------------\n";

	while (head) {
		std::cout << head->student.name;
		if (head->student.name.length() < 8) std::cout << "\t\t";
		else std::cout << "\t";

		std::cout << head->student.id << "\t\t"
			<< head->student.degree << "\t\t"
			<< head->student.level << std::endl;

		head = head->next;
	}

	std::cout << "------------------------------------------------------\n";
}

void showCourseList(const CourseNode* courseList) {
	while (courseList != nullptr) {
		std::cout << "Curso: " << courseList->courseName << std::endl;
		courseList = courseList->next;  // Mover al siguiente nodo
	}
}

void showScheduleList(const ScheduleNode* scheduleList) {
	while (scheduleList != nullptr) {
		std::cout << "D�a: " << scheduleList->day
			<< " | Hora: " << scheduleList->time
			<< " | Curso: " << scheduleList->course
			<< std::endl;
		scheduleList = scheduleList->next;  // Mover al siguiente nodo
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

void registerStudent(StudentNode*& studentList) {
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::string fileName = "archivo.txt";

	// Verificar si el archivo existe
	std::ifstream checkFile(fileName);
	if (!checkFile) {
		std::ofstream file(fileName);
		if (!file) {
			std::cerr << "Error al crear el archivo." << std::endl;
			return;
		}
		file << "Nombre;ID;Carrera;Nivel\n";
		file.close();
		std::cout << "Archivo creado correctamente." << std::endl;
	}
	checkFile.close();

	// Abrir el archivo en modo append
	std::ofstream file(fileName, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Error: No se pudo abrir el archivo '" << fileName << "'." << std::endl;
		return;
	}

	std::string name, id, degree, level;
	char option;

	do {
		std::cin.ignore();  // Limpiar el buffer antes de usar getline

		std::cout << "Ingrese el nombre del estudiante: ";
		std::getline(std::cin, name);

		std::cout << "Ingrese el ID del estudiante: ";
		std::getline(std::cin, id);

		std::cout << "Ingrese la carrera del estudiante: ";
		std::getline(std::cin, degree);

		std::cout << "Ingrese el nivel del estudiante: ";
		std::getline(std::cin, level);

		// Guardar en el archivo
		file << name << ";" << id << ";" << degree << ";" << level << "\n";
		file.flush();

		// Insertar en la lista enlazada
		Student newStudent(name, id, degree, level);
		StudentNode* newNode = new StudentNode{ newStudent, nullptr };

		if (!studentList) {
			studentList = newNode;
		}
		else {
			StudentNode* temp = studentList;
			while (temp->next) temp = temp->next;
			temp->next = newNode;
		}

		std::cout << "�Desea agregar otro estudiante? (s/n): ";
		std::cin >> option;

	} while (option == 's' || option == 'S');

	file.close();
	std::cout << "Datos guardados correctamente en '" << fileName << "'.\n";

	std::cout << "Presione ENTER para continuar...";
	std::cin.ignore();  // Evitar problemas con la espera de entrada en consola
	std::cin.get();
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

void registerSchedule(ScheduleNode*& scheduleList) {
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
	
		ScheduleNode* newNode = new ScheduleNode{ schedule, nullptr };
		if (!head) {
			head = newNode;
		}
		else {
			ScheduleNode* temp = head;
			while (temp->next) temp = temp->next;
			temp->next = newNode;
		}
	
	file.close();
	std::cout << "Horario agregado correctamente al archivo y a la lista." << std::endl;
	system("PAUSE");
}


Schedule searchSchedule(const ScheduleNode* scheduleList) {
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

void registerCourse(CourseNode*& head, ScheduleNode*& scheduleHead) {
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::string fileName = "Course.txt";

	// Verificar si el archivo existe
	std::ifstream checkFile(fileName);
	bool fileExists = checkFile.good();
	checkFile.close();

	// Abrir el archivo en modo append
	std::ofstream file(fileName, std::ios::app);
	if (!file) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return;
	}

	// Si el archivo no existe, escribir la cabecera
	if (!fileExists) {
		file << "nombreDelCurso;codigo;creditos;nombreDelProfesor;codigoHorario\n";
	}

	std::string name, code, teacher;
	int credits;
	Schedule selectedSchedule;

	// Solicitar datos del curso
	std::cout << "Ingrese el nombre del curso: ";
	std::getline(std::cin, name);

	std::cout << "Ingrese el c�digo del curso: ";
	std::getline(std::cin, code);

	std::cout << "Ingrese la cantidad de cr�ditos: ";
	std::cin >> credits;
	std::cin.ignore();  // Evitar problemas con std::getline()

	std::cout << "Ingrese el nombre del profesor: ";
	std::getline(std::cin, teacher);

	std::string option;
	while (true) {
		std::cout << "(a) Crear horario y agregarlo a la lista \n(b) Usar horario existente\n";
		std::getline(std::cin, option);

		if (option == "a") {
			 ScheduleNode* (scheduleHead);  // Registrar nuevo horario
			selectedSchedule = scheduleHead->schedule;  // Tomar el �ltimo agregado
			break;
		}
		if (option == "b") {
			showScheduleList(scheduleHead);
			selectedSchedule = searchSchedule(scheduleHead);
			break;
		}
		std::cout << "Opci�n inv�lida. Intente de nuevo." << std::endl;
	}

	// Crear el curso y agregarlo a la lista enlazada
	Course newCourse(name, code, credits, teacher, selectedSchedule);
	CourseNode* newNode = new CourseNode{ newCourse, nullptr };

	if (!head) {
		head = newNode;
	}
	else {
		CourseNode* temp = head;
		while (temp->next) temp = temp->next;
		temp->next = newNode;
	}

	// Guardar en el archivo
	file << name << ";" << code << ";" << credits << ";" << teacher << ";" << selectedSchedule.getCode() << "\n";
	file.close();

	std::cout << "Curso agregado correctamente al archivo y a la lista." << std::endl;
}


Student searchStudent(const StudentNode* studentList) {
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

Course searchCourse(const CourseNode* courseList) {
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

bool checkConflict(const CourseNode* list, int index, Course course) {
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

Course* addCoursesList(const CourseNode* courseList, int numCourse, int& index, int& totalCredits) {
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

bool isRegistered(const RegistrationNode* registrationList, int& numRegistration, std::string id) {
	for (int x = 0; x < numRegistration; x++) {
		if (registrationList[x].getStudent().getId() == id) {
			return true;
		}
	}
	return false;
}

void addRegistration(RegistrationNode*& registrationList,StudentNode*& studentList, CourseNode*& courseList, ScheduleNode*& scheduleList) {

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


