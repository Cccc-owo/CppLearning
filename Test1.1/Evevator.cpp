#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_RESULT = 100;
    int N = 0;
    int results[MAX_RESULT] = { 0 };
    string desc[MAX_RESULT];
    int count = 0;

    const int wait_time = 5;
    const int up_time = 6;
    const int down_time = 4;

    while (cin >> N && N != 0) {
        int current = 0;
        int total_time = 0;
        desc[count] = "";
        for (int i = 0; i < N; ++i) {
            int target;
            cin >> target;
            int diff = target - current;
            if (diff > 0) {
                total_time += up_time * diff;
                desc[count] += to_string(up_time);
                desc[count] += " * ";
                desc[count] += to_string(diff);
            }
            else {
                total_time += down_time * (-diff);
                desc[count] += to_string(down_time);
                desc[count] += " * ";
                desc[count] += to_string(-diff);
            }
            total_time += wait_time;
            desc[count] += " + ";
            desc[count] += to_string(wait_time);
            if (i < N - 1) {
                desc[count] += " + ";
            }
            current = target;
        }
        results[count++] = total_time;
    }

    for (int i = 0; i < count; ++i) {
        cout << results[i] << " (" << desc[i] << ")" << endl;
    }

    return 0;
}