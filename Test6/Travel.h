#pragma once

#include <iostream>

using namespace std;

enum class Destination {
    DomesticShort,
    DomesticLong,
    International
};

class Passenger {
public:
    Passenger();
    Passenger(char id, bool wantTeam, int destination, int luggagesNum);
    string getName() const;
    char getId() const;
	bool getWantTeam() const;
	Destination getDestination() const;
    int getLuggagesCount() const;
	void printDestination() const;
private:
    string name;
    char id;
	bool wantTeam;
    Destination destination;
    bool luggages[3] = { false };
};

class Team {
public:
    Team();
    bool addMember(Passenger* p);			// Returns the status of adding new member
	Destination getDestination() const;
	void printDestination() const;
    int getCount() const;
	int getCost() const;
private:
    Passenger* members[6];
	Destination destination;
    int count;
};

class Ticket {
public:
    Ticket();
    Ticket(Passenger* p);
	Passenger* getPassenger() const;
    void setPassenger(Passenger* p);
    int getCost() const;
	int getLuggageCost() const;
	bool isAvailable() const;
	void setAvailable(bool available);
private:
    Passenger* passenger;
    int cost;
	int luggageCost;
	bool available;
    void calcCost();
};

class TicketOffice {
public:
    TicketOffice();
	void setTicket(Ticket* tickets, int amount);
    void printAnalyse();
private:
    Ticket* tickets;
	int amount;
};
