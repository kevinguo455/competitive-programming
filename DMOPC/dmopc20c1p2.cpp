// https://dmoj.ca/problem/dmopc20c1p2
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <math.h>
#include <tuple>
#include <deque>

using namespace std;

int main() {
    deque<int> numbers;

    int n, d, x;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> x;
        numbers.push_back(x);
    }

    for (int i = 0; i < d; i++) {
        cin >> x;
        
        int sum1 = 0, sum2 = 0;

        for (deque<int>::iterator it = numbers.begin(); it != numbers.begin() + x; it++) {
            sum1 += *it;
        }
        for (deque<int>::iterator it = numbers.begin() + x; it != numbers.end(); it++) {
            sum2 += *it;
        }
        int snapped = 0;
        if (sum1 >= sum2) {
            for (int j = 0; j < x; j++) {
                snapped += numbers.front();
                numbers.pop_front();
            }
        }
        else {
            for (int j = numbers.size(); j > x; j--) {
                snapped += numbers.back();
                numbers.pop_back();
            }
        }
        cout << snapped << endl;
    }

    return 0;
}
