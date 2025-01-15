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

void showScheduleList(Schedule* scheduleList, int numSchedule) {
	for (int x = 0; x < numSchedule; x++) {
		scheduleList[x].showSchedule();
	}
}

std::string enterText() {
	std::string text;
	std::cin >> text;
	return text;
}
int enterNum() {
	int num;
	std::cin >> num;
	return num;
}

void registerStudent(Student* studentList,int& numStudents){
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::cout << "Ingrese el nombre:" << std::endl;
	std::string name = enterText();
	std::cout << "Ingrese el numero de cedula:" << std::endl;
	std::string id= enterText();
	std::cout << "Ingrese la carrera:" << std::endl;
	std::string degree = enterText();
	std::cout << "Ingrese el nivel:" << std::endl;
	std::string level = enterText();

	studentList[numStudents] = Student(name,id,degree,level);
	numStudents++;
}

Schedule registerSchedule(Schedule* scheduleList,int &numSchedules) {
	std::cout << "Ingrese los datos del Horario" << std::endl;
	std::cout << "Dia:" << std::endl;
	std::string day = enterText();
	std::cout << "Hora de inicio:" << std::endl;
	std::string startTime = enterText();
	std::cout << "Hora de fin:" << std::endl;
	std::string endTime = enterText();
	std::cout << "Salon de clase:" << std::endl;
	std::string classRoom = enterText();

	scheduleList[numSchedules] = Schedule(day, startTime, endTime, classRoom);
	numSchedules++;
	return scheduleList[numSchedules];
}

void registerCourse(Course* courseList, int& numCourse, Schedule* scheduleList, int& numSchedules){
	std::cout << "Ingrese los datos solicitados" << std::endl;
	std::cout << "Ingrese el nombre del curso:" << std::endl;
	std::string name = enterText();
	std::cout << "Ingrese el codigo:" << std::endl;
	std::string code = enterText();
	std::cout << "Ingrese la cantidad de creditos:" << std::endl;
	int credits = enterNum();
	std::cout << "Nombre del Profesor:" << std::endl;
	std::string teacher = enterText();

	Schedule schedule = registerSchedule(scheduleList,numSchedules);

	courseList[numCourse]=Course(name,code,credits,teacher,schedule);
	numCourse++;
}