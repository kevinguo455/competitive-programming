// https://dmoj.ca/problem/ccc05s4
#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, n; cin >> l;
    for (int cases = 0; cases < l; cases++) {
        cin >> n;
        vector<string> in;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            in.push_back(s);
        }
        string root = in.back();
        vector<string> v;
        
        int maxL = 0;
        for (int i = 0; i < n; i++) {
            string s = in[i];
            if (s == root) {
                v.pop_back();
                continue;
            }
            if ((int) v.size() <= 1) {
                v.push_back(s);
            }
            else {
                vector<string>::iterator it = v.end()-2;
                if (*it != s) {
                    v.push_back(s);
                }
                else {
                    v.pop_back();
                }
            }
            if ((int) v.size() > maxL) {
                maxL = v.size();
            }
        }
        cout << (n-maxL*2)*10 << endl;
    }
    return 0;
}