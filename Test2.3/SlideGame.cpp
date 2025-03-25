#include <iostream>
#include <string>

using namespace std;

void getSlide(string input[], int n);
bool ifTarget(string input);
int move(string input, string output[]);
void resolve(string input[], string output[], int n);

int main() {
	string input[100];
	string result[8];

	int situation;
	cin >> situation;

	getSlide(input, situation);
	resolve(input, result, situation);

	return 0;
}

void getSlide(string input[], int n) {
	for (int i = 0; i < n; i++) {
		int nSlide;
		cin >> nSlide;
		cin.get();	// 吸收空格
		for (int j = 0; j < 2 * nSlide + 1; j++) {
			input[i] += cin.get();
		}
	}
	cout << endl;
	//for (int i = 0; i < n; i++) {
	//	cout << input[i] << endl;
	//}
}

bool ifTarget(string input) {
	bool has_B = false;
	for (size_t i = 0; i < input.size() - 1; i++) {
		if (!has_B && input[i] == 'B') {
			has_B = true;
		}
		if (has_B && input[i] == 'W') {
			return false;
		}
	}
	return true;
}

int move(const string input, string output[]) {
	int result = 0;
	int emptyPos = 0;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'E') {
			emptyPos = i;	// 获取空格位置
		}
	}
	string temp = input;
	// 走法1
	if (emptyPos > 0) { // 向左移动（非尾字符）
		temp = input;
		swap(temp[emptyPos], temp[emptyPos - 1]);
		output[result++] = temp;
	}
	if (emptyPos < input.size() - 1) { // 向右移动（非尾字符）
		temp = input;
		swap(temp[emptyPos], temp[emptyPos + 1]);
		output[result++] = temp;
	}

	// 走法2
	if (emptyPos >= 2) { // 左跃1格
		temp = input;
		swap(temp[emptyPos], temp[emptyPos - 2]);
		output[result++] = temp;
	}
	if (emptyPos <= input.size() - 3) { // 右跃1格
		temp = input;
		swap(temp[emptyPos], temp[emptyPos + 2]);
		output[result++] = temp;
	}
	if (emptyPos >= 3) { // 左跃2格
		temp = input;
		swap(temp[emptyPos], temp[emptyPos - 3]);
		output[result++] = temp;

	}
	if (emptyPos <= input.size() - 4) { // 右跃2格
		temp = input;
		swap(temp[emptyPos], temp[emptyPos + 3]);
		output[result++] = temp;
	}

	return result;
}

void resolve(string input[], string output[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "结果_" << i + 1 << endl;
		if (ifTarget(input[i])) {
			cout << "目标格局" << endl;
			continue;
		}
		int count = move(input[i], output);
		// 去重
		for (int j = 0; j < count; j++) {
			for (int k = j + 1; k < count; ) {
				if (output[j] == output[k]) {
					// 将重复项交换到数组末尾，并减少总数
					swap(output[k], output[count - 1]);
					count--; // 总数减少
				}
				else {
					k++; // 仅当不重复时递增k
				}
			}
		}
		// 排序
		for (int j = 0; j < count - 1; j++) {
			for (int k = 0; k < count - 1 - j; k++) {
				if (output[k] > output[k + 1]) {
					swap(output[k], output[k + 1]);
				}
			}
		}

		for (int j = 0; j < count; j++)	{
			cout << output[j] << endl;
		}
	}
}