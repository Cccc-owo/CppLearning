#include "Employee.h"

Employee::Employee(std::string firstName, std::string lastName, Date& birthDate, Date& hireDate): firstName(firstName), lastName(lastName), birthDate(birthDate), hireDate(hireDate) {
}

void Employee::print() {
	std::cout << lastName << ", " << firstName << " Hired: ";
	hireDate.printFullYear();
	std::cout << " Birthday: ";
	birthDate.printFullYear();
	// std::cout << std::endl;
}

int Employee::getAge(Date& date) {
	return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(Date& date) {
	return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(Date& date) {
	return hireDate.daysTo(date);
}

Employee::~Employee() {
}
