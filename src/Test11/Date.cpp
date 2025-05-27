#include "Date.h"

const int Date::DAYS_PER_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int year, int month, int day): year(year), month(month), day(day), separator('-') {
	if (month < 1 || month > 12) {
		this->month = 1;
	}
	int maxDay = DAYS_PER_MONTH[this->month - 1];
	if (month == 2 && isLeapYear(year)) {
		maxDay = 29;
	}
	if (day > maxDay) {
		this->day = 1;
	}
}

void Date::setDate(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
	if (month < 1 || month > 12) {
		this->month = 1;
	}
	int maxDay = DAYS_PER_MONTH[this->month - 1];
	if (this->month == 2 && isLeapYear(year)) {
		maxDay = 29;
	}
	if (day > maxDay) {
		this->day = 1;
	}
}

void Date::setYear(int year) {
	this->year = year;
}

int Date::getYear() const {
	return year;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getMonth() const {
	return month;
}

void Date::setDay(int day) {
	this->day = day;
}

int Date::getDay() const {
	return day;
}

void Date::setSeparator(char separator) {
	this->separator = separator;
}

void Date::printFullYear() const {
	std::cout << year << separator << std::setfill('0') << std::setw(2) << month << separator << std::setfill('0') << std::setw(2) << day;
	// std::cout << std::endl;
}

void Date::printStandardYear() const {
	std::cout << year % 100 << separator << std::setfill('0') << std::setw(2) << month << separator << std::setfill('0') << std::setw(2) << day;
	// std::cout << std::endl;
}

int Date::fullYearsTo(Date& date) const {
	int diffYear = date.getYear() - year;
	return (date.getMonth() > month || date.getMonth() == month && date.getDay() >= day) ? diffYear : diffYear - 1;
}

int Date::countDays(Date date) const {
	int ayear = date.getYear();
	int amonth = date.getMonth();
	int aday = date.getDay();
	if (amonth < 3) {
		ayear--;
		amonth += 12;
	}
	return 365 * ayear + (ayear / 4) - ayear / 100 + ayear / 400 + (153 * amonth - 457) / 5 + aday - 306;
}

int Date::daysTo(const Date& date) const {
	return countDays(date) - countDays(*this);
}

int Date::getDayOfYear() const {
	int count = 0;
	for (int i = 0; i < month - 1; i++) {
		count += DAYS_PER_MONTH[i];
	}
	count += day;
	if (month > 2 && isLeapYear(year)) {
		count++;
	}
	return count;
}

int Date::getLeftDaysYear() const {
	return isLeapYear(year) ? 366 - getDayOfYear() : 365 - getDayOfYear();
}

bool Date::operator>(const Date& date) {
	return !(this->daysTo(date) > 0);
}

int Date::checkDay(int day) const {
	if (month == 2 && isLeapYear(year) && day != 29 || day != DAYS_PER_MONTH[month - 1]) {
		return -1;
	}
	return day;
}

bool Date::isLeapYear(int year) const {
	return (year % 400 == 0 || year % 100 != 0 && year % 4 == 0);
}
