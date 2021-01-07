/*
Codeforces Round #690 (Div. 3) - C. Unique Number
Key Concepts: Implementation, Simple Math, Recursion
https://codeforces.com/contest/1462/problem/C
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

string ans(int n, int c, string out) {
    if (c == 0) return "-1";
    if (n <= c) return to_string(n) + out;
    else return ans(n-c, c-1, to_string(c) + out);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int cases; cin >> cases;
    for (int casen = 0; casen < cases; casen++) {
        int n; cin >> n;
        cout << ans(n, 9, "") << "\n";
    }

    return 0;
}