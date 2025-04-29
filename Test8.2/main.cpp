#include <iostream>
#include "date.h"
#include "Employee.h"

int main() {
	Date birth(1969, 8, 11);
	Date hire(1998, 4, 1);
	Date today(2010, 4, 30);
	Employee manager("Bob", "Blue", birth, hire);
	// cout << endl;
	manager.print();
	cout << endl;
	cout << manager.getAge(today) << endl;
	cout << manager.getDaysWorked(today) << endl;
	cout << "==========" << endl;
	Date hire2(1988, 4, 5);
	Date hire3(2001, 5, 29);
	Date hire4(1987, 12, 5);
	Date hire5(2004, 3, 21);
	Employee test1("a", "a", birth, hire);
	Employee test2("b", "b", birth, hire2);
	Employee test3("c", "c", birth, hire3);
	Employee test4("d", "d", birth, hire4);
	Employee test5("e", "e", birth, hire5);
	Employee Test[5] = { test1, test2, test3, test4, test5 };
	Employee mostFaith = Employee::getMostFaith(Test, 5);
	cout << "工作年限最长的雇员是";
	mostFaith.print();
	cout << "他工作了" << mostFaith.getDaysWorked(today) << "天。" << endl;
	return 0;
}
