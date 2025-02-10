#ifndef STUDENT_H   
#define STUDENT_H
#include <iostream>
#include <string>

class Student {
	private:
		std::string name;
		std::string id;
		std::string degree;
		std::string level;
	

	public:
		Student();
		~Student();
		Student(std::string name, std::string id, std::string degree, std::string level);
		std::string getName();
		std::string getId();
		std::string getDegree();
		std::string getLevel();
		void setName(std::string name);
		void setId(std::string id);
		void setDegree(std::string degree);
		void setLevel(std::string level);

		void showStudent();

};

#endif
