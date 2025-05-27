#include "Point.h"
#include <cmath>

Point::Point(int xx, int yy) {
	x = xx;
	y = yy;
}
void Point::setX(int xx) {
	x = xx;
}
int Point::getX() const {
	return x;
}
void Point::setY(int yy) {
	y = yy;
}
int Point::getY() const {
	return y;
}
void Point::print() const {
	std::cout << "(" << x << ", " << y << ")";
}
void Point::moveRight(int offset) {
	x += offset;
}
void Point::moveDown(int offset) {
	y += offset;
}

double Point::distanceTo(Point point) const {
	return sqrt(pow(x - point.getX(), 2) + pow(y - point.getY(), 2));
}

bool Point::operator>(const Point& point) {
	return this->distanceTo() > point.distanceTo();
}
