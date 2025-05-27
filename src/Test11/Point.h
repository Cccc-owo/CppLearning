#include <iostream>

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
