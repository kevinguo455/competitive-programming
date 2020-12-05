// https://dmoj.ca/problem/dmopc14c1p5
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1005;

string grid[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int rows,cols;cin>>rows>>cols;
    int r1,c1,rend,cend;
    cin>>r1>>c1>>rend>>cend;
    f(i,0,rows){//init grid
        string s;
        cin>>s;
        grid[i]=s;
    }
    int ts;cin>>ts;//init tp
    f(i,0,ts){
        int rt,ct;cin>>rt>>ct;
        grid[rt][ct] = 'T';
    }
    //bfs
    queue<pii> q;
    q.push({r1,c1});
    int d = 0;
    int dt = 0x3f3f3f3f;
    bool done = 0;
    while(!q.empty()) {
        int s = q.size();
        f(i,0,s) {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if (r < 0 || c < 0 || r >= rows || c >= cols) continue;
            if (grid[r][c] == 'X') continue;
            if (r == rend && c == cend) {
                dt = min(dt,d);
                done = 1;
                break;
            }
            if (grid[r][c] == 'T')
                dt = min(dt,d);
            grid[r][c] = 'X';
            q.push({r,c+1});
            q.push({r,c-1});
            q.push({r+1,c});
            q.push({r-1,c});
        }
        if (done) break;
        d++;
    }
    cout << d-dt << endl;
    return 0;
}
