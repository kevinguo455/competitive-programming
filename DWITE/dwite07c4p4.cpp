/*
DWITE '07 R4 #4 - Shortest path around
Key Concepts: Graph Theory (BFS)
https://dmoj.ca/problem/dwite07c4p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200005;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string grid[10];
    bool vis[10][10];
    string s;
    pii start, end;
    bool second = 0;

    f(cases,0,5){
        f(i,0,10){
            cin >> s;
            grid[i]=s;
            f(j,0,10){
                if (s[j] == 'X'){
                    if (!second) {
                        start = {i,j};
                        second = 1;
                    }
                    else {
                        end = {i,j};
                    }
                }
            }
        }
        ms(vis,0);
        second = 0;
        cin >> s;
        queue<pii> q;
        q.push(start);
        int d = 0;
        bool quit = 0;
        while (!q.empty()) {
            int s = q.size();
            f(i,0,s) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x < 0 || y < 0 || x > 9 || y > 9) continue;
                if (vis[x][y]) continue;
                if (x == end.first && y == end.second) {
                    cout << d << endl;
                    quit = 1;
                    break;
                }
                vis[x][y] = 1;
                if (grid[x][y] == '#') continue;
                q.push({x+1,y-1});
                q.push({x,y-1});
                q.push({x-1,y-1});
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x+1,y+1});
                q.push({x,y+1});
                q.push({x-1,y+1});
            }
            if (quit) break;
            d++;
        }
    }
    
    return 0;
}
