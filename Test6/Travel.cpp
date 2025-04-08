#include <iostream>

#include "Travel.h"

using namespace std;

Passenger::Passenger() : id('A'), wantTeam(false), destination(Destination::DomesticShort) {
	name = "乘客";
	name.push_back(id);
}

Passenger::Passenger(char id, bool wantTeam, int destination, int luggagesNum) :
	id(id), wantTeam(wantTeam), destination(static_cast<Destination>(destination)) {
	name = "乘客 ";
	name.push_back(id);
	for (int i = 0; i < luggagesNum; i++) {
		luggages[i] = true;
	}
}

string Passenger::getName() const {
	return name;
}

char Passenger::getId() const {
	return id;
}

bool Passenger::getWantTeam() const {
	return wantTeam;
}

Destination Passenger::getDestination() const {
	return destination;
}

int Passenger::getLuggagesCount() const {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (luggages[i] == false) {
			break;
		}
		count++;
	}
	return count;
}

void Passenger::printDestination() const {
	if (destination == Destination::DomesticShort) {
		cout << "国内短途";
	} else if (destination == Destination::DomesticLong) {
		cout << "国内长途";
	} else {
		cout << "国际游";
	}
}

Team::Team() : count(0) {
	for (int i = 0; i < 6; i++) {
		members[i] = nullptr;
	}
	destination = static_cast<Destination>(rand() % 3);
}

bool Team::addMember(Passenger* p) {
	if (count >= 6) {
		return false;
	}
	members[count++] = p;
	return true;
}

Destination Team::getDestination() const {
	return destination;
}

void Team::printDestination() const {
	if (destination == Destination::DomesticShort) {
		cout << "国内短途";
	} else if (destination == Destination::DomesticLong) {
		cout << "国内长途";
	} else {
		cout << "国际游";
	}
}

int Team::getCount() const {
	return count;
}

int Team::getCost() const {
	int cost = 0;
	for (int i = 0; i < count; i++) {
		cost += Ticket(members[i]).getCost();
	}
	return cost;
}

Ticket::Ticket() : passenger(nullptr), cost(0), luggageCost(0), available(false) {
}

Ticket::Ticket(Passenger* p) : passenger(p), cost(0), luggageCost(0), available(true) {
	calcCost();
}

Passenger* Ticket::getPassenger() const {
	return passenger;
}

void Ticket::setPassenger(Passenger* p) {
	passenger = p;
	available = true;
	calcCost();
}

void Ticket::calcCost() {
	if (luggageCost == 0 && passenger->getDestination() == Destination::International) {
		for (int i = 2; i < passenger->getLuggagesCount(); i++) {
			luggageCost += 100;
		}
	}
	if (cost == 0) {
		switch (passenger->getDestination()) {
			case Destination::DomesticShort:
				cost = 10;
				break;
			case Destination::DomesticLong:
				cost = 100;
				break;
			case Destination::International:
				cost = 500;
				break;
			default:
				break;
		}
	}
}

int Ticket::getCost() const {
	return cost;
}

int Ticket::getLuggageCost() const {
	return luggageCost;
}

bool Ticket::isAvailable() const {
	return available;
}

void Ticket::setAvailable(bool available) {
	this->available = available;
}

TicketOffice::TicketOffice() : tickets(nullptr), amount(0) {
}

void TicketOffice::setTicket(Ticket* tickets, int amount) {
	this->tickets = tickets;
	this->amount = amount;
}

void TicketOffice::printAnalyse() {
	cout << "售票结束，营业额统计信息如下：" << endl;

	struct Stats {
		int totalCost = 0;
		string passengerNames;
		bool isFirstPassenger = true;

		void addPassenger(const string& name) {
			if (!isFirstPassenger) {
				passengerNames += "、";
			}
			passengerNames += name;
			isFirstPassenger = false;
		}
	};
	Stats freeDomesticShort, freeDomesticLong, freeInternational;
	Stats teamDomesticShort, teamDomesticLong, teamInternational;

	for (int i = 0; i < amount; i++) {
		if (!tickets[i].isAvailable()) continue;

		Passenger* p = tickets[i].getPassenger();
		Destination dest = p->getDestination();
		bool isTeam = p->getWantTeam();
		int cost = tickets[i].getCost() + tickets[i].getLuggageCost();

		if (isTeam) {
			switch (dest) {
				case Destination::DomesticShort:
					teamDomesticShort.totalCost += cost;
					teamDomesticShort.addPassenger(p->getName());
					break;
				case Destination::DomesticLong:
					teamDomesticLong.totalCost += cost;
					teamDomesticLong.addPassenger(p->getName());
					break;
				case Destination::International:
					teamInternational.totalCost += cost;
					teamInternational.addPassenger(p->getName());
					break;
			}
		} else {
			switch (dest) {
				case Destination::DomesticShort:
					freeDomesticShort.totalCost += cost;
					freeDomesticShort.addPassenger(p->getName());
					break;
				case Destination::DomesticLong:
					freeDomesticLong.totalCost += cost;
					freeDomesticLong.addPassenger(p->getName());
					break;
				case Destination::International:
					freeInternational.totalCost += cost;
					freeInternational.addPassenger(p->getName());
					break;
			}
		}
	}

	// 输出结果
	cout << "国内短途自由行：" << freeDomesticShort.totalCost << " 元，乘客姓名：" << freeDomesticShort.passengerNames << endl;
	cout << "国内长途自由行：" << freeDomesticLong.totalCost << " 元，乘客姓名：" << freeDomesticLong.passengerNames << endl;
	cout << "国际游自由行： " << freeInternational.totalCost << " 元，乘客姓名：" << freeInternational.passengerNames << endl;
	cout << "国内短途团购： " << teamDomesticShort.totalCost << " 元，乘客姓名：" << teamDomesticShort.passengerNames << endl;
	cout << "国内长途团购： " << teamDomesticLong.totalCost << " 元，乘客姓名：" << teamDomesticLong.passengerNames << endl;
	cout << "国际游团购： " << teamInternational.totalCost << " 元，乘客姓名：" << teamInternational.passengerNames << endl;
}
