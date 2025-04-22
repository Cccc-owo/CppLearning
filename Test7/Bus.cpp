#include "Bus.h"

Bus::Bus(string id, int maxMember) : Automobile(move(id)), maxMember(maxMember) {
}

int Bus::pay() const {
	return 2;
}
