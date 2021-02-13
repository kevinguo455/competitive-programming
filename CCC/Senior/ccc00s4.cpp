// https://dmoj.ca/problem/ccc00s4
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

int dp[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    ms(dp, INF);
    dp[0] = 0;
    int d, c, x; cin >> d >> c;
    f(i,0,c){
        cin >> x;
        f(j,0,d-x+1){
            if(dp[j] != INF) dp[j+x] = min(dp[j+x], dp[j]+1);   // left-to-right dp transition to reuse clubs
        }
    }
    if (dp[d] == INF) cout << "Roberta acknowledges defeat." << endl;
    else cout << "Roberta wins in " << dp[d] << " strokes." << endl;
    return 0;
}