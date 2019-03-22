#include "Arachnid.h"



Arachnid::Arachnid()
{
    runalready = false; // hasnt been run before so set to false
}


bool Arachnid::bake() {
    if (!runalready) { //first time doing a task so run annd set the first run time
		runalready = true;
		startimetask = steady_clock::now();
		return true;
	}
else {
        steady_clock::time_point currenttime = steady_clock::now(); // this has already been run so get current time
		double milliseconds = std::chrono::duration_cast<std::chrono::milliseconds> (currenttime - startimetask).count();
        if (milliseconds < baketime - pow(getrobotlevel(), 3)) { //this guy gets cubic upgrades since his tasks are slower
            return false; // if it is still running return flase
		}

	}
	startimetask = steady_clock::now();
	return true;
}

string Arachnid::getbakedescription()
{
    return bakedescription; // get the description of baking
}
unsigned int Arachnid::getbaketime() { //time left to bake
	if (baketime > pow(getrobotlevel(), 3))
		return baketime - pow(getrobotlevel(), 3);
	else
		return 0;
}
