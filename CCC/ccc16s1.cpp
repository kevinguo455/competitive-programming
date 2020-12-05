// https://dmoj.ca/problem/ccc16s1
#include <iostream>
#include <string>

int main() {
    std::string a, b;
    std::cin >> a >> b;

    int letterA[26];
    int letterB[26];
    int wild = 0;

    for (int i = 0; i < 26; i++) {
        letterA[i] = 0;
        letterB[i] = 0;
    }

    for (int i = 0; i < a.length(); i++) {
        letterA[a[i]-97]++;
    }

    for (int i = 0; i < b.length(); i++) {
        if (b[i] == 42) {
            wild++;
        }
        else {
            letterB[b[i]-97]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (letterA[i] != letterB[i]) {
            if (letterA[i] > letterB[i]) {
                wild -= letterA[i] - letterB[i];
            }
            else {
                wild -= letterB[i] - letterA[i];
            }
            if (wild < 0) {
                std::cout << "N";
                return 0;
            }
        }
    }

    std::cout << "A";

    return 0;
}
