#include <iostream>
#include <iomanip>

using namespace std;

class Date {
public:
	/* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日，同时设置日
	期分隔符为“-” */
	Date(int ayear = 1990, int amonth = 1, int aday = 1);
	/* get、set方法 */
	// 设置日期，如果有非法的月或日，将其置为1
	void setDate(int ayear, int amonth, int aday);
	void setYear(int ayear);
	int getYear();
	void setMonth(int amonth);
	int getMonth();
	void setDay(int aday);
	int getDay();
	void setSeparator(char input);
	/* 输出函数，请使用setfill(‘0’)和setw(2)，需要包含<iomanip>头文件 */
	void printFullYear(); // 以YYYY-MM-DD的形式打印，2011-01-08
	void printStandardYear(); // 以YY-MM-DD的形式打印，比如11-01-08
	/* 计算函数 */
	// 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
	int fullYearsTo(int ayear, int amonth, int aday);
	/* 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。 */
	int daysTo(int ayear, int amonth, int aday);

	static const int DAYS_PER_MONTH[12];
private:
	int year;
	int month;
	int day;
	char separator; // 日期分隔符
	int countDays(int ayear, int amonth, int aday);
};

int main() {
	Date birthDate(1969, 8, 11);
	birthDate.printFullYear(); // 打印：1969-08-11
	birthDate.printStandardYear(); // 打印：69-08-11
	birthDate.setSeparator('/');
	birthDate.printFullYear(); // 打印：1969/08/11
	cout << birthDate.fullYearsTo(2010, 4, 15) << endl; // 打印：40，满四十岁
	cout << birthDate.daysTo(2010, 4, 15) << endl; // 打印14857
	// 打印-7254，共和国比我早诞生了7254天
	cout << birthDate.daysTo(1949, 10, 1) << endl;

	return 0;
}

Date::Date(int ayear, int amonth, int aday) : year(ayear), month(amonth), day(aday) , separator('-') {
	if (month < 1 || month > 12) {
		this->month = 1;
	}
	int maxDay = DAYS_PER_MONTH[this->month - 1];
	if (month == 2 && (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)) {
		maxDay = 29;
	}
	if (day != maxDay) {
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
	if (day != maxDay) {
		this->day = 1;
	}
}

void Date::setYear(int ayear) {
	year = ayear;
}

int Date::getYear() {
	return year;
}

void Date::setMonth(int amonth) {
	month = amonth;
}

int Date::getMonth() {
	return month;
}

void Date::setDay(int aday) {
	day = aday;
}

int Date::getDay() {
	return day;
}

void Date::setSeparator(char input) {
	separator = input;
}

void Date::printFullYear() {
	cout << year << separator << setfill('0') << setw(2) << month  << separator << day;
	cout << endl;
}

void Date::printStandardYear() {
	cout << year % 100 << separator << setfill('0') << setw(2) << month << separator << day;
	cout << endl;
}

int Date::fullYearsTo(int ayear, int amonth, int aday) {
	int diffYear = ayear - year;
	return (amonth > month || amonth == month && aday >= day) ? diffYear : diffYear - 1;
}

int Date::daysTo(int ayear, int amonth, int aday) {
	return (countDays(ayear, amonth, aday) - countDays(year, month, day));
}

int Date::countDays(int ayear, int amonth, int aday) {
	if (amonth < 3) {
		ayear--;
		amonth += 12;
	}
	return 365 * ayear + (ayear / 4) - ayear / 100 + ayear / 400 + (153 * amonth - 457) / 5 + aday - 306;
}
