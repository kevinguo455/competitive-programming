/*
VM7WC '16 #2 Bronze - G
Key Concepts: Implementation
https://dmoj.ca/problem/vmss7wc16c2p1
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e5+5; 

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    f(i,0,n){
        f(j,0,n) cout << "GGGGG";
        cout << endl;
    }
    f(i,0,n){
        f(j,0,n) cout << "G";
        f(j,0,n) cout << "....";
        cout << endl;
    }
    f(i,0,n){
        f(j,0,n) cout << "G";
        f(j,0,n) cout << "..";
        f(j,0,n) cout << "GG";
        cout << endl;
    }
    f(i,0,n){
        f(j,0,n) cout << "G";
        f(j,0,n) cout << "...";
        f(j,0,n) cout << "G";
        cout << endl;
    }
    f(i,0,n){
        f(j,0,n) cout << "GGGGG";
        cout << endl;
    }

    return 0;
}