#include "Shape.h"
#include <iomanip>

void Shape::printCircumference() const {
	std::cout << "周长" << std::fixed << std::setprecision(2) << getCircumference() << std::defaultfloat;
}

bool operator>(const Shape& a, const Shape& b) {
	return a.getCircumference() > b.getCircumference();
}
