/*
DWITE '10 R5 #3 - Balancing Act
Key Concepts: Dynamic Programming (knapsack)
https://dmoj.ca/problem/dwite10c5p3
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
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 15005; 

bitset<MAXN> b;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    f(cases,0,5){
        int n, x, sum = 0; cin >> n;
        queue<int> q;
        f(i,0,n){
            cin >> x;
            sum += x;
            q.push(x);
        }
        b.reset();
        b[0] = 1;
        f(i,0,n){
            x = q.front();
            q.pop();
            fr(j,sum/2-x,-1){
                if (b[j]) b[j+x] = 1;
            }
        }
        fr(i,sum/2,-1){
            if (b[i]) {
                cout << abs(2*i-sum) << endl;
                break;
            }
        }
    }
    return 0;
}