#include "Circle.h"

Circle::Circle(double radius) : radius(radius) {
}

std::string Circle::getName() const {
	return std::string("圆");
}

void Circle::printArg() const {
	std::cout << "半径" << radius;
}

double Circle::getCircumference() const {
	const double PI = 3.1415926;
	return 2 * PI * radius;
}
