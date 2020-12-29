/*
CCO '08 P4 - Herding
Key Concepts: Graph Theory (components)
https://dmoj.ca/problem/cco08p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

char grid[MAXN][MAXN];
bool vis1[MAXN][MAXN];
bool vis2[MAXN][MAXN];

int r, c;
int ans;

void dfs(int cr, int cc) {
    if (vis2[cr][cc]) {
        ans--;
        return;
    }
    if (vis1[cr][cc]) return;

    vis1[cr][cc] = 1;
    
    if (grid[cr][cc] == 'N') dfs(cr-1, cc);
    else if (grid[cr][cc] == 'S') dfs(cr+1, cc);
    else if (grid[cr][cc] == 'W') dfs(cr, cc-1);
    else if (grid[cr][cc] == 'E') dfs(cr, cc+1);

    vis2[cr][cc] = 1;
}

int main() {

    // init
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
    }

    // traverse
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vis2[i][j]) continue;
            dfs(i, j);
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}