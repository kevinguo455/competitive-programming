/*
Christmas '14 Special P1 - Is it a Tree?
Key Concepts: Graph Theory (adjacency matrix, cycle detection) 
https://dmoj.ca/problem/tree1
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 4;

int adj[MAXN][MAXN];
bool vis[MAXN];
int parent[MAXN];
bool cycle;

void dfs(int c) {
    vis[c] = 1;
    f(t,0,MAXN) {
        if (adj[c][t]) {
            if (t == c) cycle = 1;
            else if (!vis[t]) {
                parent[t] = c;
                dfs(t);
            }
            else if (t != parent[c]) cycle = 1;
        }
        if (cycle) return;
    }
}

int main() {
    fio;

    f(i,0,MAXN) {
        f(j,0,MAXN) {
            cin >> adj[i][j];
        }
    }

    ms(parent, INF);

    f(i,0,MAXN) {
        ms(vis, 0);
        dfs(i);
        if (cycle) break;
    }
    if (cycle) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}