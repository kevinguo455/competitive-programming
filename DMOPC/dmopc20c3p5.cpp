/*
DMOPC '20 Contest 3 P5 - Tower of Power
Key Concepts: Advanced Math (Euler's Theorem), Binary Exponentiation
https://dmoj.ca/problem/dmopc20c3p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll totient(ll n) {
    ll a = n;  
    for (ll p = 2; p <= sqrt(n); p++) { 
        if (n % p == 0) { 
            while (n % p == 0) {
                n /= p; 
            }     
            a -= a / p; 
        } 
    } 
    if (n > 1) {
        a -= a / n; 
    }
    return a;
}

ll mul(ll a, ll b, ll m) {
    a *= b;
    if (a >= m) return (a % m) + m;
    return a;
}

/*
ll binexp(ll n, ll p, ll MOD) {
    if (MOD == 1) return 1;

    ll a = 1;
    while (p > 0) {
        if (p & 1) {
            a = mul(a, n, MOD);
        }
        n = mul(n, n, MOD);
        p /= 2;
    }
    return a;
}*/

ll binexp(ll n, ll p, ll MOD) {
    if (p == 0) return 1;
    if (p & 1) return mul(binexp(n, p-1, MOD), n, MOD);
    ll a = binexp(n, p/2, MOD);
    return mul(a, a, MOD);
}

stack<ll> s, t;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; ll M; cin >> N >> M;
    ll x, y = M;
    for (int i = 0; i < N; i++) {
        cin >> x;
        s.push(x);
    }
    t.push(M);
    for (int i = 2; i < N; i++) {
        y = totient(y);
        t.push(y);
    }

    ll ans = s.top(); s.pop();

    while (!s.empty()) {
        ans = binexp(s.top(), ans, t.top()); 
        s.pop(); t.pop();
    }
    cout << ans % M << "\n";

    return 0;
}