#pragma once
#include<string>
#include <chrono>
#include<math.h>
using namespace std::chrono;
using namespace std;
class Robot //parent class basically defines the standard robot unctions wihhc inncludes level and tasks completed
{
public:
	Robot();
	string getname();
	void setname(string name);
	int getrobotlevel();
	void increaselevel();
	void increasetask();
	int gettaskcompleted();
private:
	string robotname;
	unsigned int robotlevel;
	unsigned int taskscompleted;
};

