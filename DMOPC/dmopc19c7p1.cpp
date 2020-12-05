// https://dmoj.ca/problem/dmopc19c7p1
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;

//const int MAXN = 10002;

//vector<int> adj[MAXN];
//int val[MAXN];

int main() {
    int a, b, c, d, carbons, hydrogens;
    cin >> a >> b >> c >> d;
    carbons = a + b + c + 1;
    hydrogens = d;

    if (carbons*2 + 2 - b*2 - c*4 != d) cout << "invalid" << endl;
    else cout << "C" << carbons << "H" << hydrogens << endl;

    return 0;
}
