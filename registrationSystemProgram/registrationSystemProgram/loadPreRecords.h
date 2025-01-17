#pragma once

void loadPreRecords(Registration* registrationList,int& numRegistration,
	Course* courseList,int& numCourse,
	Student* studentList,int& numStudents,
	Schedule* scheduleList,int& numSchedule){
	studentList[0]=Student("Marco Anthonio","603170469","Ingenieria en Sistemas", "1");
	studentList[1]=Student("Michell Obiedo", "408370485", "Redes", "2");
	studentList[2]=Student ("Filiberto Castro", "204570467", "Administracion", "3");
	studentList[3]=Student("Kevin Perez", "704530417", "Administracion", "3");

	scheduleList[0] = Schedule("Lunes","8","10","Aula 2");
	scheduleList[1] = Schedule("Miercoles", "8", "10", "Aula 3");
	scheduleList[2] = Schedule("Jueves", "13", "15", "Aula 9");
	scheduleList[3] = Schedule("Martes", "7", "10", "Aula 12");

	courseList[0] = Course("Fundamentos","F01",3,"Marcos M.", scheduleList[0]);
	courseList[1] = Course("Programacion 1", "P01", 4, "Paco", scheduleList[1]);
	courseList[2] = Course("Programacion 2", "P02", 4, "Santiago", scheduleList[2]);
	courseList[3] = Course("Contabilidad", "C01", 2, "Beathan", scheduleList[3]);

	Course* list1 = new Course[10];
	list1[0] = Course("Fundamentos", "F01", 3, "Marcos M.", scheduleList[0]);
	list1[1] = Course("Programacion 1", "P01", 4, "Paco", scheduleList[1]);
	registrationList[0]= Registration(list1,2,studentList[0]);

	Course* list2 = new Course[10];
	list2[0] = Course("Fundamentos", "F01", 3, "Marcos M.", scheduleList[0]);
	list2[1] = Course("Programacion 2", "P02", 4, "Santiago", scheduleList[2]);
	registrationList[1]= Registration(list2, 2, studentList[1]);

	Course* list3 = new Course[10];
	list3[0] = Course("Fundamentos", "F01", 3, "Marcos M.", scheduleList[0]);
	list3[1] = Course("Contabilidad", "C01", 2, "Beathan", scheduleList[3]);
	registrationList[2]= Registration(list3, 2, studentList[2]);

	Course* list4 = new Course[10];
	list4[0] = Course("Fundamentos", "F01", 3, "Marcos M.", scheduleList[0]);
	registrationList[3]= Registration(list4, 1, studentList[3]);

	numRegistration += 4;
	numCourse += 4;
	numStudents += 4;
	numSchedule += 4;


}
