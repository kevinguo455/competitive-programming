/*
DWITE '09 R3 #2 - Rounding to Fibonacci
Key Concepts: Implementation, Simple Math
https://dmoj.ca/problem/dwite09c3p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e9 + 5e8; 

int main() {
    fio;

    // construct a set of every fibonacci number <= 1e9+5e8
    set<int> fib;
    fib.insert(0);
    ll a = 0, b = 1, c;
    while (b <= MAXN) {
        fib.insert((int)b);
        a += b;
        c = a;
        a = b;
        b = c;
    }

    f(cases,0,5) {
        int n; cin >> n;

        int r = *fib.lower_bound(n);
        int l = *prev(fib.upper_bound(n));
        
        cout << (r - n <= n - l ? r : l) << endl;
    }

    return 0;
}