// https://dmoj.ca/problem/dmopc14ce1p3
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1005;

int nodes, edges, hydrogens, carbons, doubleBonds;
vector<int> adj[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> nodes >> edges;
    f(i,0,edges) {
        int x, y; cin >> x >> y;
        for (int e:adj[x]) {
            if (e == y) {
                doubleBonds++;
                break;
            }
        }
        adj[x].pb(y);
        adj[y].pb(x);
        
    }
    f(i,1,nodes+1) {
        if (adj[i].size() == 1) { // is hydrogen
            hydrogens++;
        }
        else if (adj[i].size() == 4) { // is carbon
            carbons++;
        }
        else {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << hydrogens*413 + doubleBonds*615 + (edges-doubleBonds*2-hydrogens)*346 << endl;
    cout << "C";
    if (carbons != 1) cout << carbons;
    cout << "H";
    if (hydrogens != 1) cout << hydrogens;
    cout << endl;

    return 0;
}