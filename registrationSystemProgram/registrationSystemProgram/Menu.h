#pragma once
//#include <iostream>
void subMenuA() {
	std::cout << "Archivo:" << std::endl;
	std::cout << "  (a)Acerca de\n"<<
		"  (b)Salir " << std::endl;
	std::cout << "Selecione una opcion:" << std::endl;
	char opcion = ' ';
	std::cin >> opcion;
	switch (opcion) {
	case 'a':
		std::cout << "aopcion1" << std::endl;
		break;
	case 'b':
		std::cout << "aopcion2" << std::endl;
		break;
	default:
		break;
	}
}

void subMenuB() {
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

void subMenuC() {
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

void subMenuD() {
	std::cout << "Consulta:" << std::endl;
	std::cout << "  (a)Estudiantes\n" <<
		"  (b)Cursos \n" << std::endl;
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
	default:
		break;
	}
}


void menu() {
	std::cout<< "Bienvenido al sistema de registro o matricula" << std::endl;
	std::cout << "  (a)Archivo\n" <<
		"  (b)Mantenimiento \n" <<
		"  (c)Matricula\n" <<
		"  (d)Consulta\n" << std::endl;
	std::cout << "Ingrese la opcion que desea realizar: " << std::endl;
	char opcion=' ';
	std::cin >> opcion;
	switch (opcion){
	case 'a':
		subMenuA();
		break;
	case 'b':
		subMenuB();
		break;
	default:
		break;
	}

}