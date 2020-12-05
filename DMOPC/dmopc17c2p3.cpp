// https://dmoj.ca/problem/dmopc17c2p3
#include <bits/stdc++.h>
using namespace std;
/*
19 5
1 2
2 3
3 4
2 5
5 6
5 7
7 8
2 9
1 10
10 11
11 12
11 13
13 14
13 15
15 16
11 17
17 18
17 19
4
8
16
18
19
5 12
*/
const int MAXN = 200001;
//const int MAXN = 1001;

vector<int> g[MAXN];
set<int> r;
stack<int> path;
bool visited[MAXN];
bool halt;

void scan() {
    //bfs to nearest rabbit from each location on path
    int mindist = MAXN;
    while (!path.empty()) {
        int n = path.top();
        path.pop();
        queue<int> q;
        q.push(n);
        int x,y=0,c=MAXN;
        bool exit = false;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                x = q.front();
                visited[x] = true;
                q.pop();
                if (r.find(x) != r.end()) {
                    c = y;
                    exit = true;
                    break;
                }
                for (int i:g[x]) {
                    if (!visited[i]) {
                        q.push(i);
                    }
                }
            }
            if (exit) break;
            y++;
        }
        if (c < mindist) {
            mindist = c;
        }
    }
    cout << mindist << endl;
    return;
}

void dfs(int n, int m) {
    //dfs to exit
    if (halt) return;
    visited[n] = 1;
    path.push(n);

    if (n == m) {
        scan();
        halt = 1;
        return;
    }

    for (int i:g[n]) {
        if (!visited[i]) {
            dfs(i, m);
            if (halt) return;
        }
    }
    path.pop();
    visited[n] = 0;
}

int main() {
    int n,rn,a,b;cin>>n>>rn;
    for (int i = 0; i < n-1; i++) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < rn; i++) {
        cin>>a;
        r.insert(a);
    }
    int p1,p2;cin>>p1>>p2;
    
    dfs(p1,p2);

    return 0;
}