#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>


int main(int argc, char * argv[]) {
	std::vector<int> counts(1);

	std::string line;
	std::ifstream f(argv[2]);
	if(f.is_open()) {
		while(getline(f, line)) {
			if(line.empty()) {
				counts.push_back(0);
			} else {
				counts.back() += std::stoi(line);
			}
		}
    
		f.close();
	}

	std::string test = argv[1];
	if(test == "a") {
		auto i = std::max_element(counts.begin(), counts.end());
		std::cout << *i << std::endl;
	} else {
		std::sort(counts.begin(), counts.end(), std::greater<>());

		auto s = std::accumulate(counts.begin(), counts.begin() + 3, 0);
		std::cout << s << std::endl;
	}
}
