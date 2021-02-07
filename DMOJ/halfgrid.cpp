// https://dmoj.ca/problem/halfgrid
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e6+5;

int dp[MAXN];
/*
int choose(int n, int k) {
    if (k*2 > n) return choose(n, n-k);

    int ret = 1, a = n;
    while (a > k) {
        ret = (ret * a) % MOD;
        a--;
    }
}*/

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int w, h, x; cin >> w >> h >> x;
    pii x1 = {-1,-1}, x2 = {-1,-1};

    if (x >= 1) cin >> x1.fi >> x1.se;
    if (x >= 2) cin >> x2.fi >> x2.se;

    dp[1] = 1;
    f(i,1,w+1){
        f(j,1,h+1){
            if (mp(i,j) == x1 || mp(i,j) == x2) dp[j] = 0;
            else {
                dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
    }
    cout << dp[h] << endl;

    return 0;
}