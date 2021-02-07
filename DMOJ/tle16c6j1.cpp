/*
TLE '16 Contest 6 (Mock CCC) J1 - Paper Printing
Key Concepts: Implementation
https://dmoj.ca/problem/tle16c6j1
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n, m, a; cin >> n >> m >> a;
    int x = 0, q;
    f(i,0,a) {
        n += x;
        cin >> x >> q;
        n -= x;
        n += q;
        if (n < q) {
            cout << "The printer melts at " << x+n-q+1 << " second(s)." << endl;
            return 0;
        }
        if (n > m) {
            cout << "The printer jams at " << x << " second(s)." << endl;
            return 0;
        }
    }
    cout << "The printer melts at " << x+n+1 << " second(s)." << endl;

    return 0;
}