/*
CCC '21 S1 - Crazy Fencing
Key Concepts: Implementation
https://dmoj.ca/problem/ccc21s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int x, y; cin >> x;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        cin >> y;
        q.push(x+y);
        x = y;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        ans += q.front() * x;
        q.pop();
    }
    printf("%.1f\n", ans/2.0);

    return 0;
}