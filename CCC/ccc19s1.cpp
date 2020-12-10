//https://dmoj.ca/problem/ccc19s1
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

    string s; cin >> s;
    bool h = 0, v = 0;
    f(i,0,(int)s.size()){
        if (s[i] == 'H') h = !h;
        else v = !v;
    }
    if (!h && !v) {
        cout << "1 2" << endl << "3 4" << endl;
    }
    else if (!h && v) {
        cout << "2 1" << endl << "4 3" << endl;
    }
    else if (h && !v) {
        cout << "3 4" << endl << "1 2" << endl;
    }
    else {
        cout << "4 3" << endl << "2 1" << endl;
    }
    return 0;
}