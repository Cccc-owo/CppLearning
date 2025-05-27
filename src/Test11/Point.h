#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
	// 默认构造函数，默认值为左上角坐标(0, 0)
	Point(int xx = 0, int yy = 0);
	void setX(int xx);
	int getX() const;
	void setY(int yy);
	int getY() const;
	void print() const;
	void moveRight(int offset);
	void moveDown(int offset);
	double distanceTo(Point point = Point(0, 0)) const;
	bool operator>(const Point& point);
private:
	int x;
	int y;
};

#endif // POINT_H