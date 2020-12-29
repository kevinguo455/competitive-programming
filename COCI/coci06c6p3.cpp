/*
COCI '06 Contest 6 #3 Maraton
Key Concepts: Implementation
https://dmoj.ca/problem/coci06c6p3
Solution by Kevin Guo
*/
#include <iostream>
#include <string>
#include <vector>

int size;
std::vector<std::string> board;

bool inrange(int n) {
    if (n > 0 && n < size-1) {
        return true;
    }
    return false;
}

// Return true if is center of winning sequence, false otherwise
bool scan(int x, int y) {
    char tile = board[x][y];
    if (tile == '.') {
        return false;
    }
    if (inrange(x) && inrange(y)) { // Check diagonals
        if (board[x-1][y-1] == tile && board[x+1][y+1] == tile) { //   \ diagonal
            return true;
        }
        if (board[x+1][y-1] == tile && board[x-1][y+1] == tile) { //   / diagonal
            return true;
        }
    }
    if (inrange(x)) { // Check vertical
        if (board[x+1][y] == tile && board[x-1][y] == tile) { 
            return true;
        }
    }
    if (inrange(y)) { // Check vertical
        if (board[x][y+1] == tile && board[x][y-1] == tile) { 
            return true;
        }
    }
    return false;
}

int main() {
    std::string line;
    std::cin >> size;
    for (int i = 0; i < size; i++) {
        std::cin >> line;
        board.push_back(line);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (scan(i,j)) {
                std::cout << board[i][j];
                return 0;
            }
        }
    }

    std::cout << "ongoing";
    return 0;
}