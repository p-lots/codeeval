// https://www.codeeval.com/open_challenges/83/
// submitted October 9, 2016

/**
 * Beautiful strings work like so:
 *   1. Get a count of all the letters in the string
 *   2. Sum the following: multiply 26 by the highest count, 25 by the second
 *      highest count, 24 by the third highest count, etc
 *   2a. If there is a tie, decrement anyway after multiplying
 */

#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>

int main(int argc, char *argv[])
{
	std::ifstream file;
	if (argc > 1)
		file = std::ifstream(argv[1]);
	std::string line;
	while (std::getline(file, line)) {
		std::map<char, int> letterCounts;
		int l = 97; // ascii lowercase a
		for (int i = 0; i < 26; ++i)
			letterCounts[static_cast<char>(l + i)] = 0;
		char testLetter;
		for (char c : line) {
			if (isalpha(c)) {
				testLetter = (isupper(c) ? tolower(c) : c);
				letterCounts[testLetter]++;
			}
		}
		std::list<int> countList;
		for (auto it : letterCounts)
			countList.push_back(it.second);
		countList.sort(std::greater<int>());
		int sum = 0;
		int beaut = 26;
		for (auto it : countList)
			sum += (beaut-- * it);
		std::cout << sum << '\n';
	}
	return 0;
}