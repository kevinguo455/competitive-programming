/*
Wesley's Anger Contest 6 Problem 4 - Runway Lights
Key Concepts: Dynamic Programming (Math)
https://dmoj.ca/problem/wac6p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353; 

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, r; cin >> n >> r;
    string s; cin >> s;

    ll Wc = 0;
    ll Ab = 0, Ac = 0;
    ll Ca = 0, Cb = 0, Cc = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            Wc++;
        }
        else if (s[i] == 'A') {
            Ab++;
            Ac = add(Ac, Wc);
        }
        else if (s[i] == 'C') {
            Ca++;
            Cb = add(Cb, Ab);
            Cc = add(Cc, Ac);
        }
    }
    ll w = 0, a = 0, c = 0;
    for (int i = 0; i < r; i++) {
        c = add(c, mul(Ca, a) + mul(Cb, w) + Cc);
        a = add(a, mul(Ab, w) + Ac);
        w = add(w, Wc); 
    }

    cout << c << "\n";

    return 0;
}