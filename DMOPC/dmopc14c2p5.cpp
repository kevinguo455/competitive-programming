/*
DMOPC '14 Contest 2 P5 - Sawmill Scheme
Key Concepts: Dynamic Programming (tree), Graph Theory
https://dmoj.ca/problem/dwite08c1p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;

vector<int> adj[MAXN];
double p[MAXN];

int main() {
    int n, e; scanf("%d%d", &n, &e);
    int a, b;
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }

    // tree dp
    p[1] = 1;
    for (int c = 1; c <= n; c++) {
        if (adj[c].size() == 0) {
            printf("%.9f\n", p[c]);
        }
        else {
            double a = p[c] / adj[c].size();
            for (int t:adj[c]) {
                p[t] += a;
            }
        }
    }

    return 0;
}