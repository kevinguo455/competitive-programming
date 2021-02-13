// https://dmoj.ca/problem/ccc01s1
#include <iostream>
#include <string>

int main() {
    std::string cards;
    std::cin >> cards;
    std::string dealt[4] = {"","","",""};
    int points[4] = {0,0,0,0};
    std::string suits[4] = {"Clubs","Diamonds","Hearts","Spades"};
    int suit = 0;
    for (int i = 0; i < cards.length(); i++) {
        if (cards[i] == 'C') {
            suit = 0;
        }
        else if (cards[i] == 'D') {
            suit = 1;
        }
        else if (cards[i] == 'H') {
            suit = 2;
        }
        else if (cards[i] == 'S') {
            suit = 3;
        }
        else {
            dealt[suit] = dealt[suit] + " " + cards[i];
            if (cards[i] == 'A') {
                points[suit] += 4;
            }
            else if (cards[i] == 'K') {
                points[suit] += 3;
            }
            else if (cards[i] == 'Q') {
                points[suit] += 2;
            }
            else if (cards[i] == 'J') {
                points[suit] += 1;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (dealt[i].length() == 0) {
            points[i] += 3;
        }
        else if (dealt[i].length() == 2) {
            points[i] += 2;
        }
        else if (dealt[i].length() == 4) {
            points[i] += 1;
        }
    }
    std::cout << "Cards Dealt Points" << std::endl;
    int total = 0;
    for (int i = 0; i < 4; i++) {
        std::cout << suits[i] << dealt[i] << " " << points[i] << std::endl;
        total += points[i];
    }
    std::cout << "Total " << total;
    return 0;
}