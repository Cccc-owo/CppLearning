#include "Employee.h"

Employee::Employee(std::string firstName, std::string lastName, Date birthDate, Date hireDate): firstName(firstName), lastName(lastName), birthDate(birthDate), hireDate(hireDate) {
}

void Employee::print() const {
	std::cout << lastName << ", " << firstName << " Hired: ";
	hireDate.printFullYear();
	std::cout << " Birthday: ";
	birthDate.printFullYear();
	// std::cout << std::endl;
}

int Employee::getAge(Date& date) const {
	return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(Date& date) const {
	return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(Date& date) const {
	return hireDate.daysTo(date);
}

Date Employee::getBirthDate() const {
	return birthDate;
}

Date Employee::getHireDate() const {
	return hireDate;
}

Employee::~Employee() {
}

bool Employee::operator>(const Employee& employee) {
	return !(this->birthDate > employee.getBirthDate());
}
