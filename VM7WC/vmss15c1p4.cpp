/*
VMSS '15 #4 - Frank and Roads 
Key Concepts: Graph theory, Dijkstra's algorithm
https://dmoj.ca/problem/vmss15c1p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2005;

struct Edge{int weight, node;};

bool cmp(Edge x, Edge y) {
    return x.weight > y.weight;
}

vector<Edge> adj[MAXN];
int dist[MAXN];
vector<int> dest;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int maxdist, nodes, edges, dests;
    cin >> maxdist >> nodes >> edges >> dests;

    f(i,0,dests){
        int x; 
        cin >> x;
        dest.pb(x);
    }

    ms(dist, 0x3f);
    f(i,0,edges){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }

    priority_queue<Edge, vector<Edge>, function<bool(Edge,Edge)>> pq(cmp);
    pq.push({0,0});
    dist[0] = 0;
    while (!pq.empty()) {
        Edge c = pq.top();
        if (c.weight > maxdist) {
            break;
        }
        pq.pop();
        for (Edge t:adj[c.node]) {
            if (t.weight + c.weight < dist[t.node]) {
                dist[t.node] = t.weight + c.weight;
                pq.push({dist[t.node],t.node});
            }
        }
    }
    int score = 0;
    for (int i:dest) {
        if (dist[i] <= maxdist) score++;
    }
    cout << score << endl;
    return 0;
}