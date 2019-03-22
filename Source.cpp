#include "Unipedal.h"
#include<iostream>
using namespace std;
int main() {
	Unipedal david;
	david.setname("David");
	cout << "my name " << david.getname() << endl;
	int davidtasks = david.gettaskcompleted();
	while (davidtasks < 100) {
		if (david.dishes()) {
			david.increasetask();
			cout << "david completed another task you now have " << david.gettaskcompleted() << endl;
			davidtasks = david.gettaskcompleted();
			david.increaselevel();
			cout << "it not takes you " << david.getdishtime() << " to do this task " << endl;
		}
	}
	return 0;
}