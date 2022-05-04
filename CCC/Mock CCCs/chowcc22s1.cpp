/*
Mock CCC '22 S1 - Hungry Shark
Key Concepts: Implementation
https://www.hackerrank.com/contests/csec-mock-ccc-2022-senior/challenges/hungry-shark
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, A, B; cin >> N >> A >> B;

    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    while (A < B) {
        int i = 0;
        while (i < N && A < v[i]) i++;
        if (i == N) {
            cout << "-1\n";
            return 0;
        }
        A += v[i];
        v[i] = 0x3f3f3f3f;
        ans++;
    }

    cout << ans << '\n';

    return 0;
}