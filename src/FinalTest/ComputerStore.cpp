#include <iostream>
#include "ComputerStore.h"

ComputerStore::ComputerStore(const std::string& name, int size) : name(name), quantity(0), totalRevenue(0), products(size) {
	std::cout << name << " 商店开张了。" << std::endl;
}

void ComputerStore::addComputers(Array<Computer*> computers) {
	std::cout << name << ": 正在进货，" << computers.getSize() << " 台计算机。" << std::endl;
	products.resize(quantity + computers.getSize());
	for (int i = 0; i < computers.getSize(); i++) {
		products[quantity + i] = computers[i];
	}
	quantity += computers.getSize();
}

Computer* ComputerStore::sellComputer(const std::string& brand, const std::string& model) {
	for (int i = 0; i < products.getSize(); i++) {
		if (products[i] != nullptr && products[i]->brand == brand && products[i]->model == model) {
			this->quantity--;
			// std::cout << quantity << " " << std::endl;
			this->totalRevenue += products[i]->price;
			// std::cout << totalRevenue << " " << std::endl;
			Computer* result = products[i];
			products[i] = nullptr;
			return result;
		}
	}
	return nullptr;
}

void ComputerStore::getMenu() const {
	std::cout << name << "的计算机产品目录：" << std::endl;
	for (int i = 0; i < products.getSize(); i++) {
		if (products[i] != nullptr) {
			products[i]->showInfo();
		}
	}
}

void ComputerStore::displayCurrentStatus() const {
	std::cout << "商店名称：" << name << std::endl;
	std::cout << "库存产品数量：" << quantity << std::endl;
	std::cout << "总收入：" << totalRevenue << "元" << std::endl;
	std::cout << "计算机产品目录：" << std::endl;
	for (int i = 0; i < products.getSize(); i++) {
		if (products[i] != nullptr) {
			products[i]->showInfo();
		}
	}
}
