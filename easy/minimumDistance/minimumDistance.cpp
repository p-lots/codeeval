// https://www.codeeval.com/open_challenges/189/
// Submitted November 23, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		int numfriends;
		vector<int> nums;

		stringstream ss(line);
		string temp;
		bool firstTime = true;
		while (getline(ss, temp, ' ')) {
			if (firstTime) {
				firstTime = false;
				numfriends = stoi(temp);
			}
			else 
				nums.push_back(stoi(temp));
		}

		sort(nums.begin(), nums.end());

		int lowest = nums[0];
		int diff, sumdiff = 0;
		long final = LONG_MAX;

		for (; lowest < nums.back(); ++lowest) {
			for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
				if (*it > lowest)
					diff = *it - lowest;
				else
					diff = lowest - *it;

				sumdiff += diff;
			}

			if (sumdiff < final)
				final = sumdiff;
			sumdiff = 0;
		}

		cout << final << endl;
	}

	return 0;
}