#pragma once
#include "Robot.h"
class Aeronautical : public Robot //she can wash the car, bit different because only one task, has the strongest upgrade factor
{
public:
	Aeronautical();
	bool washcar();
	string getcardescription();
	unsigned int getcartime();
private:
	steady_clock::time_point startimetask;
	string cardescription = "wash the car";
	unsigned int cartime = 20000;
	bool runalready;

};

