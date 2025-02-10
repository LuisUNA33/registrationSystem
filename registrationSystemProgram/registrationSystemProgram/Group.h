#ifndef Group_H
#define Group_H
#include <iostream>
#include <string>
class Group
{
private:
    std::string NRC = "";
    std::string codCourse = "";
    std::string professor = "";

public:
    Group();
    Group(std::string NRC, std::string codCourse, std::string professor);
    std::string getNRC();
    std::string getCodeCourses();
    std::string getProfessor();
    void setNRC(std::string NRC);
    void setCodeCourse(std::string codeCourse);
    void setProfessor(std::string Professor);
    void showGroup();

};
#endif

