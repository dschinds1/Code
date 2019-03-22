#include "Bipedal.h"



Bipedal::Bipedal()
{
    doinglaundry = false; // at the start it has not done laundry or recycled yet
	doingrecycling = false;
}


bool Bipedal::laundry() {
    if (!doinglaundry && !doingrecycling) { //first time doing any task in general so we can do laundry
		doinglaundry = true;
		startimetask = steady_clock::now();
		return true;
	}
	else if (doingrecycling) {
        steady_clock::time_point currenttime = steady_clock::now(); //if recycling is set to true we see if that is still going on
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < recyclingtime - pow(getrobotlevel(),3)) {    //If the robot is still working on this task
			return false;
		}
		else {
            doingrecycling = false; // This means it is no longer recycling
		}
	}

	else {
        steady_clock::time_point currenttime = steady_clock::now(); // check to see if we are still doing laundry
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < laundrytime - pow(getrobotlevel(),3)) { // he is still doing laundry
			return false;
		}

	}
    startimetask = steady_clock::now(); // run the task
	doinglaundry = true;
	return true;
}
bool Bipedal::recycling() {
	if (!doinglaundry && !doingrecycling) { //first time doing this task, probably the first task
		doingrecycling = true;
		startimetask = steady_clock::now();
		return true;
	}
	else if (doinglaundry) {
        steady_clock::time_point currenttime = steady_clock::now(); // see if it is still doing laundry
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < laundrytime - pow(getrobotlevel(),3)) {    //If the robot is still working on this task
			return false;
		}
		else {
			doinglaundry = false; // no longer doing laundry

		}
	}

	else {
        steady_clock::time_point currenttime = steady_clock::now(); //see if it is still recycling
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < recyclingtime - pow(getrobotlevel(),3)) {
			return false;
		}

	}
    startimetask = steady_clock::now(); // otherwise start the task
	doingrecycling = true;
	return true;
}
string Bipedal::getrecyclingdescription() //get the description
{
	return recyclingdescription;
}
string Bipedal::getlaundrydescription() { //get the description
	return laundrydescription;
}
unsigned int Bipedal::getlaundrytime() { //acuraate cubic laundry time
    if (laundrytime > pow(getrobotlevel(),3))
        return laundrytime - pow(getrobotlevel(),3);
	else
		return 0;
}
unsigned int Bipedal::getrecyclingtime() { // accurate cubic recycling time
    if (recyclingtime > pow(getrobotlevel(),3))
        return recyclingtime - pow(getrobotlevel(),3);
	else
		return 0;
}
