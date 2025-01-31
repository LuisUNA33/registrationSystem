#include "processes.h"
#include <iostream>
#include <limits>

void about() {
	std::cout << "***	Sistema de registro de matricula estudiantil	***\n" <<
		"Author: Luis Gerardo Sanchez ALvarez\n" <<
		"Vercion del Programa: v2.0\n" <<
		"Incio de desarrollo: 18/12/2024\n" <<
		"Fecha de Ultima actualizacion: 18/01/2025\n" <<
		"Lenguaje de programacion: c++\n" << std::endl;
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
	std::cout << "Ingrese el nombre:" << std::endl;
	std::string name = enterText();
	std::cout << "Ingrese el numero de cedula:" << std::endl;
	std::string id = enterText();
	std::cout << "Ingrese la carrera:" << std::endl;
	std::string degree = enterText();
	std::cout << "Ingrese el nivel:" << std::endl;
	std::string level = enterText();

	studentList[numStudents] = Student(name, id, degree, level);
	numStudents++;
	std::cout << "Estudiante agregado a la lista" << std::endl;
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
	std::cout << "Ingrese codigo de horario: " << std::endl;
	int code = enterNum();
	std::cout << "Dia:" << std::endl;
	std::string day = enterDay();
	int startTime;
	int endTime;
	enterStartEndTime(startTime, endTime);
	std::cout << "Salon de clase:" << std::endl;
	std::string classRoom = enterText();

	scheduleList[numSchedules] = Schedule(code, day, startTime, endTime, classRoom);
	numSchedules++;
	std::cout << "Horario agregado a la lista. " << std::endl;
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
	std::cout << "Ingrese el nombre del curso:" << std::endl;
	std::string name = enterText();
	std::cout << "Ingrese el codigo:" << std::endl;
	std::string code = enterText();
	std::cout << "Ingrese la cantidad de creditos:" << std::endl;
	int credits = enterNum();
	std::cout << "Nombre del Profesor:" << std::endl;
	std::string teacher = enterText();

	std::string option = "";
	while (true) {
		std::cout << "(a)Crear horario y agregarlo a la lista \n(b)Usar Horario existente" << std::endl;
		option = enterText();
		if (option == "a") {
			registerSchedule(scheduleList, numSchedules);
			courseList[numCourse] = Course(name, code, credits, teacher, scheduleList[numSchedules - 1]);
			break;
		}
		if (option == "b") {
			showScheduleList(scheduleList, numSchedules);
			courseList[numCourse] = Course(name, code, credits, teacher, searchSchedule(scheduleList, numSchedules));
			break;
		}
	}
	numCourse++;
	std::cout << "Curso agregado a la lista." << std::endl;
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


