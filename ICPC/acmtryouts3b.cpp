/*
University of Toronto ACM-ICPC Tryouts 2013 Problem 3B - A Careful Reply
Key Concepts: Implementation, String Algorithms
https://dmoj.ca/problem/acmtryouts3b
Solution by Kevin Guo
*/
#include <iostream>
#include <string>

int main() {
    int textamt, hearts;
    std::cin >> textamt;
    std::cin.ignore();
    std::string str, output;
    int x = 0;
    std::cin>>str;
    for (int i = 0; i < textamt; i++) {
        hearts = 0;
        output = "";
        std::getline (std::cin,str);
        x = str.length();
        for (int j = 0; j < x-1; j++) {
            if (str[j] == 60) {
                if (str[j+1] == 51) {
                    hearts++;
                }
            }
        }
        output = "<3";
        for (int k = 0; k < hearts; k++) {
            output += " <3";
        }
        std::cout << output << std::endl;
    }
    return 0;
}