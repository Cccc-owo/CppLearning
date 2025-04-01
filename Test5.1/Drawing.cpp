#include <iostream>

using namespace std;

typedef struct Point {
	int x;
	int y;
} Point;

void displayMenu();

void getTwoPoints(Point* p1, Point* p2);

void printPoint(Point* p);

void drawCircle(Point* p1, Point* p2);

void drawRectangle(Point* p1, Point* p2);

int main() {
	int choice;

	Point startP, endP;
	do {
		displayMenu();
		cin >> choice;
		
		switch (choice) {
			case 1:	// 圆
				getTwoPoints(&startP, &endP);
				if (endP.x < startP.x || endP.y < startP.y) {
					cout << "Unsupported end point!" << endl;
					break;
				}
				drawCircle(&startP, &endP);
				cout << endl;
				break;
			case 2: // 长方形
				getTwoPoints(&startP, &endP);
				if (endP.x < startP.x || endP.y < startP.y) {
					cout << "Unsupported end point!" << endl;
					cout << endl;
					break;
				}
				drawRectangle(&startP, &endP);
				cout << endl;
				break;
			case 0:
				cout << "Good bye!" << endl;
				break;
			default:
				cout << "Not supported! Please select again!" << endl;
				cout << endl;
				break;
		}
	} while (choice);

	return 0;
}

void displayMenu() {
	cout << "******************************" << endl;
	cout << "    1. Circle (圆)            " << endl;
	cout << "    2. Rectangle (长方形)      " << endl;
	cout << "    0. Exit (退出)            " << endl;
	cout << "******************************" << endl;
	cout << "Please select the shape: ";
}

void getTwoPoints(Point* p1, Point* p2) {
	cout << "Please input the coordinate (x, y) of the start point: ";
	cin >> p1->x >> p1->y;
	cout << "Please input the coordinate (x, y) of the end point: ";
	cin >> p2->x >> p2->y;
}

void printPoint(Point* p) {
	cout << "a point at (" << p->x << ", " << p->y << ")";
}

void drawCircle(Point* p1, Point* p2) {
	Point center;
	double radius = 0;
	if (p2->x - p1->x != p2->y - p1->y) {
		cout << "Not a circle, select again." << endl;
	} else {
		radius = (p2->x - p1->x) / 2.0;
		center.x = (p1->x + p2->x) / 2;
		center.y = (p1->y + p2->y) / 2;
		cout << "Draw a circle at center (" << center.x << ", " << center.y << ") with radius " << radius << endl;
	}
}

void drawRectangle(Point* p1, Point* p2) {
	int width = p2->x - p1->x;
	int height = p2->y - p1->y;
	cout << "Draw a rectangle at topleft (" << p1->x << ", " << p1->y << "), whose width is " << width << " and height is " << height << "." << endl;
}
