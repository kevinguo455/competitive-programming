/* 
DMOPC '20 Contest 2 P2 - Lousy Christmas Presents
Key Concepts: Greedy Algorithms
Solution by Kevin Guo
https://dmoj.ca/problem/dmopc20c2p2
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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e6+5; 

int first[MAXN];
int last[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    ms(first, INF);
    int x;
    f(i,0,n) {
        cin >> x;
        first[x] = min(first[x],i);
        last[x] = max(last[x],i);
    }

    int a, b, c = 0;
    f(i,0,m){
        cin >> a >> b;
        c = max(c, last[b] - first[a] + 1);
    }
    cout << c << endl;

    return 0;
}