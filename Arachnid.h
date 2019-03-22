#pragma once
#include "Robot.h"
class Arachnid : public Robot // He can bake some cookies
{
public:
	Arachnid();
	bool bake();
	string getbakedescription();
	unsigned int getbaketime();
private:
	steady_clock::time_point startimetask;
	string bakedescription= "bake some cookies";
	unsigned int baketime = 8000;
	bool runalready;
	
};

