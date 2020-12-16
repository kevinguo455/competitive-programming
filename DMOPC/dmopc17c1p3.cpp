/*
DMOPC '17 Contest 1 P3 - Hitchhiking Fun
Key Concepts: Graph Theory (Dijkstra's)
https://dmoj.ca/problem/dmopc17c1p3
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

struct Edge{int n; bool d;};
vector<Edge> adj[MAXN];

int main() {
    fio;

    int nodes, edges; cin >> nodes >> edges;
    int a, b;
    bool c;
    f(i,0,edges) {
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {

    }


    return 0;
}