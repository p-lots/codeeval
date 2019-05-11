// https://www.codeeval.com/open_challenges/124/
// Submitted November 23, 2015

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<string> linesep;
		stringstream ss(line);
		string temp;

		while (getline(ss, temp, ' '))
			linesep.push_back(temp);

		string delimiter = ",";
		vector<string> stringNums;
		for (vector<string>::const_iterator it = linesep.begin();
			it != linesep.end(); ++it) {
			string::size_type pos = it->find(delimiter);
			stringNums.push_back(it->substr(pos + 1, it->find(";")));
		}

		vector<int> nums;
		for (vector<string>::const_iterator it = stringNums.begin();
			it != stringNums.end(); ++it) 
			nums.push_back(stoi(*it));
		
		sort(nums.begin(), nums.end());

		int dist, start = nums[0];

		cout << start << ",";

		for (vector<int>::size_type i = 1; i < nums.size(); ++i) {
			dist = nums[i] - nums[i - 1];
			cout << dist;
			if (i < nums.size() - 1)
				cout << ",";
		}
		cout << endl;
		
	}

	return 0;
}