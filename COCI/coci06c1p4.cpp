/*
COCI '06 Contest 1 #4 Slikar
Key Concepts: Graph Theory (BFS, grid, simulation)
https://dmoj.ca/problem/coci06c1p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 55;
int rows,cols;

string grid[MAXN];

bool inb(int r,int c) {
    return (r >= 0 && r < rows && c >= 0 && c < cols);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>rows>>cols;
    f(i,0,rows){
        string s;cin>>s;
        grid[i]=s;
    }
    //find start/end/source
    queue<pii> f;
    queue<pii> q;
    f(i,0,rows){
        f(j,0,cols){
            char c = grid[i][j];
            if (c == 'S') {
                q.push({i,j});
                grid[i][j] = '.';
            }
            else if (c == '*') {
                f.push({i,j});
                grid[i][j] = '.';
            }
        }
    }

    bool done = 0;
    int steps=0;
    while (!q.empty()) {
        // advance f
        int fs = f.size();
        f(i,0,fs) {
            int r = f.front().first;
            int c = f.front().second;
            f.pop();
            if (!inb(r,c)) continue;
            if (grid[r][c] != '.' && grid[r][c] != 'V') continue;
            grid[r][c] = '*';
            f.push({r-1,c});
            f.push({r+1,c});
            f.push({r,c-1});
            f.push({r,c+1});
        }

        int s=q.size();
        f(i,0,s) { //advance q
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (!inb(r,c)) continue;
            if (grid[r][c] == 'D') {
                done = 1;
                break;
            }
            if (grid[r][c] != '.') continue;
            grid[r][c] = 'V';
            q.push({r-1,c});
            q.push({r+1,c});
            q.push({r,c-1});
            q.push({r,c+1});
        }
        if (done) break;
        steps++;
    }
    cout << (done ? to_string(steps) : "KAKTUS") << endl;
    return 0;
}