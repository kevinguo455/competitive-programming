// https://dmoj.ca/problem/ccc16j1
#include <iostream>
#include <math.h>
#include <string>

int main() {

    int wins = 0;

    for (int i = 1; i <= 6; i++) {
        std::string x;
        std::cin >> x;
        if (x == "W") {
            wins++;
        }
    }

    if (wins == 0) {
        std::cout << "-1";
    }
    else {
        std::cout << 1 + ceil((6-wins)/2);
    }

    return 0;
}