#include "loadPreRecords.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void loadPreRecords(Registration* registrationList, int& numRegistration,
    Course* courseList, int& numCourse,
    Student* studentList, int& numStudents,
    Schedule* scheduleList, int& numSchedule) {

    ifstream file("archivo.txt");
    if (!file) {
        cout << "Error al abrir el archivo!" << endl;
        return;
    }

    string line;

    // Leer estudiantes
    getline(file, line); // # Students
    file >> numStudents;
    file.ignore();

    for (int i = 0; i < numStudents; i++) {
        getline(file, line);
        stringstream ss(line);
        string name, id, career, year;
        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, career, ',');
        getline(ss, year);
        studentList[i] = Student(name, id, career, year);
    }

    //// Leer horarios
    //getline(file, line); // # Schedules
    //file >> numSchedule;
    //file.ignore();

    //for (int i = 0; i < numSchedule; i++) {
    //    getline(file, line);
    //    stringstream ss(line);
    //    int id, start, end;
    //    string day, room;
    //    ss >> id;
    //    ss.ignore();
    //    getline(ss, day, ',');
    //    ss >> start;
    //    ss.ignore();
    //    ss >> end;
    //    ss.ignore();
    //    getline(ss, room);
    //    scheduleList[i] = Schedule(id, day, start, end, room);
    //}

    //// Leer cursos
    //getline(file, line); // # Courses
    //file >> numCourse;
    //file.ignore();

    //for (int i = 0; i < numCourse; i++) {
    //    getline(file, line);
    //    stringstream ss(line);
    //    string name, code, professor;
    //    int credits, scheduleId;
    //    getline(ss, name, ',');
    //    getline(ss, code, ',');
    //    ss >> credits;
    //    ss.ignore();
    //    getline(ss, professor, ',');
    //    ss >> scheduleId;

    //    Schedule schedule;
    //    for (int j = 0; j < numSchedule; j++) {
    //        if (scheduleList[j].getId() == scheduleId) {
    //            schedule = scheduleList[j];
    //            break;
    //        }
    //    }

    //    courseList[i] = Course(name, code, credits, professor, schedule);
    //}

    // Leer registros
    getline(file, line); // # Registrations
    file >> numRegistration;
    file.ignore();

    for (int i = 0; i < numRegistration; i++) {
        getline(file, line);
        stringstream ss(line);
        int numCourses;
        string studentId, courseCode;
        ss >> numCourses;
        ss.ignore();
        getline(ss, studentId, ',');

        Course* list = new Course[numCourses];
        for (int j = 0; j < numCourses; j++) {
            getline(ss, courseCode, ',');
            for (int k = 0; k < numCourse; k++) {
                if (courseList[k].getCode() == courseCode) {
                    list[j] = courseList[k];
                    break;
                }
            }
        }

        Student student;
        for (int j = 0; j < numStudents; j++) {
            if (studentList[j].getId() == studentId) {
                student = studentList[j];
                break;
            }
        }

        registrationList[i] = Registration(list, numCourses, student);
    }

    file.close();
}
