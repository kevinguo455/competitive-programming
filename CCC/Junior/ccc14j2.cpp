// https://dmoj.ca/problem/ccc14j2
#include <iostream>
#include <string>

int main() {
    int v, a = 0, b = 0;
    std::string votes;

    std::cin >> v >> votes;

    for (int i = 0; i < votes.length(); i++) {
        if (votes[i] == 65) {
            a++;
        }
        if (votes[i] == 66) {
            b++;
        }
    }

    if (a == b) {
        std::cout << "Tie";
    }
    else if (a < b) {
        std::cout << "B";
    }
    else {
        std::cout << "A";
    }
}