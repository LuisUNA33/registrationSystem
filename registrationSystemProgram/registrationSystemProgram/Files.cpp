#include "Files.h"
// Función para leer un archivo y devolver su contenido
std::string readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string text, line;

    if (!file) {
        std::cerr << "Error al abrir el archivo: " << fileName << std::endl;
        return "";
    }

    while (getline(file, line)) {
		if (line.size() > 8) {
			text += line;
		}
    }
    file.close();
    return text;
}

void writeFile(const std::string& fileName,std::string text) {
	std::ofstream file(fileName, std::ios::app);
	if (!file) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return ;
	}
	//file <<text;
	file << text << endl;

	file.close();
	std::cout << "linea Agregada a " <<fileName<< std::endl;
}

void clearFile(const std::string& fileName) {
	std::ofstream file(fileName);
	if (!file) {
		std::cerr << "Error al abrir el archivo." << std::endl;
		return;
	}
	file <<"";
	file.close();
	std::cout << "Archivo de texto "<<fileName<<" limpiado." << std::endl;
}

void clearAllFiles(){
	clearFile("Students.txt");
	clearFile("Schedules.txt");
	clearFile("Courses.txt");
	clearFile("Groups.txt");
	clearFile("Requirements.txt");
	clearFile("ApprovedCourses.txt");
}
