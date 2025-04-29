#ifndef DATE_H
#define DATE_H

class Date {
public:
    /* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日，同时设置日
    期分隔符为“-” */
    Date(int ayear = 1990, int amonth = 1, int aday = 1);
    /* get、set方法 */
    // 设置日期，如果有非法的月或日，将其置为1
    void setDate(int ayear, int amonth, int aday);
    void setYear(int ayear);
    int getYear() const;
    void setMonth(int amonth);
    int getMonth() const;
    void setDay(int aday);
    int getDay() const;
    void setSeparator(char input);
    /* 输出函数，请使用setfill(‘0’)和setw(2)，需要包含<iomanip>头文件 */
    void printFullYear() const; // 以YYYY-MM-DD的形式打印，2011-01-08
    void printStandardYear() const; // 以YY-MM-DD的形式打印，比如11-01-08
    /* 计算函数 */
    // 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
    int fullYearsTo(int ayear, int amonth, int aday) const;
    /* 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。 */
    int daysTo(int ayear, int amonth, int aday) const;
	int operator-(const Date& date2) const;
	bool operator>(const Date& date2) const;
	bool operator<(const Date& date2) const;
    static const int DAYS_PER_MONTH[12];
private:
    int year;
    int month;
    int day;
    char separator; // 日期分隔符
};

#endif //DATE_H
