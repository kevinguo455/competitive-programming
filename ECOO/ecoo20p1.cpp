/*
ECOO '20 P1 - Music with Mimi
Key Concepts: Implementation
https://dmoj.ca/problem/ecoo20p1
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
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef priority_queue<int> pqi;
const int MOD = 1e9+7, INF = 0x3f3f3f3f, MAXN = 12; 

int note(string s) {
    if (s == "C") return 0;
    else if (s == "C#") return 1;
    else if (s == "D") return 2;
    else if (s == "D#") return 3;
    else if (s == "E") return 4;
    else if (s == "F") return 5;
    else if (s == "F#") return 6;
    else if (s == "G") return 7;
    else if (s == "G#") return 8;
    else if (s == "A") return 9;
    else if (s == "A#") return 10;
    else if (s == "B") return 11;
    else return 12;
}

int d(int a, int b) {
    return (b - a + MAXN) % MAXN;
}

bool d7(int n[4]) {
    return (d(n[0], n[1]) == 4 && d(n[1], n[2]) == 3 && d(n[2], n[3]) == 3);
}

void rshift(int n[4]) {
    int t = n[3];
    n[3] = n[2];
    n[2] = n[1];
    n[1] = n[0];
    n[0] = t;
}

int main() {
    fio;
    
    int cases; cin >> cases;
    f(casen,0,cases){
        string s;
        int n[4];
        f(i,0,4){
            cin >> s;
            n[i] = note(s);
        }
        if (d7(n)) {
            cout << "root\n";
            continue;
        }
        rshift(n);
        if (d7(n)) {
            cout << "first\n";
            continue;
        }
        rshift(n);
        if (d7(n)) {
            cout << "second\n";
            continue;
        }
        rshift(n);
        if (d7(n)) {
            cout << "third\n";
            continue;
        }
        cout << "invalid\n";
    }

    return 0;
}