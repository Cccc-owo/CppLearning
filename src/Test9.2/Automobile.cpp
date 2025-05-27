#include "Automobile.h"
#include "Park.h"

Automobile::Automobile(string id) : id(std::move(id)) {
}

void Automobile::pay(Park* park) {
}

string Automobile::getId() {
	return id;
}

void Automobile::enter(Park* park) {
	park->claimSpace(this);
}

void Automobile::leave(Park* park) {
	park->reclaimSpace(this);
	pay(park);
}
