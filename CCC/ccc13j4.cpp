// https://dmoj.ca/problem/ccc13j4
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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 5300;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t, c, x; cin >> t >> c;
    vi v;
    f(i,0,c){
        cin >> x;
        v.pb(x);
    }
    vs(v);
    x = 0;
    f(i,0,c){
        x += v[i];
        if (x > t) {
            cout << i << endl;
            return 0;
        }
    }
    cout << c << endl;
    return 0;
}