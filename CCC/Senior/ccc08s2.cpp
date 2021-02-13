// https://dmoj.ca/problem/ccc08s2
#include <bits/stdc++.h>
using namespace std;

#define ms(x, a) memset(x, a, sizeof(x))
#define pb(x) push_back(x)
#define f(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9+7, MAXN = 1e5+5;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r; cin >> r;
    while (r != 0) {
        int c = 0;
        f(y,0,r){
            c += floor(sqrt(r*r-y*y));
        }
        cout << c*4+1 << endl;
        cin >> r;
    }
    return 0;
}