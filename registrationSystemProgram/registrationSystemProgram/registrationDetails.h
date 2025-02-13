#pragma once
#include <iostream>
#include <string>

using namespace std;

class RegistrationDetails
{
private:
	string registrationCode;
	string codeGroup;
	float cost;
	float score;

public:
	RegistrationDetails();
	RegistrationDetails(string registrationCode, string codeGroup, float cost, float score);
	string getRegistrationCode();
	string getCodeGroup();
	float getCost();
	float getScore();
	void setRegistrationCode(string registrationCode);
	void setCodeGroup(string codeGroup);
	void setCost(float cost);
	void setScore(float score);
	void showRegistrationDetails();
};

