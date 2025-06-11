#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Computer.h"
#include "ComputerStore.h"

class Customer {	// 顾客
public:
	Customer(const std::string& name);
	~Customer();
	void browseCatalogue(const ComputerStore& store) const;		// 浏览产品目录
	void buyComputer(ComputerStore& store, const std::string& brand, const std::string& model);			// 购买计算机
	void writeAndRunProgram(const std::string& programName) const;	// 编写程序并运行

private:
	std::string name;	// 姓名
	bool hasBought;		// 是否已经购买
	Computer* computer;
};

#endif //CUSTOMER_H
