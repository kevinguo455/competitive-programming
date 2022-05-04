/*
CCC '20 S1 - Surmising a Sprinter's Speed
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/ccc20s1
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

struct Pair{int t, p;} arr[MAXN];

bool cmp(Pair a, Pair b) {
    return a.t < b.t;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].t >> arr[i].p;
    }

    sort(arr, arr+N, cmp);

    double ans = -1e11;
    for (int i = 1; i < N; i++) {
        ans = max(ans, abs(((double)arr[i].p-arr[i-1].p) / ((double)arr[i].t-arr[i-1].t)));
    }
    cout << ans << '\n';

    return 0;
}