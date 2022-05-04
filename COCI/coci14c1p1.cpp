/*
COCI '14 Contest 1 #1 Prosjek
Key Concepts: Simple Math, Implementation
https://dmoj.ca/problem/coci14c1p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int s = 0;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        x *= i;
        x -= s;
        cout << x << ' ';
        s += x;
    }

    return 0;
}