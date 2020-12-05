// https://dmoj.ca/problem/dmopc18c6p3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200005;

vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int x) {
    vis[x]=1;
    for(int e:adj[x]){
        if (!vis[e]){
            dfs(e);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int nodes, edges; cin >> nodes >> edges;
    f(i,0,edges){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int c = 0;
    f(i,1,nodes+1){
        if (!vis[i]){
            c++;
            dfs(i);
        }
    }
    cout << (edges+c == nodes || edges+c == nodes+1 ? "YES" : "NO") << endl;
    return 0;
}
