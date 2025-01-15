#pragma once

class Registration {
private:
	Course* courseList=new Course[10];
	int courseIndex = 0;
	Student student;

public:
	Registration();
	~Registration();

	Registration(Course* courseList,int courseIndex ,Student student);

	Course* getCourseList();
	int getCourseIndex();
	Student getStudent();
	void setCourseList(Course* course);
	void setCourseIndex(int courseIndex);
	void setStudent(Student student);

	void showRegistration();
};

Registration::Registration() {}

Registration::~Registration() {}

Registration::Registration(Course* courseList,int courseIndex, Student student) {
	this->courseList = courseList;
	this->courseIndex = courseIndex;
	this->student = student;
}

Course* Registration::getCourseList() {
	return this->courseList;
}
int Registration::getCourseIndex() {
	return this->courseIndex;
}
Student Registration::getStudent() {
	return this->student;
}

void Registration::setCourseList(Course* course) {
	this->courseList= course;
}
void Registration::setCourseIndex(int courseIndex) {
	this->courseIndex = courseIndex;
}
void Registration::setStudent(Student student) {
	this->student = student;
}

void Registration::showRegistration(){
	this->student;
	std::cout <<"Datos de matricula:"<< std::endl;
	std::cout <<"Estudiante:"<< std::endl;
	std::cout << "Nombre: ";
	std::cout << this->student.getName() << std::endl;
	std::cout << "Cedula: ";
	std::cout << this->student.getId() << std::endl;
	std::cout << "Carrera: ";
	std::cout << this->student.getDegree() << std::endl;
	std::cout << "Nivel: ";
	std::cout << this->student.getLevel() << std::endl;
	for (int x = 0; x < this->courseIndex; x++) {
		std::cout << "\nCurso " <<x+1<<": "<< std::endl;
		std::cout << "Nombre del curso: " ;
		std::cout << this->courseList[x].getName() << std::endl;
		std::cout << "Codigo: ";
		std::cout << this->courseList[x].getCode() << std::endl;
		std::cout << "Creditos: ";
		std::cout << this->courseList[x].getCredits() << std::endl;
		std::cout << "Preofesor: " ;
		std::cout << this->courseList[x].getTeacher() << std::endl;

		std::cout << "\nHorario: "<<std::endl;
		std::cout << "Dia: ";
		std::cout << this->courseList[x].getSchedule().getDay() << std::endl;
		std::cout << "Hora de inicio: ";
		std::cout << this->courseList[x].getSchedule().getStartTime() << std::endl;
		std::cout << "Hora de salida: ";
		std::cout << this->courseList[x].getSchedule().getEndTime() << std::endl;
		std::cout << "Salon de clase: ";
		std::cout << this->courseList[x].getSchedule().getClassRoom()<< std::endl;
	}

}