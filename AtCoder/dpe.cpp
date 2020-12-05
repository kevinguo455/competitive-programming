// https://dmoj.ca/problem/dpe
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5;

int dp[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n, mw, w, v, mv = 0; cin >> n >> mw;
    ms(dp,0x3f);
    dp[0] = 0;
    f(cn,0,n){
        cin >> w >> v;
        mv += v;
        fr(i,mv,0){
            if (i-v < 0) dp[i] = min(dp[i], dp[i+1]);
            else dp[i] = min(dp[i], dp[i-v]+w);
        }
    }
    fr(i,mv,0){
        if (dp[i] <= mw) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}