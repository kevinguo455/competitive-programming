// https://dmoj.ca/problem/ccc09s2
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb(x) push_back(x)
#define f(i,a,b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 55;
int rows,cols;
vector<int> grid;

int adb(int n, int d) {
    return ((n << 1) | d);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>rows>>cols;
    f(i,0,rows) {
        int n = 0;
        f(j,0,cols) {
            int d; cin>>d;
            n = adb(n,d);
        }
        grid.pb(n);
    }
    set<int> xors;
    int last = 0;
    for (int i = rows-1; i >= 0; i--) {
        last = last^grid[i];
        xors.insert(last);
    }
    
    cout << xors.size() << endl;
    return 0;
}