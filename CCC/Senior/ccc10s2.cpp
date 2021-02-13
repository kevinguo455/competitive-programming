// https://dmoj.ca/problem/ccc10s2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, char> m;
    for (int i = 0; i < n; i++) {
        char c;
        string s;
        cin >> c >> s;
        m.insert(make_pair(s,c));
    }
    string str; cin >> str;
    string s = "";
    for (int i = 0; i < (int) str.length(); i++) {
        s.append(str, i, 1);
        map<string, char>::iterator it = m.find(s);
        if (it != m.end()) {
            cout << it->second;
            s = "";
        }
    }
    cout << endl;
    return 0;
}
