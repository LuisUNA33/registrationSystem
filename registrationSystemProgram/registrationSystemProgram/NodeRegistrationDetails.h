#pragma once
#include <iostream>
#include <string>

#include "registrationDetails.h"
#include "NodeGroup.h"
#include "NodeCourse.h"
#include "Files.h"

using namespace std;

class NodeRegistrationDetails
{
private:
	RegistrationDetails data;
	NodeRegistrationDetails* next;

public:
	NodeRegistrationDetails(RegistrationDetails data);
	~NodeRegistrationDetails();
	RegistrationDetails getData();
	void setData(RegistrationDetails data);
	NodeRegistrationDetails* getNext();
	void setNext(NodeRegistrationDetails* next);
};

class RegistrationDetailsList {
private:
	NodeRegistrationDetails* head;

public:
	RegistrationDetailsList();
	NodeRegistrationDetails* getHead();
	void deleteNode(NodeRegistrationDetails nodoPrev);
	void insertAtBeginning(RegistrationDetails data);
	void insertAtEnd(NodeRegistrationDetails* newNode);
	void printList();
	void writeRegistrationDetailsList();
	void loadRegistrationDetailsList(RegistrationDetailsList& list);

	void getCreditsTotal(int& credits, float& cost, std::string codRegister, GroupList groups, CourseList courses);
	
};