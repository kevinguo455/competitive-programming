/*
USACO 2021 January Contest, Gold - Problem 2. Telephone
Key Concepts: Graph Theory (BFS)
http://www.usaco.org/current/current/index.php?page=viewproblem2&cpid=1090
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+5, MAXK = 51; 

int N, B;
int breed[MAXN];
bool adj[MAXK][MAXK];
bool inqf[MAXK];
bool inqb[MAXK];
int dist[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> breed[i];
        breed[i]--;
    }

    for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
            char c; cin >> c;
            adj[i][j] = (c == '1');
        }
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;

    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        inqf[breed[c]] = 0;
        inqb[breed[c]] = 0;

        for (int t = c+1; t < N; t++) {
            if (adj[breed[c]][breed[t]]) {
                if (!inqf[breed[t]] && dist[c] + abs(t-c) < dist[t]) {
                    q.push(t);
                    inqf[breed[t]] = 1;
                }
                dist[t] = min(dist[t], dist[c] + abs(t-c));
            }
        }
        for (int t = c-1; t > 0; t--) {
            if (adj[breed[c]][breed[t]]) {
                if (!inqb[breed[t]] && dist[c] + abs(t-c) < dist[t]) {
                    q.push(t);
                    inqb[breed[t]] = 1;
                }
                dist[t] = min(dist[t], dist[c] + abs(t-c));
            }
        }
    }

    if (dist[N-1] == 0x3f3f3f3f) cout << "-1\n";
    else cout << dist[N-1] << "\n";

    return 0;
}