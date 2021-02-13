// https://dmoj.ca/problem/ccc09s3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 55;
set<int> adj[MAXN] = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};
bool vis[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    char action; cin >> action;
    while (action != 'q') {
        if (action == 'i') {
            int a, b; cin >> a >> b;
            if (adj[a].find(b) == adj[a].end()) {
                adj[a].insert(b);
                adj[b].insert(a);
            }
        }
        else if (action == 'd') {
            int a, b; cin >> a >> b;
            adj[a].erase(b);
            adj[b].erase(a);
        }
        else if (action == 'n') {
            int a; cin >> a;
            cout << adj[a].size() << endl;
        }
        else if (action == 'f') {
            int a; cin >> a;
            set<int> s;
            for (int i:adj[a]) {
                for (int j:adj[i]) {
                    s.insert(j);
                }
            }
            for (int i:adj[a]) {
                s.erase(i);
            }
            s.erase(a);
            cout << s.size() << endl;
        }
        else if (action == 's') {
            int a, b; cin >> a >> b;
            queue<int> q;
            q.push(a);
            int d = 0;
            bool done = 0;
            ms(vis,0);
            while (!q.empty()) {
                int s = q.size();
                f(i,0,s) {
                    int c = q.front();
                    q.pop();
                    vis[c] = 1;
                    if (c == b) {
                        done = 1;
                        break;
                    }
                    for(int i:adj[c]){
                        if (!vis[i]) {
                            q.push(i);
                        }
                    }
                }
                if (done) break;
                d++;
            }
            cout << (done ? to_string(d) : "Not connected") << endl;
        }
        cin >> action;
    }
    return 0;
}