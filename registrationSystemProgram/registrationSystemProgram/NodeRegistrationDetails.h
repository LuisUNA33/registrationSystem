#pragma once
#include <iostream>
#include <string>

#include "registrationDetails.h"
#include "Files.h"

using namespace std;

class NodeRegistrationDetails
{
private:
	registrationDetails data;
	NodeRegistrationDetails* next;

public:
	NodeRegistrationDetails(registrationDetails data);
	~NodeRegistrationDetails();
	registrationDetails getData();
	void setData(registrationDetails data);
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
	void insertAtBeginning(registrationDetails data);
	void insertAtEnd(NodeRegistrationDetails* newNode);
	void printList();
	void writeRegistrationDetailsList();
	void loadRegistrationDetailsList(RegistrationDetailsList& list);
};