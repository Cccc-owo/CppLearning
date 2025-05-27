#include "Car.h"
#include "Park.h"

Car::Car(std::string id, std::string type) : Automobile(std::move(id)), type(type) {
}

void Car::pay(Park* park) {
	std::cout << id << "离开停车场，缴纳停车费" << 1 << "元。" << std::endl;
	park->getPaid(1);
}
