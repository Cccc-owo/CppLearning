#include "RightTriangle.h"

RightTriangle::RightTriangle(double lengthA, double lengthB) : lengthA(lengthA), lengthB(lengthB) {
}

std::string RightTriangle::getName() const {
	return std::string("三角形");
}

void RightTriangle::printArg() const {
	std::cout << "直角边" << lengthA << "，直角边" << lengthB;
}

double RightTriangle::getCircumference() const {
    return lengthA + lengthB + sqrt(lengthA * lengthA + lengthB * lengthB);
}
