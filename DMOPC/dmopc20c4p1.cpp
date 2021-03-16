/*
DMOPC '20 Contest 4 P1 - Missing Numbers
Key Concepts: Simple Math
https://dmoj.ca/problem/dmopc20c4p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T; 
    while (T--) {
        ll N, S; cin >> N >> S;
        ll R = N*(N+1)/2 - S;
        cout << (R+1)/2 - max(R-N, 1LL) << '\n';
    }

    return 0;
}