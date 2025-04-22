#include "Truck.h"

#include <utility>

Truck::Truck(string id, double maxWeight) : Automobile(move(id)), maxWeight(maxWeight) {
}

int Truck::pay() const {
	return 3;
}
