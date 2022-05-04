/*
TLE '15 P4 - Olympiads Homework
Key Concepts: Intermediate Math (Binary Exponentiation)
https://dmoj.ca/problem/tle15p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9+13; 

inline ll add(ll a, ll b) {
    return (a + b + MOD) % MOD;
}

inline ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll qpow(int n, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mul(n, qpow(n, p-1));
    ll x = qpow(n, p/2);
    return mul(x, x);    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N; cin >> N;
    
    if (N == 1) {
        cout << "1\n";
        return 0;
    }

    ll a = qpow(2, N-2), b = 0;
    if (N % 8 == 0)                     b = qpow(2, (N-1)/2);
    else if (N % 8 == 1 || N % 8 == 7)  b = qpow(2, (N-3)/2);
    else if (N % 8 == 3 || N % 8 == 5)  b = -qpow(2, (N-3)/2);
    else if (N % 8 == 4)                b = -qpow(2, (N-1)/2);

    cout << add(a, b) << '\n';

    return 0;
}