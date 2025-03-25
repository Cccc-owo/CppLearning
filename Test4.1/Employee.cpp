#include <iostream>
#include <iomanip>

using namespace std;

class Date {
public:
	/* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日，同时设置日期分隔符为“-” */
	Date(int year = 1990, int month = 1, int day = 1);

	/* get、set方法 */
	// 设置日期，如果有非法的月或日，将其置为1
	void setDate(int year, int month, int day);
	void setYear(int year);
	int getYear() const;
	void setMonth(int month);
	int getMonth() const;
	void setDay(int day);
	int getDay() const;
	void setSeparator(char separator);

	/* 输出函数，请使用setfill(‘0’)和setw(2)。*/
	void printFullYear() const;      //以YYYY-MM-DD的形式打印，2011-01-08
	void printStandardYear() const; //以YY-MM-DD的形式打印，比如11-01-08
	/* 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况。注意参数为日期对象的引用。*/
	int fullYearsTo(Date& date) const;
	/* 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。注意参数为日期对象的引用。*/
	int daysTo(Date& date);
	/* 新增函数，可以被daysTo函数调用 */
	int getDayOfYear();  //计算当前日期是本年的第几天
	int getLeftDaysYear(); //计算当前日期距本年结束还有几天，不包括当前日期这天
private:
	int year;
	int month;
	int day;
	char separator;  // 日期分隔符
	/* 新增数据成员和函数成员 */
	/*声明静态常变量，每月的天数，在.cpp文件中定义并初始化 */
	static const int DAYS_PER_MONTH[12];
	/*根据年和月，判断参数日期是否合法。如果合法，返回day，否则返回-1。*/
	int checkDay(int day);
	bool isLeapYear(int year);//判断参数年是否是闰年。
	int countDays(Date date);//计算一个日期是1/1/1的第几天
};

const int Date::DAYS_PER_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Employee {
public:
	//构造函数，使用“初始化列表”初始化数据成员
	Employee(string, string, Date&, Date&);
	//打印员工的信息。调用Date类的print函数，打印员工的生日和雇佣日期。
	void print();
	//计算员工在参数指定的日期时，满多少岁。请使用Date类的fullYearsTo函数
	int getAge(Date& date);
	//计算该员工在参数指定的日期时，工作满了多少年。
	int getYearsWorked(Date& date);
	//计算该员工在参数指定的日期时，工作了多少天。使用Date类的daysTo函数。
	int getDaysWorked(Date& date);
	~Employee();   //析构函数
private:
	string firstName;
	string lastName;
	Date birthDate;    //内嵌对象，出生日期
	Date hireDate;     //内嵌对象，雇用日期
};

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
	return 0;
}

Date::Date(int year, int month, int day): year(year), month(month), day(day), separator('-') {
	if (month < 1 || month > 12) {
		this->month = 1;
	}
	int maxDay = DAYS_PER_MONTH[this->month - 1];
	if (month == 2 && isLeapYear(year)) {
		maxDay = 29;
	}
	if (day != maxDay) {
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
	if (day != maxDay) {
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
	cout << year << separator << setfill('0') << setw(2) << month << separator << setfill('0') << setw(2) << day;
	// cout << endl;
}

void Date::printStandardYear() const {
	cout << year % 100 << separator << setfill('0') << setw(2) << month << separator << setfill('0') << setw(2) << day;
	// cout << endl;
}

int Date::fullYearsTo(Date& date) const {
	int diffYear = date.getYear() - year;
	return (date.getMonth() > month || date.getMonth() == month && date.getDay() >= day) ? diffYear : diffYear - 1;
}

int Date::countDays(Date date) {
	int ayear = date.getYear();
	int amonth = date.getMonth();
	int aday = date.getDay();
	if (amonth < 3) {
		ayear--;
		amonth += 12;
	}
	return 365 * ayear + (ayear / 4) - ayear / 100 + ayear / 400 + (153 * amonth - 457) / 5 + aday - 306;
}

int Date::daysTo(Date& date) {
	return countDays(date) - countDays(*this);
}

int Date::getDayOfYear() {
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

int Date::getLeftDaysYear() {
	return isLeapYear(year) ? 366 - getDayOfYear() : 365 - getDayOfYear();
}

int Date::checkDay(int day) {
	if (month == 2 && isLeapYear(year) && day != 29 || day != DAYS_PER_MONTH[month - 1]) {
		return -1;
	}
	return day;
}

bool Date::isLeapYear(int year) {
	return (year % 400 == 0 || year % 100 != 0 && year % 4 == 0);
}

Employee::Employee(string firstName, string lastName, Date& birthDate, Date& hireDate): firstName(firstName), lastName(lastName), birthDate(birthDate), hireDate(hireDate) {
}

void Employee::print() {
	cout << lastName << ", " << firstName << " Hired: ";
	hireDate.printFullYear();
	cout << " Birthday: ";
	birthDate.printFullYear();
	// cout << endl;
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
