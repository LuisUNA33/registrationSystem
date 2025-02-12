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
    ScheduleList listS;

public:
    Group();
    Group(std::string NRC, std::string codCourse, std::string professor, ScheduleList listS);
    std::string getNRC();
    std::string getCodeCourses();
    std::string getProfessor();
    ScheduleList getSchedule();
    void setNRC(std::string NRC);
    void setCodeCourse(std::string codeCourse);
    void setProfessor(std::string Professor);
    void showGroup();

};
#endif

