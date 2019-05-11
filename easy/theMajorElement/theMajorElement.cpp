// https://www.codeeval.com/open_challenges/132/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

void fill_vec(string line, vector<int>& output)
{
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, ','))
		output.push_back(stoi(temp));
}

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line)) {
		vector<int> nums;
		fill_vec(line, nums);

		long major = nums.size() / 2;

		long r = LONG_MIN, count;

		for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
			count = 0;

			for (vector<int>::size_type j = 0; j < nums.size(); ++j) {
				if (nums[i] == nums[j]) {
					count++;
				}
			}

			if (count > major) {
				r = nums[i];
				break;
			}
		}

		if (r != LONG_MIN)
			cout << r << endl;
		else
			cout << "None" << endl;

	}

	file.close();
	return 0;
}