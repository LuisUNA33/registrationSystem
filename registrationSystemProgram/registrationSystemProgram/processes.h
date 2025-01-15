#pragma once

void about() {
	std::cout <<"Luis Gerado Sanchez Alvarez"<< std::endl;
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