/*
CCC '09 J4 - Signage
Key Concepts: Implementation
https://dmoj.ca/problem/ccc09j4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6; 

string s[MAXN] = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int W; cin >> W;
    int a = 0, b = 0, l = 0;
    
    while (b < MAXN) {
        
        // detect words in this line
        a = b;
        l = s[b].length();
        b++;
        while (b < MAXN && l + s[b].length() + 1 <= W) {
            l += s[b].length() + 1;
            b++;
        }

        // print words in this line
        int p = 0;
        if (b-a-1 != 0) p = (W-l) / (b-a-1) + 1;
        int e = W - l - (p-1) * (b-a-1);

        string out = "";

        for (int i = a; i < b-1; i++) {
            //cout << s[i];
            out += s[i];
            for (int j = 0; j < p; j++) /*cout << ".";*/ out += ".";
            if (i < a + e) /*cout << ".";*/ out += ".";
        }
        //cout << s[b-1];
        out += s[b-1];
        while (out.length() < W) {
            out += ".";
        }

        /*if (a == b-1) {
            for (int j = 0; j < p; j++) cout << ".";
        }*/
        cout << out << "\n";
    }

    return 0;
}