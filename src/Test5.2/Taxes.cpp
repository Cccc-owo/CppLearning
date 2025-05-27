#include <iostream>
#include <iomanip>

using namespace std;

typedef struct {
	int base;
	int rate;
} Rule;

void inputRules(Rule rules[], int n);

void printRules(Rule rules[], int n);

double computeTax(Rule rules[], int n, int income);

int main() {
	Rule rules[100];
	int amount = 0;
	int income = -1;
	double taxes = 0.0;

	cout << "请输入规则的条数：";
	cin >> amount;
	if (amount <= 0) {
		cout << "输入数值不合法！" << endl;
		return 0;
	}

	inputRules(rules, amount);
	cout << endl;

	printRules(rules, amount);
	cout << endl;

	do {
		cout << "请输入您的收入：";
		cin >> income;
		if (income == -1) {
			cout << "再见！" << endl;
			break;
		}
		taxes = computeTax(rules, amount, income);
		cout << "您的收入是：" << income << "，应缴所得税：" << fixed << setprecision(2) << taxes << " 元。" << endl;
		cout << endl;
	} while (income != -1);

	return 0;
}

void inputRules(Rule rules[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "条规则：";
		cin >> rules[i].base >> rules[i].rate;
	}
}

void printRules(Rule rules[], int n) {
	cout << "纳税规则如下：" << endl;
	cout << "纳税线      税率" << endl;
	for (int i = 0; i < n; i++) {
		cout << setw(8) << left << rules[i].base << setw(6) << right << rules[i].rate << endl;
	}
}

double computeTax(Rule rules[], int n, int income) {
	double taxes = 0.0;
	for (int i = n - 1; i >= 0; i--) {
		if (income <= rules[i].base) {
			continue;
		}
		int difference = income - rules[i].base;
		// cout << endl << difference << endl;
		taxes += difference * rules[i].rate / 100.0;
		income -= difference;
		// cout << endl << taxes << endl;
	}
	return taxes;
}
