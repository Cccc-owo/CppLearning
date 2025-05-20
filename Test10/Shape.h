#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
public:
	Shape() = default;
	virtual std::string getName() const = 0;
	virtual void printArg() const = 0;
	virtual double getCircumference() const = 0;
	void printCircumference();
	friend bool operator>(const Shape& a, const Shape& b);
};

#endif //SHAPE_H
