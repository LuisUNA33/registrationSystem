#ifndef Group_H
#define Group_H
#include <iostream>
#include <string>
class Group
{
private:
    std::string NCR = "";
    std::string codCourse = "";
    std::string professor = "";

public:
    Group();
    Group(std::string ncr, std::string codCourse, std::string professor);
    std::string getNCR();
    std::string getCodeCourses();
    std::string getProfessor();
    void setNCR(std::string NCR);
    void setCodeCourse(std::string codeCourse);
    void setProfessor(std::string Professor);
    void showGroup();

};
#endif

