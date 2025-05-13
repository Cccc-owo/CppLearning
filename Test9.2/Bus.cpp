#include "Bus.h"
#include "Park.h"

Bus::Bus(std::string id, int maxMember) : Automobile(std::move(id)), maxMember(maxMember) {
}

void Bus::pay(Park* park) {
	std::cout << id << "离开停车场，缴纳停车费" << 2 << "元。" << std::endl;
	park->getPaid(2);
}
