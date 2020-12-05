// https://dmoj.ca/problem/ccc15j2
#include <iostream>
#include <string>

int main() {
    std::string text, compare;
    getline(std::cin, text);
    int happy = 0, sad = 0;

    for (int i = 0; i < text.length() - 2; i++) {
        compare = "";
        if (text[i] == 58) {
            compare += text[i];
            compare += text[i+1];
            compare += text[i+2];
        }
        if (compare == ":-)") {
            happy++;
            i += 2;
        }
        else if (compare == ":-(") {
            sad++;
            i += 2;
        }
    }

    if (happy == 0 && sad == 0) {
        std::cout << "none";
    }
    else if (happy == sad) {
        std::cout << "unsure";
    }
    else if (happy < sad) {
        std::cout << "sad";
    }
    else {
        std::cout << "happy";
    }

    return 0;
}