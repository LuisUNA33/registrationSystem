#ifndef FILES_H   
#define FILES_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readFile(const string& fileName);
void writeFile(const string& fileName,string text );

#endif