// https://dmoj.ca/problem/tss17b
#include <bits/stdc++.h>
using namespace std;

#define ms(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,b,a) for (int i = b; i > a; i--)
#define vs(v) sort(v.begin(), v.end())
#define vr(v) reverse(v.begin(), v.end())
#define fi first
#define se second
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1414220; 

int d[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    ll a, b; 
    // init frequency array
    f(i,0,n){
        cin >> a >> b;
        d[(int)ceil(sqrt(a*a+b*b))]++;
    }
    // prefix sum array
    f(i,1,MAXN-1){
        d[i] += d[i-1];
    }
    // range queries
    f(i,0,q){
        cin >> a;
        cout << d[a] << endl;
    }
    return 0;
}