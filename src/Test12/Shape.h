#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
public:
	Shape();
	Shape(int classId);
	virtual ~Shape() = default;
	virtual std::string getName() const = 0;
	virtual void printArg() const = 0;
	virtual double getCircumference() const = 0;
	void printCircumference() const;
	int getClassId() const;
	double getUnitPrice() const;
	virtual void setUnitPrice(double unitPrice);
	friend bool operator>(const Shape& a, const Shape& b);
private:
	int classId;
	double unitPrice;
};

#endif //SHAPE_H
