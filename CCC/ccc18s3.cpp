// https://dmoj.ca/problem/ccc18s3
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 105;
string grid[MAXN];
int dist[MAXN][MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, rb, cb; cin >> r >> c;
    string s;
    f(i,0,r){
        cin >> s;
        grid[i] = s;
        f(j,0,c){
            if (s[j] == 'S') {
                rb = i;
                cb = j;
            }
        }
    }
    bool dead = 0;
    f(i,0,r){
        f(j,0,c){
            if (grid[i][j] == 'C'){
                f(v,j,c){
                    if (grid[i][v] == '.'){
                        grid[i][v] = ',';
                    }
                    if (grid[i][v] == 'W'){
                        break;
                    }
                    if (grid[i][v] == 'S'){
                        dead = 1;
                        break;
                    }
                }
                for(int v = j; v>=0; v--){
                    if (grid[i][v] == '.'){
                        grid[i][v] = ',';
                    }
                    if (grid[i][v] == 'W'){
                        break;
                    }
                    if (grid[i][v] == 'S'){
                        dead = 1;
                        break;
                    }
                }
                f(h,i,r){
                    if (grid[h][j] == '.'){
                        grid[h][j] = ',';
                    }
                    if (grid[h][j] == 'W'){
                        break;
                    }
                    if (grid[h][j] == 'S'){
                        dead = 1;
                        break;
                    }
                }
                for(int h = i; h>=0; h--){
                    if (grid[h][j] == '.'){
                        grid[h][j] = ',';
                    }
                    if (grid[h][j] == 'W'){
                        break;
                    }
                    if (grid[h][j] == 'S'){
                        dead = 1;
                        break;
                    }
                }
            }
        }
    }
    //bfs time
    ms(dist,-1);
    if (!dead) {
        queue<pii> q;
        q.push({rb,cb});
        int d = 0;
        while (!q.empty()) {
            int s = q.size();
            f(i,0,s) {
                int rc = q.front().first;
                int cc = q.front().second;
                q.pop();
                if (rc < 0 || cc < 0 || rc >= r || cc >= c) continue;
                if (dist[rc][cc] != -1) continue;
                if (grid[rc][cc] == 'W' || grid[rc][cc] == 'C' || grid[rc][cc] == ',') continue;
                
                //woohoo conveyors
                bool leave = 0;
                dist[rc][cc] = d;
                while (grid[rc][cc] == 'L' || grid[rc][cc] == 'R' || grid[rc][cc] == 'U' || grid[rc][cc] == 'D') {
                    if (grid[rc][cc] == 'L') cc--;
                    else if (grid[rc][cc] == 'R') cc++;
                    else if (grid[rc][cc] == 'U') rc--;
                    else if (grid[rc][cc] == 'D') rc++;
                    if (rc < 0 || cc < 0 || rc >= r || cc >= c) {
                        leave = 1;
                        break;
                    }
                    if (dist[rc][cc] != -1) {
                        leave = 1;
                        break;
                    }
                    if (grid[rc][cc] == 'W' || grid[rc][cc] == 'C' || grid[rc][cc] == ',') {
                        leave = 1;
                        break;
                    }
                    dist[rc][cc] = d;
                }
                if (leave) continue;

                dist[rc][cc] = d;
                q.push({rc+1,cc});
                q.push({rc-1,cc});
                q.push({rc,cc+1});
                q.push({rc,cc-1});
            }
            d++;
        }
    }
    f(i,0,r){
        f(j,0,c){
            if (grid[i][j] == '.' || grid[i][j] == ',') {
                cout << dist[i][j] << endl;
            }
        }
    }
    return 0;
}