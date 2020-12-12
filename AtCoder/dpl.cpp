/*
AtCoder Educational DP Contest Problem L - Deque
Key Concepts: Dynamic Programming, Greedy Algorithms (turn-based)
https://dmoj.ca/problem/dpl
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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 3005;

ll dp[MAXN][MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n; cin >> n;
    cin >> dp[0][0];
    ll s = dp[0][0];
    f(i,1,n){
        cin >> dp[i][i];
        dp[i-1][i] = max(dp[i-1][i-1], dp[i][i]);
        s += dp[i][i];
    }
    f(l,2,n){
        f(a,0,n-l){
            dp[a][a+l] = max(dp[a][a] + min(dp[a+1][a+l-1], dp[a+2][a+l]), dp[a+l][a+l] + min(dp[a][a+l-2], dp[a+1][a+l-1]));
        }
    }

    cout << 2*dp[0][n-1] - s << endl;
    return 0;
}