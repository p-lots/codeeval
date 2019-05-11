// https://www.codeeval.com/open_challenges/103/
// Submitted March 23, 2016

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;
	vector<int> nums;

	while (getline(file, line)) {
		stringstream ss(line);
		string temp;
		vector<int> numscpy;
		
		while (getline(ss, temp, ' ')) {
			nums.push_back(stoi(temp));
			numscpy.push_back(stoi(temp));
		}

		sort(numscpy.begin(), numscpy.end());

		bool isUnique;
		int lowestIndex;

		for (int i = 0; i < numscpy.size(); ++i) {
			isUnique = true;

			for (int j = 0; j < numscpy.size(); ++j) {
				if (numscpy[i] == numscpy[j] && i != j)
					isUnique = false;
			}
			
			if (isUnique){
				lowestIndex = i;
				break;
			}
		}
		
		if (isUnique) {
			for (int i = 0; i < nums.size(); ++i) {
				if (numscpy[lowestIndex] == nums[i]) {
					int winner = ++i;
					cout << winner << endl;

				}
			}
		}
		else
			cout << "0" << endl;

		nums.clear();
		numscpy.clear();
		
	}

	return 0;
}