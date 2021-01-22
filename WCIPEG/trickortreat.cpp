/*
PEG Test - Halloween 2014: Trick-or-Treat
Key Concepts: Greedy Algorithms
https://dmoj.ca/problem/trickortreat
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, d, x; cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    d -= v[0];
    if (d < 0) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i < n; i++) {
        d -= v[i] + 1;
        if (d < 0) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << n << "\n";

    return 0;
}