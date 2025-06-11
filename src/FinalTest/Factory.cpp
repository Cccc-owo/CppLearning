#include <iostream>
#include "Factory.h"

Factory::Factory(const std::string& name) : name(name) {
	std::cout << name << " 工厂建成了。" << std::endl;
}

Array<Computer*> Factory::produceComputers(ComputerType type, const std::string& brand, const std::string& model, const int quantity) const {
	std::cout << name << ": 正在制造 " << quantity << " 台 " << brand << " 品牌 " << model << " 型号计算机。" << std::endl;
	Array<Computer*> arr(quantity);
	for (int i = 0; i < quantity; i++) {
		if (type == ComputerType::DESKTOP) {
			arr[i] = new Desktop(brand, model);
		} 
		if (type == ComputerType::LAPTOP) {
			arr[i] = new Laptop(brand, model);
		}
		if (type == ComputerType::SERVER) {
			arr[i] = new Server(brand, model);
		}
	}
	return arr;
}
