/*
University of Toronto ACM-ICPC Tryouts 2012 Problem 1A - Rock Paper Scissors Fox
Key Concepts: Implementation
https://dmoj.ca/problem/acmtryouts1a
Solution by Kevin Guo
*/
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string play;

    for (int i = 0; i < n; i++) {
        std::cin >> play;
        if (play == "Rock") {
            std::cout << "Paper" << std::endl;
        }
        else if (play == "Paper") {
            std::cout << "Scissors" << std::endl;
        }
        else if (play == "Scissors") {
            std::cout << "Rock" << std::endl;
        }
        else if (play == "Fox") {
            std::cout << "Foxen" << std::endl;
        }
        else if (play == "Foxen") {
            return 0;
        }
    }

    return 0;
}