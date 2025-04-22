#include "Car.h"

#include <utility>

Car::Car(string id, string type) : Automobile(move(id)), type(type) {
}

int Car::pay() const {
	return 1;
}
