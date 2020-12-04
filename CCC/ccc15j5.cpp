// https://dmoj.ca/problem/ccc15j5
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 251;

vector<short> arr[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    short n, k; cin >> n >> k;
    short t = n - k;
    f(i,0,t+1) {
        arr[i].pb(i);
    }
    f(i,2,k+1) {
        fr(j,t,0){
            arr[j].clear();
            f(a,0,j) {
                for (short b:arr[a]) {
                    if (j-a >= b) arr[j].pb(j-a);
                }
            }
        }
    }
    cout << arr[t].size() << endl;
    return 0;
}