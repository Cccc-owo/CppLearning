#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

Date::Date(int ayear, int amonth, int aday) : year(ayear), month(amonth), day(aday), separator('-') {
    if (month < 1 || month > 12) {
        this->month = 1;
    }
    int maxDay = DAYS_PER_MONTH[this->month - 1];
    if (month == 2 && (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)) {
        maxDay = 29;
    }
    if (day > maxDay) {
        this->day = 1;
    }
}

const int Date::DAYS_PER_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void Date::setDate(int ayear, int amonth, int aday) {
    year = ayear;
    if (amonth < 1 || amonth > 12) {
        month = 1;
    } else {
        month = amonth;
    }
    int maxDay = DAYS_PER_MONTH[month - 1];
    if (month == 2 && (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)) {
        maxDay = 29;
    }
    if (day > maxDay) {
        this->day = 1;
    }
}

void Date::setYear(int ayear) {
    year = ayear;
}

int Date::getYear() const {
    return year;
}

void Date::setMonth(int amonth) {
    month = amonth;
}

int Date::getMonth() const {
    return month;
}

void Date::setDay(int aday) {
    day = aday;
}

int Date::getDay() const {
    return day;
}

void Date::setSeparator(char input) {
    separator = input;
}

void Date::printFullYear() const {
    cout << year << separator << setfill('0') << setw(2) << month << separator << day;
    cout << endl;
}

void Date::printStandardYear() const {
    cout << year % 100 << separator << setfill('0') << setw(2) << month << separator << day;
    cout << endl;
}

int Date::fullYearsTo(int ayear, int amonth, int aday) const {
    int diffYear = ayear - year;
    return (amonth > month || amonth == month && aday >= day) ? diffYear : diffYear - 1;
}

int Date::operator-(const Date& date2) const {
	int y2, m2, d2;
	int y1, m1, d1;

	m1 = (month + 9) % 12;
	y1 = year - m1 / 10;
	d1 = 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 + (m1 * 306 + 5) / 10 + (day - 1);

	m2 = (date2.getMonth() + 9) % 12;
	y2 = date2.getYear() - m2 / 10;
	d2 = 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400 + (m2 * 306 + 5) / 10 + (date2.getDay() - 1);

	return (d2 - d1);
}

bool Date::operator>(const Date& date2) const {
	return (*this - date2 < 0) ? true : false;
}

bool Date::operator<(const Date& date2) const {
    return (*this - date2 > 0) ? true : false;
}
