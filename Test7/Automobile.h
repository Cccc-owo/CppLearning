#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include <string>

using namespace std;

class Park;

class Automobile {
public:
	explicit Automobile(string id);
	virtual ~Automobile() = default;
    virtual int pay() const = 0;
	string getId();
	void enter(Park* park);
	void leave(Park* park);
protected:
    string id;	// 车牌号
};

#endif //AUTOMOBILE_H
