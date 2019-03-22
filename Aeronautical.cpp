#include "Aeronautical.h"



Aeronautical::Aeronautical()
{
    runalready = false; //if its the first time being run
}


bool Aeronautical::washcar() {
	if (!runalready) { //first time doing a task
		runalready = true;
		startimetask = steady_clock::now();
		return true;
	}
	else {
		steady_clock::time_point currenttime = steady_clock::now();
        double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count(); //diference between first time and current time run
        if (milliseconds < cartime - pow(getrobotlevel(), 6)) { //if it is still running return false
			return false;
		}

	}
	startimetask = steady_clock::now();
	return true;
}

string Aeronautical::getcardescription() //get function
{
	return cardescription;
}
unsigned int Aeronautical::getcartime() { // gives an accurate time to do a task
	if(cartime > pow(getrobotlevel(), 6) )
	return cartime - pow(getrobotlevel(), 6);
	else
	return 0;
}
