#include <iostream>
#include "Customer.h"

Customer::Customer(const std::string& name) : name(name), hasBought(false), computer(nullptr) {
}

Customer::~Customer() {
	delete computer;
}

void Customer::browseCatalogue(const ComputerStore& store) const {
	std::cout << name << "：正在浏览计算机产品目录。" << std::endl;
	store.getMenu();
}

void Customer::buyComputer(ComputerStore& store, const std::string& brand, const std::string& model) {
	std::cout << name << "：我打算买一台计算机用来编程。我看好了 " << brand << " 的 " << model << " 型号。" << std::endl;
	Computer* computer = store.sellComputer(brand, model);
	if (computer != nullptr) {
		std::cout << name << "：我购买了计算机。" << std::endl;
		hasBought = true;
		this->computer = computer;
	} else {
		std::cout << name << "：没有买到我看好的计算机。" << std::endl;
	}
}

void Customer::writeAndRunProgram(const std::string& programName) const {
	if (hasBought) {
		computer->runProgram(programName);
	} else {
		std::cout << name << "：我没有计算机来运行程序。" << std::endl;
	}
}
