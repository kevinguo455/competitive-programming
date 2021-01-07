/*
AtCoder Beginner Contest 187 Problem D - Choose Me 
Key Concepts: Implementation
https://atcoder.jp/contests/abc187/tasks/abc187_d
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;

ll arr[MAXN];

int main() {
    int n; cin >> n;
    ll a, b;
    ll d = 0; // delta

    for (int i = 0; i < n; i++) {
        cin >> b >> a;
        d -= b;
        arr[i] = b*2 + a;
    }
    sort(arr, arr+n, greater<ll>());
    
    int ans = 0;
    while (d <= 0) {
        d += arr[ans];
        ans++;
    }
    cout << ans << "\n";

    return 0;
}