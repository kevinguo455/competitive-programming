/*
CCC '07 J5 - Keep on Truckin'
Key Concepts: Dynamic Programming (Golf)
https://dmoj.ca/problem/ccc07j5
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 35;

ll dp[MAXN];

int main() {
    fio;

    // init
    vi v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int a, b, n, x; cin >> a >> b >> n;
    f(i,0,n){
        cin >> x;
        v.pb(x);
    }
    vs(v);

    // dp
    dp[0] = 1;
    f(i,0,(int)v.size()) {
        if (dp[i] == 0) continue;
        
        unsigned int j = i;
        while (v[j] < v[i] + a && j < v.size()) {
            j++;
        }
        while (v[j] <= v[i] + b && j < v.size()) {
            dp[j] += dp[i];
            j++;
        }
    }

    cout << dp[v.size()-1] << "\n";

    return 0;
}