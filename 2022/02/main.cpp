#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <map>


int main(int argc, char * argv[]) {
	std::map<std::string, int> scores;

	std::string test = argv[1];
	if(test == "a") {
		scores = {
			{ "A X", 1 + 3 },
			{ "A Y", 2 + 6 },
			{ "A Z", 3 + 0 },
			{ "B X", 1 + 0 },
			{ "B Y", 2 + 3 },
			{ "B Z", 3 + 6 },
			{ "C X", 1 + 6 },
			{ "C Y", 2 + 0 },
			{ "C Z", 3 + 3 },
		};
	} else {
		scores = {
			{ "A X", 3 + 0 },
			{ "A Y", 1 + 3 },
			{ "A Z", 2 + 6 },
			{ "B X", 1 + 0 },
			{ "B Y", 2 + 3 },
			{ "B Z", 3 + 6 },
			{ "C X", 2 + 0 },
			{ "C Y", 3 + 3 },
			{ "C Z", 1 + 6 },
		};
	}

	int score = 0;

	std::string line;
	std::ifstream f(argv[2]);
	if(f.is_open()) {
		while(getline(f, line)) {
			score += scores[line];
		}
    
		f.close();
	}

	std::cout << score << std::endl;
}
