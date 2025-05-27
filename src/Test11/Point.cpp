#include "Point.h"

Point::Point(int xx, int yy) {
	x = xx;
	y = yy;
}
void Point::setX(int xx) {
	x = xx;
}
int Point::getX() {
	return x;
}
void Point::setY(int yy) {
	y = yy;
}
int Point::getY() {
	return y;
}
void Point::print() {
	std::cout << "(" << x << ", " << y << ")";
}
void Point::moveRight(int offset) {
	x += offset;
}
void Point::moveDown(int offset) {
	y += offset;
}
