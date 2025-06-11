#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

enum class ComputerType {
	DESKTOP,		// 台式机
	LAPTOP,			// 笔记本
	SERVER			// 服务器
};

class Computer {  // 计算机的基类
public:
	Computer(const std::string& brand, const std::string& model);
	virtual ~Computer() = default;
	virtual void runProgram(const std::string& programName) = 0;	// 在计算机上运行程序
	void showInfo() const;

public:
	std::string brand;		// 品牌
	std::string model;		// 型号
	int price;			// 单价
};

class Desktop : public Computer {	// 台式计算机
public:
	Desktop(const std::string& brand, const std::string& model);
	void runProgram(const std::string& programName) override;	// 在计算机上运行程序

protected:
	double weight;  // 重量
};

class Laptop : public Computer {		// 笔记本计算机
public:
	Laptop(const std::string& brand, const std::string& model);
	void runProgram(const std::string& programName) override;	// 在计算机上运行程序

protected:
	double batteryLife;  // 电池寿命，单位：年
	std::string color;  // 颜色
};

class Server : public Computer {		// 笔记本计算机
public:
	Server(const std::string& brand, const std::string& model);
	void runProgram(const std::string& programName) override;	// 在计算机上运行程序

};

#endif //COMPUTER_H
