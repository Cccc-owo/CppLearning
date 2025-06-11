#ifndef COMPUTERSTORE_H
#define COMPUTERSTORE_H

#include <string>
#include "Array.h"
#include "Computer.h"

class ComputerStore {  // 商店，用于展示和销售各型计算机
public:
	ComputerStore(const std::string& name, int size);
	~ComputerStore() = default;
	void addComputers(Array<Computer*> computers);  // 向商店中添加工厂生产的计算机
	Computer* sellComputer(const std::string& brand, const std::string& model);  // 销售计算机
	void getMenu() const;
	void displayCurrentStatus() const;  // 显示商店当前状态

private:
	std::string name;  // 商店名称
	Array<Computer*> products;  // 存储计算机对象指针的数组
	int quantity;  // 库存产品数量
	int totalRevenue;  // 总收入
};

#endif //COMPUTERSTORE_H
