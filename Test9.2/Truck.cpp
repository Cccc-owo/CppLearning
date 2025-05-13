#include "Truck.h"
#include "Park.h"

Truck::Truck(std::string id, double maxWeight) : Automobile(move(id)), maxWeight(maxWeight) {
}

void Truck::pay(Park* park) {
	std::cout << id << "离开停车场，缴纳停车费" << 3 << "元。" << std::endl;
	park->getPaid(3);
}