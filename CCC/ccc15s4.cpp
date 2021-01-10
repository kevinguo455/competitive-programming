// wow this solution is jank

/*
CCC '15 S4 - Convex Hull
Key Concepts: Graph Theory (Dijkstra's)
https://dmoj.ca/problem/ccc15s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
const int INF = 0x3f3f3f3f, /*MAXN = 10, MAXH = 12;*/MAXN = 2005, MAXH = 205; 

struct Edge{int n, w, h;};  // to, weight, hull
vector<Edge> adj[MAXN];
int dist[MAXN][MAXH];       // distance to the nth node with h hull damage
int mindist[MAXN];
bool inq[MAXN];

bool cmp(int a, int b) {
    return mindist[a] > mindist[b];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // init
    int hull, nodes, edges; cin >> hull >> nodes >> edges;
    int a, b, t, h;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b >> t >> h;
        adj[a].pb({b, t, h});
        adj[b].pb({a, t, h});
    }
    int start, end; cin >> start >> end;

    // dijkstra's (?)
    //priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
    queue<int> pq;
    pq.push(start);
    ms(dist, 0x3f);
    ms(mindist, 0x3f);
    dist[start][0] = 0;
    mindist[start] = 0;

    while (!pq.empty()) {
        int c = pq.front(); pq.pop();
        inq[c] = 0;
        
        for (Edge t : adj[c]) {
            //if (inq[t.n]) continue;

            for (int ch = 0; ch < hull-t.h; ch++) {
                if (dist[c][ch] == INF) continue;

                if (dist[c][ch] + t.w < dist[t.n][ch+t.h]) {
                    dist[t.n][ch+t.h] = dist[c][ch] + t.w;
                    mindist[t.n] = min(mindist[t.n], dist[t.n][ch+t.h]);
                    pq.push(t.n);
                    inq[t.n] = 1;
                }
            }
        }
    }

    if (mindist[end] == INF) cout << "-1\n";
    else cout << mindist[end] << "\n";

    return 0;
}