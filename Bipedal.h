#pragma once
#include "Robot.h"
class Bipedal :public Robot //She can take out laundry and do recyclinng
{
public:
	Bipedal();
	bool laundry();
	bool recycling();
	string getrecyclingdescription();
	string getlaundrydescription();
	unsigned int getlaundrytime();
	unsigned int getrecyclingtime();
	
private: 
	steady_clock::time_point startimetask;
	bool doinglaundry;
	bool doingrecycling;
	string laundrydescription = "do the laundry";
	string recyclingdescription = "take out the recycling";
	unsigned int laundrytime = 10000;
	unsigned int recyclingtime = 4000;
};

