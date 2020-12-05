// https://dmoj.ca/problem/dmopc16c4p5
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 200005;

struct Edge{int w, n;};

vector<Edge> adj[MAXN];
int dist[MAXN];
bool inq[MAXN];

bool cmp(int a, int b) {
    return dist[a] < dist[b];
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);
    int nodes, edges; 
    //cin >> nodes >> edges;
    scanf("%d%d",&nodes,&edges);
    f(i,0,edges){
        int a, b, p; //cin >> a >> b >> p;
        scanf("%d%d%d",&a,&b,&p);
        adj[a].push_back({p,b});
        adj[b].push_back({p,a});
    }

    priority_queue<int, vector<int>, function<bool(int,int)>> pq(cmp);
    pq.push(1);
    dist[1] = 0x3f3f3f3f;
    inq[1]=1;
    while (!pq.empty()) {
        int c = pq.top();
        pq.pop();
        inq[c]=0;
        
        for (Edge t:adj[c]) {
            int m = min(dist[c],t.w);
            if (m > dist[t.n]) {
                dist[t.n] = m;
                if (!inq[t.n]) {
                    pq.push(t.n);
                    inq[t.n]=1;
                }
            } 
        }

    }
    //cout << 0 << endl;
    printf("0\n");
    for (int i = 2; i <= nodes; i++) {
        //cout << dist[i] << endl;
        printf("%d\n",dist[i]);
    }
    return 0;
}