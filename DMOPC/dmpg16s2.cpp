/*
DMPG '16 S2 - Pandemic
Key Concepts: Recursion
https://dmoj.ca/problem/dmpg16s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, ans;
int K, D;

void solve(ll r, int d) {
    if (d > D) return;
    if (r > N) return;
    solve(r*K, d+1);
    ans += N/r;
    N %= r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K >> D;
    solve(1, 0);
    cout << ans << '\n';

    return 0;
}