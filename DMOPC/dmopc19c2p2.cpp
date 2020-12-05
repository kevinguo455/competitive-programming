// https://dmoj.ca/problem/dmopc19c2p2
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 500+5;

int grid[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, x; cin >> r >> c;
    f(j,1,c+1){
        cin>>x;
        grid[j] = grid[j-1] + x;
    }
    grid[0] = INF;
    f(i,1,r){
        f(j,1,c+1){
            cin>>x;
            grid[j] = min(grid[j],grid[j-1]) + x;
        }
    }
    cout << grid[c] << endl;
    return 0;
}