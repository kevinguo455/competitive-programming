/*
CCC '07 S3 - Friends
Key Concepts: Graph Theory (connectivity)
https://dmoj.ca/problem/ccc07s3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 10002;

int adj[MAXN];
bool vis[MAXN];

int main() {
    int n, x, y, d; cin >> n;
    f(i,0,n) {
        cin >> x >> y;
        adj[x] = y;
    }
    cin >> x >> y;
    while (!(x == 0 && y == 0)) {
        ms(vis,0);
        d = -1;
        while (x != y) {
            if (vis[x]) break;
            vis[x] = 1;
            x = adj[x];
            d++;
        }
        if (vis[x]) cout << "No" << endl;
        else cout << "Yes " << d << endl;
        cin >> x >> y;
    }
    return 0;
}