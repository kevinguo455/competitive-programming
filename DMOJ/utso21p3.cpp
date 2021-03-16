/*
UTS Open '21 P3 - Latin Class
Key Concepts: Dynamic Programming
https://dmoj.ca/problem/utso21p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5, MOD = 1e9+7; 

ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    ll ans = 1, x; cin >> x;
    int peak = x;
    int idx = 0;

    for (int i = 1; i < N; i++) {
        cin >> x;
        
        if (x >= peak) {
            if (i - idx > 1) ans = mul(ans, i-idx+1);
            else ans = mul(ans, 2);
            
            peak = x;
            idx = i;
        }
    }

    cout << ans << '\n';

    return 0;
}