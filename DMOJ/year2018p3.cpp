/*
New Year's 2018 Problem 3 - World Domination Fun
Key Concepts: Binary Search, Difference Array
https://dmoj.ca/problem/year2018p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
const int MAXN = 1e5+5; 

typedef long long ll;

ll n, s, k;
ll h[MAXN];
ll d[MAXN];
ll l, r;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // binary search
    l = 0;
    r = 2e9+1;
    while (l < r) {
        ll m = (l+r)/2+1;
        ms(d, 0);
        ll c = k;
        bool success = 1;
        
        // simulate
        for (int i = 0; i < n; i++) {
            ll v = h[i] + d[i];
            if (v < m) {
                c -= (m-v);
                if (c < 0) {
                    success = 0;
                    break;
                }
                d[i] += (m-v);
                d[min(n+1,i+s)] -= (m-v);
            }
            d[i+1] += d[i];
        }
        
        // next
        if (success) {
            l = m;
        }
        else {
            r = m-1;
        }
    }
    cout << l << "\n";
    return 0;
}