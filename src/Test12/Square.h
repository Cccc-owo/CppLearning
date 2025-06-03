#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
	Square(double length);
	std::string getName() const override;
	void printArg() const override;
	double getLength() const;
	// void setUnitPrice(double unitPrice) override;
};

#endif // SQUARE_H