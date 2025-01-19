#pragma once
//#include <iostream>
bool subMenuA() {
	std::cout << "Archivo:" << std::endl;
	std::cout << "  (a)Acerca de\n"<<
		"  (b)Salir " << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char option=enterChar();
	switch (option) {
	case 'a':
		about();
		return false;
	case 'b':
		std::cout << "Saliendo....." << std::endl;
		return true;
	default:
		return false;
	}
}

void subMenuB(Course* courseList, int& numCourse, 
	Student* studentList, int& numStudents,
	Schedule* scheduleList, int& numSchedules){
	std::cout << "Mantenimiento:" << std::endl;
	std::cout << "  (a)Estudiantes(Agrega estudiante a lista))\n" <<
		"  (b)Cursos(Agrega curso a lista) \n" <<
		"  (c)Horarios(Agrega horario a lista)"<<std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char option = enterChar();
	switch (option) {
	case 'a':
		registerStudent(studentList,numStudents);
		break;
	case 'b':
		registerCourse(courseList,numCourse,scheduleList,numSchedules);
		break;
	case 'c':
		registerSchedule(scheduleList, numSchedules);
		break;
	default:
		break;
	}
}

void subMenuC(Registration* registrationList,int& numRegistration,
	Student* studentList, int numStudents, Course* courseList, int numCourse, Schedule* scheduleList, int numSchedules) {
	std::cout << "Matricula:" << std::endl;
	std::cout << "  (a)Registro de matricula" << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char option = enterChar();
	switch (option) {
	case 'a':
		addRegistration(registrationList,numRegistration,
			studentList,numStudents,courseList,numCourse,scheduleList,numSchedules);
		break;
	default:
		break;
	}
}

void subMenuD(Registration* registrationList,int numRegistration,
	Course* courseList, int numCourse, 
	Student* studentList, int numStudents,
	Schedule* scheduleList, int numSchedules) {
	std::cout << "Consulta:" << std::endl;
	std::cout << "  (a)Estudiantes(Lista de estudiantes)\n" <<
		"  (b)Cursos(Lista de los cursos)\n" <<
		"  (c)Horarios(Lista de Horarios)\n" <<
		"  (d)Estudiantes Matriculados(Todos los matriculados) \n" << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char option = enterChar();
	switch (option) {
	case 'a':
		showStudentsList(studentList,numStudents);
		break;
	case 'b':
		showCourseList(courseList, numCourse);
		break;
	case 'c':
		showScheduleList(scheduleList,numSchedules);
		break;
	case 'd':
		showEnrolledStudents(registrationList,numRegistration);
		break;
	default:
		break;
	}
}


void menu(Registration* registrationList,int& numRegistration,
	Course* courseList,int& numCourse,
	Student* studentList,int& numStudents,
	Schedule* scheduleList, int& numSchedules) {
	bool exit = false;
	while (exit==false) {
		std::cout << "\nBienvenido al sistema de registro o matricula" << std::endl;
		std::cout << "  (a)Archivo\n" <<
			"  (b)Mantenimiento \n" <<
			"  (c)Matricula\n" <<
			"  (d)Consulta\n" << std::endl;
		std::cout << "Ingrese la opcion que desea realizar: " << std::endl;
		char option = enterChar();
		//char option =' ';
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cin >> option;
		switch (option) {
		case 'a':
			exit=subMenuA();
			break;
		case 'b':
			subMenuB(courseList, numCourse, studentList, numStudents,scheduleList,numSchedules);
			break;
		case 'c':
			subMenuC(registrationList, numRegistration,
				studentList, numStudents, courseList, numCourse, scheduleList, numSchedules);
			break;
		case 'd':
			subMenuD(registrationList,numRegistration,
				courseList,numCourse,
				studentList,numStudents,
				scheduleList,numSchedules);
			break;
		default:
			break;
		}
	}

}