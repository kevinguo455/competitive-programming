// https://dmoj.ca/problem/ccc16j2
#include <iostream>

int main() {
    int square [4] [4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> square[i][j];
        }
    }

    int sum = 0;
    int compare = 0;
    for (int j = 0; j < 4; j++) {
        sum += square[0][j];
    }

    for (int i = 0; i < 4; i++) {
        compare = 0;
        for (int j = 0; j < 4; j++) {
            compare += square[i][j];
        }
        if (compare != sum) {
            std::cout << "not magic" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < 4; i++) {
        compare = 0;
        for (int j = 0; j < 4; j++) {
            compare += square[j][i];
        }
        if (compare != sum) {
            std::cout << "not magic" << std::endl;
            return 0;
        }
    }

    std::cout << "magic" << std::endl;
    return 0;
}