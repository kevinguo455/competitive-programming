/*
DWITE '09 R2 #4 - Breadth First Not Quite Tree
Key Concepts: Graph Theory (BFS)
https://dmoj.ca/problem/dwite09c2p4
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 105; 

vi adj[MAXN];
int dist[MAXN];
bool vis[MAXN];

int main() {
    fio;

    f(cases,0,5){        
        f(i,0,MAXN) adj[i].clear();
        ms(dist, INF);

        int n, a, b; cin >> n;
        f(i,0,n){
            cin >> a >> b;  // init
            adj[a].pb(b);
            adj[b].pb(a);
        }

        queue<int> q;
        q.push(1);
        dist[1] = 0;
        int d = 0;
        while (!q.empty()){     // bfs
            int s = q.size();
            f(i,0,s){           // keeping track of depth
                int c = q.front();
                q.pop();
                for (int t:adj[c]) {
                    if (dist[t] == INF) {   // if unvisited
                        q.push(t);
                        dist[t] = d+1;      // update distances
                    }
                }
            }
            d++;
        }

        // find score
        int score = 0;
        f(c,1,MAXN){
            for (int t:adj[c]) {    // loop throgh every edge
                if (dist[t] == dist[c]) score++;
            }
        }
        cout << score/2 << "\n";
    }

    return 0;
}