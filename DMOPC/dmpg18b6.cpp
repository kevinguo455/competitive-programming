// https://dmoj.ca/problem/dmpg18b6
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

bool used[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, x; cin >> n >> k;
    vi w;
    f(i,0,n){
        cin >> x;
        w.pb(x);
    }
    vs(w);
    vr(w);
    x = w[0];
    int c = 1;
    f(i,1,n){
        if (x-w[i] >= k){
            x = w[i];
            c++;
        }
    }
    cout << c << endl;
    return 0;
}