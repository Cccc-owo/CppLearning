#include <iostream>
#include <iomanip>
#include "Employee.h"

using namespace std;

Employee::Employee(string firstName, string lastName, Date& birthDate, Date& hireDate): firstName(firstName), lastName(lastName), birthDate(birthDate), hireDate(hireDate) {
}

void Employee::print() {
	cout << lastName << ", " << firstName << " Hired: ";
	hireDate.printFullYear();
	cout << "Birthday: ";
	birthDate.printFullYear();
	// cout << endl;
}

int Employee::getAge(Date& date) const {
	return birthDate.fullYearsTo(date.getYear(), date.getMonth(), date.getDay());
}

int Employee::getYearsWorked(Date& date) const {
	return hireDate.fullYearsTo(date.getYear(), date.getMonth(), date.getDay());
}

int Employee::getDaysWorked(Date& date) const {
	return hireDate - date;
}

Date Employee::getBirthDate() const {
	return birthDate;
}

Date Employee::getHireDate() const {
	return hireDate;
}

const Employee& Employee::getMostFaith(const Employee employees[], int n) {
	const Employee* mostFaith = &employees[0];
	for (int next = 1; next < n; next++) {
		if (mostFaith->getHireDate() > employees[next].getHireDate()) {
			mostFaith = &employees[next];
		}
	}
	return *mostFaith;
}

Employee::~Employee() = default;
