#ifndef ApprovedCourse_H
#define ApprovedCourse_H
#include <iostream>
#include <string>
class ApprovedCourse
{
private:
	std::string codStudent = "";
	std::string codCourse = "";
	bool condition="";
public:
	ApprovedCourse();
	ApprovedCourse(std::string codStudent, std::string codCourse,bool condition);
	std::string getCodeStudent();
	std::string getCodeCourse();
	bool getCondition();
	void setCondition(bool condition);
	void setCodeStudent(std::string codStudent);
	void setCodeCourse(std::string codCourse);
	void showApprovedCourse();
	

};

#endif