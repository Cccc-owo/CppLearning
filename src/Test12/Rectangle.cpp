#include "Rectangle.h"

Rectangle::Rectangle(double lengthA, double lengthB) : lengthA(lengthA), lengthB(lengthB), Shape(2) {
}

std::string Rectangle::getName() const {
	return "长方形";
}

void Rectangle::printArg() const {
	std::cout << "长" << lengthA << "，宽" << lengthB;
}

double Rectangle::getCircumference() const {
	return (lengthA + lengthB) * 2;
}

void Rectangle::setUnitPrice(double unitPrice) {
	Shape::setUnitPrice(unitPrice);
}

double Rectangle::getWidth() const {
	return lengthA;
}

double Rectangle::getHeight() const {
	return lengthB;
}
