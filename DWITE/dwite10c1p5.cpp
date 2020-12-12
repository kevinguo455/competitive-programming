/*
DWITE '10 R1 #5 - Ricochet Robot
Key Concepts: Implementation
https://dmoj.ca/problem/dwite10c1p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 100005;

string grid[10];
bool vis[10][10];

bool inb(int n) {
    return (n>=0&&n<10);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    f(cases,0,5) {
        ms(vis,0);
        string s; 
        f(i,0,10) {
            cin >> s;
            grid[i] = s;
        }
        cin >> s;
        int x,y;
        f(i,0,10){
            f(j,0,10){
                if (grid[i][j] == 'A') {
                    x=i;
                    y=j;
                }
            }
        }
        queue<pii> q;
        q.push({x,y});
        int quit = 0;
        int d = 0;
        while (!q.empty()) {
            int s = q.size();
            f(i,0,s) {
                int rs = q.front().first;
                int cs = q.front().second;
                q.pop();
                if(vis[rs][cs]) continue;
                if (grid[rs][cs] == 'B') {
                    quit = 1;
                    break;
                }
                vis[rs][cs] = 1;
                //move up
                int r = rs, c = cs;
                while (inb(r-1) && grid[r-1][c] != '#') {
                    r--;
                }
                q.push({r,c});
                r = rs, c = cs;
                while (inb(r+1) && grid[r+1][c] != '#') {
                    r++;
                }
                q.push({r,c});
                r = rs, c = cs;
                while (inb(c-1) && grid[r][c-1] != '#') {
                    c--;
                }
                q.push({r,c});
                r = rs, c = cs;
                while (inb(c+1) && grid[r][c+1] != '#') {
                    c++;
                }
                q.push({r,c});
            }
            d++;
            if (quit) break;
        }
        cout << d-1 << endl;
    }
    return 0;
}