#ifndef REGISTRATION_H   
#define REGISTRATION_H 
#include <iostream>
#include <string>
using namespace std;

class Registration {
private:
	string code;
	string codStudent;
	string year;
	string semester;

public:
	Registration();
	~Registration();

	Registration(string code,string codStudent,string year,string semester);

	string getCode();
	string getCodeStudent();
	string getYear();
	string getSemester();

	void setCode(string code);
	void setCodeStudent(string codStudent);
	void setYear(string year);
	void setSemester(string semester);

	void showRegistration();
};

#endif
