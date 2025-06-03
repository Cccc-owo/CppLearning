#include "RightTriangle.h"
#include "cmath"

RightTriangle::RightTriangle(double lengthA, double lengthB) : lengthA(lengthA), lengthB(lengthB), Shape(3) {
}

std::string RightTriangle::getName() const {
	return "三角形";
}

void RightTriangle::printArg() const {
	std::cout << "直角边" << lengthA << "，直角边" << lengthB;
}

double RightTriangle::getCircumference() const {
    return lengthA + lengthB + sqrt(lengthA * lengthA + lengthB * lengthB);
}

void RightTriangle::setUnitPrice(double unitPrice) {
	Shape::setUnitPrice(unitPrice);
}

double RightTriangle::getLengthA() const {
	return lengthA;
}

double RightTriangle::getLengthB() const {
	return lengthB;
}
