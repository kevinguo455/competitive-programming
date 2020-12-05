// https://dmoj.ca/problem/ccc09s4
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 5005;

struct Edge{int w,n;}; // weight, node

bool cmp(Edge x, Edge y) {
    return x.w > y.w;
}

vector<Edge> adj[MAXN];
int dist[MAXN];
vector<int> dest;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nodes, edges; 
    cin >> nodes >> edges;
    
    f(i,0,edges) {
        int x,y,c; 
        cin>>x>>y>>c;
        adj[x].push_back({c,y});
        adj[y].push_back({c,x});
    }
    ms(dist,0x3f);
    priority_queue<Edge,vector<Edge>,function<bool(Edge,Edge)>> pq(cmp);
    int s; cin>> s;
    f(i,0,s){
        int x, c; cin>>x>>c;
        pq.push({c,x});
        dist[x] = c;
    }

    while(!pq.empty()) {
        Edge c = pq.top();
        pq.pop();
        for (Edge t:adj[c.n]) {
            if (c.w + t.w < dist[t.n]) {
                dist[t.n] = c.w + t.w;
                pq.push({dist[t.n], t.n});
            }
        }
    }

    int d;cin>>d;
    cout << dist[d] << endl;

    return 0;
}