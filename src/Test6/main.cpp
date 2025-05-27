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
	const int TEAM_NUMS = 5;

	// 初始化旅客及票
	int numOfPassengers = rand() % MAX_PASSENGERS + 1;
	Passenger passenger[MAX_PASSENGERS];
	Ticket tickets[MAX_PASSENGERS];
	for (int order = 0; order < numOfPassengers; order++) {	// 生成旅客
		char id;
		if (order < 26) {
			id = 'A';
		} else if (order - 26 < 26) {
			id = 'a';
		} else {
			id = '0';
		}
		id += (order % 26);
		passenger[order] = Passenger(id, static_cast<bool>(rand() % 2), rand() % MAX_DESTINATION, rand() % (Passenger::MAX_LUGGAGES + 1));
		tickets[order] = move(Ticket(&passenger[order]));
		cout << "我是" << passenger[order].getName() << "，";
		if (passenger[order].getWantTeam()) {
			cout << "报名旅行社，";
		} else {
			cout << "选择自由出行，";
		}
		passenger[order].printDestination();
		cout << "，携带 " << passenger[order].getLuggagesCount() << " 件行李，";
		if (passenger[order].getLuggagesCount() > 0) {
			cout << "行李编号是 ";
			for (int luggageOrder = 0; luggageOrder < passenger[order].getLuggagesCount(); luggageOrder++) {
				cout << passenger[order].getId() << setfill('0') << setw(2) << luggageOrder + 1;
				if (luggageOrder + 1 < passenger[order].getLuggagesCount()) {
					cout << "、";
				} else {
					cout << "，";
				}
			}
		}
		cout << "买票需付 " << tickets[order].getCost() << " 元";
		if (tickets[order].getLuggageCost() == 0) {
			cout << "。" << endl;
		} else {
			cout << "，行李托运费 " << tickets[order].getLuggageCost() << " 元。" << endl;
		}
	}
	cout << endl;

	// 初始化旅行社
	TravelAgency agency(TEAM_NUMS);
	agency.setTeams();

	// 将乘客添加到旅行团
	cout << "旅行社开始报名。" << endl;
	for (int i = 0; i < numOfPassengers; i++) {
		agency.addPassenger(&passenger[i]);
	}
	cout << endl;

	// 打印旅行社的总结信息
	agency.printSummary();
	cout << endl;

	// 初始化售票处
	TicketOffice office;
	cout << "售票处开始售票。" << endl;
	office.setTicket(tickets, numOfPassengers);
	office.printAnalyse();

	return 0;
}
