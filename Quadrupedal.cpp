#include "Quadrupedal.h"



Quadrupedal::Quadrupedal()
{
    makingsandwich = false; // set both starting variables to false because neither have been run
	mowinglawn = false;
}

bool Quadrupedal::mowlawn() {
	if (!mowinglawn && !makingsandwich) { //first time doing a task
		mowinglawn = true;
		startimetask = steady_clock::now();
		return true;
	}
	else if (makingsandwich) {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < sandwichtime - pow(getrobotlevel(), 4)) {    //see if robot is still makingn a sandwich
			return false;
		}
		else {
            makingsandwich = false; // no longer making a sandwich

		}
	}

	else {
        steady_clock::time_point currenttime = steady_clock::now(); // see if the robot is still mowing the lawn
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
		if (milliseconds < lawntime - pow(getrobotlevel(), 4)) {
			return false;
		}

	}
    startimetask = steady_clock::now(); //if this is hit the robot can mow the lawn
	mowinglawn = true;
	return true;
}
bool Quadrupedal::sandwich() {
    if (!mowinglawn && !makingsandwich) { //first time doing a task
		makingsandwich = true;
		startimetask = steady_clock::now();
		return true;
	}
	else if (mowinglawn) {
        steady_clock::time_point currenttime = steady_clock::now(); //see if robot is mowing lawn currently
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
		if (milliseconds < lawntime - pow(getrobotlevel(), 4)) {    //If the robot is still working on this task
			return false;
		}
		else {
            mowinglawn = false; // no longer mowing the lawn

		}
	}

	else {
        steady_clock::time_point currenttime = steady_clock::now(); // see if the robot is making a sanwich
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
		if (milliseconds < sandwichtime - pow(getrobotlevel(), 4)) {
			return false;
		}

	}
    startimetask = steady_clock::now(); // the robot is able to sucesfully make a sanwich
	makingsandwich = true;
	return true;
}
string Quadrupedal::getmowlawndescription() // get description of mowing lawn
{
	return mowlawndescription;
}
string Quadrupedal::getsandwichdescription() { //get the description of this
	return sandwichdescription;
}
unsigned int Quadrupedal::getlawntime() { //accurate lawn time this guy has a quadradic function
	if (lawntime > pow(getrobotlevel(), 4))
		return lawntime - pow(getrobotlevel(), 4);
	else
		return 0;
}
unsigned int Quadrupedal::getsandwichtime() { // accurate sandwich time quadratic function
	if (sandwichtime > pow(getrobotlevel(), 4))
		return sandwichtime - pow(getrobotlevel(), 4);
	else
		return 0;
}
