#ifndef TRUCK_H
#define TRUCK_H

#include "Automobile.h"

class Truck : public Automobile {
public:
	Truck(std::string id, double maxWeight);
private:
	double maxWeight;
	void pay(Park* park) override;
};

#endif //TRUCK_H
