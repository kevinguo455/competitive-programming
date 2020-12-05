// https://dmoj.ca/problem/ccc07s4
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 10002;

vector<int> adj[MAXN];
int val[MAXN];

int main() {
    int n, x, y; cin >> n >> x >> y;
    while (!(x == 0 && y == 0)) {
        adj[x].pb(y);
        cin >> x >> y;
    }
    val[1] = 1;
    f(i,1,n){
        for (int t:adj[i]) {
            val[t] += val[i];
        }
    }
    cout << val[n];
    return 0;
}