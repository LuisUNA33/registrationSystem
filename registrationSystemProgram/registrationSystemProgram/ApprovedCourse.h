#ifndef ApprovedCourse_H
#define ApprovedCourse_H
#include <iostream>
#include <string>
class ApprovedCourse
{
private:
	std::string codStudent = "";
	std::string codCourse = "";
public:
	ApprovedCourse();
	ApprovedCourse(std::string codStudent, std::string codCourse);
	std::string getCodeStudent();
	std::string getCodeCourse();
	void setCodeStudent(std::string codStudent);
	void setCodeCourse(std::string codCourse);
	void showApprovedCourse();

};

#endif