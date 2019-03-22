#include "Unipedal.h"
#include <QMessageBox>


Unipedal::Unipedal()
{

	sweeping = false;
	washingdish = false;

}
bool Unipedal::dishes() {
	if (!washingdish && !sweeping) { //first time doing a task
		washingdish = true;
		startimetask = steady_clock::now();
		return true;
	}
	else if (sweeping) {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < sweeptime - pow(getrobotlevel(), 2)) {    //If the robot is still currently sweeping
			return false;
		}
		else {
			sweeping = false;

		}
	}

	else {
        steady_clock::time_point currenttime = steady_clock::now(); // see if robot is currently doing the dishes
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
		if (milliseconds < dishtime - pow(getrobotlevel(), 2)) {
			return false;
		}
		
	}
	startimetask = steady_clock::now();
	washingdish = true;
	return true;
}
bool Unipedal::sweep() {

         if (!washingdish && ! sweeping) { //first time doing a task

			sweeping = true;
			startimetask = steady_clock::now();
			return true;
		}
	else if (washingdish) {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < dishtime - pow(getrobotlevel(), 2)) {    //If the robot is still washing dishes
			return false;
		}
		else {
			washingdish = false; // no longer washing dishes

		}
	}

	else {
		steady_clock::time_point currenttime = steady_clock::now();
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < sweeptime - pow(getrobotlevel(), 2)) { // robot is currently sweeping
			return false;
		}

	}
    startimetask = steady_clock::now(); // robot can start sweepingn
	sweeping = true;
	return true;
}
string Unipedal::getdishdescription() { // get description of doing dishes
	return dishdescription;
}
string Unipedal::getsweepdescription() { // get the description of sweeping
	return sweepdescription;
}
unsigned int Unipedal::getdishtime() { //acurate dish time quadradic function
	if (dishtime > pow(getrobotlevel(), 2))
		return dishtime - pow(getrobotlevel(), 2);
	else
		return 0;
}
unsigned int Unipedal::getsweeptime() { // accurate sweep time quadradic function
	if (sweeptime > pow(getrobotlevel(), 2))
		return sweeptime - pow(getrobotlevel(), 2);
	else
		return 0;
}

