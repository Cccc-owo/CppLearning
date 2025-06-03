#include "Circle.h"

Circle::Circle(double radius) : radius(radius), Shape(1) {
}

std::string Circle::getName() const {
	return "圆";
}

void Circle::printArg() const {
	std::cout << "半径" << radius;
}

double Circle::getCircumference() const {
	constexpr double PI = 3.1415926;
	return 2 * PI * radius;
}

void Circle::setUnitPrice(double unitPrice) {
	Shape::setUnitPrice(unitPrice);
}

double Circle::getRadius() const {
	return radius;
}