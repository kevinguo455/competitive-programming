/*
Mock CCC '15 Senior P2 - Problem-setting Pandemonium
Key Concepts: Greedy algorithm
https://dmoj.ca/problem/mockccc15s2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int problem[100005];

int main() {
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x; 
        problem[x]++;
    }
    int max = 0;
    for (int i = 0; i < 100005; i++) {
        if (problem[i] > max) 
            max = problem[i];
    }
    cout << max << endl;
    return 0;
}