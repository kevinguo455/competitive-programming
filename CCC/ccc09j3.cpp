// https://dmoj.ca/problem/ccc09j3
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e4+5; 

int shift(int t, int hs, int ms) {
    int h = t / 100;
    int m = t % 100;

    h += hs;
    m += ms;
    if (m >= 60) {
        m -= 60;
        h++;
    }

    if (h >= 24) {
        h -= 24;
    }
    else if (h < 0) {
        h += 24;
    }

    return h * 100 + m;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n; cin >> n;
    cout << n << " in Ottawa" << endl;
    cout << shift(n, -3, 0) << " in Victoria" << endl;
    cout << shift(n, -2, 0) << " in Edmonton" << endl;
    cout << shift(n, -1, 0) << " in Winnipeg" << endl;
    cout << n << " in Toronto" << endl;
    cout << shift(n, 1, 0) << " in Halifax" << endl;
    cout << shift(n, 1, 30) << " in St. John's" << endl;

    return 0;
}