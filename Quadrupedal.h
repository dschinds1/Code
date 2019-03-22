#pragma once
#include "Robot.h"
class Quadrupedal : public Robot // He can makes sandwiches and mow lawns
{
public:
	Quadrupedal();
	bool sandwich();
	bool mowlawn();
	string getsandwichdescription();
	string getmowlawndescription();
	unsigned int getsandwichtime();
	unsigned int getlawntime();

private:
	steady_clock::time_point startimetask;
	bool makingsandwich;
	bool mowinglawn;
	string sandwichdescription = "make a sammich";
	string mowlawndescription = "mow the lawn";
unsigned int sandwichtime = 7000;
    unsigned int lawntime = 20000;
};

