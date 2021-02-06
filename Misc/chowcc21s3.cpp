/*
Mock CCC '21 S3 - Graphville
Key Concepts: Graph Theory, Brute Force
https://www.hackerrank.com/contests/mss-csec-mock-2021-senior/challenges/csec-2021-mock-graph
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1001, MAXM = 8;

bool isSet(int n, int d) {
    return (n >> d) & 1;
}

int setBit(int n, int d) {
    return n | (1 << d);
}

struct Edge{int n, w;};

vector<Edge> adj[MAXN];
int loc[MAXM];
int dp[(1<<MAXM)+1][MAXM];

int N, E, D, L;

int dist[MAXN];
int disthome[MAXN];

bool cmp(int a, int b) {
    return dist[a] > dist[b];
}

/*
int sssp(int a, int b) {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
    dist[a] = 0;
    pq.push(a);
    while (!pq.empty()) {
        int c = pq.top(); pq.pop();
        if (c == b) return dist[b];
        for (Edge t : adj[c]) {
            if (dist[c] + t.w < dist[t.n]) {
                dist[t.n] = dist[c] + t.w;
                pq.push(t.n);
            }
        }
    }
    return 0x3f3f3f3f;  // should never occur
}

void sssp2(int a) {
    memset(disthome, 0x3f, sizeof disthome);
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);
    disthome[a] = 0;
    pq.push(a);
    while (!pq.empty()) {
        int c = pq.top(); pq.pop();
        for (Edge t : adj[c]) {
            if (disthome[c] + t.w < disthome[t.n]) {
                disthome[t.n] = disthome[c] + t.w;
                pq.push(t.n);
            }
        }
    }
}*/

int apsp[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(apsp, 0x3f, sizeof apsp);

    cin >> N >> E >> D >> L;
    int a, b, w;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> w;
        apsp[a][b] = w;
        apsp[b][a] = w;
    }

    // floyd warshall barely fast enough :0
    for (int i = 0; i <= N; i++) {
        apsp[i][i] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                apsp[i][j] = min(apsp[i][j], apsp[i][k] + apsp[k][j]);
            }
        }
    }

    //sssp2(1);

    ll ans = 0;

    for (int d = 0; d < D; d++) {
        for (int i = 0; i < L; i++) {
            cin >> loc[i];
        }

        memset(dp, 0x3f, sizeof dp);

        for (int h = 0; h < L; h++) {
            dp[1<<h][h] = apsp[1][loc[h]];
        }

        for (int state = 1; state < (1<<L); state++) {
            for (int c = 0; c < L; c++) {
                if (!isSet(state, c)) continue;

                for (int t = 0; t < L; t++) {
                    if (isSet(state, t)) continue;

                    int tstate = setBit(state, t);
                    dp[tstate][t] = min(dp[tstate][t], dp[state][c] + apsp[loc[c]][loc[t]]);
                }
            }
        }

        ll day = 1e18;
        int visall = (1<<L)-1;
        for (int last = 0; last < L; last++) {
            day = min(day, (ll) dp[visall][last] + apsp[1][loc[last]]);
        }
        ans += day;
    }

    cout << ans << "\n";

    return 0;
}

/*
5 6 1 3
1 2 5
2 4 11
2 3 9
3 5 4
1 5 6
3 4 2
3 4 5
*/
