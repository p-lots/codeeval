// https://www.codeeval.com/open_challenges/128/
// Submitted November 26, 2015

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void split_line(string line, vector<int>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ' '))
		output.push_back(stoi(temp));
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<int> nums, finalcount, finalnum;
		split_line(line, nums);
		
		int ncount = 0;
		vector<int>::size_type i, j;

		for (i = 0; i < nums.size(); ++i) {
			finalnum.push_back(nums[i]);
			for (j = i; j < nums.size(); ++j) {
				if (nums[i] == nums[j]) 
					ncount++;
				else {
					i = j - 1;
					break;
				}
			}

			finalcount.push_back(ncount);
			
			ncount = 0;
			if (j == nums.size())
				break;
		}

		for (vector<int>::size_type it = 0; it < finalnum.size(); ++it)
			cout << finalcount[it] << " " << finalnum[it] << " ";

		cout << endl;
	}

	return 0;
}