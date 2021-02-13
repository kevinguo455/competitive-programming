// https://dmoj.ca/problem/ccc05s2
#include <iostream>

int main() {
    int maxx = 0, maxy = 0, posx = 0, posy = 0, movex = 0, movey = 0;
    std::cin >> maxx >> maxy;
    std::cin >> movex >> movey;
    
    while (movex != 0 || movey != 0) {
        posx += movex;
        posy += movey;

        if (posx < 0) {posx = 0;}
        else if (posx > maxx) {posx = maxx;}
        if (posy < 0) {posy = 0;}
        else if (posy > maxy) {posy = maxy;}

        std::cout << posx << " " << posy << std::endl;
        std::cin >> movex >> movey;
    }

    return 0;
}
