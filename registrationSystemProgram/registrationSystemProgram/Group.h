#ifndef Group_H
#define Group_H
#include <iostream>
#include <string>
class Group
{
private:
    std::string ncr = "";
    std::string codCourse = "";
    std::string professor = "";

public:
    Group();
    Group(std::string ncr, std::string codCourse, std::string professor);

};
#endif

