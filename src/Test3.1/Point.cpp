#include <iostream>

using namespace std;

class Point {
public:
	// 默认构造函数，默认值为左上角坐标(0, 0)
	Point(int xx = 0, int yy = 0);
	void setX(int xx);
	int getX();
	void setY(int yy);
	int getY();
	void print();
	void moveRight(int offset);
	void moveDown(int offset);
private:
	int x;
	int y;
};

int main() {
	int xx, yy;
	cout << "Please input a point: ";
	cin >> xx >> yy;
	Point p1(xx, yy); // 生成点对象1
	cout << "Point p1: ";
	p1.print();
	cout << endl;
	Point p2(xx * 2, yy * 2); //生成点对象2
	cout << "Point p2: ";
	p2.print();
	cout << endl;
	p1.moveRight(10);
	cout << "After moving right, p1: ";
	p1.print();
	cout << endl;
	p2.moveDown(-10); // 位移量为负数，表示向上移动
	cout << "After moving down, p2: ";
	p2.print();
	cout << endl;

	return 0;
}

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
	cout << "(" << x << ", " << y << ")";
}
void Point::moveRight(int offset) {
	x += offset;
}
void Point::moveDown(int offset) {
	y += offset;
}
