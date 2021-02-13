// https://dmoj.ca/problem/ccc00s2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    double t;
    vector<double> v;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }
    int op; cin >> op;
    double s,p;
    while (op != 77) {
        if (op == 99) {
            cin >> s >> p;
            double x = v[s-1];
            double y = x*p/100;
            double z = x-y;
            v[s-1] = y;
            v.insert(v.begin()+s, z);
        }
        else if (op == 88) {
            cin >> s;
            v[s-1] += v[s];
            v.erase(v.begin()+s);
        }
        cin >> op;
    }
    for (double i:v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}