#ifndef Requirement_H
#define Requirement_H
#include <iostream>
#include <string>
class Requirement
{
private:
	std::string codeCourse = "";
	std::string  requirement_A= "";
	std::string  requirement_B= "";
public:
	Requirement();
	Requirement(std::string CodeCourse, std::string Requirements_A, std::string Requirements_B);
	std::string getRequirement_A();
	std::string getRequirement_B();
	std::string codCourse();
	void setRequirement_A(std::string requirement_A);
	void setRequirement_B(std::string requirement_B);
	void setCodCourse(std::string codeCourse);
	void showRequirements();

};

#endif