#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(double lengthA, double lengthB);
	std::string getName() const override;
	void printArg() const override;
	double getCircumference() const override;
private:
	double lengthA;
	double lengthB;
};

#endif //RECTANGLE_H
