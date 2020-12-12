/*
CCC '08 S4 - Twenty-four
Key Concepts: Recursion
https://dmoj.ca/problem/ccc08s4
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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

set<int> m24(vi v) {
    set<int> out;
    if (v.size() == 0) return out;
    if (v.size() == 1) {
        out.insert(v[0]);
        return out;
    }
    if (v.size() == 2) {
        out.insert(v[0] + v[1]);
        if (v[0] >= v[1]) out.insert(v[0] - v[1]);
        else out.insert(v[1] - v[0]);
        out.insert(v[0] * v[1]);
        if (v[0] >= v[1] && v[1] != 0 && v[0] % v[1] == 0) out.insert(v[0] / v[1]);
        else if (v[1] >= v[0] && v[0] != 0 && v[1] % v[0] == 0) out.insert(v[1] / v[0]);
        return out;
    }
    f(i,0,(int)v.size()) {
        f(j,i,(int)v.size()) {
            vi t, u;
            f(k,0,(int)v.size()) {
                if (k == i || k == j) t.pb(v[k]);
                else u.pb(v[k]);
            }
            set<int> a(m24(t)), b(m24(u));
            for (int n : a) {
                for (int m : b) {
                    out.insert(n + m);
                    if (n >= m) out.insert(n - m);
                    else out.insert(m - n);
                    out.insert(n * m);
                    if (n >= m && m != 0 && n % m == 0) out.insert(n / m);
                    else if (m >= n && n != 0 && m % n == 0) out.insert(m / n);
                }
            }
        }
    }
    return out;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int cases; cin >> cases;
    f(casen,0,cases){
        vi ns(4);
        cin >> ns[0] >> ns[1] >> ns[2] >> ns[3];
        set<int> s(m24(ns));
        cout << *prev(s.upper_bound(24)) << endl;
    }

    return 0;
}
