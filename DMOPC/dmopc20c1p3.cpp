// https://dmoj.ca/problem/dmopc20c1p3
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;

    int n, x, peak = INT32_MIN, lastPeakPos = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x >= peak) {
            peak = x;
            lastPeakPos = i;
        }
        numbers.push_back(x);
    }
    long long int score = 0, floor = INT32_MIN;
    for (int i = 0; i < lastPeakPos; i++) {
        if (numbers[i] < floor) {
            score += floor - numbers[i];
        }
        else {
            floor = numbers[i];
        }
    }
    floor = INT32_MIN;
    for (int i = numbers.size() - 1; i > lastPeakPos; i--) {
        if (numbers[i] < floor) {
            score += floor - numbers[i];
        }
        else {
            floor = numbers[i];
        }
    }
    cout << score;

    return 0;
}
