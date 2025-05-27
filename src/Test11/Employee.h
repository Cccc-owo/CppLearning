#include "Date.h"

class Employee {
public:
	//构造函数，使用“初始化列表”初始化数据成员
	Employee(std::string, std::string, Date&, Date&);
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
	std::string firstName;
	std::string lastName;
	Date birthDate;    //内嵌对象，出生日期
	Date hireDate;     //内嵌对象，雇用日期
};
