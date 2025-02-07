#ifndef FILES_H   
#define FILES_H
#include <iostream>
#include <fstream>
#include <string>

//#include "NodeStudent.h"
using namespace std;

string readFile(const string& fileName);
void writeFile(const string& fileName,string text );
void clearFile(const std::string& fileName);

#endif