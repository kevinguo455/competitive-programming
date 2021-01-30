/*
Wesley's Anger Contest 6 Problem 1 - Timbit Sales
Key Concepts: Simple Math
https://dmoj.ca/problem/wac6p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    double p, c;
    for (int i = 0; i < n; i++) {
        cin >> p >> c;
        cout << (100*p/c) / (1+100/c) << "\n";
    }

    return 0;
}