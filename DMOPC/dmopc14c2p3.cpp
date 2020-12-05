// https://dmoj.ca/problem/dmopc14c2p3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define sv(v) sort(v.begin(), v.end())
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e3+5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n;
    vi a, b;
    f(i,0,n){
        cin >> x;
        a.pb(x);
    }
    f(i,0,n){
        cin >> x;
        b.pb(x);
    }
    sv(a);
    reverse(a.begin(),a.end());
    sv(b);
    ll s = 0;
    f(i,0,n){
        s+=a[i]*b[i];
    }
    cout << s << endl;
    return 0;
}