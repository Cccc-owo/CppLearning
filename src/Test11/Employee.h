#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Date.h"

class Employee {
public:
	//构造函数，使用“初始化列表”初始化数据成员
	Employee(std::string firstName, std::string lastName, Date birthDate, Date hireDate);
	//打印员工的信息。调用Date类的print函数，打印员工的生日和雇佣日期。
	void print() const;
	//计算员工在参数指定的日期时，满多少岁。请使用Date类的fullYearsTo函数
	int getAge(Date& date) const;
	//计算该员工在参数指定的日期时，工作满了多少年。
	int getYearsWorked(Date& date) const;
	//计算该员工在参数指定的日期时，工作了多少天。使用Date类的daysTo函数。
	int getDaysWorked(Date& date) const;
	Date getBirthDate() const;
	Date getHireDate() const;
	/*
	*参数employees[]是雇员对象的数组；n是雇员对象数组的元素个数
	*返回值：工作年限最长的雇员对象的引用
	*/
	static const Employee& getMostFaith(const Employee employees[], int n);

	~Employee();   //析构函数
	bool operator>(const Employee& employee);

private:
	std::string firstName;
	std::string lastName;
	Date birthDate;    //内嵌对象，出生日期
	Date hireDate;     //内嵌对象，雇用日期
};

#endif // EMPLOYEE_H