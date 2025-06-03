#include "Square.h"

Square::Square(const double length) : Rectangle(length, length), Shape(4) {
}

std::string Square::getName() const {
	return "正方形";
}

void Square::printArg() const {
	std::cout << "边长" << lengthA;
}

double Square::getLength() const {
	return lengthA;
}
