#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include <string>
#include <utility>

class Park;

class Automobile {
public:
	explicit Automobile(std::string id);
	virtual ~Automobile() = default;
	std::string getId();
	void enter(Park* park);
	void leave(Park* park);
protected:
    std::string id;	// 车牌号
private:
	virtual void pay(Park* park) = 0;
};

#endif //AUTOMOBILE_H
