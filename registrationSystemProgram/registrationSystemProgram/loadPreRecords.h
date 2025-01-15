#pragma once

Registration** initializeArray(int rows,int columns) {
	Registration** registrationList = new Registration*[rows];
	for (int x = 0; x < rows; x++) {
		registrationList[x] = new Registration[columns];
	}
	return registrationList;
}

void loadPreRecords(Registration** registrationList,int& recordedAmount,Course* courseList,int& numCourse,Student* studentList,int& numStudents){
	studentList[0]=Student("Marco Anthonio","603170469","Ingenieria en Sistemas", "1");
	studentList[1]=Student("Michell Obiedo", "408370485", "Redes", "2");
	studentList[2]=Student ("Filiberto Castro", "204570467", "Administracion", "3");
	studentList[3]=Student("Kevin Perez", "704530417", "Administracion", "3");

	Schedule schedule1("Lunes","8","10","Aula 2");
	Schedule schedule2("Miercoles", "8", "10", "Aula 3");
	Schedule schedule3("Jueves", "13", "15", "Aula 9");
	Schedule schedule4("Martes", "7", "10", "Aula 12");

	courseList[0] = Course("Fundamentos","F01",3,"Marcos M.",schedule1);
	courseList[1] = Course("Programacion 1", "P01", 4, "Paco", schedule2);
	courseList[2] = Course("Programacion 2", "P02", 4, "Santiago", schedule3);
	courseList[3] = Course("Contabilidad", "C01", 2, "Beathan",schedule4);

	Course* list1 = new Course[10];
	list1[0] = courseList[0];
	list1[1] = courseList[1];
	registrationList[0][0] = Registration(list1,2,studentList[0]);

	Course* list2 = new Course[10];
	list2[0] = courseList[0];
	list2[1] = courseList[2];
	registrationList[0][1] = Registration(list2, 2, studentList[1]);

	Course* list3 = new Course[10];
	list3[0] = courseList[2];
	registrationList[0][2] = Registration(list3, 2, studentList[2]);

	Course* list4 = new Course[10];
	list4[0] = courseList[3];
	registrationList[0][3] = Registration(list4, 2, studentList[3]);

	recordedAmount += 4;
	numCourse += 4;
	numStudents += 4;


}
