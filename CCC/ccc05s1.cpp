// https://dmoj.ca/problem/ccc05s1
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

string append(string s, char c) {
    if (s.size() == 12) return s;
    if (s.size() == 3 || s.size() == 7) return s + "-" + c;
    return s + c;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    f(i,0,n){
        string s, o = ""; cin >> s;
        f(i,0,(int)s.size()){
            if (s[i] >= '0' && s[i] <= '9') o = append(o, s[i]);
            else if (s[i] >= 'A' && s[i] <= 'C') o = append(o, '2');
            else if (s[i] >= 'D' && s[i] <= 'F') o = append(o, '3');
            else if (s[i] >= 'G' && s[i] <= 'I') o = append(o, '4');
            else if (s[i] >= 'J' && s[i] <= 'L') o = append(o, '5');
            else if (s[i] >= 'M' && s[i] <= 'O') o = append(o, '6');
            else if (s[i] >= 'P' && s[i] <= 'S') o = append(o, '7');
            else if (s[i] >= 'T' && s[i] <= 'V') o = append(o, '8');
            else if (s[i] >= 'W' && s[i] <= 'Z') o = append(o, '9');
        }
        cout << o << endl;
    }

    return 0;
}