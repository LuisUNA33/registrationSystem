#ifndef Requirement_H
#define Requirement_H
#include <iostream>
#include <string>
class Requirement
{
private:
	std::string codeCourse = "";
	std::string  requirement= "";
	
public:
	Requirement();
	Requirement(std::string CodeCourse, std::string Requirements);
	std::string getRequirements();
	std::string getCodCourse();
	void setRequirements(std::string requirements);
	void setCodCourse(std::string codeCourse);
	void showRequirement();

};

#endif