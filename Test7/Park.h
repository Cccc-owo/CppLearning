#ifndef PARK_H
#define PARK_H

#include <iostream>

using namespace std;

class Automobile;

class Park {
public:
	explicit Park(int spacesNum);
	~Park();
	void enter(Automobile* automobile);
	void leave(Automobile* automobile);
	void showInfo() const;
private:
	int count;
	int income;
	int spacesNum;
	Automobile** spaces;
};

#endif // PARK_H
