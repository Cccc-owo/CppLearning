#include <iostream>
#include "Park.h"
#include "Automobile.h"

Park::Park(const int spacesNum) : count(0), income(0), spacesNum(spacesNum) {
	spaces = new Automobile * [spacesNum];
	for (int foo = 0; foo < spacesNum; foo++) {
		spaces[foo] = nullptr;
	}
}

Park::~Park() {
	delete[] spaces;
}

void Park::enter(Automobile* automobile) {
	for (int foo = 0; foo < spacesNum; foo++) {
		if (spaces[foo] == nullptr) {
			spaces[foo] = automobile;
			cout << automobile->getId() << "进入停车场，分配停车位。" << endl;
			count++;
			return;
		}
	}
	cout << "无法为" << automobile->getId() << "分配停车位。" << endl;
}

void Park::leave(Automobile* automobile) {
	for (int foo = 0; foo < spacesNum; foo++) {
		if (spaces[foo] != nullptr) {
			int income = automobile->pay();
			this->income += income;
			spaces[foo] = nullptr;
			count--;
			cout << automobile->getId() << "离开停车场，缴纳停车费" << income << "元。" << endl;
			return;
		}
	}
}

void Park::showInfo() const {
	cout << "停车场目前停放了" << count << "辆汽车";
	if (count != 0) {
		cout << "：";
		for (int foo = 0; foo < spacesNum; foo++) {
			if (spaces[foo] != nullptr) {
				cout << spaces[foo]->getId() << "，";
			}
		}
	} else {
		cout << "，";
	}
	cout << "共收入" << income << "元停车费。" << endl;
}
