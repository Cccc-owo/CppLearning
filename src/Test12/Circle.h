#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
public:
	Circle(double radius);
	std::string getName() const override;
	void printArg() const override;
	double getCircumference() const override;
	void setUnitPrice(double unitPrice) override;
	double getRadius() const;
private:
	double radius;
};

#endif //CIRCLE_H
