// https://dmoj.ca/problem/ccc08s3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 22;

string grid[MAXN];
bool vis[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int cases; cin>>cases;
    f(casen,0,cases){
        ms(vis,0);
        int rows,cols;
        cin>>rows>>cols;
        string s;
        f(i,0,rows){
            cin>>s;
            grid[i]=s;
        }

        if (grid[rows-1][cols-1] == '*') {
            cout << -1 << endl;
            continue; 
        }

        //bfs
        queue<pii> q;
        q.push({0,0});
        int steps=1;
        bool done = 0;
        
        while(!q.empty()) {
            int s = q.size();
            f(i,0,s) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (!(r >= 0 && c >= 0 && r < rows && c < cols)) continue;
                if (vis[r][c]) continue;
                vis[r][c] = 1;
                if (r == rows-1 && c == cols-1) {
                    done = 1;
                    break;
                }

                if (grid[r][c] == '+') {
                    q.push({r,c-1});
                    q.push({r,c+1});
                    q.push({r+1,c});
                    q.push({r-1,c});
                }
                else if (grid[r][c] == '|') {
                    q.push({r+1,c});
                    q.push({r-1,c});
                }
                else if (grid[r][c] == '-') {
                    q.push({r,c-1});
                    q.push({r,c+1});
                }
            }
            
            if (done) break;
            steps++;
        }
        cout << (done ? steps : -1) << endl;
    }

    return 0;
}