#include <iostream>
#include "Computer.h"

Computer::Computer(const std::string& brand, const std::string& model) : brand(brand), model(model), price(0) {
}

void Computer::runProgram(const std::string& programName) {
}

void Computer::showInfo() const {
	std::cout << "品牌：" << brand << "，型号：" << model << "，价格：" << price << std::endl;
}

Desktop::Desktop(const std::string& brand, const std::string& model) : Computer(brand, model), weight(10) {
	price = 5000;
}

void Desktop::runProgram(const std::string& programName) {
	std::cout << "在台式计算机上运行\"" << programName << "\"。" << std::endl;
}

Laptop::Laptop(const std::string& brand, const std::string& model) : Computer(brand, model), batteryLife(10), color("白色") {
	price = 8000;
}

void Laptop::runProgram(const std::string& programName) {
	std::cout << "在笔记本计算机中运行\"" << programName << "\"。" << std::endl;
}

Server::Server(const std::string& brand, const std::string& model) : Computer(brand, model) {
}

void Server::runProgram(const std::string& programName) {
	std::cout << "在服务器计算机上运行\"" << programName << "\"。" << std::endl;
}
