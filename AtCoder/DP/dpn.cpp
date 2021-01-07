/*
AtCoder Educational DP Contest Problem N - Slimes
Key Concepts: Dynamic Programming (intervals), Prefix Sum Array
https://dmoj.ca/problem/dpn
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 405;

ll dp[MAXN][MAXN]; // 0-indexed
ll psa[MAXN];      // 1-indexed

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    // init
    ms(dp, INF);
    int n; cin >> n;
    f(i,0,n) {
        cin >> psa[i+1];
        psa[i+1] += psa[i];
        dp[i][i] = 0;
    }

    f(s,1,n){ // size
        f(l,0,n-s){ // left ptr
            f(x,l,l+s){ // iterate through to right ptr
                dp[l][l+s] = min(dp[l][l+s], dp[l][x] + dp[x+1][l+s] + psa[l+s+1] - psa[l]);
            }
        }
    }
    cout << dp[0][n-1] << endl;

    return 0;
}