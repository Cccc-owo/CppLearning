#include "Shape.h"
#include <iomanip>

Shape::Shape() : classId(0), unitPrice(0) {
}

Shape::Shape(int classId) : classId(classId), unitPrice(0) {
}

void Shape::printCircumference() const {
	std::cout << "周长" << std::fixed << std::setprecision(2) << getCircumference() << std::defaultfloat;
}

int Shape::getClassId() const {
	return classId;
}

double Shape::getUnitPrice() const {
	return unitPrice;
}

void Shape::setUnitPrice(double unitPrice) {
	this->unitPrice = unitPrice;
}

bool operator>(const Shape& a, const Shape& b) {
	return a.getCircumference() > b.getCircumference();
}
