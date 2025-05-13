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

void Park::claimSpace(Automobile* automobile) {
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

void Park::reclaimSpace(Automobile* automobile) {
	for (int foo = 0; foo < spacesNum; foo++) {
		if (spaces[foo] == automobile) {
			spaces[foo] = nullptr;
			count--;
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

void Park::getPaid(int fee) {
	income += fee;
}
