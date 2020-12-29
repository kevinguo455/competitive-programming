/*
COCI '15 Contest 4 #3 Deathstar
Key Concepts: Boolean Algebra
https://dmoj.ca/problem/coci15c4p3
Solution by Kevin Guo
*/
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e3+5;

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int r; cin >> r;
    f(i,0,r){
        f(j,0,r){
            int x; cin >> x;
            arr[i] = arr[i] | x;
            arr[j] = arr[j] | x;
        }
    }
    f(i,0,r){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
