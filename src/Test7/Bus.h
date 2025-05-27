#ifndef BUS_H
#define BUS_H

#include "Automobile.h"

class Bus : public Automobile {
public:
	Bus(string id, int maxMember);
	int pay() const;
private:
	int maxMember;
};

#endif //BUS_H
