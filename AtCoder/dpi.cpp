/*
AtCoder Educational DP Contest Problem I - Coins
Key Concepts: Dynamic Programming (probability)
https://dmoj.ca/problem/dpi
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = (int)a; i < (int)b; i++)
#define fr(i,b,a) for (int i = (int)b; i > (int)a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 3001; 

double dp[MAXN];

int main() {
    fio;

    int n; cin >> n;

    dp[0] = 1;  
    double p;
    f(c,1,n+1) {
        cin >> p;
        fr(j,c,-1) {
            dp[j] = dp[j] * (1-p);
            dp[j] += dp[j-1] * p;
        }
    }
    double ans = 0;
    f(i,n/2+1,n+1) {
        ans += dp[i];
    }
    printf("%.9f\n", ans);

    return 0;
}