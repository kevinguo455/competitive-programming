/*
DMOPC '14 Exam Time P6 - Math Homework
Key Concepts: Dynamic Programming, Advanced Math (binomial theorem, binomial coefficents, binary exponentiation)
https://dmoj.ca/problem/dmopc14ce1p6
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXC = 3001, MOD = 1e9+7; 

inline ll add(ll a, ll b) {
    return (a+b)%MOD;
}

inline ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

inline ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll binexp(ll n, ll p) {
    ll a = 1;
    while (p) {
        if (p&1) a = mul(a, n);
        n = mul(n, n);
        p /= 2;
    }
    return a;
}

int dp[MAXC];
int choose[MAXC][MAXC];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    choose[0][0] = 1;
    for (int i = 1; i < MAXC; i++) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++) {
            choose[i][j] = add(choose[i-1][j-1], choose[i-1][j]);
        }
    }

    int cases; cin >> cases;
    dp[1] = 1;
    while (cases--) {
        int R, C; cin >> R >> C;
        
        ll pow2 = 4;
        for (int c = 2; c <= C; c++) {
            dp[c] = binexp(sub(pow2, 1), R);
            pow2 = mul(pow2, 2);
            
            for (int k = 1; k < c; k++) {
                dp[c] = sub(dp[c], mul(choose[c][k], dp[c-k]));
            }
        }

        cout << dp[C] << '\n';
    }

    return 0;
}