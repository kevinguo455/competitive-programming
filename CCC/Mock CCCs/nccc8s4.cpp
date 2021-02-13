/*
Mock CCC '21 S4 - Infinite Molecule
Key Concepts: Graph Theory (cycle detection)
https://dmoj.ca/problem/nccc8s4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN1 = 26, MAXN2 = 2*MAXN1+2; 

bool adj1[MAXN2][MAXN2];
int vis[MAXN2][2];
bool exist[MAXN2];

int M;
bool cycle;

int flip(int n) {
    return 2*MAXN1 - n;
}

void dfs(int c, bool inter) {
    if (!exist[c]) return;

    if (vis[c][inter] == 2) return;
    if (vis[c][inter] == 1) {
        cycle = 1;
        return;
    }

    vis[c][inter] = 1;
    
    if (inter) {
        dfs(flip(c), 0);
    }
    else {
        for (int t = 0; t < MAXN2; t++) {
            if (adj1[c][t]) {
                dfs(t, 1);
                if (cycle) return;
            }
        }
    }

    vis[c][inter] = 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> M;
    int a, b, c, d;
    while (M--) {
        cin >> a >> b >> c >> d;
        a += MAXN1;
        b += MAXN1;
        c += MAXN1;
        d += MAXN1;
        adj1[a][b] = 1;
        adj1[a][c] = 1;
        adj1[a][d] = 1;
        adj1[b][a] = 1;
        adj1[b][c] = 1;
        adj1[b][d] = 1;
        adj1[c][a] = 1;
        adj1[c][b] = 1;
        adj1[c][d] = 1;
        adj1[d][a] = 1;
        adj1[d][b] = 1;
        adj1[d][c] = 1;
        exist[a] = 1;
        exist[b] = 1;
        exist[c] = 1;
        exist[d] = 1;
    }

    exist[MAXN1] = 0;

    for (int s = 0; s < MAXN2; s++) {
        if (!vis[s][1]) dfs(s, 1);
        if (cycle) break;
    }

    cout << (cycle ? "1\n" : "0\n");

    return 0;
}