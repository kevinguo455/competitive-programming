// https://dmoj.ca/problem/dmopc13c3p3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1500;

int n, h;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int x, int y, int c) {
    if (x < 0 || y < 0 || x >= n || y >= n) return;
    if (vis[x][y]) return;
    if (max(grid[x][y]-c, c-grid[x][y]) > h) return;
    
    vis[x][y] = 1;
    dfs(x+1,y,grid[x][y]);
    dfs(x-1,y,grid[x][y]);
    dfs(x,y+1,grid[x][y]);
    dfs(x,y-1,grid[x][y]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> h;
    f(i,0,n) {
        f(j,0,n) {
            int x; cin >> x;
            grid[i][j] = x;
        }
    }
    dfs(0,0,grid[0][0]);
    cout << (vis[n-1][n-1] ? "yes" : "no") << endl;

    return 0;
}