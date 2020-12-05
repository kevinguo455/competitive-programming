// https://dmoj.ca/problem/ccc12j4
//https://dmoj.ca/problem/dmopc15c6p3
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

//ll dp[MAXN][MAXN];

char shift (char c, int n) {
    int c1 = c - 'A';
    c1 += n;
    return ((c1 + (26 * 10)) % 26) + 'A';
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int k; cin >> k;
    string s; cin >> s;

    f(i,0,(int)s.size()){
        s[i] = shift(s[i], -k-((i+1)*3));
    }
    cout << s << endl;
    return 0;
}