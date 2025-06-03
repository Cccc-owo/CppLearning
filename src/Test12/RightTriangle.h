#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Shape.h"

class RightTriangle : public Shape {
public:
	RightTriangle(double lengthA, double lengthB);
	std::string getName() const override;
	void printArg() const override;
	double getCircumference() const override;
	void setUnitPrice(double unitPrice) override;
	double getLengthA() const;
	double getLengthB() const;

private:
	double lengthA;
	double lengthB;
};

#endif //RIGHTTRIANGLE_H
