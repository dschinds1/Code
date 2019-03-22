#include "Robot.h"



Robot::Robot()//superclass basic setters and getters
{
    robotlevel = 0; // starting level and tasks completed
	taskscompleted = 0;
}
void Robot::setname(string name) {
	robotname = name;
}
string Robot::getname() {
	return robotname;
}
int Robot::getrobotlevel() {
	return robotlevel;
}
void Robot::increaselevel() {
	robotlevel++;
}
void Robot::increasetask() {
	taskscompleted++;
}
int Robot::gettaskcompleted() {
	return taskscompleted;
}


