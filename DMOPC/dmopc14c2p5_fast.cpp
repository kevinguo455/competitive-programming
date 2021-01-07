/*
DMOPC '14 Contest 2 P5 - Sawmill Scheme
Key Concepts: Dynamic Programming (tree), Graph Theory
https://dmoj.ca/problem/dwite08c1p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5, MAXE = 2e6+5;

// no more vector<int> adj[MAXN] adjacency list :)
int size[MAXN];
int from[MAXE];
int to[MAXE];
int id[MAXN];
int adj[MAXE];
double p[MAXN];

int main() {
    int nodes, edges; scanf("%d%d", &nodes, &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &from[i], &to[i]);
        from[i]--;
        to[i]--;
        size[from[i]]++;
    }

    for (int i = 0; i < nodes; i++) {
        id[i+1] = id[i] + size[i];
    }

    for (int i = 0; i < edges; i++) {
        adj[id[from[i]]] = to[i];
        id[from[i]]++;
    }

    // tree dp
    p[0] = 1;
    int e = 0;
    for (int c = 0; c < nodes; c++) {
        if (size[c] == 0) {
            printf("%.9f\n", p[c]);
        }
        else {
            double a = p[c] / size[c];
            while(size[c]) {
                p[adj[e]] += a;
                e++;
                size[c]--;
            }
        }
    }

    return 0;
}