/* 
DMOPC '20 Contest 2 P1 - Laugh Graphs
Key Concepts: Implementation
Solution by Kevin Guo
https://dmoj.ca/problem/dmopc20c2p1
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
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 1e3+5; 

int loc[MAXN];
char ch[MAXN];
int l = INF, h = 0-INF;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    string in; cin >> in;

    int c = 0;
    for (int i = 0; i < (int) in.length(); i++) {
        if (in[i] == 'v') {
            c++;   
            ch[i] = '\\';
            loc[i] = c;
        }
        else if (in[i] == '^') {
            loc[i] = c;
            c--;
            ch[i] = '/';
        }
        else {
            ch[i] = '_';
            loc[i] = c;
        }
        l = min(l, loc[i]);
        h = max(h, loc[i]);
    }

    for (int i = l; i <= h; i++) {
        for (int j = 0; j < n; j++) {
            if (loc[j] == i) {
                cout << ch[j];
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}