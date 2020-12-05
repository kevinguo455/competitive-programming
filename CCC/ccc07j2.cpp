// https://dmoj.ca/problem/ccc07j2
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cin >> text;

    while (text != "TTYL") {
        if (text == "CU") {
            std::cout << "see you";
        }
        else if (text == ":-)") {
            std::cout << "I'm happy";
        }
        else if (text == ":-(") {
            std::cout << "I'm unhappy";
        }
        else if (text == ";-)") {
            std::cout << "wink";
        }
        else if (text == ":-P") {
            std::cout << "stick out my tongue";
        }
        else if (text == "(~.~)") {
            std::cout << "sleepy";
        }
        else if (text == "TA") {
            std::cout << "totally awesome";
        }
        else if (text == "CCC") {
            std::cout << "Canadian Computing Competition";
        }
        else if (text ==  "CUZ") {
            std::cout << "because";
        }
        else if (text == "TY") {
            std::cout << "thank-you";
        }
        else if (text == "YW") {
            std::cout << "you're welcome";
        }
        else {
            std::cout << text;
        }

        std::cout << std::endl;
        std::cin >> text;
    }

    std::cout << "talk to you later";

    return 0;
}