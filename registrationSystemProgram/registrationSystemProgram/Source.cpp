#include <iostream>
#include <fstream>
#include <string>

//#include "Student.h"


//    // Nombre del archivo
//    std::string nombreArchivo = "archivo.txt";
//
//    // Crear un objeto de tipo ofstream
//    std::ofstream archivoSalida;
//
//    // Abrir el archivo en modo de escritura
//    archivoSalida.open(nombreArchivo);
//
//    // Verificar si el archivo se abrió correctamente
//    if (archivoSalida.is_open()) {
//        // Escribir en el archivo
//        archivoSalida << "Hola, este es un ejemplo de escritura en un archivo .txt.\n";
//        archivoSalida << "Podemos agregar múltiples líneas como esta.\n";
//
//        // Cerrar el archivo
//        archivoSalida.close();
//        std::cout << "Escritura en el archivo completada con éxito.\n";
//    }
//    else {
//        std::cerr << "No se pudo abrir el archivo para escritura.\n";
//    }
//}
//
//void crearArhivotxt(std::string nombreArchivo){
//    std::ofstream archivo;
//    archivo.open(nombreArchivo);
//    archivo.close();
//}
//
//void agregarLineaArchivotxt(std::string nombreArchivo, std::string texto) {
//    std::ofstream archivo;
//    archivo.open(nombreArchivo,std::ios::app);
//    archivo << texto <<std::endl;
//    archivo.close();
//}
//
//
//std::string leerArchivo(std::string nombreArchivo) {
//    std::ifstream archivo;
//    archivo.open(nombreArchivo, std::ios::out);
//    std::string texto = " ";
//    std::string line;
//    while (std::getline(archivo, line)) {
//        texto += line;
//    }
//    archivo.close();
//    return texto;
//}
