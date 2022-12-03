#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>


int char_value(char c) {
	if(c >= 'a' && c <= 'z') {
		return c - 'a' + 1;
	}

	if(c >= 'A' && c <= 'Z') {
		return c - 'A' + 27;
	}

	throw std::runtime_error("input broken");
}

int priorities_sum(std::vector<int> const &counts, int n) {
	int score = 0;
	for(size_t i = 0; i < counts.size(); ++i) {
		if(counts[i] == n) {
			score += i;
		}
	}

	return score;
}

template<typename T>
void fill(std::vector<int> & counts, T begin, T end) {
	std::set<char> s(begin, end);
	for(auto i : s) {
		++counts[char_value(i)];
	}
}

int scan_group(std::vector<std::string> const & g) {
	std::vector<int> counts(26 * 2 + 1);
	for(auto s : g) {
		fill(counts, s.begin(), s.end());
	}

	return priorities_sum(counts, g.size());
}

int scan_rucksack(std::string const & s) {
	std::vector<std::string> g;

	auto n = s.size() / 2;
	g.emplace_back(s.begin(), s.begin() + n);
	g.emplace_back(s.begin() + n, s.end());

	return scan_group(g);
}

int main(int argc, char * argv[]) {
	int score = 0;

	std::string line;
	std::ifstream f(argv[2]);
	if(f.is_open()) {
		std::string test = argv[1];
		if(test == "a") {
			while(getline(f, line)) {
				score += scan_rucksack(line);
			}
		} else {
			std::vector<std::string> group;
			while(getline(f, line)) {
				group.push_back(line);
				if(group.size() == 3) {
					score += scan_group(group);
					group.clear();
				}
			}
		}
    
		f.close();
	}

	std::cout << score << std::endl;
}
