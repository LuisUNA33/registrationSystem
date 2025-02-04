#include "Menu.h"

bool subMenuA() {
    char option;
    while (true) {
        system("CLS");
        std::cout << "=== Archivo ===" << std::endl;
        std::cout << "a) Acerca de" << std::endl;
        std::cout << "b) Salir del Programa" << std::endl;
        std::cout << "c) Ir al Menu principal" << std::endl;
        std::cout << "Ingrese alguna opcion disponible: " << std::endl;
        std::cin >> option;

        option = std::tolower(option);

        switch (option) {
        case 'a':
            about();
            return false;
        case 'b':
            std::cout << "Saliendo....." << std::endl;
            return true;
        case 'c':
            return false;
        default:
            return false;
        }
    }
}

void subMenuB() {
    system("CLS");
    char option;
    while (true) {
        system("CLS");
        std::cout << "=== Mantenimiento ===" << std::endl;
        std::cout << "a) Estudiantes" << std::endl;
        std::cout << "b) Cursos" << std::endl;
        std::cout << "c) Horarios" << std::endl;
        std::cout << "d) regresar " << std::endl;
        std::cout << "Ingrese alguna opcion disponible: " << std::endl;

        option = enterChar(); // Solo se usa esta lectura

        switch (option) {
        case 'a':
            system("CLS");
            //registerStudent(studentList, numStudents);
            break;
        case 'b':
            system("CLS");
            //registerCourse(courseList, numCourse, scheduleList, numSchedules);
            break;
        case 'c':
            system("CLS");
            //registerSchedule(scheduleList, numSchedules);
            break;
        case 'd':
            return;
        default:
            std::cout << "Opcion no valida, intente nuevamente." << std::endl;
            break;
        }
    }
}

void subMenuC() {
    system("CLS");
    char option;
    do {
        std::cout << "Matricula:" << std::endl;
        std::cout << "  (a)Registro de matricula" << std::endl;
        std::cout << "  (b)Registro de matricula" << std::endl;
        std::cout << "  (c) regresar " << std::endl;
        std::cout << "Selecione una opcion:" << std::endl;
        option = enterChar();
        switch (option) {
        case 'a':
            //addRegistration(registrationList, numRegistration,
            //    studentList, numStudents, courseList, numCourse, scheduleList, numSchedules);
        case 'b':
            return;

        default:
            break;
        }
    } while (option != 'a' && option != 'b' && option != 'c');

}


void subMenuD() {
	std::cout << "Consulta:" << std::endl;
    system("CLS");
    char option;
    while (true) {
        std::cout << "  (a)Estudiantes(Lista de estudiantes)" << std::endl;
        std::cout << "  (b)Cursos(Lista de los cursos)"<< std::endl;
        std::cout << "  (c)Horarios(Lista de Horarios)" << std::endl;
        std::cout << "  (d)Estudiantes Matriculados(Todos los matriculados)" << std::endl;
        std::cout << "  (e)regresar" << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	option = enterChar();
	switch (option) {
	case 'a':
		//showStudentsList(studentList, numStudents);
		break;
	case 'b':
		//showCourseList(courseList, numCourse);
		break;
	case 'c':
		//showScheduleList(scheduleList, numSchedules);
		break;
	case 'd':
		//showEnrolledStudents(registrationList, numRegistration);
		break;
    case 'e':
        return;
	default:
		break;
	}
    }
}


void menu() {
  
	bool exit = false;
	while (exit == false) {
        system("CLS");
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
			exit = subMenuA();
			break;
		case 'b':
			subMenuB();
			break;
		case 'c':
			subMenuC();
			break;
		case 'd':
			subMenuD();
			break;
		default:
			break;
		}
	}

}




