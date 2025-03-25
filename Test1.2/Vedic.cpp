#include <iostream>

using namespace std;

int digitalRoot(int n);

int main() {
	int vedic[9][9] = { 0 };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			vedic[i][j] = (i + 1) * (j + 1);
			do {
				vedic[i][j] = digitalRoot(vedic[i][j]);
			} while (vedic[i][j] >= 10);
		}
	}

	cout << "   | 1  2  3  4  5  6  7  8  9 " << endl;
	cout << "---|---------------------------" << endl;
	for (int i = 0; i < 9; i++) {
		cout << " " << i + 1 << " |";
		for (int j = 0; j < 9; j++) {
			cout << " " << vedic[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "=x==x==x==x==x==x==x==x==x=" << endl;
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if (vedic[j][k] == i) {
					cout << " * ";
				}
				else {
					cout << "   ";
				}
			}
			cout << endl;
		}
		cout << "=x==x==x==x==x==x==x==x==x=" << endl;
	}

	return 0;
}

int digitalRoot(int n) {
	int sum = 0;
	int num = 0;
	while (n / 10 != 0) {
		num = n % 10;
		n /= 10;
		sum += num;
		// cout << "num is " << num << endl;
	}
	num = n % 10;
	sum += num;
	// cout << "num is " << num << endl;
	return sum;
}