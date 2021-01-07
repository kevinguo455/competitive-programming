/*
Christmas '14 Special P2 - Tree Cutting
Key Concepts: Graph Theory (adjacency matrix, cycle detection) 
https://dmoj.ca/problem/tree2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
#define endl "\n"
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 10;

int rows, cols; 
short cost[MAXN][MAXN];
short dist[MAXN][MAXN];
short treedist[MAXN][MAXN];

bool cmp(pii a, pii b) {
    if (dist[a.fi][a.se] == dist[b.fi][b.se]) return treedist[a.fi][a.se] < treedist[b.fi][b.se];
    return dist[a.fi][a.se] < dist[b.fi][b.se];
}

priority_queue<pii, vector<pii>, function<bool(pii,pii)>> pq(cmp);

bool inr(pii c) {
    return !(c.fi < 0 || c.se < 0 || c.fi >= rows || c.se >= cols);
}

void eval(pii c, pii t) {
    if (!inr(t)) return;
    
    int d = dist[c.fi][c.se] + cost[c.fi][c.se];
    int td = treedist[c.fi][c.se];
    if (cost[c.fi][c.se] != 0) td++;

    if (d < dist[t.fi][t.se] || (d == dist[t.fi][t.se] && td < treedist[t.fi][t.se])) {
        dist[t.fi][t.se] = d;
        treedist[t.fi][t.se] = td;
        pq.push(t);
    }
}

int main() {
    fio;

    // init
    cin >> rows >> cols;
    pii start, end;
    char c;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> c;
            if (c == 'X') start = {i, j};   // determine start
            else if (c != '.') {
                cost[i][j] = c - '0';
            }
        }
    }

    // determine end
    int maxh = 0;
    int mind = INF;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int d = abs(start.fi - i) + abs(start.se - j);
            if (cost[i][j] > maxh || (cost[i][j] == maxh && d < mind)) {
                maxh = cost[i][j];
                mind = d;
                end = {i, j};
            }
        }
    }

    // dijkstra's
    ms(dist, INF);
    ms(treedist, INF);
    dist[start.fi][start.se] = 0;
    treedist[start.fi][start.se] = 0;

    pq.push(start);
    while (!pq.empty()) {
        pii c = pq.top();
        pq.pop();
        eval(c, {c.fi+1, c.se});
        eval(c, {c.fi-1, c.se});
        eval(c, {c.fi, c.se+1});
        eval(c, {c.fi, c.se-1});
    }

    cout << treedist[end.fi][end.se] << endl;

    return 0;
}