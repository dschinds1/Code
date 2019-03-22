#pragma once
#include "Robot.h"
class Radial : public Robot // he can rake the leaves and give the dog a bath
{
public:
	Radial();
	bool rake();
	bool bath();
	string getrakedescription();
	string getbathdescription();
	unsigned int getraketime();
	unsigned int getbathtime();

private:
	steady_clock::time_point startimetask;
	bool raking;
	bool bathing;
	string rakedescription = "rake the leaves";
	string bathdescription = "give the dog a bath";
	unsigned int raketime = 18000;
	unsigned int bathtime = 14500;
};


