// https://www.codeeval.com/open_challenges/115/
// Submitted December 26, 2015

#include <fstream>
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void tokenize(string line, vector<string>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ','))
		output.push_back(temp);
}

void sort_tokens(vector<string> tokens, vector<string>& alpha,
				vector<string>& nums)
{
	for (vector<string>::const_iterator it = tokens.begin();
		it != tokens.end(); ++it) {
		if (isalpha(it[0][0]))
			alpha.push_back(*it);
		else if(isdigit(it[0][0]))
			nums.push_back(*it);
	}
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<string> tokens, alpha, nums;
		tokenize(line, tokens);

		sort_tokens(tokens, alpha, nums);

		if (!alpha.empty()) {
			for (vector<string>::const_iterator it = alpha.begin();
				it != alpha.end(); ++it) {
				cout << *it;
				if (it == alpha.end() - 1)
					cout << "|";
				else
					cout << ",";
			}
		}

		if (!nums.empty()) {
			for (vector<string>::const_iterator it = nums.begin();
				it != nums.end(); ++it) {
				cout << *it;
				if (it == nums.end() - 1)
					cout << endl;
				else
					cout << ",";
			}
		}
	}

	return 0;
}