#ifndef TRUCK_H
#define TRUCK_H

#include "Automobile.h"

class Truck : public Automobile{
public:
	Truck(string id, double maxWeight);
	int pay() const override;
private:
	double maxWeight;
};

#endif //TRUCK_H
