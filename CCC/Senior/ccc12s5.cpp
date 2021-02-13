// https://dmoj.ca/problem/ccc12s5
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 27;

int r, c;
int grid[MAXN][MAXN];
queue<pii> q;

void eval(int rc, int cc) {
    if (grid[rc][cc] != 0) return;
    if (rc-1 >= 0 && grid[rc-1][cc] > 0) grid[rc][cc] += grid[rc-1][cc];
    if (cc-1 >= 0 && grid[rc][cc-1] > 0) grid[rc][cc] += grid[rc][cc-1];
    if (rc+1 <= r) q.push({rc+1,cc});
    if (cc+1 <= c) q.push({rc,cc+1});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int x, n, m; cin >> r >> c >> x;
    f(i,0,x){
        cin >> n >> m;
        grid[n][m] = -1;
    }
    grid[1][0] = 1;
    
    q.push({1,1});
    while (!q.empty()){
        int rf = q.front().first;
        int cf = q.front().second;
        q.pop();
        eval(rf,cf);
    }
    cout << grid[r][c] << endl;
    return 0;
}