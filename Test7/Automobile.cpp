#include "Automobile.h"
#include "Park.h"

Automobile::Automobile(string id) : id(move(id)) {
}

string Automobile::getId() {
	return id;
}

void Automobile::enter(Park* park) {
	park->enter(this);
}

void Automobile::leave(Park* park) {
	park->leave(this);
}
