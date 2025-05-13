#ifndef BUS_H
#define BUS_H

#include "Automobile.h"

class Bus : public Automobile {
public:
	Bus(std::string id, int maxMember);
private:
	int maxMember;
	void pay(Park* park) override;
};

#endif //BUS_H
