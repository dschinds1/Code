#pragma once
#include "Robot.h"
//this guy can do the dishes and sweep the house, so we need to record the start times of these
class Unipedal : public Robot 
{
public:
	Unipedal();
	bool dishes();
	bool sweep();
	string getdishdescription();
	string getsweepdescription();
	unsigned int getdishtime();
	unsigned int getsweeptime();
private: 
	steady_clock::time_point startimetask;
	bool washingdish;
	bool sweeping;
	string dishdescription = "do the dishes";
	string sweepdescription = "sweep the house";
	unsigned int dishtime = 1000;
    unsigned int sweeptime = 3000; //is 3000
};

