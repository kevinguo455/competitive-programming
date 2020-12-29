/*
COCI '08 Regional #2 Majstor
Key Concepts: Implementation, Greedy Algorithms
https://dmoj.ca/problem/crci08p2
Solution by Kevin Guo
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int rps(std::string a, std::string b) { // Evaluates points won by a in a RPS game of a vs b
	int points = 0;

	for (int i = 0; i < a.length(); i++) { // R == 82, P == 80, S == 83
		if (a[i] == 82) {
			if (b[i] == 82) {
				points += 1;
			}
			else if (b[i] == 80) {

			}
			else {
				points += 2;
			}
		}
		else if (a[i] == 80) {
			if (b[i] == 82) {
				points += 2;
			}
			else if (b[i] == 80) {
				points += 1;
			}
			else {

			}
		}
		else {
			if (b[i] == 82) {

			}
			else if (b[i] == 80) {
				points += 2;
			}
			else {
				points += 1;
			}
		}
	}

	return points;
}

int optimize(std::string friends) { // Picks the best symbol to play against a string of all his friends' symbols, returns max possible points
	int R = 0, P = 0, S = 0;
	for (int i = 0; i < friends.length(); i++) {
		if (friends[i] == 82) {
			R++;
		}
		else if (friends[i] == 80) {
			P++;
		}
		else {
			S++;
		}
	}

	int points, maxpoints = 0;
	// If Sven plays R
	points = R + S * 2;
	maxpoints = std::max(points, maxpoints);
	// If Sven plays P
	points = P + R * 2;
	maxpoints = std::max(points, maxpoints);
	// If Sven plays S
	points = S + P * 2;
	maxpoints = std::max(points, maxpoints);
	
	return maxpoints;
}

int main()
{
	int rounds, friendAmount = 0;
	int pointsEarned = 0;
	std::string sven;
	std::cin >> rounds >> sven >> friendAmount;

	std::vector<std::string> friends(friendAmount);
	for (int i = 0; i < friendAmount; i++) {
		std::cin >> friends[i];
		pointsEarned += rps(sven, friends[i]);
	}
	
	int maxPossiblePoints = 0;
	std::string friendSymbols = "";
	for (int i = 0; i < rounds; i++) {
		for (int j = 0; j < friendAmount; j++) {
			friendSymbols += friends[j][i];
		}
		maxPossiblePoints += optimize(friendSymbols);
		friendSymbols = "";
	}

	std::cout << pointsEarned << std::endl << maxPossiblePoints;

    return 0;
}