#include "Rectangle.h"

Rectangle::Rectangle(double lengthA, double lengthB) : lengthA(lengthA), lengthB(lengthB) {
}

std::string Rectangle::getName() const {
	return std::string("长方形");
}

void Rectangle::printArg() const {
	std::cout << "长" << lengthA << "，宽" << lengthB;
}

double Rectangle::getCircumference() const {
	return (lengthA + lengthB) * 2;
}
