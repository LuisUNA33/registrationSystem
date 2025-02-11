#include "registrationDetails.h"

RegistrationDetails::RegistrationDetails(){}

RegistrationDetails::RegistrationDetails(string registrationCode, string codeGroup, float cost, float score) {
	this->registrationCode = registrationCode;
	this->codeGroup = codeGroup;
	this->cost = cost;
	this->score = score;
}

string RegistrationDetails::getRegistrationCode() {
	return this->registrationCode;
}

string RegistrationDetails::getCodeGroup() {
	return this->codeGroup;
}

float RegistrationDetails::getCost() {
	return this->cost;
}

float RegistrationDetails::getScore() {
	return this->score;
}

void RegistrationDetails::setRegistrationCode(string registrationCode) {
	this->registrationCode = registrationCode;
}

void RegistrationDetails::setCodeGroup(string codeGroup) {
	this->codeGroup = codeGroup;
}

void RegistrationDetails::setCost(float cost) {
	this->cost = cost;
}

void RegistrationDetails::setScore(float score) {
	this->score = score;
}

void RegistrationDetails::showRegistrationDetails() {
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
