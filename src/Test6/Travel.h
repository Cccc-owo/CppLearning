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
	static constexpr int MAX_LUGGAGES = 3;
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
    bool luggages[MAX_LUGGAGES] = { false };
};

class Team {
public:
    Team();
	static constexpr int MAX_MEMBER = 6;
    bool addMember(Passenger* p);			// Returns the status of adding new member
	Destination getDestination() const;
	void printDestination() const;
    int getCount() const;
	int getCost() const;
private:
    Passenger* members[MAX_MEMBER];
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

class TravelAgency {
public:
	TravelAgency(int teamsCount);
	void addPassenger(Passenger* p);
	void printSummary() const;
	void setTeams();
private:
	Team* teams;
	int teamsCount;
	int teamMemberCount = 0;
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
