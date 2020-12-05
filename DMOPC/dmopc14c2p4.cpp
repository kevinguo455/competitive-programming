// https://dmoj.ca/problem/dmopc14c2p4
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e6+5;

int arr[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    
    int n; cin >> n;
    f(i,1,n+1){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    int q, a, b; cin >> q;
    f(i,0,q){
        cin >> a >> b;
        cout << arr[b+1] - arr[a] << endl;
    }

    return 0;
}