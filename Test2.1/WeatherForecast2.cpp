/*
 *		文件名：	WeatherForecast.cpp
 *		概要：	模拟天气预报，一个月的温度分析
 *		函数：	
 *			1. displayTemps	显示月间温度的柱状图
 *			2. displayPeaks 显示月间温度的峰值
 *			3. displayFlat	显示月间持续最久的温度
 *			4. inputTemps	接收用户输入
 */

#include <iostream>
#include <iomanip>

using namespace std;

// 输入n个温度
void inputTemps(int temp[], int n);
// 显示柱状图
void displayTemps(int temp[], int n);
// 显示月间温度的所有峰值
void displayPeaks(int temp[], int n);
// 显示月间持续最久的温度
void displayFlat(int temp[], int n);

// 主函数
int main() {
	int temps[30];

	inputTemps(temps, 30);
	displayTemps(temps, 30);
	displayPeaks(temps, 30);
	displayFlat(temps, 30);

	return 0;
}

void inputTemps(int temp[], int n) {
	cout << "Please input the temperatures:" << endl;
	int count = 0;
	while (cin.peek() != '\n') {
		cin >> temp[count++];
	}
	//if (count > 30) {
	//	cout << "输入数据大于30个，暂不支持" << endl;
	//}
	if (count < 30) {
		temp[count] = -274;
	}
	cout << endl;
}

void displayTemps(int temp[], int n) {
	cout << "显示柱状图如下：" << endl;
	for (int i = 0; i < n; i++)	{
		if (temp[i] == -274) {
			break;
		}
		int max = abs(temp[0]);
		for (int i = 0; i < n; i++)	{
			if (temp[i] == -274) {
				break;
			}
			if (abs(temp[i]) > max) {
				max = abs(temp[i]);
			}
		}
		cout << setw(3) << right << temp[i];
		if (temp[i] < 0) {
			for (int j = max + 2; j > abs(temp[i]); j--) {
				cout << " ";
			}
			for (int j = 0; j < abs(temp[i]); j++) {
				cout << "*";
			}
			cout << "|";
		} else {
			for (int j = max + 2; j > 0; j--) {
				cout << " ";
			}
			cout << "|";
			for (int j = 0; j < temp[i]; j++) {
				cout << "*";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void displayPeaks(int temp[], int n) {
	cout << "显示峰值如下：" << endl;
	int max[7] = { 0 };
	int max_count = 0;
	for (int i = 1; i < n - 1; i++) {
		if (temp[i] == -274 || temp[i] != -274 && temp[i + 1] == -274) {
			break;
		}
		if (temp[i - 1] < temp[i] && temp[i + 1] < temp[i]) {
			max[max_count++] = i;
		}
	}
	if (max_count == 0) {
		cout << "没有峰值" << endl;
	}
	for (int i = 0; i < max_count; i++) {
		cout << "Max at day " << max[i] + 1 << " is " << temp[max[i]] << endl;
	}
	cout << endl;
}

void displayFlat(int temp[], int n) {
	cout << "显示崮的长度如下：" << endl;
	int max_length = 1;
	int max_number = 0;
	int current_length = 1;
	for (int i = 1; i < n; i++)	{
		if (temp[i] == -274) {
			break;
		}
		if (temp[i] == temp[i - 1]) {
			current_length++;
		} else {
			current_length = 1;
		}
		if (current_length > max_length) {
			max_length = current_length;
			max_number = i;
		}
	}
	cout << "The length of longest flat is " << max_length << endl;
	cout << "It is " << temp[max_number] << "℃" << endl;
}