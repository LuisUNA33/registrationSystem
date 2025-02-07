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
        text += line + "\n";
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
	file << text <<"\n";

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

