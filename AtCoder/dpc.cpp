// https://dmoj.ca/problem/dpc
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e2+5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    int a = 0, b = 0, c = 0, ia, ib, ic, ca, cb, cc;
    f(i,0,n){
        cin >> ia >> ib >> ic;
        ca = max(b,c) + ia;
        cb = max(a,c) + ib;
        cc = max(a,b) + ic;
        a = ca;
        b = cb;
        c = cc;
    }
    cout << max(a,max(b,c)) << endl;
    return 0;
}