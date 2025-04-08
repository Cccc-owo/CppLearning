#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#include "Travel.h"

using namespace std;

int main() {
	srand(static_cast<unsigned> (time(NULL)));
	const int MAX_PASSENGERS = 62;
	const int MAX_DESTINATION = 3;
	const int MAX_LUGGAGES = 3;
	const int TEAM_NUMS = 5;
	const int TEAM_MAX_MEMBERS = 6;

	// init passengers and tickets
	int numOfPassengers = rand() % MAX_PASSENGERS + 1;
	Passenger passenger[MAX_PASSENGERS];
	Ticket tickets[MAX_PASSENGERS];
	for (int i = 0; i < numOfPassengers; i++) {	// generate passengers
		char id;
		if (i < 26) {
			id = 'A';
		} else if (i - 26 < 26) {
			id = 'a';
		} else {
			id = '0';
		}
		id += (i % 26);
		passenger[i] = Passenger(id, static_cast<bool>(rand() % 2), rand() % MAX_DESTINATION, rand() % (MAX_LUGGAGES + 1));
		cout << "我是" << passenger[i].getName() << "，";
		if (passenger[i].getWantTeam()) {
			cout << "报名旅行社，";
		} else {
			cout << "选择自由出行，";
		}
		passenger[i].printDestination();
		cout << "，携带 " << passenger[i].getLuggagesCount() << " 件行李，";
		if (passenger[i].getLuggagesCount() > 0) {
			cout << "行李编号是 ";
			for (int j = 0; j < passenger[i].getLuggagesCount(); j++) {
				cout << passenger[i].getId() << setfill('0') << setw(2) << j + 1;
				if (j + 1 < passenger[i].getLuggagesCount()) {
					cout << "、";
				} else {
					cout << "，";
				}
			}
		}
		tickets[i] = Ticket(&passenger[i]);		// init tickets
		cout << "买票需付 " << tickets[i].getCost() << " 元";
		if (tickets[i].getLuggageCost() == 0) {
			cout << "。" << endl;
		} else {
			cout << "，行李托运费 " << tickets[i].getLuggageCost() << " 元。" << endl;
		}
	}
	cout << endl;

	// init teams
	Team teams[TEAM_NUMS];
	cout << "旅行社开始报名。" << endl;
	for (int i = 0; i < numOfPassengers; i++) {
		if (passenger[i].getWantTeam()) {
			for (int j = 0; j < TEAM_NUMS; j++) {
				if (teams[j].getCount() < TEAM_MAX_MEMBERS && teams[j].getDestination() == passenger[i].getDestination()) {
					teams[j].addMember(&passenger[i]);
					break;
				}
				if (j + 1 == TEAM_NUMS && teams[j].getDestination() != passenger[i].getDestination()) {
					tickets[i].setAvailable(false);
					cout << "由于所有符合条件的旅行团（";
					passenger[i].printDestination();
					cout << "）均已报满，" << passenger[i].getName() << " 无法报名旅行团。" << endl;
				}
			}
		}
	}
	cout << "旅行社共计安排了 " << TEAM_NUMS << " 个旅行团，";
	int teamMemberCount = 0;
	for (int i = 0; i < TEAM_NUMS; i++) {
		teamMemberCount += teams[i].getCount();
	}
	cout << "共计 " << teamMemberCount << " 人报名。" << endl;
	cout << "出行目的地分别是：";
	for (int i = 0; i < TEAM_NUMS; i++) {
		teams[i].printDestination();
		if (i + 1 < TEAM_NUMS) {
			cout << "，";
		} else {
			cout << "；";
		}
	}
	cout << "每个旅行团的人数分别是：";
	for (int i = 0; i < TEAM_NUMS; i++) {
		cout << teams[i].getCount() << " 人";
		if (i + 1 < TEAM_NUMS) {
			cout << "，";
		} else {
			cout << "；";
		}
	}
	cout << "每个旅行团需要支付的票价是：";
	for (int i = 0; i < TEAM_NUMS; i++) {
		cout << teams[i].getCost() << " 元";
		if (i + 1 < TEAM_NUMS) {
			cout << "，";
		} else {
			cout << "。" << endl;
		}
	}
	cout << endl;

	// init ticketOffice
	TicketOffice office;
	cout << "售票处开始售票。" << endl;
	office.setTicket(tickets, numOfPassengers);
	office.printAnalyse();

	return 0;
}
