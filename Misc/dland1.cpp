// https://dmoj.ca/problem/dland1
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

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n, q, a, b; cin >> n >> q;
    vector<ll> s(n), v(n+1);
    f(i,0,n) {
        cin >> s[i];
    }
    vs(s);
    vr(s);
    f(i,0,q) {
        cin >> a >> b;
        v[a-1]++;
        v[b]--;
    }
    f(i,1,n+1) {
        v[i] += v[i-1];
    }
    v.pop_back();
    vs(v);
    ll out = 0;
    f(i,0,n) {
        out += s[i] * v[i];
    }
    cout << out << endl;
    return 0;
}