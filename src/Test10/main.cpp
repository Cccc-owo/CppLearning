#include <iostream>
#include "Array.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RightTriangle.h"

using namespace std;

void printMenu();

void printResult(Array<Shape*> arr, int count);

int main() {
	Array<Shape*> ShapeArray(10);

	int choice = -1;
	int shapeCount = 0;

	while(true) {
		printMenu();
		cin >> choice;
		if (choice == -1) {
			break;
		}
		if (choice < 1 || choice > 3) {
			cout << "无效选择，请重新输入。" << endl;
			continue;
		}
		double arg1, arg2;
		switch (choice) {
			case 1:	// 圆
				cin >> arg1;
				if (ShapeArray.getSize() < shapeCount) {
					ShapeArray.resize(ShapeArray.getSize() + 5);
				}
				ShapeArray[shapeCount++] = new Circle(arg1);
				break;
			case 2:	// 长方形
				cin >> arg1;
				cin >> arg2;
				if (ShapeArray.getSize() < shapeCount) {
					ShapeArray.resize(ShapeArray.getSize() + 5);
				}
				ShapeArray[shapeCount++] = new Rectangle(arg1, arg2);
				break;
			case 3:	// 直角三角形
				cin >> arg1;
				cin >> arg2;
				if (ShapeArray.getSize() < shapeCount) {
					ShapeArray.resize(ShapeArray.getSize() + 5);
				}
				ShapeArray[shapeCount++] = new RightTriangle(arg1, arg2);
				break;
			default:
				break;
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i < shapeCount; i++) {	// 对 Shape 的周长进行插入排序
		Shape* temp = ShapeArray[i];
		int j;
		for (j = i - 1; j >= 0 && *temp > *ShapeArray[j]; j--) {
			ShapeArray[j + 1] = ShapeArray[j];
		}
		ShapeArray[j + 1] = temp;
	}

	printResult(ShapeArray, shapeCount);

    return 0;
}

void printMenu() {
	cout << "请选择框架并给出参数：" << endl;
	cout << " 1. 圆 - 半径" << endl;
	cout << " 2. 长方形 - 长 宽" << endl;
	cout << " 3. 直角三角形 - 直角边A 直角边B" << endl;
	cout << "-1. 退出" << endl;
}

void printResult(Array<Shape*> arr, int count) {
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ". " + arr[i]->getName() << "，";
		arr[i]->printArg();
		cout << "，";
		arr[i]->printCircumference();
		cout << endl;
	}
}
