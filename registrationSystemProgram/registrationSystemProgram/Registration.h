#ifndef REGISTRATION_H   
#define REGISTRATION_H 
#include <iostream>
#include <string>
using namespace std;

class Registration {
private:
	string code;
	string codStudent;
	string anio;
	string ciclo;

public:
	Registration();
	~Registration();

	Registration(string code,string codStudent,string anio,string ciclo);

	string getCode();
	string getCodeStudent();
	string getAnio();
	string getCiclo();

	void setCode(string code);
	void setCodeStudent(string codStudent);
	void setAnio(string anio);
	void setCiclo(string ciclo);

	void showRegistration();
};

#endif
