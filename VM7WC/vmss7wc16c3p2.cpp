/*
VM7WC '16 #3 Silver - Can Shahir even get there?!
Key Concepts: Graph Theory (DFS/BFS)
https://dmoj.ca/problem/vmss7wc16c3p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

bool visited[2001];
vector<int> roads[2001];
queue<int> q;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n,m,a,b; cin>>n>>m>>a>>b;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        roads[x].push_back(y);
        roads[y].push_back(x);
    }
    q.push(a);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == b) {
            cout << "GO SHAHIR!" << endl;
            return 0;
        }
        visited[x] = 1;
        for (int i:roads[x]) {
            if (!visited[i])
                q.push(i);
        }
    }
    cout << "NO SHAHIR!" << endl;
    return 0; 
}