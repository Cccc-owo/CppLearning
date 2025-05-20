#include "Shape.h"
#include <iomanip>

bool operator>(const Shape& a, const Shape& b) {
	return a.getCircumference() > b.getCircumference();
}

void Shape::printCircumference() {
	std::cout << "周长" << std::fixed << std::setprecision(2) << getCircumference() << std::defaultfloat;
}
