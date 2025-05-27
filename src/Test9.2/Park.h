#ifndef PARK_H
#define PARK_H

#include <iostream>

using namespace std;

class Automobile;

class Park {
public:
	explicit Park(int spacesNum);
	~Park();
	void claimSpace(Automobile* automobile);
	void reclaimSpace(Automobile* automobile);
	void showInfo() const;
	void getPaid(int fee);
private:
	int count;
	int income;
	int spacesNum;
	Automobile** spaces;
};

#endif // PARK_H
