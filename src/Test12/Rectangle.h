#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : virtual public Shape {
public:
	Rectangle(double lengthA, double lengthB);
	std::string getName() const override;
	void printArg() const override;
	double getCircumference() const override;
	void setUnitPrice(double unitPrice) override;
	double getWidth() const;
	double getHeight() const;
protected:
	double lengthA;
	double lengthB;
};

#endif //RECTANGLE_H
