/*
Fizz Coke
Key Concepts: Implementation
https://dmoj.ca/problem/fizzcoke
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1e5+5; 

struct Word {int n; string s;};

bool cmp(Word a, Word b) {
    return a.n < b.n;
}

string arr[MAXM];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M; cin >> N >> M;
    vector<Word> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].n >> v[i].s;
    }
    sort(v.begin(), v.end(), cmp);
    for (Word w : v) {
        for (int j = w.n; j <= M; j += w.n) arr[j] += w.s;
    }
    for (int i = 1; i <= M; i++) {
        if (arr[i].length() == 0) cout << i << '\n';
        else cout << arr[i] << '\n';
    }

    return 0;
}