/*
COCI '08 Contest 1 #2 Ptice
Key Concepts: Implementation
https://dmoj.ca/problem/coci08c1p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int score;
    int cycle;
    vector<char> guesses;
};

bool cmp(Student a, Student b) {
    if (a.score == b.score) return a.name < b.name;
    return a.score > b.score;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    
    vector<Student> k;
    k.push_back({"Adrian", 0, 3, {'A', 'B', 'C'}});
    k.push_back({"Bruno", 0, 4, {'B', 'A', 'B', 'C'}});
    k.push_back({"Goran", 0, 6, {'C', 'C', 'A', 'A', 'B', 'B'}});
    
    for (int i = 0; i < n; i++) {
        /*for (Student x : k) {
            if (x.guesses[i % x.cycle] == s[i]) x.score++;
            cout << x.guesses[i % x.cycle] << " " << s[i] << " " << (x.guesses[i % x.cycle] == s[i]) << " " << x.score << "\n";
        }*/
        for (int j = 0; j < (int) k.size(); j++) {  
            if (k[j].guesses[i % k[j].cycle] == s[i]) k[j].score++;
        }
    }

    sort(k.begin(), k.end(), cmp);
    cout << k[0].score << "\n";
    for (int i = 0; i < (int) k.size(); i++) {
        if (k[i].score != k[0].score) break;   
        cout << k[i].name << "\n";
    }

    return 0;
}