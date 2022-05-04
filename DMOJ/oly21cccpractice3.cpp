#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5; 

struct Edge{int n; ll w; int id;};

vector<Edge> adj[MAXN];
bitset<MAXN> vis;
bitset<2*MAXN> removed;

int N, M, C;
ll tot;
ll ans = 1e18;

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M >> C;
    for (int i = 0, a, b, w; i < M; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w, i});
        adj[b].push_back({a, w, i});
        tot += w;
    }

    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq(cmp);
    pq.push({1, 0});

    while (!pq.empty()) {
        Edge c = pq.top(); pq.pop();
        vis[c.n] = 1;

        // c.w is current dist

        for (Edge t : adj[c.n]) {
            if (vis[t.n]) {
                if (!removed[t.id]) { 
                    tot -= t.w;
                    removed[t.id] = 1;
                }
            }
            else {
                pq.push({t.n, c.w+t.w});
            }
        }

        ans = min(ans, (ll)C * c.w + tot);
    }

    cout << ans << '\n';

    return 0;
}