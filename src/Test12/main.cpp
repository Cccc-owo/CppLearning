#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "Array.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RightTriangle.h"
#include "Square.h"
#include "MyException.h"

using namespace std;

void printResult(Array<Shape*> arr, int count);

void writeBinaryFile(const string& filename, Shape* shape);

void readAndDisplayBinaryFile(const string& filename);

int main() {
	try	{
		const char* binaryFiles[] = { "D:/CODE/CppLearning/src/Test12/data/Circle.dat",
			"D:/CODE/CppLearning/src/Test12/data/Rectangle.dat",
			"D:/CODE/CppLearning/src/Test12/data/RightTriangle.dat",
			"D:/CODE/CppLearning/src/Test12/data/Square.dat" };
		Array<Shape*> ShapeArray(10);
		int shapeCount = 0;

		ifstream shapesList("D:/CODE/CppLearning/src/Test12/data/Shapes.txt");
		if (!shapesList.is_open()) {
			throw FileNotOpenedException("Failed to open Shapes.txt");
		}

		string line;
		while (getline(shapesList, line)) {
			istringstream strStream(line);
			int classId;
			strStream >> classId;
			string str1, str2;
			double unitPrice;
			strStream >> str1 >> str2 >> unitPrice;
			// 每行的样式:
			// 1. Circle, 4.0
			// 语句执行之后，str1的值是".", str2的值是"Circle,", unitPrice的值是4.0

			Shape* shape = nullptr;
			switch(classId) {
			case 1:
				shape = new Circle(3.0);
				break;
			case 2:
				shape = new Rectangle(3.0, 3.0);
				break;
			case 3:
				shape = new RightTriangle(3.0, 3.0);
				break;
			case 4:
				shape = new Square(3.0);
				break;
			default:
				cout << "Wrong classId" << endl;
			}
			if (shape) {
				shape->setUnitPrice(unitPrice);
				if (shapeCount >= ShapeArray.getSize()) {
					ShapeArray.resize(ShapeArray.getSize() * 2);
				}
				ShapeArray[shapeCount++] = shape;
			}
		}

		shapesList.close();

		for (int i = 1; i < shapeCount; i++) {	// 对 Shape 的周长进行插入排序
			Shape* temp = ShapeArray[i];
			int j;
			for (j = i - 1; j >= 0 && *temp > *ShapeArray[j]; j--) {
				ShapeArray[j + 1] = ShapeArray[j];
			}
			ShapeArray[j + 1] = temp;
		}

		printResult(ShapeArray, shapeCount);

		cout << endl;

		for (int i = 0; i < shapeCount; i++) {
			int classId = ShapeArray[i]->getClassId();
			writeBinaryFile(binaryFiles[classId-1], ShapeArray[i]);
		}

		cout << endl;

		for (int i = 0; i < 4; i++) {
			readAndDisplayBinaryFile(binaryFiles[i]);
		}

	} catch (FileNotOpenedException& e)	{
		cerr << "Error: " << e.what() << endl;
		cerr << "Possible reasons: file not found, incorrect path, or file locked by another process." << endl;
	} catch (const exception& e) {
		cerr << "Standard exception: " << e.what() << endl;
	} catch (...) {
		cerr << "Unknown exception occurred" << endl;
	}

    return 0;
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

void writeBinaryFile(const string& filename, Shape* shape) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error opening binary file: " << filename << endl;
        return;
    }

    int classId = shape->getClassId();
    outFile.write(reinterpret_cast<const char*>(&classId), sizeof(int));

	double price = 0.0;
	char shapeName[16] = { 0 };

	switch(classId) {
		case 1: { // Circle
			auto* circle = dynamic_cast<Circle*>(shape);
			double radius = circle->getRadius();
			price = circle->getUnitPrice();
			strcpy(shapeName, "Circle");
			outFile.write(shapeName, 16 * sizeof(char));
			outFile.write(reinterpret_cast<const char*>(&radius), sizeof(double));
			outFile.write(reinterpret_cast<const char*>(&price), sizeof(double));
			break;
		}
		case 2: { // Rectangle
			auto* rect = dynamic_cast<Rectangle*>(shape);
			double width = rect->getWidth();
			double height = rect->getHeight();
			price = rect->getUnitPrice();
			strcpy(shapeName, "Rectangle");
			outFile.write(shapeName, 16 * sizeof(char));
			outFile.write(reinterpret_cast<const char*>(&width), sizeof(double));
			outFile.write(reinterpret_cast<const char*>(&height), sizeof(double));
			outFile.write(reinterpret_cast<const char*>(&price), sizeof(double));
			break;
		}
		case 3: { // RightTriangle
			auto* tri = dynamic_cast<RightTriangle*>(shape);
			double lengthA = tri->getLengthA();
			double lengthB = tri->getLengthB();
			price = tri->getUnitPrice();
			strcpy(shapeName, "RightTriangle");
			outFile.write(shapeName, 16 * sizeof(char));
			outFile.write(reinterpret_cast<const char*>(&lengthA), sizeof(double));
			outFile.write(reinterpret_cast<const char*>(&lengthB), sizeof(double));
			outFile.write(reinterpret_cast<const char*>(&price), sizeof(double));
			break;
		}
		case 4: { // Square
			auto* square = dynamic_cast<Square*>(shape);
			double length = square->getLength();
			price = square->getUnitPrice();
			strcpy(shapeName, "Square");
			outFile.write(shapeName, 16 * sizeof(char));
			outFile.write(reinterpret_cast<const char*>(&length), sizeof(double));
			outFile.write(reinterpret_cast<const char*>(&price), sizeof(double));
			break;
		}
		default:
			break;
    }
	cout << "Written " << filename << endl;
    outFile.close();
}

void readAndDisplayBinaryFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error opening binary file: " << filename << endl;
        return;
    }

    cout << "Contents of " << filename << ": " << endl;

	int classId = 0;
	double price = 0.0;
	inFile.read(reinterpret_cast<char*>(&classId), sizeof(int));
	char shapeName[16];
	inFile.read(shapeName, 16 * sizeof(char));

	Shape* shape = nullptr;

    switch(classId) {
        case 1: { // Circle
            double radius = 0.0;
            inFile.read(reinterpret_cast<char*>(&radius), sizeof(double));
            inFile.read(reinterpret_cast<char*>(&price), sizeof(double));
            shape = new Circle(radius);
            break;
        }
        case 2: { // Rectangle
            double width = 0.0, height = 0.0;
            inFile.read(reinterpret_cast<char*>(&width), sizeof(double));
            inFile.read(reinterpret_cast<char*>(&height), sizeof(double));
            inFile.read(reinterpret_cast<char*>(&price), sizeof(double));
			shape = new Rectangle(width, height);
            break;
        }
        case 3: { // RightTriangle
            double lengthA = 0.0, lengthB = 0.0;
            inFile.read(reinterpret_cast<char*>(&lengthA), sizeof(double));
            inFile.read(reinterpret_cast<char*>(&lengthB), sizeof(double));
            inFile.read(reinterpret_cast<char*>(&price), sizeof(double));
			shape = new RightTriangle(lengthA, lengthB);
            break;
        }
        case 4: { // Square
            double length = 0.0;
            inFile.read(reinterpret_cast<char*>(&length), sizeof(double));
            inFile.read(reinterpret_cast<char*>(&price), sizeof(double));
			shape = new Square(length);
            break;
        }
		default:
			break;
    }

	if (shape) {
		cout << classId << "   " << shapeName << "    ";
		shape->printArg();
		delete shape;
	}

    cout << "，单价" << price << endl;
    inFile.close();
}
