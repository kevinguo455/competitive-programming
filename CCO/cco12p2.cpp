/*
CCO '12 P2 - The Hungary Games 
Key Concepts: Graph Theory
https://dmoj.ca/problem/cco12p2
Solution by Kevin Guo

(this is also a solution to Mock CCO '18 Contest 4 Problem 3 - Counterattack)
https://dmoj.ca/problem/ncco4d1p3
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int INF = 0x3f3f3f3f, MAXN = 2e4+5; 

struct Edge{int n, w;};
vector<Edge> adj[MAXN];

struct Dist{
    int a = INF;    // shortest dist
    int b = INF+1;  // 2nd shortest dist

    bool update(Dist n, int w) {
        int na = n.a + w;   // new distances
        int nb = n.b + w;

        if (na < a) {           // na < a < b
            b = min(a, nb);     // na < nb < a < b (potentially)
            a = na;
            return true;
        }
        if (na > a && na < b) { // a < na < b < nb
            b = na;
            return true;
        }
        if (nb > a && nb < b) { // a = na < nb < b
            b = nb;
            return true;
        }
        return false;
    }
};

Dist dist[MAXN];

bool cmp(int x, int y) {
    /*if (dist[x].a == dist[y].a) return dist[x].b > dist[y].b;
    else*/ return dist[x].a > dist[y].a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init graph
    int nodes, edges; cin >> nodes >> edges;
    int a, b, c;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    // modified Dijkstra's 
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
    pq.push(1);
    dist[1].a = 0;

    while (!pq.empty()) {
        int c = pq.top();
        pq.pop();
        for (Edge t:adj[c]) {
            if (dist[t.n].update(dist[c], t.w)) {
                pq.push(t.n);
            }   
        }
    }

    // answer
    if (dist[nodes].b >= INF) cout << "-1\n";
    else cout << dist[nodes].b << "\n";

    return 0;
}