#pragma once

void about() {
	std::cout << "***	Sistema de registro de matricula estudiantil	***\n" <<
		"Author: Luis Gerardo Sanchez ALvarez\n" <<
		"Vercion del Programa: v1.0\n" <<
		"Incio de desarrollo: 18/12/2024\n" <<
		"Fecha de Ultima actualizacion: 14/01/2025\n" <<
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
	std::cin >> text;
	return text;
}
int enterNum() {
	int num;
	std::cin >> num;
	return num;
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
}

void registerSchedule(Schedule* scheduleList, int& numSchedules) {
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

	registerSchedule(scheduleList, numSchedules);

	courseList[numCourse] = Course(name, code, credits, teacher, scheduleList[numSchedules-1]);
	numCourse++;
}
Student searchStudent(Student* studentList, int numStudents) {
	showStudentsList(studentList, numStudents);
	while (true) {
		std::cout << "Ingrese el numero de cedula del estudiante a matricular:" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::string id;
		std::cin >> id;
		for (int x = 0; x < numStudents; x++) {
			if (studentList[x].getId() == id) {
				return studentList[x];
			}
		}
		std::cout << "Estudiante no encontrado en la lista." << std::endl;
	}
}

Course searchCourse(Course* courseList, int numCourse) {
	std::cout << "Ingrese el codigo del curso: " << std::endl;
	std::string code;
	std::cin >> code;
	for (int x = 0; x < numCourse; x++) {
		if (courseList[x].getCode() == code) {
			return courseList[x];
		}
	}
}
Course* addCoursesList(Course* courseList, int numCourse,int &index,int &totalCredits){
	Course* list = new Course[10];
	showCourseList(courseList, numCourse);
	std::string option = "a";
	while (true){
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (option == "a") {
			Course course = searchCourse(courseList, numCourse);
			list[index] = course;
			totalCredits += course.getCredits();
			index++;
		}
		if(option=="b") {
			return list;
		}
		std::cout << "\n(a) Agregar Curso \n(b) Terminar: " << std::endl;
		std::cin >> option;
	}
}

void registerRegistration(Registration* registrationList,int & numRegistration,
	Student* studentList, int numStudents,Course* courseList, int numCourse, Schedule* scheduleList, int numSchedules){
	std::cout << numRegistration << std::endl;
	Student student=searchStudent(studentList,numStudents);
	int courseIndex = 0;
	int totalCredits = 0;
	Course* list = addCoursesList(courseList, numCourse, courseIndex, totalCredits);
	//Registration(list, courseIndex, student).showRegistration();
	registrationList[numRegistration]= Registration(list, courseIndex,student);
	numRegistration += 1;
	std::cout << "El total de creditos matriculados:" <<totalCredits<< std::endl;
	std::cout << "A 12700 por credito: " << totalCredits*12700 << "colones"<<std::endl;
	std::cout << "Matricula completada"<< std::endl;

}