// https://dmoj.ca/problem/dmopc14c3p6
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
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 10005;

int dp[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n, mw, w1, w2, w3, v1, v2, v3; cin >> n >> mw;
    f(cn,0,n){
        cin >> w1 >> v1 >> w2 >> v2 >> w3 >> v3;
        fr(i,mw,0) {
            if (i - w1 >= 0) dp[i] = max(dp[i], dp[i-w1]+v1);
            if (i - w2 >= 0) dp[i] = max(dp[i], dp[i-w2]+v2);
            if (i - w3 >= 0) dp[i] = max(dp[i], dp[i-w3]+v3);
        }
    }
    cout << dp[mw] << endl;
    return 0;
}