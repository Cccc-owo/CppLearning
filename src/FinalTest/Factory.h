#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include "Array.h"
#include "Computer.h"

class Factory {  // 工厂，用于制造各型计算机
public:
	Factory(const std::string& name);
	Array<Computer*> produceComputers(ComputerType type, const std::string& brand, const std::string& model, int quantity) const;  // 根据指定的类型和数量制造计算机
private:
	std::string name;  // 工厂名称
};

#endif //FACTORY_H
