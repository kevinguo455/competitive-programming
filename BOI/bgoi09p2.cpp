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

vi adj[MAXN];
bool vis[MAXN];

void dfs(int n) {
    vis[n] = 1;
    for (int t:adj[n]) {
        if (!vis[t]) dfs(t);
    }
}

int main() {
    fio;

    f(cases,0,2){
        int n, x; cin >> n;
        f(i,0,MAXN) adj[i].clear();
        ms(vis,0);
        f(i,1,n+1){
            cin >> x;
            adj[i].pb(x);
            adj[x].pb(i);
        }
        int c = 0;
        f(i,1,n+1){
            if (vis[i]) continue;
            c++;
            dfs(i);
        }
        cout << c << " ";
    }
    cout << "\n";

    return 0;
}