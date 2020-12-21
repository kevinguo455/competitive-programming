/*
USACO 2020 December Contest, Bronze - Problem 1. Do You Know Your ABCs?
Key Concepts: Implementation, Simple Math
http://www.usaco.org/index.php?page=viewproblem&cpid=1047
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> v(7);
    for (int i = 0; i < 7; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 2; i < 6; i++) {
        if (v[i] != v[6] - v[0] && v[i] != v[6] - v[1] && v[i] != v[0] + v[1]) {
            cout << v[0] << " " << v[1] << " " << v[i] << "\n";
            return 0;
        }
    }

    return 0;
}