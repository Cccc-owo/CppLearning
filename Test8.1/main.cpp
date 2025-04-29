#include <iostream>
#include "date.h"

using namespace std;

int main() {
	Date birthDate(1969, 8, 11);
	Date date2(2010, 4, 15);
	Date nation(1949, 10, 1);
	birthDate.printFullYear(); // 打印：1969-08-11
	birthDate.printStandardYear(); // 打印：69-08-11
	birthDate.setSeparator('/');
	birthDate.printFullYear(); // 打印：1969/08/11
	cout << birthDate.fullYearsTo(2010, 4, 15) << endl; // 打印：40，满四十岁
	cout << birthDate - date2 << endl; // 打印14857
	// 打印-7254，共和国比我早诞生了7254天
	cout << birthDate - nation << endl;
	if (birthDate > date2) {
		cout << "birthDate > date2" << endl;
	} else if (birthDate < date2) {
		cout << "birthDate < date2" << endl;
	}
	return 0;
}
