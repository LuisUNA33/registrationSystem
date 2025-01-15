#pragma once
//#include <iostream>
bool subMenuA() {
	std::cout << "Archivo:" << std::endl;
	std::cout << "  (a)Acerca de\n"<<
		"  (b)Salir " << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char opcion = ' ';
	std::cin >> opcion;
	switch (opcion) {
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

void subMenuB(Registration** registrationList, int rows, int columns, int recordedAmount) {
	std::cout << "Mantenimiento:" << std::endl;
	std::cout << "  (a)Estudiantes\n" <<
		"  (b)Cursos \n" <<
		"  (c)Horarios"<<std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char opcion = ' ';
	std::cin >> opcion;
	switch (opcion) {
	case 'a':
		std::cout << "bopcion1" << std::endl;
		break;
	case 'b':
		std::cout << "bopcion2" << std::endl;
		break;
	case 'c':
		std::cout << "bopcion3" << std::endl;
		break;
	default:
		break;
	}
}

void subMenuC(Registration** registrationList, int rows, int columns, int recordedAmount) {
	std::cout << "Matricula:" << std::endl;
	std::cout << "  (a)Registro de matricula" << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char opcion = ' ';
	std::cin >> opcion;
	switch (opcion) {
	case 'a':
		std::cout << "bopcion1" << std::endl;
		break;
	default:
		break;
	}
}

void subMenuD(Registration** registrationList, int rows, int columns, int recordedAmount, Course* courseList, int numCourse, Student* studentList, int numStudents) {
	std::cout << "Consulta:" << std::endl;
	std::cout << "  (a)Estudiantes(Lista de estudiantes)\n" <<
		"  (b)Cursos(Lista de los cursos)\n" <<
		"  (c)Estudiantes Matriculados(Todos los matriculados) \n" << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char opcion = ' ';
	std::cin >> opcion;
	switch (opcion) {
	case 'a':
		showStudentsList(studentList,numStudents);
		break;
	case 'b':
		std::cout << "bopcion2" << std::endl;
		break;
	case 'c':
		showEnrolledStudents(registrationList, rows, columns, recordedAmount);
		break;
	default:
		break;
	}
}


void menu(Registration** registrationList, int rows, int columns, int recordedAmount,Course* courseList,int numCourse,Student* studentList,int numStudents) {
	bool exit = false;
	while (exit==false) {
		std::cout << "\nBienvenido al sistema de registro o matricula" << std::endl;
		std::cout << "  (a)Archivo\n" <<
			"  (b)Mantenimiento \n" <<
			"  (c)Matricula\n" <<
			"  (d)Consulta\n" << std::endl;
		std::cout << "Ingrese la opcion que desea realizar: " << std::endl;
		char opcion = ' ';
		std::cin >> opcion;
		switch (opcion) {
		case 'a':
			exit=subMenuA();
			break;
		case 'b':
			subMenuB(registrationList, rows, columns, recordedAmount);
			break;
		case 'c':
			subMenuC(registrationList, rows, columns, recordedAmount);
			break;
		case 'd':
			subMenuD(registrationList,rows,columns,recordedAmount,courseList,numCourse,studentList,numStudents);
			break;
		default:
			break;
		}
	}

}