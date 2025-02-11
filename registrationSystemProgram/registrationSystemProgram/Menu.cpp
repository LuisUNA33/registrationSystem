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
    courses.loadCourseList(courses);
    groups.loadGroupList(groups);
    requirements.loadRequirementList(requirements);
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
        std::cout << "d) Regresar " << std::endl;
        std::cout << "Ingrese alguna opcion disponible: " << std::endl;

        option = enterChar(); // Solo se usa esta lectura

        switch (option) {
        case 'a':
            system("CLS");
            registerStudent(students);
            system("pause");
            //students.writeStudentList();
            break;
        case 'b':
            system("CLS");
            registerCourse(courses, groups);
            system("pause");
            groups.printList();
            //courses.writeCourseList();
            break;
        case 'c':
            system("CLS");
            registerSchedule(schedules);
            system("pause");
            //schedules.writeScheduleList();
            break;
        case 'd':
            return;
        default:
            std::cout << "Opcion no valida, intente nuevamente." << std::endl;
            break;
        }
    }
}

void subMenuC() {
    system("CLS");
    char option;
    do {
        std::cout << "Matricula:" << std::endl;
        std::cout << "  (a)Registro de matricula Completa" << std::endl;
        std::cout << "  (b)Registro de matricula(matricula sin cursos)" << std::endl;
        std::cout << "  (c) regresar " << std::endl;
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
            return;

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
        std::cout << "  (a)Estudiantes(Lista de estudiantes)" << std::endl;
        std::cout << "  (b)Cursos(Lista de los cursos)" << std::endl;
        std::cout << "  (c)Horarios(Lista de Horarios)" << std::endl;
        std::cout << "  (d)Estudiantes Matriculados(Todos los matriculados)" << std::endl;
        std::cout << "  (e)regresar" << std::endl;
        std::cout << "Selecione una opcion:" << std::endl;
        option = enterChar();
        switch (option) {
        case 'a':
            system("CLS");
            //students.loadStudentList(students);
            students.printList();
            system("pause");
            break;
        case 'b':
            system("CLS");
            //courses.loadCourseList(courses);
            //courses.printList();
            ShowCoursesGroup(courses,groups);
            system("pause");
            break;
        case 'c':
            system("CLS");
            //schedules.loadScheduleList(schedules);
            schedules.printList();
            system("pause");
            break;
        case 'd':
            //showEnrolledStudents(registrationList, numRegistration);
            break;
        case 'e':
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
        //char option =' ';
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //std::cin >> option;
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





