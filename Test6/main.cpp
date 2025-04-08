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
	for (int i = 0; i < numOfPassengers; i++) {	// 生成旅客
		char id;
		if (i < 26) {
			id = 'A';
		} else if (i - 26 < 26) {
			id = 'a';
		} else {
			id = '0';
		}
		id += (i % 26);
		passenger[i] = Passenger(id, static_cast<bool>(rand() % 2), rand() % MAX_DESTINATION, rand() % (Passenger::MAX_LUGGAGES + 1));
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
		tickets[i] = move(Ticket(&passenger[i]));
		cout << "买票需付 " << tickets[i].getCost() << " 元";
		if (tickets[i].getLuggageCost() == 0) {
			cout << "。" << endl;
		} else {
			cout << "，行李托运费 " << tickets[i].getLuggageCost() << " 元。" << endl;
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
