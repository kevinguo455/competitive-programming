/*
Bulgarian OI '09 P2 - Boxen
Key Concepts: Graph Theory (components)
https://dmoj.ca/problem/bgoi09p2
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int adj[MAXN];
short vis[MAXN];
int ans;

void dfs(int n) {
    vis[n] = 1;
    if (vis[adj[n]] == 1) ans++;    // count loopbacks
    if (vis[adj[n]] == 0) dfs(adj[n]);
    vis[n] = 2;
}

int main() {
    fio;

    f(cases,0,2){
        int n; cin >> n;
        ms(vis,0);
        ans = 0;
        f(i,1,n+1) cin >> adj[i];
        f(i,1,n+1) if (vis[i] == 0) dfs(i);
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}