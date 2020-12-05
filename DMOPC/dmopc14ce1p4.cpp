// https://dmoj.ca/problem/dmopc14ce1p4
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7, MAXN = 1005;

double dist[MAXN];
int r[MAXN];

struct Edge {int n; double w;};

bool cmp(int x, int y) {
    if (dist[x] == dist[y]) return r[x] < r[y];
    return dist[x] < dist[y];
}

vector<Edge> adj[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int nodes, edges, a, b; double d, s;
    cin >> nodes >> edges;
    f(i,0,edges){
        cin >> a >> b >> d >> s;
        adj[a].push_back({b,d/s*60});
        adj[b].push_back({a,d/s*60});
    }
    f(i,0,MAXN){
        dist[i] = 0x3f3f3f3f;
    }
    dist[1] = 0;
    priority_queue<int, vector<int>, function<bool(int,int)>> pq(cmp);
    pq.push(1);
    while (!pq.empty()) {
        int c = pq.top();
        pq.pop();
        for (Edge t:adj[c]) {
            if (dist[c] + t.w < dist[t.n] || (dist[c] + t.w == dist[t.n] && r[c] + 1 < r[t.n])) {
                dist[t.n] = dist[c] + t.w;
                r[t.n] = r[c] + 1;
                pq.push(t.n);
            }
        }
    }
    cout << r[nodes] << endl << (int) round(dist[nodes]/3) << endl;
    return 0;
}