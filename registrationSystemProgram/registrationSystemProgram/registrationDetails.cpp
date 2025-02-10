#include "registrationDetails.h"

registrationDetails::registrationDetails() {}

registrationDetails::registrationDetails(string registrationCode, string codeGroup, float cost, float score) {
	this->registrationCode = registrationCode;
	this->codeGroup = codeGroup;
	this->cost = cost;
	this->score = score;
}

string registrationDetails::getRegistrationCode() {
	return this->registrationCode;
}

string registrationDetails::getCodeGroup() {
	return this->codeGroup;
}

float registrationDetails::getCost() {
	return this->cost;
}

float registrationDetails::getScore() {
	return this->score;
}

void registrationDetails::setRegistrationCode(string registrationCode) {
	this->registrationCode = registrationCode;
}

void registrationDetails::setCodeGroup(string codeGroup) {
	this->codeGroup = codeGroup;
}

void registrationDetails::setCost(float cost) {
	this->cost = cost;
}

void registrationDetails::setScore(float score) {
	this->score = score;
}

void registrationDetails::showRegistrationDetails() {
	std::cout << "\nDetalles de la matricula: " << std::endl;
	std::cout << "Codigo de matricula: ";
	std::cout << this->registrationCode << std::endl;
	std::cout << "NRC de grupo: ";
	std::cout << this->codeGroup << std::endl;
	std::cout << "Costo: ";
	std::cout << this->cost << std::endl;
	std::cout << "Nota: ";
	std::cout << this->score << std::endl;
}
