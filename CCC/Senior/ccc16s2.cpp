// https://dmoj.ca/problem/ccc16s2
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int problem, n, x;
    vector<int> a;
    vector<int> b;

    cin >> problem >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int total = 0;

    if (problem == 2) {
        reverse(b.begin(), b.end());
    }
    for (int i = 0; i < n; i++) {
        total += max(a[i], b[i]);
    }
    cout << total;

    return 0;
}
