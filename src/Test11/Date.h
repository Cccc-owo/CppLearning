#include <iostream>
#include <iomanip>

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