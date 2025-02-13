#include "Menu.h"

StudentList students;
ScheduleList schedules;
CourseList courses;
GroupList groups;
RequirementList requirements;
ApprovedCourseList approvedCourses;
RegistrationList registrations;
RegistrationDetailsList registrationDestails;


void loadAllList() {
    students.loadStudentList(students);
    schedules.loadScheduleList(schedules);
    groups.loadGroupList(groups, schedules);
    courses.loadCourseList(courses,groups);
    requirements.loadRequirementList(requirements,courses);
    approvedCourses.loadApprovedCourseList(approvedCourses);
    registrations.loadRegistrationList(registrations);
    registrationDestails.loadRegistrationDetailsList(registrationDestails);
}
void saveAllChanges(){
    clearAllFiles();
    students.writeStudentList();
    schedules.writeScheduleList();
    courses.writeCourseList();
    groups.writeGroupList();
    requirements.writeRequirementList();
    approvedCourses.writeApprovedCourseList();
    registrations.writeRegistrationList();
    registrationDestails.writeRegistrationDetailsList();
}

bool subMenuA() {
    char option;
    while (true) {
        system("CLS");
        std::cout << "=== Archivo ===" << std::endl;
        std::cout << "a) Acerca de" << std::endl;
        std::cout << "b) Salir del Programa" << std::endl;
        std::cout << "c) Ir al Menu principal" << std::endl;
        std::cout << "Ingrese alguna opcion disponible: " << std::endl;
        std::cin >> option;

        option = std::tolower(option);

        switch (option) {
        case 'a':
            about();
            return false;
        case 'b':
            saveAllChanges();
            std::cout << "Saliendo....." << std::endl;
            return true;
        case 'c':
            return false;
        default:
            return false;
        }
    }
}

void subMenuB() {
    system("CLS");
    char option;
    while (true) {
        system("CLS");
        std::cout << "=== Mantenimiento ===" << std::endl;
        std::cout << "a) Agregar estudiantes" << std::endl;
        std::cout << "b) Agregar cursos" << std::endl;
        std::cout << "c) Agregar horarios" << std::endl;
        std::cout << "d) Agregar Grupos" << std::endl;
        std::cout << "e) Regresar " << std::endl;
        std::cout << "Ingrese alguna opcion disponible: " << std::endl;

        option = enterChar(); // Solo se usa esta lectura

        switch (option) {
        case 'a':
            system("CLS");
            registerStudent(students);
            system("pause");
            break;
        case 'b':
            system("CLS");
            registerCourse(courses, groups,requirements);
            system("pause");
            groups.printList();
            break;
        case 'c':
            system("CLS");
            registerSchedule(schedules);
            system("pause");
            break;
        case 'd':
            system("CLS");
            registerGroup(groups,schedules);
            system("pause");
            break;
        case 'e':
            return;
        default:
            std::cout << "Opcion invalida, intente nuevamente." << std::endl;
            break;
        }
    }
}

void subMenuC() {
    system("CLS");
    char option;
    do {
        std::cout << "Matricula:" << std::endl;
        std::cout << "  (a)Registro de matricula completa" << std::endl;
        std::cout << "  (b)Registro de matricula (matricula sin cursos)" << std::endl;
        std::cout << "  (c)Regresar " << std::endl;
        std::cout << "Selecione una opcion:" << std::endl;
        option = enterChar();
        switch (option) {
        case 'a':
            registerRegistration(registrationDestails,registrations,
                students,schedules,courses,groups,requirements,
                approvedCourses);
            system("pause");
            break;
        case 'b':
            registration(registrations,students);
            system("pause");
            break;

        default:
            break;
        }
    } while (option != 'a' && option != 'b' && option != 'c');

}


void subMenuD() {
    std::cout << "Consulta:" << std::endl;
    system("CLS");
    char option;
    while (true) {
        system("CLS");
        std::cout << "  (a)Estudiantes (Lista de estudiantes)" << std::endl;
        std::cout << "  (b)Cursos (Lista de los cursos)" << std::endl;
        std::cout << "  (c)Horarios (Lista de Horarios)" << std::endl;
        std::cout << "  (d)Grupos" << std::endl;
        std::cout << "  (e)Estudiantes Matriculados (Todos los matriculados)" << std::endl;
        std::cout << "  (f)Regresar" << std::endl;
        std::cout << "Selecione una opcion:" << std::endl;
        option = enterChar();
        switch (option) {
        case 'a':
            system("CLS");
            students.printList();
            system("pause");
            break;
        case 'b':
            system("CLS");
            courses.printList();
            system("pause");
            break;
        case 'c':
            system("CLS");
            schedules.printList();
            system("pause");
            break;
        case 'd':
            groups.printList();
            system("pause");
            break;
        case 'e':
            showRegistration(registrations, registrationDestails);
            system("pause");
            break;
        case 'f':
            return;
        default:
            break;
        }
    }
}


void menu() {
    loadAllList();
    bool exit = false;
    while (exit == false) {
        system("CLS");
        std::cout << "\nBienvenido al sistema de registro o matricula" << std::endl;
        std::cout << "  (a)Archivo\n" <<
            "  (b)Mantenimiento \n" <<
            "  (c)Matricula\n" <<
            "  (d)Consulta\n" <<
            "  (e)Guardar cambios\n" << std::endl;
        std::cout << "Ingrese la opcion que desea realizar: " << std::endl;
        char option = enterChar();
        switch (option) {
        case 'a':
            exit = subMenuA();
            break;
        case 'b':
            subMenuB();
            break;
        case 'c':
            subMenuC();
            break;
        case 'd':
            subMenuD();
            break;
        case 'e':
            saveAllChanges();
            break;
        default:
            break;
        }
    }

}





