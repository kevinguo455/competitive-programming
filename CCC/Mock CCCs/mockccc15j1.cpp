/*
Mock CCC '15 Junior P1 - 416
Key Concepts: Implementation, string parsing
https://dmoj.ca/problem/mockccc15j1
Solution by Kevin Guo
*/
#include <iostream>
#include <string>

int main() {
    std::string n;
    std::getline(std::cin,n);
    if ((n[0] == '4' && n[1] == '1' && n[2] == '6') || (n[0] == '6' && n[1] == '4' && n[2] == '7') || (n[0] == '4' && n[1] == '3' && n[2] == '7')) {
        if (n.length() == 11) {
            if (n[3] == ' ') {
                for (int i = 4; i <= 10; i++) {
                    if (n[i] >= '0' && n[i] <= '9') {

                    } else {
                        std::cout << "invalid";
                        return 0;
                    }
                }
                if (n[0] == '4' && n[1] == '1' && n[2] == '6') {
                    std::cout << "valuable";
                } else {
                    std::cout << "valueless";
                }
                return 0;
            }
        }
    }

    std::cout << "invalid";
    return 0;
}