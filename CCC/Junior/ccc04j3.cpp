// https://dmoj.ca/problem/ccc04j3
#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> nouns;
    std::vector<std::string> adjs;
    std::string a, b;
    
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        nouns.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b;
        adjs.push_back(b);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << nouns[i] << " as " << adjs[j] << std::endl;
        }
    }
    return 0;
}