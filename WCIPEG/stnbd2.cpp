/*
Claire Elstein
Key Concepts: Graph Theory (Topological Sort), Dynamic Programming (Tree)
https://dmoj.ca/problem/stnbd2
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

int nodes, edges;
vi adj[MAXN];
bool vis[MAXN];
ui threads[MAXN];
ui dist[MAXN];
stack<int> s;

void tpdfs(int c) { // implements topological sort
    vis[c] = 1;
    for (int t:adj[c]) 
        if (!vis[t]) tpdfs(t);
    s.push(c);
}

int main() {
    fio;

    // init
    cin >> nodes >> edges;
    int a, b;
    f(i,0,edges){
        cin >> a >> b;
        adj[a].pb(b);
    }

    // topological sort: for the more general problem where directed edges from a to b may not satisfy a < b
    f(n,1,nodes+1) {
        if (!vis[n]) {
            tpdfs(n);
        }
    }

    // tree dp
    ui sum = 0;
    f(c,1,nodes+1) {

        if (threads[c] == 0) threads[c] = 1;

        for (int t:adj[c]) {
            threads[t] = (threads[t] + threads[c]) % MOD;
            dist[t] = (dist[t] + dist[c] + threads[c]) % MOD;
        }

        if (adj[c].size() == 0) {
            sum = (sum + dist[c]) % MOD;
        }
    }

    cout << sum << "\n";

    return 0;
}