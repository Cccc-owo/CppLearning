#ifndef TRUCK_H
#define TRUCK_H

#include "Automobile.h"

class Truck : public Automobile {
public:
	Truck(string id, double maxWeight);
	int pay() const;
private:
	double maxWeight;
};

#endif //TRUCK_H
