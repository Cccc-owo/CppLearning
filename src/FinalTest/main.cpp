#include <iostream>
#include "Array.h"
#include "Computer.h"
#include "ComputerStore.h"
#include "Customer.h"
#include "Factory.h"

int main(){
	Factory factory("Lenovo Factory");	// 创建工厂
	// 工厂制造计算机
	Array<Computer*> desktops = factory.produceComputers(ComputerType::DESKTOP, "Lenovo", "ThinkCentre", 5);		// 类型、品牌、型号、数量
	Array<Computer*> laptops = factory.produceComputers(ComputerType::LAPTOP, "Lenovo", "ThinkPad", 3);
	cout << endl;

	ComputerStore store("Lenovo Store", 5);		// 创建商店，Array数组初始容量为5
	// 商店从工厂进货
	store.addComputers(desktops);
	store.addComputers(laptops);
	cout << endl;

	Customer zhang("小张");	// 创建顾客

	// 顾客浏览产品目录
	zhang.browseCatalogue(store);

	// 顾客购买台式计算机
	zhang.buyComputer(store, "Lenovo", "ThinkCentre");    // 注意ThinkCentre不要拼写错

	// 顾客编写程序并运行
	zhang.writeAndRunProgram("Hello World");
	cout << endl;

	Customer wu("小吴");	// 创建顾客

	// 顾客购买笔记本计算机
	wu.buyComputer(store, "Lenovo", "ThinkPad");

	// 顾客编写程序并运行
	wu.writeAndRunProgram("C Program");
	cout << endl;

	Customer wang("小王");		// 创建顾客

	// 顾客购买服务器，但商店没有库存
	wang.buyComputer(store, "Lenovo", "ThinkServer");

	// 顾客编写程序并运行
	wang.writeAndRunProgram("C++ Program");
	cout << endl;

	// 商店盘点，显示当前状态
	store.displayCurrentStatus();

	return 0;
}