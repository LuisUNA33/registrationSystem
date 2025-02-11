#ifndef Group_H
#define Group_H
#include <iostream>
#include <string>
#include "NodeSchedule.h"
class Group
{
private:
    std::string NRC = "";
    std::string codCourse = "";
    std::string professor = "";
    std::string schedule_A = "";
    std::string schedule_B ="";

public:
    Group();
    Group(std::string NRC, std::string codCourse, std::string professor,string schedule_A,string schedule_B);
    std::string getNRC();
    std::string getCodeCourses();
    std::string getProfessor();
    string  getSchedule_A();
    string  getSchedule_B();
    void setNRC(std::string NRC);
    void setCodeCourse(std::string codeCourse);
    void setProfessor(std::string Professor);
    void setSchedule_A(string schedule_A);
    void setSchedule_B(string schedule_B);
    void showGroup();

};
#endif

