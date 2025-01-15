#pragma once

void about() {
	std::cout << "***	Sistema de registro de matricula estudiantil	***\n" <<
		"Author: Luis Gerardo Sanchez ALvarez\n" <<
		"Vercion del Programa: v1.0\n" <<
		"Incio de desarrollo: 18/12/2024\n" <<
		"Fecha de Ultima actualizacion: 14/01/2025\n" <<
		"Lenguaje de programacion: c++\n" << std::endl;
}

void showEnrolledStudents(Registration** registrationList,int rows,int columns,int recordedAmount){
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < columns; y++) {
			if (recordedAmount == 0) {
				return;
			}
			registrationList[x][y].showRegistration();
			recordedAmount --;
		}
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

std::string enterText() {
	std::string text;
	std::cin >> text;
	return text;
}

void registerStudent(){
	std::cout << "Ingrese los datos solicitados" << std::endl;

	std::cout << "Ingrese el nombre:" << std::endl;
	std::string name = enterText();
	std::cout << "Ingrese el numero de cedula:" << std::endl;
	std::string id= enterText();
	std::cout << "Ingrese la carrera:" << std::endl;
	std::string degree = enterText();
	std::cout << "Ingrese el nivel:" << std::endl;
	std::string level = enterText();
}