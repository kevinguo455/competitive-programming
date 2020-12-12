/*
AtCoder Educational DP Contest Problem H - Grid 1
Key Concepts: Dynamic Programming (Gridwalk)
https://dmoj.ca/problem/dph
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7, MAXN = 1005;

string grid[MAXN];
int dist[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int r, c; cin >> r >> c;
    f(i,1,r+1){
        cin >> grid[i];
    }
    dist[1][0] = 1;
    f(i,1,r+1){
        f(j,1,c+1){
            if (grid[i][j-1] == '#') continue;
            dist[i][j] = (dist[i-1][j] + dist[i][j-1])%mod;
        }
    }
    cout << dist[r][c] << endl;
    
    return 0;
}