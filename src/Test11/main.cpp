#include <iostream>
#include "Point.h"
#include "Date.h"
#include "Employee.h"

using namespace std;

template <typename T>
T max(T arr[], int size){
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
	Date today(2025, 5, 27);

	Point arr1[] = { Point(3, 1),
		Point(3, 4), 
		Point(1, 1) };
	Date arr2[] = { Date(2025, 5, 27), 
		Date(1997, 3, 1), 
		Date(2000, 5, 1) };
	Employee arr3[] = { Employee("A", "A", Date(1997, 1, 1), today), 
		Employee("B", "B", Date(1996, 2, 17), today), 
		Employee("C", "C", Date(1990, 1, 1), today) };

	Point maxPoint = max<Point>(arr1, 3);
	Date maxDate = max<Date>(arr2, 3);
	Employee maxEmployee = max<Employee>(arr3, 3);

	cout << "数组中离坐标系原点最远的点：";
	maxPoint.print();
	cout << endl;
	cout << "数组中最晚的日期：";
	maxDate.printFullYear();
	cout << endl;
	cout << "数组中年龄最大的雇员：";
	maxEmployee.print();
	cout << endl;

    return 0;
}