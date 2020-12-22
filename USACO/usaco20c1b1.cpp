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

    cout << v[0] << " " << v[1] << " " << v[6] - v[1] - v[0] << "\n";

    return 0;
}