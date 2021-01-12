/*
COCI '09 Contest 4 #2 Planina
Key Concepts: Simple Math
https://dmoj.ca/problem/coci09c4p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    int s = 2;
    while (n--) {
        s *= 2;
        s -= 1;
    }
    cout << s * s << endl;

    return 0;
}