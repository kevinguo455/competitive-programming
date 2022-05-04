/*
CCC '22 S1 - Good Fours and Good Fives
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/ccc22s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int ans = 0;

    int y = N % 4;
    int x = (N - 5*y)/4;

    while (x >= 0) {
        x -= 5;
        y += 4;
        ++ans;
    }

    cout << ans << '\n';

    return 0;
}