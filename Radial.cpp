#include "Radial.h"



Radial::Radial()
{
    raking = false; // both of these are set to false at first
	bathing = false;
}
bool Radial::rake() {
	if (!raking && !bathing) { //first time doing a task
		raking = true;
		startimetask = steady_clock::now();
		return true;
	}
	else if (bathing) {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < bathtime - pow(getrobotlevel(), 5)) {    //If the robot is currently bathing the dog
			return false;
		}
		else {
            bathing = false; // This robot is not currently bathing the dog

		}
	}

	else {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < raketime - pow(getrobotlevel(), 5)) { //see if the robot is raking the lawn currently
			return false;
		}

	}
    startimetask = steady_clock::now(); // the robot starts raking the lawn at this time
	raking = true;
	return true;
}
bool Radial::bath() {
    if (!raking && !bathing) { //first time doing a task
		bathing = true;
		startimetask = steady_clock::now();
		return true;
	}
	else if (raking) {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < raketime - pow(getrobotlevel(), 5)) {    //If the robot is currently raking the lawn
			return false;
		}
		else {
			raking = false; // no longer raking

		}
	}

	else {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
		if (milliseconds < bathtime - pow(getrobotlevel(), 5)) {
			return false; // Robot is still giving the dog the bath
		}

	}
    startimetask = steady_clock::now(); // robot starts giving the dog a bath
	bathing = true;
	return true;
}
string Radial::getbathdescription() // description of the bath
{
	return bathdescription;
}
string Radial::getrakedescription() {
	return rakedescription;
}
unsigned int Radial::getbathtime() {
    if (bathtime > pow(getrobotlevel(), 5)) //accurate bath time quintic function
		return bathtime - pow(getrobotlevel(), 5);
	else
		return 0;
}
unsigned int Radial::getraketime() { // accurate rake time quintic function
	if (raketime > pow(getrobotlevel(), 5))
		return raketime - pow(getrobotlevel(), 5);
	else
		return 0;
}


